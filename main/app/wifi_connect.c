//
// Created by Administrator on 2024/2/29.
//

#include "wifi_connect.h"
#include "common.h"
#include "littlefs_drv.h"
#include "wifi_init.h"

#include "esp_event.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include <string.h>

// 事件组允许每个事件有多个位，但我们只关心两个事件
#define WIFI_CONNECTED_BIT BIT0 // 连接到 AP 成功
#define WIFI_FAIL_BIT BIT1      // 最大重试次数后，依然连接失败

#define ESP_MAXIMUM_CONNECT_RETRY 3 // 连接失败重试次数

static EventGroupHandle_t wifi_dpp_evt_group; // WiFi事件组，用于事件通知
static int connect_retry_num = 0;

static void WifiEventHandler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
  if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
    esp_wifi_connect();
  } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
    if (connect_retry_num < ESP_MAXIMUM_CONNECT_RETRY) {
      esp_wifi_connect();
      connect_retry_num++;
      ESP_LOGI(ESP_LOG_TAG, "retry to connect to the AP");
    } else {
      xEventGroupSetBits(wifi_dpp_evt_group, WIFI_FAIL_BIT);
    }
    ESP_LOGI(ESP_LOG_TAG, "connect to the AP fail");
  } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
    ESP_LOGI(ESP_LOG_TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
    connect_retry_num = 0;
    xEventGroupSetBits(wifi_dpp_evt_group, WIFI_CONNECTED_BIT);
  }
}

static void WifiInitSta() {
  wifi_dpp_evt_group = xEventGroupCreate();

  if (!WifiIsInited()) {
    WifiInit();
    esp_netif_create_default_wifi_sta();
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  }

  wifi_config_t wifi_config = {0};
  ESP_ERROR_CHECK(esp_wifi_get_config(WIFI_IF_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));

  esp_event_handler_instance_t instance_any_id;
  esp_event_handler_instance_t instance_got_ip;
  ESP_ERROR_CHECK(
      esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &WifiEventHandler, NULL, &instance_any_id)
  );
  ESP_ERROR_CHECK(
      esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &WifiEventHandler, NULL, &instance_got_ip)
  );

  ESP_ERROR_CHECK(esp_wifi_start());
  ESP_LOGI(ESP_LOG_TAG, "WiFi init STA finished.");

  /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
   * number of re-tries (WIFI_FAIL_BIT). The bits are set by WifiEventHandler() (see above) */
  EventBits_t bits =
      xEventGroupWaitBits(wifi_dpp_evt_group, WIFI_CONNECTED_BIT | WIFI_FAIL_BIT, pdFALSE, pdFALSE, portMAX_DELAY);

  /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
   * happened. */
  if (bits & WIFI_CONNECTED_BIT) {
    ESP_LOGI(ESP_LOG_TAG, "connected to ap SSID:%s password:%s", wifi_config.sta.ssid, wifi_config.sta.password);
  } else if (bits & WIFI_FAIL_BIT) {
    ESP_LOGI(ESP_LOG_TAG, "Failed to connect to SSID:%s, password:%s", wifi_config.sta.ssid, wifi_config.sta.password);
  } else {
    ESP_LOGE(ESP_LOG_TAG, "UNEXPECTED EVENT");
  }

  vTaskDelete(NULL); // 删除任务
}

void TaskWifiConnect() {
  struct stat wifi_conf_stat;
  if (stat(WIFI_CONFIG_PATH, &wifi_conf_stat) == 0) {
    // 如果文件存在则尝试连接WiFi
    ESP_LOGI(ESP_LOG_TAG, "Start connect to WiFi...");
    xTaskCreate(WifiInitSta, __func__, 1024 * 8, NULL, tskIDLE_PRIORITY, NULL);
  } else {
    ESP_LOGI(ESP_LOG_TAG, "WiFi configuration not found.");
  }
}

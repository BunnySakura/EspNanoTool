//
// Created by hello3rd on 24-1-31.
//

#include "wifi_dpp.h"
#include "common.h"
#include "littlefs_drv.h"
#include "wifi_init.h"

#include "esp_dpp.h"
#include "esp_event.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef CONFIG_ESP_DPP_LISTEN_CHANNEL
#define WIFI_DPP_LISTEN_CHANNEL_LIST CONFIG_ESP_DPP_LISTEN_CHANNEL_LIST
#else
#define WIFI_DPP_LISTEN_CHANNEL_LIST "6"
#endif

#ifdef CONFIG_ESP_DPP_BOOTSTRAPPING_KEY
#define WIFI_DPP_BOOTSTRAPPING_KEY CONFIG_ESP_DPP_BOOTSTRAPPING_KEY
#else
#define WIFI_DPP_BOOTSTRAPPING_KEY 0
#endif

#ifdef CONFIG_ESP_DPP_DEVICE_INFO
#define WIFI_DPP_DEVICE_INFO CONFIG_ESP_DPP_DEVICE_INFO
#else
#define WIFI_DPP_DEVICE_INFO 0
#endif

#define CURVE_SEC256R1_PKEY_HEX_DIGITS 64

#define DPP_CONNECTED_BIT BIT0
#define DPP_CONNECT_FAIL_BIT BIT1
#define DPP_AUTH_FAIL_BIT BIT2

char wifi_dpp_qr_data[256]; // 保存WiFi DPP 配网数据，用于显示二维码

static EventGroupHandle_t wifi_dpp_evt_group; // WiFi事件组，用于事件通知
static wifi_config_t wifi_dpp_config;
static int connect_retry_num = 0;

static void WifiEventHandler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
  if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
    ESP_ERROR_CHECK(esp_supp_dpp_start_listen());
    ESP_LOGI(ESP_LOG_TAG, "Started listening for DPP Authentication");
  } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
    if (connect_retry_num < 5) {
      esp_wifi_connect();
      connect_retry_num++;
      ESP_LOGI(ESP_LOG_TAG, "retry to connect to the AP");
    } else {
      xEventGroupSetBits(wifi_dpp_evt_group, DPP_CONNECT_FAIL_BIT);
    }
    ESP_LOGI(ESP_LOG_TAG, "connect to the AP fail");
  } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
    ESP_LOGI(ESP_LOG_TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
    connect_retry_num = 0;
    xEventGroupSetBits(wifi_dpp_evt_group, DPP_CONNECTED_BIT);
  }
}

static void DppEnrolleeEvtHandler(esp_supp_dpp_event_t event, void *data) {
  switch (event) {
    case ESP_SUPP_DPP_URI_READY: {
      if (data != NULL) {
        ESP_LOGI(ESP_LOG_TAG, "Scan QR Code to configure the enrollee:\n");
        memset(wifi_dpp_qr_data, 0, sizeof(wifi_dpp_qr_data));
        strcpy(wifi_dpp_qr_data, (const char *) data);
        // esp_qrcode_config_t cfg = ESP_QRCODE_CONFIG_DEFAULT();
        // esp_qrcode_generate(&cfg, (const char *) data); // esp_qrcode_generate 调用会修改数据
      }
      break;
    }

    case ESP_SUPP_DPP_CFG_RECVD: {
      memcpy(&wifi_dpp_config, data, sizeof(wifi_dpp_config));
      esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_dpp_config);
      ESP_LOGI(ESP_LOG_TAG, "DPP Authentication successful, connecting to AP : %s", wifi_dpp_config.sta.ssid);
      connect_retry_num = 0;
      esp_wifi_connect();
      break;
    }

    case ESP_SUPP_DPP_FAIL: {
      if (connect_retry_num < 5) {
        ESP_LOGI(ESP_LOG_TAG, "DPP Auth failed (Reason: %s), retry...", esp_err_to_name((int) data));
        ESP_ERROR_CHECK(esp_supp_dpp_start_listen());
        connect_retry_num++;
      } else {
        xEventGroupSetBits(wifi_dpp_evt_group, DPP_AUTH_FAIL_BIT);
      }
      break;
    }

    default: {
      break;
    }
  }
}

static esp_err_t DppEnrolleeBootstrap() {
  esp_err_t ret;
  size_t pkey_len = strlen(WIFI_DPP_BOOTSTRAPPING_KEY);
  char *key = NULL;

  if (pkey_len) {
    /* Currently only NIST P-256 curve is supported, add prefix/postfix accordingly */
    char prefix[] = "30310201010420";
    char postfix[] = "a00a06082a8648ce3d030107";

    if (pkey_len != CURVE_SEC256R1_PKEY_HEX_DIGITS) {
      ESP_LOGI(ESP_LOG_TAG, "Invalid key length! Private key needs to be 32 bytes (or 64 hex digits) long");
      return ESP_FAIL;
    }

    key = malloc(sizeof(prefix) + pkey_len + sizeof(postfix));
    if (!key) {
      ESP_LOGI(ESP_LOG_TAG, "Failed to allocate for bootstrapping key");
      return ESP_ERR_NO_MEM;
    }
    sprintf(key, "%s%s%s", prefix, WIFI_DPP_BOOTSTRAPPING_KEY, postfix);
  }

  /* Currently only supported method is QR Code */
  ret = esp_supp_dpp_bootstrap_gen(WIFI_DPP_LISTEN_CHANNEL_LIST, DPP_BOOTSTRAP_QR_CODE, key, WIFI_DPP_DEVICE_INFO);

  if (key) free(key);

  return ret;
}

static void DppEnrolleeInit() {
  wifi_dpp_evt_group = xEventGroupCreate();

  if (!WifiIsInited()) {
    WifiInit();
    esp_netif_create_default_wifi_sta();
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  }

  ESP_ERROR_CHECK(esp_supp_dpp_init(DppEnrolleeEvtHandler));
  ESP_ERROR_CHECK(DppEnrolleeBootstrap());

  ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &WifiEventHandler, NULL));
  ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &WifiEventHandler, NULL));

  // 需要等待上述步骤完成，否则`esp_supp_dpp_start_listen`会报错：
  // DPP: failed to start listen as dpp not initialized or bootstrapped.
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  ESP_ERROR_CHECK(esp_wifi_start());

  /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
   * number of re-tries (WIFI_FAIL_BIT). The bits are set by WifiEventHandler() (see above) */
  EventBits_t bits = xEventGroupWaitBits(
      wifi_dpp_evt_group, DPP_CONNECTED_BIT | DPP_CONNECT_FAIL_BIT | DPP_AUTH_FAIL_BIT, pdFALSE, pdFALSE, portMAX_DELAY
  );

  /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
   * happened. */
  if (bits & DPP_CONNECTED_BIT) {
    ESP_LOGI(
        ESP_LOG_TAG, "connected to ap SSID:%s password:%s", wifi_dpp_config.sta.ssid, wifi_dpp_config.sta.password
    );
    // 创建一个文件，下次开机时检测到文件存在会自动尝试连接WiFi
    FILE *f = fopen(WIFI_CONFIG_PATH, "w");
    if (f == NULL) {
      ESP_LOGE(ESP_LOG_TAG, "Failed to open file for writing");
      return;
    }
    fclose(f);
  } else if (bits & DPP_CONNECT_FAIL_BIT) {
    ESP_LOGI(
        ESP_LOG_TAG, "Failed to connect to SSID:%s, password:%s", wifi_dpp_config.sta.ssid, wifi_dpp_config.sta.password
    );
  } else if (bits & DPP_AUTH_FAIL_BIT) {
    ESP_LOGI(ESP_LOG_TAG, "DPP Authentication failed after %d retries", connect_retry_num);
  } else {
    ESP_LOGE(ESP_LOG_TAG, "UNEXPECTED EVENT");
  }

  esp_supp_dpp_deinit();
  ESP_ERROR_CHECK(esp_event_handler_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, &WifiEventHandler));
  ESP_ERROR_CHECK(esp_event_handler_unregister(WIFI_EVENT, ESP_EVENT_ANY_ID, &WifiEventHandler));
  vEventGroupDelete(wifi_dpp_evt_group);
  vTaskDelete(NULL); // 删除任务
}

void TaskDppEnrollee() {
  ESP_LOGI(ESP_LOG_TAG, "Start WiFi DPP...");
  struct stat wifi_conf_stat;
  if (stat(WIFI_CONFIG_PATH, &wifi_conf_stat) == 0) {
    // 清理WiFi配置文件，重新配网
    unlink(WIFI_CONFIG_PATH);
  }
  xTaskCreate(DppEnrolleeInit, __func__, 1024 * 8, NULL, tskIDLE_PRIORITY, NULL);
}

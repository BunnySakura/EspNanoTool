#include "wifi_init.h"
#include "common.h"

#include "esp_log.h"
#include "esp_wifi.h"

static bool wifi_is_inited = false;

void WifiInit(int mode) {
  if (wifi_is_inited) {
    return;
  }

  ESP_LOGI(ESP_LOG_TAG, "WiFi initing...");
  ESP_ERROR_CHECK(esp_netif_init());
  esp_err_t esp_err_code = esp_event_loop_create_default();
  if (esp_err_code == ESP_ERR_INVALID_STATE) {
    ESP_LOGW(ESP_LOG_TAG, "Default event loop has already been created.");
  } else {
    ESP_ERROR_CHECK(esp_err_code);
  }
  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));
  ESP_ERROR_CHECK(esp_wifi_set_ps(WIFI_PS_NONE)); // 关闭WiFi省电以避免干扰 GPIO39 上的按键

  wifi_is_inited = true;
  ESP_LOGI(ESP_LOG_TAG, "WiFi init finished.");
}

void WifiDeinit() {
  if (!wifi_is_inited) {
    return;
  }

  ESP_LOGI(ESP_LOG_TAG, "WiFi deiniting...");
  ESP_ERROR_CHECK(esp_wifi_disconnect());
  ESP_ERROR_CHECK(esp_wifi_stop());
  ESP_ERROR_CHECK(esp_wifi_deinit());

  wifi_is_inited = false;
  ESP_LOGI(ESP_LOG_TAG, "WiFi deinit finished.");
}

bool WifiIsInited() {
  return wifi_is_inited;
}

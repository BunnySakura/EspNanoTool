#include <sys/cdefs.h>
/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "lvgl.h"
#include "lvgl_driver/lv_port_indev.h"
#include "lvgl_driver/lvgl_init.h"
#include "littlefs_init.h"
#include "esp_littlefs.h"
#include "wifi_connect.h"
#include "main_page.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LED_4 12
#define LED_5 13
#define LOW_LEVEL 0
#define HIGH_LEVEL 1

lv_ui guider_ui;

_Noreturn void TaskPrintChipInfo(void *params) {
  (void) params;
  /* Print chip information */
  esp_chip_info_t chip_info;
  uint32_t flash_size;
  esp_chip_info(&chip_info);
  ESP_LOGI(
      __func__,
      "This is %s chip with %d CPU core(s), %s%s%s%s, ",
      CONFIG_IDF_TARGET,
      chip_info.cores,
      (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
      (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
      (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
      (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : ""
  );

  unsigned major_rev = chip_info.revision / 100;
  unsigned minor_rev = chip_info.revision % 100;
  ESP_LOGI(__func__, "silicon revision v%d.%d, ", major_rev, minor_rev);
  if (esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
    ESP_LOGW(__func__, "Get flash size failed");
  }

  ESP_LOGI(
      __func__,
      "%" PRIu32 "MB %s flash\n",
      flash_size / (uint32_t) (1024 * 1024),
      (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external"
  );

  ESP_LOGI(
      __func__,
      "Minimum free heap size: %" PRIu32 " bytes\n",
      esp_get_minimum_free_heap_size()
  );

  while (true) {
    // 任务禁止主动返回
    ESP_LOGI(__func__, "Task delete.");
    fflush(stdout);
    vTaskDelete(NULL);
  }
}

_Noreturn void TaskBlinkLed(void *params) {
  (void) params;
  uint8_t level = LOW_LEVEL;
  gpio_reset_pin(LED_4);
  gpio_set_direction(LED_4, GPIO_MODE_OUTPUT); // Set the GPIO as a push/pull output
  gpio_reset_pin(LED_5);
  gpio_set_direction(LED_5, GPIO_MODE_OUTPUT); // Set the GPIO as a push/pull output
  ESP_LOGI(__func__, "LED configuration completed.");

  while (true) {
    gpio_set_level(LED_4, level);
    ESP_LOGI(__func__, "LED_4: %s!", level == HIGH_LEVEL ? "ON" : "OFF");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    level = !level;

    gpio_set_level(LED_5, level);
    ESP_LOGI(__func__, "LED_5: %s!", level == HIGH_LEVEL ? "ON" : "OFF");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void TaskWifiConnect() {
  wifi_config_t config = {};
  /**
   * \brief 二进制读取WiFi配置
   */
  char wifi_config_path[] = LFS_WIFI_CONFIG_PATH;
  FILE *wifi_config = fopen(LFS_WIFI_CONFIG_PATH, "rb");
  do {
    if (wifi_config == NULL) {
      ESP_LOGE(__func__, "Error opening file: %s", wifi_config_path);
      break;
    }
    size_t bytes_written = fread(&config, sizeof(char), sizeof(wifi_config_t), wifi_config);
    if (bytes_written != sizeof(wifi_config_t)) {
      ESP_LOGE(__func__, "Error reading from file: %s", wifi_config_path);
      break;
    }
    WifiConnect(&config);
  } while (false);
  fclose(wifi_config);

  vTaskDelete(NULL);
}

_Noreturn void app_main() {
  DrvLittleFs *little_fs = DrvLittleFsInit();
  DrvLittleFsMount(little_fs, LFS_DEFAULT_ROOT_PATH, "littlefs");

  xTaskCreate(TaskWifiConnect, "TaskWifiConnect", 1024 * 4, NULL, tskIDLE_PRIORITY, NULL);

  /**
   * \brief Start LVGL.
   */
  lvgl_init();

  /*Create a GUI-Guider app */
  setup_ui(&guider_ui);
  events_init(&guider_ui);
  custom_init(&guider_ui);

  xTaskCreate(TaskPrintChipInfo, "TaskPrintChipInfo", 1024 * 4, NULL, tskIDLE_PRIORITY, NULL);

  while (true) {
    vTaskDelay(pdMS_TO_TICKS(10));
    lv_task_handler();
  }
}

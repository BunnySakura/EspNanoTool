#include <sys/cdefs.h>
/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "common.h"
#include "custom.h"
#include "events_init.h"
#include "gui_guider.h"
#include "littlefs_drv.h"
#include "lvgl.h"
#include "lvgl_driver/lv_port_indev.h"
#include "lvgl_driver/lvgl_init.h"
#include "wifi_connect.h"

#include "driver/gpio.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_littlefs.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "sdkconfig.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

lv_ui guider_ui;

void TaskPrintChipInfo(void *params) {
  (void) params;
  /* Print chip information */
  esp_chip_info_t chip_info;
  uint32_t flash_size;
  esp_chip_info(&chip_info);
  ESP_LOGI(
      ESP_LOG_TAG, "This is %s chip with %d CPU core(s), %s%s%s%s, ", CONFIG_IDF_TARGET, chip_info.cores,
      (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "", (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
      (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
      (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : ""
  );

  unsigned major_rev = chip_info.revision / 100;
  unsigned minor_rev = chip_info.revision % 100;
  ESP_LOGI(ESP_LOG_TAG, "silicon revision v%d.%d, ", major_rev, minor_rev);
  if (esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
    ESP_LOGW(ESP_LOG_TAG, "Get flash size failed");
  }

  ESP_LOGI(
      ESP_LOG_TAG, "%" PRIu32 "MB %s flash\n", flash_size / (uint32_t) (1024 * 1024),
      (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external"
  );

  ESP_LOGI(ESP_LOG_TAG, "Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());
  ESP_LOGI(ESP_LOG_TAG, "%s delete.", __func__);
  vTaskDelete(NULL);
}

/**
 * \brief 初始化NVS分区
 * \note 非易失性存储 (NVS) 库主要用于在 flash 中存储键值格式的数据。
 */
void InitNvsFlash() {
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ESP_ERROR_CHECK(nvs_flash_init());
  }
  ESP_LOGI(ESP_LOG_TAG, "NVS flash init successfully.");
}

void app_main() {
  // 初始化LittleFs文件系统
  LittleFs *little_fs = LittleFsInit();
  LittleFsMount(little_fs, LFS_DEFAULT_ROOT_PATH, "littlefs");

  // 初始化NVS
  InitNvsFlash();

  // 尝试连接WiFi
  TaskWifiConnect();

  // 启动任务，输出芯片信息
  xTaskCreate(TaskPrintChipInfo, "TaskPrintChipInfo", 1024 * 4, NULL, tskIDLE_PRIORITY, NULL);

  // 初始化LVGL相关配置
  lvgl_init();

  // 创建GUI
  custom_init(&guider_ui);
  setup_ui(&guider_ui);
  events_init(&guider_ui);

  // 循环处理LVGL事件
  while (true) {
    vTaskDelay(pdMS_TO_TICKS(10));
    lv_task_handler();
  }
}

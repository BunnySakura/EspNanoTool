//
// Created by hello3rd on 24-1-11.
//

/**
 * \example https://github.com/wreyford/demo_esp_littlefs
 */

#include "esp_littlefs.h"

#include "littlefs_init.h"

#include "esp_log.h"

struct DrvLittleFs {
  esp_vfs_littlefs_conf_t *lfs_conf_;
};

void DrvLittleFsMount(DrvLittleFs *this, const char *root, const char *partition) {
  this->lfs_conf_->base_path = root;
  this->lfs_conf_->partition_label = partition;
  this->lfs_conf_->format_if_mount_failed = true;
  this->lfs_conf_->dont_mount = false;

  // Use settings defined above to initialize and mount LittleFS filesystem.
  // Note: esp_vfs_littlefs_register is an all-in-one convenience function.
  esp_err_t ret = esp_vfs_littlefs_register(this->lfs_conf_);

  if (ret != ESP_OK) {
    if (ret == ESP_FAIL) {
      ESP_LOGE(__func__, "Failed to mount or format filesystem");
    } else if (ret == ESP_ERR_NOT_FOUND) {
      ESP_LOGE(__func__, "Failed to find LittleFS partition");
    } else {
      ESP_LOGE(__func__, "Failed to initialize LittleFS (%s)", esp_err_to_name(ret));
    }
    return;
  }

  size_t total = 0, used = 0;
  ret = esp_littlefs_info(this->lfs_conf_->partition_label, &total, &used);
  if (ret != ESP_OK) {
    ESP_LOGE(__func__, "Failed to get LittleFS partition information (%s)", esp_err_to_name(ret));
  } else {
    ESP_LOGI(__func__, "Partition size: total: %d, used: %d", total, used);
  }
}

void DrvLittleFsUnmount(DrvLittleFs *this) {
  // All done, unmount partition and disable LittleFS
  esp_vfs_littlefs_unregister(this->lfs_conf_->partition_label);
  ESP_LOGI(__func__, "LittleFS unmounted");
}

DrvLittleFs *DrvLittleFsInit() {
  DrvLittleFs *this = malloc(sizeof(DrvLittleFs));
  this->lfs_conf_ = malloc(sizeof(esp_vfs_littlefs_conf_t));
  return this;
}

void DrvLittleFsDel(DrvLittleFs *this) {
  if (this->lfs_conf_) {
    free(this->lfs_conf_);
  }

  if (this) {
    free(this);
    this = NULL;
  }
}

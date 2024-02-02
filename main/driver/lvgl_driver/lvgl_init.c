#include "esp_freertos_hooks.h"
#include "esp_timer.h"
#include "lvgl_helpers.h"

#include "lv_port_indev.h"
#include "lvgl_init.h"

extern lv_indev_t *indev_keypad;

void lv_tick_task(void *arg) {
  (void) arg;
  lv_tick_inc(1);
}

void lv_disp_init() {
  lv_init();
  lvgl_driver_init();
  lv_color_t * buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
  assert(buf1 != NULL);
  /* Use double buffered when not working with monochrome displays */
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
  lv_color_t * buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
  assert(buf2 != NULL);
#else
  static lv_color_t *buf2 = NULL;
#endif
  /**
   * \note lv_disp_draw_buf_t 和 lv_disp_drv_t 必须确保运行期间生命周期持续存在，否则程序会重启
   */
  static lv_disp_draw_buf_t disp_buf;
  uint32_t size_in_px = DISP_BUF_SIZE;
  lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = LV_HOR_RES_MAX;
  disp_drv.ver_res = LV_VER_RES_MAX;
  disp_drv.flush_cb = disp_driver_flush;
  disp_drv.draw_buf = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  const esp_timer_create_args_t periodic_timer_args = {
      .callback = &lv_tick_task,
      .name = "screen"
  };
  esp_timer_handle_t periodic_timer;
  ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 1000));
}

void lvgl_init() {
  lv_disp_init();
  lv_port_indev_init();

  // 初始化默认输入设备组
  lv_group_t *group = lv_group_create();
  lv_group_set_default(group);
  lv_indev_set_group(indev_keypad, group);
}

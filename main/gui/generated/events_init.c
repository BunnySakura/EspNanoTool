/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl_driver/lv_port_indev.h"
#include "events_init.h"
#include "wifi_dpp.h"

#include <stdio.h>
#include "lvgl.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern lv_indev_t *indev_keypad;

void events_init(lv_ui *ui) {
}

void group_init_main_page(lv_ui *ui) {
  /* 初始化输入设备组 */
  if (ui->main_page_group == NULL) {
    ui->main_page_group = lv_group_create();
    lv_indev_set_group(indev_keypad, ui->main_page_group);
    lv_group_add_obj(ui->main_page_group, ui->main_page_app_1);
    lv_group_add_obj(ui->main_page_group, ui->main_page_app_2);
    lv_group_add_obj(ui->main_page_group, ui->main_page_app_3);
    lv_group_focus_obj(ui->main_page_app_1); // 分组聚焦到对象
  }

  lv_group_set_default(ui->main_page_group);
}

void group_init_about_page(lv_ui *ui) {
  /* 初始化输入设备组 */
  if (ui->about_page_group == NULL) {
    ui->about_page_group = lv_group_create();
    lv_indev_set_group(indev_keypad, ui->about_page_group);
    lv_group_add_obj(ui->about_page_group, ui->about_page_back_setting_btn);
    lv_group_focus_obj(ui->about_page_back_setting_btn); // 分组聚焦到对象
  }

  lv_group_set_default(ui->about_page_group);
}

void group_init_setting_page(lv_ui *ui) {
  /* 初始化输入设备组 */
  if (ui->setting_page_group == NULL) {
    ui->setting_page_group = lv_group_create();
    lv_indev_set_group(indev_keypad, ui->setting_page_group);
    lv_group_add_obj(ui->setting_page_group, ui->setting_page_setting_menu_item0);
    lv_group_add_obj(ui->setting_page_group, ui->setting_page_setting_menu_item1);
    lv_group_add_obj(ui->setting_page_group, ui->setting_page_setting_menu_item2);
    lv_group_add_obj(ui->setting_page_group, ui->setting_page_setting_menu_item3);
    lv_group_focus_obj(ui->setting_page_setting_menu_item1); // 分组聚焦到对象
  }

  lv_group_set_default(ui->setting_page_group);
}

void group_init_uart_chart_page(lv_ui *ui) {
  /* 初始化输入设备组 */
  if (ui->uart_chart_page_group == NULL) {
    ui->uart_chart_page_group = lv_group_create();
    lv_indev_set_group(indev_keypad, ui->uart_chart_page_group);
    lv_group_add_obj(ui->uart_chart_page_group, ui->uart_chart_page_back_main_btn);
    lv_group_focus_obj(ui->uart_chart_page_back_main_btn); // 分组聚焦到对象
  }

  lv_group_set_default(ui->uart_chart_page_group);
}

static void default_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  uint32_t key = lv_event_get_key(e);
  lv_group_t *group = lv_group_get_default();

  switch (key) {
    case LV_KEY_UP:
    case LV_KEY_LEFT: {
      ESP_LOGI(__func__, "<= app ->");
      lv_group_focus_prev(group);
    }
      break;

    case LV_KEY_DOWN:
    case LV_KEY_RIGHT: {
      ESP_LOGI(__func__, "<- app =>");
      lv_group_focus_next(group);
    }
      break;

    default: {
      ESP_LOGD(__func__, "Undefined key: %lu!", key);
      ESP_LOGD(__func__, "Undefined code: %d", code);
      break;
    }
  }
}

static void main_page_default_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  uint32_t key = lv_event_get_key(e);
  lv_group_t *group = lv_group_get_default();

  switch (key) {
    case LV_KEY_UP:
    case LV_KEY_LEFT: {
      ESP_LOGI(__func__, "<= app ->");
      lv_group_focus_prev(group);
    }
      break;

    case LV_KEY_DOWN:
    case LV_KEY_RIGHT: {
      ESP_LOGI(__func__, "<- app =>");
      lv_group_focus_next(group);
    }
      break;

    default: {
      ESP_LOGD(__func__, "Undefined key: %lu!", key);
      ESP_LOGD(__func__, "Undefined code: %d", code);
      break;
    }
  }

  lv_obj_scroll_to_view(lv_group_get_focused(group), LV_ANIM_ON);
}

static void main_page_main_page_app_list_event_handler(lv_event_t *e) {
  main_page_default_event_handler(e);

  lv_event_code_t code = lv_event_get_code(e);
  uint32_t key = lv_event_get_key(e);

  if (key == LV_KEY_ENTER || code == LV_EVENT_CLICKED) {
    ESP_LOGI(__func__, "Clicked");
    lv_event_send(lv_event_get_user_data(e), code, e);
  }
}

static void main_page_digital_clock_app_event_handler(lv_event_t *e)//按键回调函数
{
  main_page_default_event_handler(e);
}

static void main_page_setting_app_event_handler(lv_event_t *e) {
  main_page_default_event_handler(e);

  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      lv_obj_t *act_scr = lv_scr_act();
      lv_disp_t *d = lv_obj_get_disp(act_scr);
      if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.setting_page_del == true)
          setup_scr_setting_page(&guider_ui);
        lv_scr_load_anim(guider_ui.setting_page, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, false);
        guider_ui.main_page_del = false;
      }
      break;
    }
    default: break;
  }
}

static void main_page_uart_chart_app_event_handler(lv_event_t *e) {
  main_page_default_event_handler(e);

  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      lv_obj_t *act_scr = lv_scr_act();
      lv_disp_t *d = lv_obj_get_disp(act_scr);
      if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.uart_chart_page_del == true)
          setup_scr_uart_chart_page(&guider_ui);
        lv_scr_load_anim(guider_ui.uart_chart_page, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, false);
        guider_ui.main_page_del = false;
      }
      break;
    }
    default: break;
  }
}

void events_init_main_page(lv_ui *ui) {
  group_init_main_page(ui);

  lv_obj_add_event_cb(
      ui->main_page_app_1,
      main_page_main_page_app_list_event_handler,
      LV_EVENT_ALL,
      ui->main_page_digital_clock_app
  );
  lv_obj_add_event_cb(
      ui->main_page_app_2,
      main_page_main_page_app_list_event_handler,
      LV_EVENT_ALL,
      ui->main_page_setting_app
  );
  lv_obj_add_event_cb(
      ui->main_page_app_3,
      main_page_main_page_app_list_event_handler,
      LV_EVENT_ALL,
      ui->main_page_uart_chart_app
  );

  lv_obj_add_event_cb(ui->main_page_digital_clock_app, main_page_digital_clock_app_event_handler, LV_EVENT_ALL, ui);
  lv_obj_add_event_cb(ui->main_page_setting_app, main_page_setting_app_event_handler, LV_EVENT_ALL, ui);
  lv_obj_add_event_cb(ui->main_page_uart_chart_app, main_page_uart_chart_app_event_handler, LV_EVENT_ALL, ui);
}

static void setting_page_setting_menu_item0_event_handler(lv_event_t *e) {
  default_event_handler(e);

  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      lv_obj_t *act_scr = lv_scr_act();
      lv_disp_t *d = lv_obj_get_disp(act_scr);
      if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.main_page_del == true)
          setup_scr_main_page(&guider_ui);
        lv_scr_load_anim(guider_ui.main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
        guider_ui.setting_page_del = true;
      }
      break;
    }
    default: break;
  }
}

static void setting_page_setting_menu_item3_event_handler(lv_event_t *e) {
  default_event_handler(e);

  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      lv_obj_t *act_scr = lv_scr_act();
      lv_disp_t *d = lv_obj_get_disp(act_scr);
      if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.about_page_del == true)
          setup_scr_about_page(&guider_ui);
        lv_scr_load_anim(guider_ui.about_page, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, false);
        guider_ui.setting_page_del = false;
      }
      break;
    }
    default: break;
  }
}

static void setting_page_setting_menu_item1_event_handler(lv_event_t *e) {
  default_event_handler(e);

  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      xTaskCreate(DppEnrolleeMain, "DppEnrolleeMain", 1024 * 4, NULL, tskIDLE_PRIORITY, NULL);
      break;
    }
    default: break;
  }
}

void events_init_setting_page(lv_ui *ui) {
  group_init_setting_page(ui);

  lv_obj_add_event_cb(ui->setting_page_setting_menu_item0,
                      setting_page_setting_menu_item0_event_handler,
                      LV_EVENT_ALL,
                      ui);
  lv_obj_add_event_cb(ui->setting_page_setting_menu_item3,
                      setting_page_setting_menu_item3_event_handler,
                      LV_EVENT_ALL,
                      ui);
  lv_obj_add_event_cb(ui->setting_page_setting_menu_item1,
                      setting_page_setting_menu_item1_event_handler,
                      LV_EVENT_ALL,
                      ui);
}

static void about_page_back_setting_btn_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      lv_obj_t *act_scr = lv_scr_act();
      lv_disp_t *d = lv_obj_get_disp(act_scr);
      if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.setting_page_del == true)
          setup_scr_setting_page(&guider_ui);
        lv_scr_load_anim(guider_ui.setting_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
        guider_ui.about_page_del = true;
      }
      break;
    }
    default: break;
  }
}

void events_init_about_page(lv_ui *ui) {
  group_init_about_page(ui);

  lv_obj_add_event_cb(ui->about_page_back_setting_btn, about_page_back_setting_btn_event_handler, LV_EVENT_ALL, ui);
}

static void uart_chart_page_back_main_btn_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      lv_obj_t *act_scr = lv_scr_act();
      lv_disp_t *d = lv_obj_get_disp(act_scr);
      if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
        if (guider_ui.main_page_del == true)
          setup_scr_main_page(&guider_ui);
        lv_scr_load_anim(guider_ui.main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
        guider_ui.uart_chart_page_del = true;
      }
      break;
    }
    default: break;
  }
}

void events_init_uart_chart_page(lv_ui *ui) {
  group_init_uart_chart_page(ui);

  lv_obj_add_event_cb(ui->uart_chart_page_back_main_btn, uart_chart_page_back_main_btn_event_handler, LV_EVENT_ALL, ui);
}

/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "esp_log.h"
void DppEnrolleeMain() {}

void events_init(lv_ui *ui) {
}

static void app_list_event_handler(lv_event_t *e)//按键回调函数
{
  static int8_t current_app_idx = 0;
  lv_obj_t *current_app = NULL;

  lv_event_code_t code = lv_event_get_code(e);
  uint32_t key = lv_event_get_key(e);

  switch (key) {
    case LV_KEY_UP:
    case LV_KEY_LEFT: {
      current_app_idx = current_app_idx <= 0 ? 2 : current_app_idx - 1;
      ESP_LOGD(__func__, "Current app index: %d", current_app_idx);
      lv_group_focus_prev(lv_group_get_default());
      break;
    }
    case LV_KEY_DOWN :
    case LV_KEY_RIGHT: {
      current_app_idx = current_app_idx >= 2 ? 0 : current_app_idx + 1;
      ESP_LOGD(__func__, "Current app index: %d", current_app_idx);
      lv_group_focus_next(lv_group_get_default());
      break;
    }
    case LV_KEY_ENTER: {
      if (code == LV_EVENT_CLICKED) {
        ESP_LOGI(__func__, "Clicked");
      } else if (code == LV_EVENT_VALUE_CHANGED) {
        ESP_LOGI(__func__, "Toggled");
      } else {
        ESP_LOGD(__func__, "Other");
      }
      break;
    }
    default: { break; }
  }

  switch (current_app_idx) {
    case 0: {
      current_app = guider_ui.main_page_digital_clock_app;
      break;
    }
    case 1: {
      current_app = guider_ui.main_page_uart_chart_app;
      break;
    }
    case 2: {
      current_app = guider_ui.setting_page_setting_menu;
      break;
    }
    default: {
      break;
    }
  }
  lv_group_focus_obj(current_app); // 分组聚焦到对象
  lv_obj_scroll_to_view_recursive(current_app, LV_ANIM_ON);
}

static void main_page_setting_app_event_handler(lv_event_t *e) {
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
    }
      break;
    default: break;
  }
}

static void main_page_uart_chart_app_event_handler(lv_event_t *e) {
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
    }
      break;
    default: break;
  }
}

void events_init_main_page(lv_ui *ui) {
  lv_group_add_obj(lv_group_get_default(), ui->app_1);
  lv_group_add_obj(lv_group_get_default(), ui->app_2);
  lv_group_add_obj(lv_group_get_default(), ui->app_3);
  lv_group_focus_obj(ui->app_1); // 分组聚焦到对象

  lv_obj_add_event_cb(ui->app_1, app_list_event_handler, LV_EVENT_ALL, ui);
  lv_obj_add_event_cb(ui->app_2, app_list_event_handler, LV_EVENT_ALL, ui);
  lv_obj_add_event_cb(ui->app_3, app_list_event_handler, LV_EVENT_ALL, ui);

  lv_obj_add_event_cb(ui->main_page_setting_app, main_page_setting_app_event_handler, LV_EVENT_ALL, ui);
  lv_obj_add_event_cb(ui->main_page_uart_chart_app, main_page_uart_chart_app_event_handler, LV_EVENT_ALL, ui);
}

static void setting_page_setting_menu_item0_event_handler(lv_event_t *e) {
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
    }
      break;
    default: break;
  }
}

static void setting_page_setting_menu_item3_event_handler(lv_event_t *e) {
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
    }
      break;
    default: break;
  }
}

static void setting_page_setting_menu_item1_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  switch (code) {
    case LV_EVENT_CLICKED: {
      DppEnrolleeMain();
    }
      break;
    default: break;
  }
}

void events_init_setting_page(lv_ui *ui) {
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
    }
      break;
    default: break;
  }
}

void events_init_about_page(lv_ui *ui) {
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
    }
      break;
    default: break;
  }
}

void events_init_uart_chart_page(lv_ui *ui) {
  lv_obj_add_event_cb(ui->uart_chart_page_back_main_btn, uart_chart_page_back_main_btn_event_handler, LV_EVENT_ALL, ui);
}

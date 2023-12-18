#include <sys/cdefs.h>
//
// Created by hello3rd on 23-12-18.
//

#ifndef ESPNANOTOOL_MAIN_GUI_MAIN_PAGE_H_
#define ESPNANOTOOL_MAIN_GUI_MAIN_PAGE_H_

#include "lvgl.h"
#include "lvgl_helpers.h"
#include "lv_port_indev.h"
#include "lvgl_init.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

extern lv_indev_t *indev_keypad;

static void btn_event_handler(lv_event_t *e)//按键回调函数
{
  lv_event_code_t code = lv_event_get_code(e);
  uint32_t key = lv_event_get_key(e);

  switch (key) {
    case LV_KEY_UP:
    case LV_KEY_LEFT: {
      lv_group_focus_prev(lv_group_get_default());
      break;
    }
    case LV_KEY_DOWN :
    case LV_KEY_RIGHT: {
      lv_group_focus_next(lv_group_get_default());
      break;
    }
    case LV_KEY_ENTER: {
      if (code == LV_EVENT_CLICKED) {
        ESP_LOGI(__func__, "Clicked");
      } else if (code == LV_EVENT_VALUE_CHANGED) {
        ESP_LOGI(__func__, "Toggled");
      }
      break;
    }
    default: { break; }
  }
}

static void tmp_event_handler(lv_event_t *e)//滑块回调函数
{
  lv_obj_t *obj = lv_event_get_target(e);
  uint32_t key = lv_event_get_key(e);
  static int i = 0;

  switch (key) {
    case LV_KEY_UP: {
      i = i < 1 ? 12 - 1 : i - 1;
      break;
    }
    case LV_KEY_DOWN : {
      i = i + 1 >= 12 ? 0 : i + 1;
      break;
    }
    case LV_KEY_LEFT: {
      lv_group_focus_prev(lv_group_get_default());
      break;
    }
    case LV_KEY_RIGHT: {
      lv_group_focus_next(lv_group_get_default());
      break;
    }
    case LV_KEY_ENTER: {
      ESP_LOGI(__func__, "Current item: %d", i + 1);
      break;
    }
    default: { break; }
  }

  lv_roller_set_selected(obj, i, LV_ANIM_ON);
}

void lv_example(void) {
  lv_obj_t *scr = lv_scr_act();
  lv_group_t *group = lv_group_create();
  lv_group_set_default(group);
  lv_indev_set_group(indev_keypad, group);
  // lv_group_set_editing(group, true); // 编辑模式

  lv_obj_t *label;
  lv_obj_t *btn1 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn1, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn1, LV_ALIGN_TOP_LEFT, 0, 0);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "Button");
  lv_obj_center(label);

  lv_obj_t *btn2 = lv_btn_create(lv_scr_act());
  lv_obj_add_event_cb(btn2, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn2, LV_ALIGN_BOTTOM_LEFT, 0, 0);
  lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(btn2, LV_SIZE_CONTENT);

  label = lv_label_create(btn2);
  lv_label_set_text(label, "Toggle");
  lv_obj_center(label);

  lv_obj_t *roller1 = lv_roller_create(scr);
  lv_roller_set_options(roller1,
                        "January\n"
                        "February\n"
                        "March\n"
                        "April\n"
                        "May\n"
                        "June\n"
                        "July\n"
                        "August\n"
                        "September\n"
                        "October\n"
                        "November\n"
                        "December",
                        LV_ROLLER_MODE_INFINITE);

  lv_roller_set_visible_row_count(roller1, 3);
  lv_obj_align(roller1, LV_ALIGN_RIGHT_MID, 0, 0);
  lv_obj_add_event_cb(roller1, tmp_event_handler, LV_EVENT_ALL, NULL);

  lv_group_add_obj(group, btn1);
  lv_group_add_obj(group, btn2);
  lv_group_add_obj(group, roller1);

  lv_group_focus_obj(btn1); // 分组聚焦到对象
}

void lv_example_win_1(void) {
  lv_group_t *group = lv_group_create();
  lv_group_set_default(group);
  lv_indev_set_group(indev_keypad, group);

  lv_obj_t *win = lv_win_create(lv_scr_act(), lv_pct(20));
  lv_obj_t *btn;
  btn = lv_win_add_btn(win, LV_SYMBOL_LEFT, lv_pct(10));
  lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_group_add_obj(group, btn);
  lv_group_focus_obj(btn); // 分组聚焦到对象

  lv_obj_t *win_label = lv_win_add_title(win, "A title of this window");
  lv_label_set_long_mode(win_label, LV_LABEL_LONG_SCROLL);

  static lv_style_t style_base;
  lv_style_init(&style_base);
  lv_style_set_bg_opa(&style_base, LV_OPA_TRANSP); // 设置背景透明度
  lv_style_set_text_color(&style_base, lv_color_black()); // 设置文本颜色
  lv_style_set_shadow_opa(&style_base, LV_OPA_TRANSP); // 设置阴影透明度
  // btn = lv_win_add_btn(win, LV_SYMBOL_WIFI, lv_pct(10));
  btn = lv_win_add_btn(win, LV_SYMBOL_REFRESH, lv_pct(10));
  lv_obj_add_style(btn, &style_base, 0);
  lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);

  btn = lv_win_add_btn(win, LV_SYMBOL_RIGHT, lv_pct(10));
  lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_group_add_obj(group, btn);

  btn = lv_win_add_btn(win, LV_SYMBOL_CLOSE, lv_pct(20));
  lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_group_add_obj(group, btn);

  lv_obj_t *cont = lv_win_get_content(win);  /*Content can be added here*/
  lv_obj_t *label = lv_label_create(cont);
  lv_label_set_text(label, "This is\n"
                           "a pretty\n"
                           "long text\n"
                           "to see how\n"
                           "the window\n"
                           "becomes\n"
                           "scrollable.\n"
                           "\n"
                           "\n"
                           "Some more\n"
                           "text to be\n"
                           "sure it\n"
                           "overflows. :)");
}

_Noreturn void LvglMainPage() {
  lv_obj_t *label = lv_label_create(lv_scr_act());
  if (NULL != label) {
    lv_label_set_text(label, "Hello world");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  }

  while (true) {
    vTaskDelete(NULL);
  }
}

#endif //ESPNANOTOOL_MAIN_GUI_MAIN_PAGE_H_

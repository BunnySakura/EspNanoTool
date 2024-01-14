#include <sys/cdefs.h>
//
// Created by hello3rd on 23-12-18.
//

#ifndef ESPNANOTOOL_MAIN_GUI_MAIN_PAGE_H_
#define ESPNANOTOOL_MAIN_GUI_MAIN_PAGE_H_

#include "lvgl.h"
#include "lvgl_helpers.h"
#include "lvgl_driver/lv_port_indev.h"
#include "lvgl_driver/lvgl_init.h"

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

_Noreturn void LvglMainPage() {
  // 输入设备组
  lv_group_t *group = lv_group_create();
  lv_group_set_default(group);
  lv_indev_set_group(indev_keypad, group);

  /*Create a menu object*/
  lv_obj_t *menu = lv_menu_create(lv_scr_act());
  lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
  lv_obj_center(menu);

  /*Modify the header*/
  lv_obj_t *back_btn = lv_menu_get_main_header_back_btn(menu);
  lv_obj_t *back_btn_label = lv_label_create(back_btn);
  lv_label_set_text(back_btn_label, "Back");

  lv_obj_t *cont;
  lv_obj_t *label;

  /*Create sub pages*/
  lv_obj_t *sub_1_page = lv_menu_page_create(menu, "Page 1");

  cont = lv_menu_cont_create(sub_1_page);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Hello, I am hiding here");

  lv_obj_t *sub_2_page = lv_menu_page_create(menu, "Page 2");

  cont = lv_menu_cont_create(sub_2_page);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Hello, I am hiding here");

  lv_obj_t *sub_3_page = lv_menu_page_create(menu, "Page 3");

  cont = lv_menu_cont_create(sub_3_page);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Hello, I am hiding here");

  /*Create a main page*/
  lv_obj_t *main_page = lv_menu_page_create(menu, NULL);

  cont = lv_menu_cont_create(main_page);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Item 1 (Click me!)");
  lv_menu_set_load_page_event(menu, cont, sub_1_page);
  lv_obj_add_event_cb(cont, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_group_add_obj(group, cont);
  lv_group_focus_obj(cont); // 分组聚焦到对象

  cont = lv_menu_cont_create(main_page);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Item 2 (Click me!)");
  lv_menu_set_load_page_event(menu, cont, sub_2_page);
  lv_obj_add_event_cb(cont, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_group_add_obj(group, cont);

  cont = lv_menu_cont_create(main_page);
  label = lv_label_create(cont);
  lv_label_set_text(label, "Item 3 (Click me!)");
  lv_menu_set_load_page_event(menu, cont, sub_3_page);
  lv_obj_add_event_cb(cont, btn_event_handler, LV_EVENT_ALL, NULL);
  lv_group_add_obj(group, cont);

  lv_menu_set_page(menu, main_page);

  static lv_style_t style_base;
  lv_style_init(&style_base);
  lv_style_set_bg_opa(&style_base, LV_OPA_TRANSP); // 设置背景透明度
  lv_style_set_text_color(&style_base, lv_palette_main(LV_PALETTE_LIGHT_GREEN)); // 设置文本颜色
  lv_style_set_shadow_opa(&style_base, LV_OPA_TRANSP); // 设置阴影透明度
  label = lv_label_create(lv_scr_act());
  lv_obj_align(label, LV_ALIGN_TOP_RIGHT, 0, 0);
  lv_label_set_text(label, LV_SYMBOL_WIFI);
  // lv_label_set_text(label, LV_SYMBOL_REFRESH);
  lv_obj_add_style(label, &style_base, 0);
  lv_obj_add_event_cb(label, btn_event_handler, LV_EVENT_ALL, NULL);

  while (true) {
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

#endif //ESPNANOTOOL_MAIN_GUI_MAIN_PAGE_H_

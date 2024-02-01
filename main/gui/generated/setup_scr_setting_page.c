/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_obj_t *g_kb_setting_page;
static void kb_setting_page_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *kb = lv_event_get_target(e);
  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
  }
}
__attribute__((unused)) static void ta_setting_page_event_cb(lv_event_t *e) {

  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);
  lv_obj_t *kb = lv_event_get_user_data(e);
  if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED) {
    lv_keyboard_set_textarea(kb, ta);
    lv_obj_move_foreground(kb);
    lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
  }
  if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED) {
    lv_keyboard_set_textarea(kb, NULL);
    lv_obj_move_background(kb);
    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
  }
}

void setup_scr_setting_page(lv_ui *ui) {

  //Write codes setting_page
  ui->setting_page = lv_obj_create(NULL);

  //Create keyboard on setting_page
  g_kb_setting_page = lv_keyboard_create(ui->setting_page);
  lv_obj_add_event_cb(g_kb_setting_page, kb_setting_page_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_add_flag(g_kb_setting_page, LV_OBJ_FLAG_HIDDEN);
  lv_obj_set_style_text_font(g_kb_setting_page, &lv_font_simsun_18, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_scrollbar_mode(ui->setting_page, LV_SCROLLBAR_MODE_OFF);

  //Set style for setting_page. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
  lv_obj_set_style_bg_color(ui->setting_page, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_color(ui->setting_page, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_dir(ui->setting_page, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui->setting_page, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  //Write codes setting_page_setting_menu
  ui->setting_page_setting_menu = lv_list_create(ui->setting_page);
  lv_obj_set_pos(ui->setting_page_setting_menu, 0, 0);
  lv_obj_set_size(ui->setting_page_setting_menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
  lv_obj_set_scrollbar_mode(ui->setting_page_setting_menu, LV_SCROLLBAR_MODE_OFF);

  //Set style for setting_page_setting_menu. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
  lv_obj_set_style_radius(ui->setting_page_setting_menu, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui->setting_page_setting_menu,
                            lv_color_make(0xff, 0xff, 0xff),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_color(ui->setting_page_setting_menu,
                                 lv_color_make(0xff, 0xff, 0xff),
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_dir(ui->setting_page_setting_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui->setting_page_setting_menu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_width(ui->setting_page_setting_menu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_color(ui->setting_page_setting_menu,
                                lv_color_make(0x21, 0x95, 0xf6),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_opa(ui->setting_page_setting_menu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_spread(ui->setting_page_setting_menu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_ofs_x(ui->setting_page_setting_menu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_ofs_y(ui->setting_page_setting_menu, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui->setting_page_setting_menu,
                                lv_color_make(0xe1, 0xe6, 0xee),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui->setting_page_setting_menu, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui->setting_page_setting_menu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui->setting_page_setting_menu, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui->setting_page_setting_menu, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui->setting_page_setting_menu, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui->setting_page_setting_menu, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

  //Set style for setting_page_setting_menu. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
  lv_obj_set_style_radius(ui->setting_page_setting_menu, 3, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui->setting_page_setting_menu,
                            lv_color_make(0xff, 0xff, 0xff),
                            LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui->setting_page_setting_menu, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

  //Set style state: LV_STATE_DEFAULT for style_setting_page_setting_menu_extra_btns_main_default
  static lv_style_t style_setting_page_setting_menu_extra_btns_main_default;
  ui_init_style(&style_setting_page_setting_menu_extra_btns_main_default);
  lv_style_set_radius(&style_setting_page_setting_menu_extra_btns_main_default, 3);
  lv_style_set_bg_color(&style_setting_page_setting_menu_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_setting_page_setting_menu_extra_btns_main_default, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_setting_page_setting_menu_extra_btns_main_default, LV_GRAD_DIR_NONE);
  lv_style_set_bg_opa(&style_setting_page_setting_menu_extra_btns_main_default, 255);
  lv_style_set_text_color(&style_setting_page_setting_menu_extra_btns_main_default, lv_color_make(0x0D, 0x30, 0x55));
  lv_style_set_text_font(&style_setting_page_setting_menu_extra_btns_main_default, &lv_font_montserratMedium_12);

  //Set style state: LV_STATE_DEFAULT for style_setting_page_setting_menu_extra_texts_main_default
  static lv_style_t style_setting_page_setting_menu_extra_texts_main_default;
  ui_init_style(&style_setting_page_setting_menu_extra_texts_main_default);
  lv_style_set_radius(&style_setting_page_setting_menu_extra_texts_main_default, 3);
  lv_style_set_bg_color(&style_setting_page_setting_menu_extra_texts_main_default, lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_color(&style_setting_page_setting_menu_extra_texts_main_default,
                             lv_color_make(0xff, 0xff, 0xff));
  lv_style_set_bg_grad_dir(&style_setting_page_setting_menu_extra_texts_main_default, LV_GRAD_DIR_NONE);
  lv_style_set_bg_opa(&style_setting_page_setting_menu_extra_texts_main_default, 255);
  lv_style_set_text_color(&style_setting_page_setting_menu_extra_texts_main_default, lv_color_make(0x0D, 0x30, 0x55));
  lv_style_set_text_font(&style_setting_page_setting_menu_extra_texts_main_default, &lv_font_montserratMedium_12);

  lv_obj_t *setting_page_setting_menu_item;
  setting_page_setting_menu_item = lv_list_add_btn(ui->setting_page_setting_menu, LV_SYMBOL_CLOSE, "Back");
  ui->setting_page_setting_menu_item0 = setting_page_setting_menu_item;
  lv_obj_add_style(setting_page_setting_menu_item,
                   &style_setting_page_setting_menu_extra_btns_main_default,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  setting_page_setting_menu_item = lv_list_add_btn(ui->setting_page_setting_menu, LV_SYMBOL_WIFI, "Wi-Fi");
  ui->setting_page_setting_menu_item1 = setting_page_setting_menu_item;
  lv_obj_add_style(setting_page_setting_menu_item,
                   &style_setting_page_setting_menu_extra_btns_main_default,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  setting_page_setting_menu_item = lv_list_add_btn(ui->setting_page_setting_menu, LV_SYMBOL_BLUETOOTH, "Bluetooth");
  ui->setting_page_setting_menu_item2 = setting_page_setting_menu_item;
  lv_obj_add_style(setting_page_setting_menu_item,
                   &style_setting_page_setting_menu_extra_btns_main_default,
                   LV_PART_MAIN | LV_STATE_DEFAULT);

  setting_page_setting_menu_item = lv_list_add_btn(ui->setting_page_setting_menu, LV_SYMBOL_FILE, "About");
  ui->setting_page_setting_menu_item3 = setting_page_setting_menu_item;
  lv_obj_add_style(setting_page_setting_menu_item,
                   &style_setting_page_setting_menu_extra_btns_main_default,
                   LV_PART_MAIN | LV_STATE_DEFAULT);


  //Init events for screen
  events_init_setting_page(ui);
}
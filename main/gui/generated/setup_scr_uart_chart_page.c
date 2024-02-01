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

static lv_obj_t *g_kb_uart_chart_page;
static void kb_uart_chart_page_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *kb = lv_event_get_target(e);
  if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
  }
}
__attribute__((unused)) static void ta_uart_chart_page_event_cb(lv_event_t *e) {

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

void setup_scr_uart_chart_page(lv_ui *ui) {

  //Write codes uart_chart_page
  ui->uart_chart_page = lv_obj_create(NULL);

  //Create keyboard on uart_chart_page
  g_kb_uart_chart_page = lv_keyboard_create(ui->uart_chart_page);
  lv_obj_add_event_cb(g_kb_uart_chart_page, kb_uart_chart_page_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_add_flag(g_kb_uart_chart_page, LV_OBJ_FLAG_HIDDEN);
  lv_obj_set_style_text_font(g_kb_uart_chart_page, &lv_font_simsun_18, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_scrollbar_mode(ui->uart_chart_page, LV_SCROLLBAR_MODE_OFF);

  //Set style for uart_chart_page. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
  lv_obj_set_style_bg_color(ui->uart_chart_page, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_color(ui->uart_chart_page, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_dir(ui->uart_chart_page, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui->uart_chart_page, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  //Write codes uart_chart_page_uart_chart
  ui->uart_chart_page_uart_chart = lv_chart_create(ui->uart_chart_page);
  lv_obj_set_pos(ui->uart_chart_page_uart_chart, 0, 0);
  lv_obj_set_size(ui->uart_chart_page_uart_chart, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
  lv_obj_set_scrollbar_mode(ui->uart_chart_page_uart_chart, LV_SCROLLBAR_MODE_OFF);

  //Set style for uart_chart_page_uart_chart. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
  lv_obj_set_style_radius(ui->uart_chart_page_uart_chart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui->uart_chart_page_uart_chart,
                            lv_color_make(0xff, 0xff, 0xff),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_color(ui->uart_chart_page_uart_chart,
                                 lv_color_make(0xff, 0xff, 0xff),
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_dir(ui->uart_chart_page_uart_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui->uart_chart_page_uart_chart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_width(ui->uart_chart_page_uart_chart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_color(ui->uart_chart_page_uart_chart,
                                lv_color_make(0x21, 0x95, 0xf6),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_opa(ui->uart_chart_page_uart_chart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_spread(ui->uart_chart_page_uart_chart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_ofs_x(ui->uart_chart_page_uart_chart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_ofs_y(ui->uart_chart_page_uart_chart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui->uart_chart_page_uart_chart,
                                lv_color_make(0xe8, 0xe8, 0xe8),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui->uart_chart_page_uart_chart, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui->uart_chart_page_uart_chart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_line_color(ui->uart_chart_page_uart_chart,
                              lv_color_make(0xe8, 0xe8, 0xe8),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_line_width(ui->uart_chart_page_uart_chart, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_line_opa(ui->uart_chart_page_uart_chart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_chart_set_type(ui->uart_chart_page_uart_chart, LV_CHART_TYPE_LINE);
  lv_chart_set_range(ui->uart_chart_page_uart_chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
  lv_chart_set_div_line_count(ui->uart_chart_page_uart_chart, 3, 5);
  lv_chart_set_point_count(ui->uart_chart_page_uart_chart, 5);
  lv_chart_series_t *uart_chart_page_uart_chart_0 =
      lv_chart_add_series(ui->uart_chart_page_uart_chart, lv_color_make(0x2F, 0xCA, 0xDA), LV_CHART_AXIS_PRIMARY_Y);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_0, 12);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_0, 34);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_0, 23);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_0, 10);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_0, 5);
  lv_chart_series_t *uart_chart_page_uart_chart_1 =
      lv_chart_add_series(ui->uart_chart_page_uart_chart, lv_color_make(0x2F, 0xDA, 0x64), LV_CHART_AXIS_PRIMARY_Y);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_1, 44);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_1, 62);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_1, 10);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_1, 24);
  lv_chart_set_next_value(ui->uart_chart_page_uart_chart, uart_chart_page_uart_chart_1, 37);

  //Write codes uart_chart_page_back_main_btn
  ui->uart_chart_page_back_main_btn = lv_btn_create(ui->uart_chart_page);
  lv_obj_set_pos(ui->uart_chart_page_back_main_btn, 10, 10);
  lv_obj_set_size(ui->uart_chart_page_back_main_btn, 20, 20);
  lv_obj_set_scrollbar_mode(ui->uart_chart_page_back_main_btn, LV_SCROLLBAR_MODE_OFF);

  //Set style for uart_chart_page_back_main_btn. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
  lv_obj_set_style_radius(ui->uart_chart_page_back_main_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui->uart_chart_page_back_main_btn,
                            lv_color_make(0x2F, 0xDA, 0x64),
                            LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_color(ui->uart_chart_page_back_main_btn,
                                 lv_color_make(0x2F, 0xCA, 0xDA),
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_grad_dir(ui->uart_chart_page_back_main_btn, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui->uart_chart_page_back_main_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_width(ui->uart_chart_page_back_main_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_color(ui->uart_chart_page_back_main_btn,
                                lv_color_make(0x21, 0x95, 0xf6),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_opa(ui->uart_chart_page_back_main_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_spread(ui->uart_chart_page_back_main_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_ofs_x(ui->uart_chart_page_back_main_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_ofs_y(ui->uart_chart_page_back_main_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui->uart_chart_page_back_main_btn,
                                lv_color_make(0x21, 0x95, 0xf6),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui->uart_chart_page_back_main_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui->uart_chart_page_back_main_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui->uart_chart_page_back_main_btn,
                              lv_color_make(0xff, 0xff, 0xff),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(ui->uart_chart_page_back_main_btn,
                             &lv_font_montserratMedium_16,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(ui->uart_chart_page_back_main_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  ui->uart_chart_page_back_main_btn_label = lv_label_create(ui->uart_chart_page_back_main_btn);
  lv_label_set_text(ui->uart_chart_page_back_main_btn_label, "×");
  lv_obj_set_size(ui->uart_chart_page_back_main_btn_label, 60, 20);
  lv_label_set_long_mode(ui->uart_chart_page_back_main_btn_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
  lv_obj_set_style_pad_all(ui->uart_chart_page_back_main_btn, 0, LV_STATE_DEFAULT);
  lv_obj_align(ui->uart_chart_page_back_main_btn_label, LV_ALIGN_CENTER, 0, 0);

  //Init events for screen
  events_init_uart_chart_page(ui);
}
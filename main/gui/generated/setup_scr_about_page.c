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


void setup_scr_about_page(lv_ui *ui){

	//Write codes about_page
	ui->about_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->about_page, LV_SCROLLBAR_MODE_OFF);

	//Set style for about_page. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->about_page, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->about_page, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->about_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->about_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_page_about_text
	ui->about_page_about_text = lv_spangroup_create(ui->about_page);
	lv_obj_set_pos(ui->about_page_about_text, 5, 25);
	lv_obj_set_size(ui->about_page_about_text, 150, 55);
	lv_obj_set_scrollbar_mode(ui->about_page_about_text, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->about_page_about_text, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->about_page_about_text, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->about_page_about_text, LV_SPAN_MODE_BREAK);

	//Set style for about_page_about_text. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->about_page_about_text, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->about_page_about_text, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->about_page_about_text, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->about_page_about_text, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->about_page_about_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->about_page_about_text, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->about_page_about_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->about_page_about_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *about_page_about_text_span;

	//create a new span
	about_page_about_text_span = lv_spangroup_new_span(ui->about_page_about_text);
	lv_span_set_text(about_page_about_text_span, "Hello, world!\n\nIt's a very low cost ESP32 tool, but very useful!");
	lv_style_set_text_color(&about_page_about_text_span->style, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&about_page_about_text_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&about_page_about_text_span->style, &lv_font_montserratMedium_12);
	lv_spangroup_refr_mode(ui->about_page_about_text);

	//Write codes about_page_back_setting_btn
	ui->about_page_back_setting_btn = lv_btn_create(ui->about_page);
	lv_obj_set_pos(ui->about_page_back_setting_btn, 5, 5);
	lv_obj_set_size(ui->about_page_back_setting_btn, 10, 10);
	lv_obj_set_scrollbar_mode(ui->about_page_back_setting_btn, LV_SCROLLBAR_MODE_OFF);

	//Set style for about_page_back_setting_btn. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->about_page_back_setting_btn, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->about_page_back_setting_btn, lv_color_make(0x2F, 0xDA, 0x64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->about_page_back_setting_btn, lv_color_make(0x2F, 0xCA, 0xDA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->about_page_back_setting_btn, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->about_page_back_setting_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->about_page_back_setting_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->about_page_back_setting_btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->about_page_back_setting_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->about_page_back_setting_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->about_page_back_setting_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->about_page_back_setting_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->about_page_back_setting_btn, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->about_page_back_setting_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->about_page_back_setting_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->about_page_back_setting_btn, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->about_page_back_setting_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->about_page_back_setting_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->about_page_back_setting_btn_label = lv_label_create(ui->about_page_back_setting_btn);
	lv_label_set_text(ui->about_page_back_setting_btn_label, "×");
	lv_obj_set_size(ui->about_page_back_setting_btn_label, 10, 10);
	lv_label_set_long_mode(ui->about_page_back_setting_btn_label, LV_LABEL_LONG_CLIP);
	lv_obj_set_style_pad_all(ui->about_page_back_setting_btn, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->about_page_back_setting_btn_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_about_page(ui);
}
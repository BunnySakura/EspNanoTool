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
#include "lv_dclock.h"
#include "lv_carousel.h"

static int main_page_digital_clock_app_hour_value = 12;
static int main_page_digital_clock_app_min_value = 34;
static int main_page_digital_clock_app_sec_value = 56;
void main_page_digital_clock_app_timer(lv_timer_t *timer)
{	clock_count_24(&main_page_digital_clock_app_hour_value, &main_page_digital_clock_app_min_value, &main_page_digital_clock_app_sec_value);
	if (lv_obj_is_valid(guider_ui.main_page_digital_clock_app))
	{
		lv_dclock_set_text_fmt(guider_ui.main_page_digital_clock_app, "%02d:%02d:%02d", main_page_digital_clock_app_hour_value, main_page_digital_clock_app_min_value, main_page_digital_clock_app_sec_value);
	}
}

void setup_scr_main_page(lv_ui *ui){

	//Write codes main_page
	ui->main_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->main_page, LV_SCROLLBAR_MODE_OFF);

	//Set style for main_page. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->main_page, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->main_page, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->main_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_app_list
	ui->main_page_app_list = lv_carousel_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_app_list, 0, 0);
	lv_obj_set_size(ui->main_page_app_list, 160, 80);
	lv_obj_set_scrollbar_mode(ui->main_page_app_list, LV_SCROLLBAR_MODE_OFF);
	lv_carousel_set_element_width(ui->main_page_app_list, 160);

	//Set style for main_page_app_list. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->main_page_app_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_page_app_list, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->main_page_app_list, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->main_page_app_list, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_app_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_app_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->main_page_app_list, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->main_page_app_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->main_page_app_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_app_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_app_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for main_page_app_list. Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->main_page_app_list, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_page_app_list, lv_color_make(0xcc, 0xcc, 0xcc), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_app_list, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//add new carousel element app_3
	ui->app_3 = lv_carousel_add_element(ui->main_page_app_list, 2);

	//Write codes main_page_setting_app
	ui->main_page_setting_app = lv_imgbtn_create(ui->app_3);
	lv_obj_set_pos(ui->main_page_setting_app, 50, 10);
	lv_obj_set_size(ui->main_page_setting_app, 60, 60);
	lv_obj_set_scrollbar_mode(ui->main_page_setting_app, LV_SCROLLBAR_MODE_OFF);

	//Set style for main_page_setting_app. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->main_page_setting_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->main_page_setting_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_setting_app, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_setting_app, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->main_page_setting_app, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_setting_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for main_page_setting_app. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->main_page_setting_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->main_page_setting_app, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_page_setting_app, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->main_page_setting_app, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->main_page_setting_app, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for main_page_setting_app. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->main_page_setting_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->main_page_setting_app, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_page_setting_app, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->main_page_setting_app, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->main_page_setting_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->main_page_setting_app, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->main_page_setting_app, LV_IMGBTN_STATE_RELEASED, NULL, &_setting_alpha_60x60, NULL);
	lv_imgbtn_set_src(ui->main_page_setting_app, LV_IMGBTN_STATE_PRESSED, NULL, &_setting_press_alpha_60x60, NULL);
	lv_obj_add_flag(ui->main_page_setting_app, LV_OBJ_FLAG_CHECKABLE);

	//add new carousel element app_2
	ui->app_2 = lv_carousel_add_element(ui->main_page_app_list, 1);

	//Write codes main_page_uart_chart_app
	ui->main_page_uart_chart_app = lv_imgbtn_create(ui->app_2);
	lv_obj_set_pos(ui->main_page_uart_chart_app, 50, 10);
	lv_obj_set_size(ui->main_page_uart_chart_app, 60, 60);
	lv_obj_set_scrollbar_mode(ui->main_page_uart_chart_app, LV_SCROLLBAR_MODE_OFF);

	//Set style for main_page_uart_chart_app. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_shadow_width(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->main_page_uart_chart_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->main_page_uart_chart_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_uart_chart_app, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_page_uart_chart_app, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor(ui->main_page_uart_chart_app, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->main_page_uart_chart_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for main_page_uart_chart_app. Part: LV_PART_MAIN, State: LV_STATE_PRESSED
	lv_obj_set_style_shadow_width(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_color(ui->main_page_uart_chart_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_opa(ui->main_page_uart_chart_app, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_spread(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_page_uart_chart_app, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor(ui->main_page_uart_chart_app, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_recolor_opa(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_img_opa(ui->main_page_uart_chart_app, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Set style for main_page_uart_chart_app. Part: LV_PART_MAIN, State: LV_STATE_CHECKED
	lv_obj_set_style_shadow_width(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_color(ui->main_page_uart_chart_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_opa(ui->main_page_uart_chart_app, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_spread(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_page_uart_chart_app, lv_color_make(0xFF, 0x33, 0xFF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor(ui->main_page_uart_chart_app, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_recolor_opa(ui->main_page_uart_chart_app, 0, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_img_opa(ui->main_page_uart_chart_app, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->main_page_uart_chart_app, LV_IMGBTN_STATE_RELEASED, NULL, &_uart_alpha_60x60, NULL);
	lv_imgbtn_set_src(ui->main_page_uart_chart_app, LV_IMGBTN_STATE_PRESSED, NULL, &_uart_press_alpha_60x60, NULL);
	lv_obj_add_flag(ui->main_page_uart_chart_app, LV_OBJ_FLAG_CHECKABLE);

	//add new carousel element app_1
	ui->app_1 = lv_carousel_add_element(ui->main_page_app_list, 0);
	static bool main_page_digital_clock_app_timer_enabled = false;

	//Write codes main_page_digital_clock_app
	ui->main_page_digital_clock_app = lv_dclock_create(ui->app_1,"12:34:56");
	lv_obj_set_style_text_align(ui->main_page_digital_clock_app, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_pos(ui->main_page_digital_clock_app, 0, 0);
	lv_obj_set_size(ui->main_page_digital_clock_app, 160, 80);

	//create timer
	if (!main_page_digital_clock_app_timer_enabled) {
		lv_timer_create(main_page_digital_clock_app_timer, 1000, NULL);
		main_page_digital_clock_app_timer_enabled = true;
	}
	//Set style for main_page_digital_clock_app. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_page_digital_clock_app, lv_color_make(0x2F, 0xDA, 0x64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->main_page_digital_clock_app, lv_color_make(0x2F, 0xCA, 0xDA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->main_page_digital_clock_app, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_page_digital_clock_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->main_page_digital_clock_app, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->main_page_digital_clock_app, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_page_digital_clock_app, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_page_digital_clock_app, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_page_digital_clock_app, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_page_digital_clock_app, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_page_digital_clock_app, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_main_page(ui);
}
/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_page_main(lv_ui *ui)
{
	//Write codes page_main
	ui->page_main = lv_obj_create(NULL);
	lv_obj_set_size(ui->page_main, 320, 240);
	lv_obj_set_scrollbar_mode(ui->page_main, LV_SCROLLBAR_MODE_OFF);

	//Write style for page_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->page_main, lv_color_hex(0x05c0da), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->page_main, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->page_main, lv_color_hex(0x05daa3), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->page_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->page_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes page_main_footer
	ui->page_main_footer = lv_obj_create(ui->page_main);
	lv_obj_set_pos(ui->page_main_footer, 0, 200);
	lv_obj_set_size(ui->page_main_footer, 320, 40);
	lv_obj_set_scrollbar_mode(ui->page_main_footer, LV_SCROLLBAR_MODE_OFF);

	//Write style for page_main_footer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->page_main_footer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->page_main_footer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->page_main_footer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->page_main_footer, LV_BORDER_SIDE_TOP, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->page_main_footer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes page_main_header
	ui->page_main_header = lv_obj_create(ui->page_main);
	lv_obj_set_pos(ui->page_main_header, 0, 0);
	lv_obj_set_size(ui->page_main_header, 320, 40);
	lv_obj_set_scrollbar_mode(ui->page_main_header, LV_SCROLLBAR_MODE_OFF);

	//Write style for page_main_header, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->page_main_header, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->page_main_header, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->page_main_header, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->page_main_header, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->page_main_header, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes page_main_app_cont
	ui->page_main_app_cont = lv_carousel_create(ui->page_main);
	lv_carousel_set_element_width(ui->page_main_app_cont, 128);
	lv_obj_set_size(ui->page_main_app_cont, 320, 160);
	ui->page_main_app_cont_first = lv_carousel_add_element(ui->page_main_app_cont, 0);
	ui->page_main_app_cont_ele1 = lv_carousel_add_element(ui->page_main_app_cont, 1);
	ui->page_main_app_cont_ele2 = lv_carousel_add_element(ui->page_main_app_cont, 2);
	ui->page_main_app_cont_ele3 = lv_carousel_add_element(ui->page_main_app_cont, 3);
	ui->page_main_app_cont_last = lv_carousel_add_element(ui->page_main_app_cont, 4);
	lv_obj_set_pos(ui->page_main_app_cont, 0, 40);
	lv_obj_set_size(ui->page_main_app_cont, 320, 160);
	lv_obj_set_scrollbar_mode(ui->page_main_app_cont, LV_SCROLLBAR_MODE_AUTO);

	//Write style for page_main_app_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_main_app_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_app_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->page_main_app_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for page_main_app_cont, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_main_app_cont, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_app_cont, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_page_main_app_cont_extra_element_items_default
	static lv_style_t style_page_main_app_cont_extra_element_items_default;
	ui_init_style(&style_page_main_app_cont_extra_element_items_default);
	
	lv_style_set_bg_opa(&style_page_main_app_cont_extra_element_items_default, 0);
	lv_style_set_outline_width(&style_page_main_app_cont_extra_element_items_default, 0);
	lv_style_set_border_width(&style_page_main_app_cont_extra_element_items_default, 0);
	lv_style_set_radius(&style_page_main_app_cont_extra_element_items_default, 5);
	lv_style_set_shadow_width(&style_page_main_app_cont_extra_element_items_default, 0);
	lv_obj_add_style(ui->page_main_app_cont_last, &style_page_main_app_cont_extra_element_items_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->page_main_app_cont_ele3, &style_page_main_app_cont_extra_element_items_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->page_main_app_cont_ele2, &style_page_main_app_cont_extra_element_items_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->page_main_app_cont_ele1, &style_page_main_app_cont_extra_element_items_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->page_main_app_cont_first, &style_page_main_app_cont_extra_element_items_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for &style_page_main_app_cont_extra_element_items_focused
	static lv_style_t style_page_main_app_cont_extra_element_items_focused;
	ui_init_style(&style_page_main_app_cont_extra_element_items_focused);
	
	lv_style_set_bg_opa(&style_page_main_app_cont_extra_element_items_focused, 0);
	lv_style_set_outline_width(&style_page_main_app_cont_extra_element_items_focused, 0);
	lv_style_set_border_width(&style_page_main_app_cont_extra_element_items_focused, 0);
	lv_style_set_radius(&style_page_main_app_cont_extra_element_items_focused, 5);
	lv_style_set_shadow_width(&style_page_main_app_cont_extra_element_items_focused, 0);
	lv_obj_add_style(ui->page_main_app_cont_last, &style_page_main_app_cont_extra_element_items_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->page_main_app_cont_ele3, &style_page_main_app_cont_extra_element_items_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->page_main_app_cont_ele2, &style_page_main_app_cont_extra_element_items_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->page_main_app_cont_ele1, &style_page_main_app_cont_extra_element_items_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_add_style(ui->page_main_app_cont_first, &style_page_main_app_cont_extra_element_items_focused, LV_PART_MAIN|LV_STATE_FOCUSED);





	//Write codes page_main_btn_1
	ui->page_main_btn_1 = lv_btn_create(ui->page_main_app_cont_ele1);
	ui->page_main_btn_1_label = lv_label_create(ui->page_main_btn_1);
	lv_label_set_text(ui->page_main_btn_1_label, "设置");
	lv_label_set_long_mode(ui->page_main_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->page_main_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->page_main_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->page_main_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->page_main_btn_1, 4, 20);
	lv_obj_set_size(ui->page_main_btn_1, 120, 120);

	//Write style for page_main_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_main_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->page_main_btn_1, lv_color_hex(0x004b4c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->page_main_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->page_main_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->page_main_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->page_main_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->page_main_btn_1, &lv_font_LXGWWenKaiRegular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->page_main_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->page_main_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes page_main_btn_2
	ui->page_main_btn_2 = lv_btn_create(ui->page_main_app_cont_ele2);
	ui->page_main_btn_2_label = lv_label_create(ui->page_main_btn_2);
	lv_label_set_text(ui->page_main_btn_2_label, "UART桥");
	lv_label_set_long_mode(ui->page_main_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->page_main_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->page_main_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->page_main_btn_2_label, LV_PCT(100));
	lv_obj_set_pos(ui->page_main_btn_2, 4, 20);
	lv_obj_set_size(ui->page_main_btn_2, 120, 120);

	//Write style for page_main_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_main_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->page_main_btn_2, lv_color_hex(0x004b4c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->page_main_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->page_main_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->page_main_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->page_main_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->page_main_btn_2, &lv_font_LXGWWenKaiRegular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->page_main_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->page_main_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes page_main_btn_3
	ui->page_main_btn_3 = lv_btn_create(ui->page_main_app_cont_ele3);
	ui->page_main_btn_3_label = lv_label_create(ui->page_main_btn_3);
	lv_label_set_text(ui->page_main_btn_3_label, "测试");
	lv_label_set_long_mode(ui->page_main_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->page_main_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->page_main_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->page_main_btn_3_label, LV_PCT(100));
	lv_obj_set_pos(ui->page_main_btn_3, 4, 20);
	lv_obj_set_size(ui->page_main_btn_3, 120, 120);

	//Write style for page_main_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_main_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->page_main_btn_3, lv_color_hex(0x004b4c), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->page_main_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->page_main_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->page_main_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->page_main_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->page_main_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->page_main_btn_3, &lv_font_LXGWWenKaiRegular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->page_main_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->page_main_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);



	//The custom code of page_main.
	#ifndef LV_USE_GUIDER_SIMULATOR
    lv_group_remove_all_objs(lv_group_get_default());
    lv_group_add_obj(lv_group_get_default(), ui->page_main_btn_1);
    lv_group_add_obj(lv_group_get_default(), ui->page_main_btn_2);
    lv_group_add_obj(lv_group_get_default(), ui->page_main_btn_3);
#endif

	//Update current screen layout.
	lv_obj_update_layout(ui->page_main);

	//Init events for screen.
	events_init_page_main(ui);
}

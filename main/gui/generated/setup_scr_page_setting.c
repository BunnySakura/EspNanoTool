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



void setup_scr_page_setting(lv_ui *ui)
{
	//Write codes page_setting
	ui->page_setting = lv_obj_create(NULL);
	lv_obj_set_size(ui->page_setting, 320, 240);
	lv_obj_set_scrollbar_mode(ui->page_setting, LV_SCROLLBAR_MODE_OFF);

	//Write style for page_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->page_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes page_setting_list_1
	ui->page_setting_list_1 = lv_list_create(ui->page_setting);
	ui->page_setting_list_1_item0 = lv_list_add_btn(ui->page_setting_list_1, LV_SYMBOL_HOME, "Home");
	ui->page_setting_list_1_item1 = lv_list_add_btn(ui->page_setting_list_1, LV_SYMBOL_SAVE, "Save");
	ui->page_setting_list_1_item2 = lv_list_add_btn(ui->page_setting_list_1, LV_SYMBOL_WIFI, "WiFi connect");
	lv_obj_set_pos(ui->page_setting_list_1, 0, 0);
	lv_obj_set_size(ui->page_setting_list_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->page_setting_list_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for &style_page_setting_list_1_main_main_default
	static lv_style_t style_page_setting_list_1_main_main_default;
	ui_init_style(&style_page_setting_list_1_main_main_default);
	
	lv_style_set_pad_top(&style_page_setting_list_1_main_main_default, 5);
	lv_style_set_pad_left(&style_page_setting_list_1_main_main_default, 5);
	lv_style_set_pad_right(&style_page_setting_list_1_main_main_default, 5);
	lv_style_set_pad_bottom(&style_page_setting_list_1_main_main_default, 5);
	lv_style_set_bg_opa(&style_page_setting_list_1_main_main_default, 255);
	lv_style_set_bg_color(&style_page_setting_list_1_main_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_page_setting_list_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_page_setting_list_1_main_main_default, 1);
	lv_style_set_border_opa(&style_page_setting_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_page_setting_list_1_main_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_page_setting_list_1_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_page_setting_list_1_main_main_default, 3);
	lv_style_set_shadow_width(&style_page_setting_list_1_main_main_default, 0);
	lv_obj_add_style(ui->page_setting_list_1, &style_page_setting_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_page_setting_list_1_main_scrollbar_default
	static lv_style_t style_page_setting_list_1_main_scrollbar_default;
	ui_init_style(&style_page_setting_list_1_main_scrollbar_default);
	
	lv_style_set_radius(&style_page_setting_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_page_setting_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_page_setting_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_page_setting_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->page_setting_list_1, &style_page_setting_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_page_setting_list_1_extra_btns_main_default
	static lv_style_t style_page_setting_list_1_extra_btns_main_default;
	ui_init_style(&style_page_setting_list_1_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_page_setting_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_page_setting_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_page_setting_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_bottom(&style_page_setting_list_1_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_page_setting_list_1_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_page_setting_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_page_setting_list_1_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_page_setting_list_1_extra_btns_main_default, 255);
	lv_style_set_radius(&style_page_setting_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_page_setting_list_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_page_setting_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_page_setting_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->page_setting_list_1_item2, &style_page_setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->page_setting_list_1_item1, &style_page_setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->page_setting_list_1_item0, &style_page_setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_page_setting_list_1_extra_texts_main_default
	static lv_style_t style_page_setting_list_1_extra_texts_main_default;
	ui_init_style(&style_page_setting_list_1_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_page_setting_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_page_setting_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_page_setting_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_page_setting_list_1_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_page_setting_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_page_setting_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_page_setting_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_page_setting_list_1_extra_texts_main_default, 255);
	lv_style_set_radius(&style_page_setting_list_1_extra_texts_main_default, 3);
	lv_style_set_transform_width(&style_page_setting_list_1_extra_texts_main_default, 0);
	lv_style_set_bg_opa(&style_page_setting_list_1_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_page_setting_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_page_setting_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

	//Write codes page_setting_qrcode_1
	ui->page_setting_qrcode_1 = lv_qrcode_create(ui->page_setting, 160, lv_color_hex(0x2C3224), lv_color_hex(0xffffff));
	const char * page_setting_qrcode_1_data = "";
	lv_qrcode_update(ui->page_setting_qrcode_1, page_setting_qrcode_1_data, strlen(page_setting_qrcode_1_data));
	lv_obj_set_pos(ui->page_setting_qrcode_1, 80, 40);
	lv_obj_set_size(ui->page_setting_qrcode_1, 160, 160);
	lv_obj_add_flag(ui->page_setting_qrcode_1, LV_OBJ_FLAG_HIDDEN);

	//The custom code of page_setting.
	#ifndef LV_USE_GUIDER_SIMULATOR
    lv_group_remove_all_objs(lv_group_get_default());
    lv_group_add_obj(lv_group_get_default(), ui->page_setting_list_1_item0);
    lv_group_add_obj(lv_group_get_default(), ui->page_setting_list_1_item1);
    lv_group_add_obj(lv_group_get_default(), ui->page_setting_list_1_item2);
#endif

	//Update current screen layout.
	lv_obj_update_layout(ui->page_setting);

	//Init events for screen.
	events_init_page_setting(ui);
}

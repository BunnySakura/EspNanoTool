/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *main_page;
	bool main_page_del;
	lv_obj_t *main_page_app_list;
	lv_obj_t *app_3;
	lv_obj_t *main_page_setting_app;
	lv_obj_t *main_page_setting_app_label;
	lv_obj_t *app_2;
	lv_obj_t *main_page_uart_chart_app;
	lv_obj_t *main_page_uart_chart_app_label;
	lv_obj_t *app_1;
	lv_obj_t *main_page_digital_clock_app;
	lv_obj_t *setting_page;
	bool setting_page_del;
	lv_obj_t *setting_page_setting_menu;
	lv_obj_t *setting_page_setting_menu_item0;
	lv_obj_t *setting_page_setting_menu_item1;
	lv_obj_t *setting_page_setting_menu_item2;
	lv_obj_t *setting_page_setting_menu_item3;
	lv_obj_t *about_page;
	bool about_page_del;
	lv_obj_t *about_page_about_text;
	lv_obj_t *about_page_back_setting_btn;
	lv_obj_t *about_page_back_setting_btn_label;
	lv_obj_t *uart_chart_page;
	bool uart_chart_page_del;
	lv_obj_t *uart_chart_page_uart_chart;
	lv_obj_t *uart_chart_page_back_main_btn;
	lv_obj_t *uart_chart_page_back_main_btn_label;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_main_page(lv_ui *ui);
void setup_scr_setting_page(lv_ui *ui);
void setup_scr_about_page(lv_ui *ui);
void setup_scr_uart_chart_page(lv_ui *ui);
LV_IMG_DECLARE(_uart_press_alpha_60x60);
LV_IMG_DECLARE(_setting_alpha_60x60);
LV_IMG_DECLARE(_uart_alpha_60x60);
LV_IMG_DECLARE(_setting_press_alpha_60x60);

#ifdef __cplusplus
}
#endif
#endif
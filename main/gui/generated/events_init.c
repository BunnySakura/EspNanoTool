/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include "wifi_dpp.h"
#include <stdio.h>
#include "lvgl.h"

void events_init(lv_ui *ui)
{
}

static void main_page_setting_app_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.setting_page_del == true)
				setup_scr_setting_page(&guider_ui);
			lv_scr_load_anim(guider_ui.setting_page, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, false);
			guider_ui.main_page_del = false;
		}
	}
		break;
	default:
		break;
	}
}

static void main_page_uart_chart_app_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.uart_chart_page_del == true)
				setup_scr_uart_chart_page(&guider_ui);
			lv_scr_load_anim(guider_ui.uart_chart_page, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, false);
			guider_ui.main_page_del = false;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_main_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->main_page_setting_app, main_page_setting_app_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->main_page_uart_chart_app, main_page_uart_chart_app_event_handler, LV_EVENT_ALL, ui);
}

static void setting_page_setting_menu_item0_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.main_page_del == true)
				setup_scr_main_page(&guider_ui);
			lv_scr_load_anim(guider_ui.main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
			guider_ui.setting_page_del = true;
		}
	}
		break;
	default:
		break;
	}
}

static void setting_page_setting_menu_item3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.about_page_del == true)
				setup_scr_about_page(&guider_ui);
			lv_scr_load_anim(guider_ui.about_page, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 100, false);
			guider_ui.setting_page_del = false;
		}
	}
		break;
	default:
		break;
	}
}

static void setting_page_setting_menu_item1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		DppEnrolleeMain();
	}
		break;
	default:
		break;
	}
}

void events_init_setting_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->setting_page_setting_menu_item0, setting_page_setting_menu_item0_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->setting_page_setting_menu_item3, setting_page_setting_menu_item3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->setting_page_setting_menu_item1, setting_page_setting_menu_item1_event_handler, LV_EVENT_ALL, ui);
}

static void about_page_back_menu_btn_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.setting_page_del == true)
				setup_scr_setting_page(&guider_ui);
			lv_scr_load_anim(guider_ui.setting_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
			guider_ui.about_page_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_about_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->about_page_back_setting_btn, about_page_back_menu_btn_event_handler, LV_EVENT_ALL, ui);
}

static void uart_chart_page_back_main_btn_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			if (guider_ui.main_page_del == true)
				setup_scr_main_page(&guider_ui);
			lv_scr_load_anim(guider_ui.main_page, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 100, 100, true);
			guider_ui.uart_chart_page_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_uart_chart_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->uart_chart_page_back_main_btn, uart_chart_page_back_main_btn_event_handler, LV_EVENT_ALL, ui);
}

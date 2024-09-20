/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#ifndef LV_USE_GUIDER_SIMULATOR
#include "common.h"
#endif
#ifndef LV_USE_GUIDER_SIMULATOR
#include "wifi_dpp.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
extern char wifi_dpp_qr_data[256];
#endif

static void page_main_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.page_setting, guider_ui.page_setting_del, &guider_ui.page_main_del, setup_scr_page_setting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

void events_init_page_main (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->page_main_btn_1, page_main_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void page_setting_list_1_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.page_main, guider_ui.page_main_del, &guider_ui.page_setting_del, setup_scr_page_main, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
		break;
	}
    default:
        break;
    }
}

static void page_setting_list_1_item1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		#ifndef LV_USE_GUIDER_SIMULATOR
		    ESP_LOGI(__func__, "Now save the config.");
		#endif
		break;
	}
    default:
        break;
    }
}

static void page_setting_list_1_item2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
	case LV_EVENT_CLICKED:
	{
		#ifndef LV_USE_GUIDER_SIMULATOR
		    TaskDppEnrollee();
		    vTaskDelay(1000 / portTICK_PERIOD_MS);
			lv_qrcode_update(guider_ui.page_setting_qrcode_1, wifi_dpp_qr_data, strlen(wifi_dpp_qr_data));
		#endif
		lv_obj_clear_flag(guider_ui.page_setting_qrcode_1, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	case LV_EVENT_DEFOCUSED:
	{
		lv_obj_add_flag(guider_ui.page_setting_qrcode_1, LV_OBJ_FLAG_HIDDEN);
		break;
	}
    default:
        break;
    }
}

void events_init_page_setting (lv_ui *ui)
{
	lv_obj_add_event_cb(ui->page_setting_list_1_item0, page_setting_list_1_item0_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->page_setting_list_1_item1, page_setting_list_1_item1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->page_setting_list_1_item2, page_setting_list_1_item2_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}

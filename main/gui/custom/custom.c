// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui) {
  /* Add your codes here */

  /*
   * 主界面添加滚动
   */
  lv_obj_set_scroll_snap_x(ui->main_page_app_list, LV_SCROLL_SNAP_CENTER);
  lv_obj_set_flex_flow(ui->main_page_app_list, LV_FLEX_FLOW_ROW_REVERSE);
  lv_obj_update_snap(ui->main_page_app_list, LV_ANIM_ON);
}


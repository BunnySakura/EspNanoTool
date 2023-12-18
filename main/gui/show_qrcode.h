//
// Created by hello3rd on 23-12-15.
//

#ifndef ESPNANOTOOL_MAIN_GUI_SHOW_QRCODE_H_
#define ESPNANOTOOL_MAIN_GUI_SHOW_QRCODE_H_

#include "lvgl.h"

void ShowQrCode(const char *data) {
  lv_color_t bg_color = lv_color_white();
  lv_color_t fg_color = lv_color_black();

  lv_obj_t *qr = lv_qrcode_create(
      lv_scr_act(),
      LV_HOR_RES_MAX > LV_VER_RES_MAX ? LV_VER_RES_MAX : LV_HOR_RES_MAX,
      fg_color,
      bg_color
  );

  /*Set data*/
  // TODO 修改二维码纠错级别`qrcodegen_Ecc_MEDIUM`
  lv_qrcode_update(qr, data, strlen(data));
  lv_obj_center(qr);

  /*Add a border with bg_color*/
  lv_obj_set_style_border_color(qr, bg_color, 0);
  lv_obj_set_style_border_width(qr, LV_HOR_RES_MAX - LV_VER_RES_MAX, 0);
}

#endif //ESPNANOTOOL_MAIN_GUI_SHOW_QRCODE_H_

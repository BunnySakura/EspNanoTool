//
// Created by hello3rd on 23-12-15.
//

#ifndef ESPNANOTOOL_MAIN_GUI_SHOW_QRCODE_H_
#define ESPNANOTOOL_MAIN_GUI_SHOW_QRCODE_H_

#include "lvgl.h"

typedef struct LvQrCode {
  void (*Show)(struct LvQrCode *this, const char *data);
  void (*Close)(struct LvQrCode *this);
  lv_obj_t *qr_code_obj;
} LvQrCode;

LvQrCode *GuiQrCode();

#endif //ESPNANOTOOL_MAIN_GUI_SHOW_QRCODE_H_

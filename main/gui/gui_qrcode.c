//
// Created by hello3rd on 24-1-2.
//

#include "lvgl.h"

#include "gui_qrcode.h"
#include "lvgl_helpers.h"

#include "esp_log.h"

struct GuiQrCode {
  lv_obj_t *qr_code_;
};

void GuiQrCodeShow(GuiQrCode *this, const char *data) {
  if (!this) {
    ESP_LOGE(__func__, "The pointer this is null!");
    return;
  }

  lv_color_t bg_color = lv_color_white();
  lv_color_t fg_color = lv_color_black();

  if (!this->qr_code_) {
    this->qr_code_ = lv_qrcode_create(
        lv_scr_act(),
        LV_HOR_RES_MAX > LV_VER_RES_MAX ? LV_VER_RES_MAX : LV_HOR_RES_MAX,
        fg_color,
        bg_color
    );
  }

  /*Set data*/
  // TODO 二维码纠错级别从`qrcodegen_Ecc_MEDIUM`改为`qrcodegen_Ecc_LOW`，便于小屏幕显示
  lv_qrcode_update(this->qr_code_, data, strlen(data));
  lv_obj_center(this->qr_code_);

  /*Add a border with bg_color*/
  lv_obj_set_style_border_color(this->qr_code_, bg_color, 0);
  lv_obj_set_style_border_width(this->qr_code_, LV_HOR_RES_MAX - LV_VER_RES_MAX, 0);
}

void GuiQrCodeHide(GuiQrCode *this) {

}

void GuiQrCodeClose(GuiQrCode *this) {
  lv_obj_del(this->qr_code_);
}

GuiQrCode *GuiQrCodeInit() {
  GuiQrCode *this = malloc(sizeof(GuiQrCode));
  this->qr_code_ = NULL;
  return this;
}

void GuiQrCodeDel(GuiQrCode *this) {
  if (this->qr_code_) {
    lv_obj_del(this->qr_code_);
  }

  if (this) {
    free(this);
    this = NULL;
  }
}

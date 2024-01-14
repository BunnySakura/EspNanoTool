//
// Created by hello3rd on 23-12-15.
//

#ifndef ESPNANOTOOL_MAIN_GUI_GUI_QRCODE_H_
#define ESPNANOTOOL_MAIN_GUI_GUI_QRCODE_H_

typedef struct GuiQrCode GuiQrCode;

GuiQrCode *GuiQrCodeInit();

void GuiQrCodeDel(GuiQrCode *this);

void GuiQrCodeShow(GuiQrCode *this, const char *data);

void GuiQrCodeHide(GuiQrCode *this);

void GuiQrCodeClose(GuiQrCode *this);

#endif // ESPNANOTOOL_MAIN_GUI_GUI_QRCODE_H_

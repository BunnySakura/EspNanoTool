// 来源：https://git.yunsi.studio/kerms/wireless-proxy-esp32
// 作者：https://yunsi.studio/

#ifndef _UART_BRIDGE_H_
#define _UART_BRIDGE_H_

#define UART_BRIDGE_PORT 23
#define UART_BRIDGE_BAUDRATE 115200

void uart_bridge_init();
void uart_bridge_task();
void uart_bridge_close();

#endif

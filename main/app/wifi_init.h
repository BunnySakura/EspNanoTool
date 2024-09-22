#ifndef MAIN_APP_TCP_SERVER_H_
#define MAIN_APP_TCP_SERVER_H_

#include <stdbool.h>

/**
 * \brief WiFi功能初始化
 * \note 如果WiFi已经初始化，则跳过
 *
 */
void WifiInit();

/**
 * \brief WiFi功能注销
 * \note 如果WiFi未初始化，则跳过
 */
void WifiDeinit();

/**
 * \brief 查询WiFi是否已经初始化
 *
 * \return true 已经初始化
 * \return false 未初始化
 */
bool WifiIsInited();

#endif // MAIN_APP_TCP_SERVER_H_

#ifndef COMMON_H
#define COMMON_H

#include "esp_log.h" 

#define TO_STR_(x) #x
#define TO_STR(x) TO_STR_(x)
#define ESP_LOG_TAG __FILE__ ":" TO_STR(__LINE__)

#endif // COMMON_H
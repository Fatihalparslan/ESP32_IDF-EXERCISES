#ifndef _WIFI_FUNC_H_
#define _WIFI_FUNC_H_

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#define EXAMPLE_ESP_WIFI_SSID      "TP-Link_3CDE"
#define EXAMPLE_ESP_WIFI_PASS      "23667464"
#define EXAMPLE_ESP_MAXIMUM_RETRY  2

void WiFi_Start_Sta(void);
#endif

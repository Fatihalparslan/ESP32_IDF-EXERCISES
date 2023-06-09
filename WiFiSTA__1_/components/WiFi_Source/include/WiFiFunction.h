#ifndef _WIFI_FUNC_H_
#define _WIFI_FUNC_H_

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#define EXAMPLE_ESP_WIFI_SSID      "xxx-xxxx"
#define EXAMPLE_ESP_WIFI_PASS      "xxxxxxxx"
#define EXAMPLE_ESP_MAXIMUM_RETRY  2

void WiFi_Start_Sta(void);
#endif

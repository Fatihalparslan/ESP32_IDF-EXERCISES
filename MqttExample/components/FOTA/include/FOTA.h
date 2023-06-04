#ifndef _FOTA_H_
#define _FOTA_H_

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "mqtt_client.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define EXAMPLE_ESP_WIFI_SSID      "TestWiFi"
#define EXAMPLE_ESP_WIFI_PASS      "TestPass"
#define EXAMPLE_ESP_MAXIMUM_RETRY  2

void WiFi_Start_Sta(void);
void mqtt_app_start(void);
void Publisher_Task(void *params);
#endif
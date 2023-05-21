#include <stdio.h>
#include "esp_log.h"
void app_main(void)
{
esp_log_level_set("LOG",ESP_LOG_INFO);

    ESP_LOGE("LOG", "This is an error");
    ESP_LOGW("LOG", "This is a warning");
    ESP_LOGI("LOG", "This is an info");
    ESP_LOGD("LOG", "This is a debug");
    ESP_LOGV("LOG", "This is a verbose");

    ESP_LOGE("TAG", "This is an error");
    ESP_LOGW("TAG", "This is a warning");
    ESP_LOGI("TAG", "This is an info");
    ESP_LOGD("TAG", "This is a debug");
    ESP_LOGV("TAG", "This is a verbose");
}

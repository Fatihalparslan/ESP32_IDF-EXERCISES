#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "string.h"

TaskHandle_t firstTaskHandle=NULL;
TaskHandle_t SecondTaskHandle=NULL;

void FirstTaskFunc(void *args){
    esp_log_level_set("FTAG",ESP_LOG_INFO);
    while(1){
        ESP_LOGI("FTAG","tickCount:%u",xTaskGetTickCount());
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
void SecondTaskFunc(void *args){
    esp_log_level_set("STAG",ESP_LOG_INFO);
    while(1){
        ESP_LOGI("STAG","tickCount:%u",xTaskGetTickCount());
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
void app_main(void)
{

xTaskCreate(FirstTaskFunc,"First Task",4096,NULL,5,firstTaskHandle);
xTaskCreate(SecondTaskFunc,"Second Task",4096,NULL,5,SecondTaskHandle);

}

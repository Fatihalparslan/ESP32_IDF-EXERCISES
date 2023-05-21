#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

TaskHandle_t FirstTaskHandle=NULL;
TaskHandle_t SecondTaskHandle=NULL;

void FirstTaskFunction(void *args)
{   
    esp_log_level_set("FTAG",ESP_LOG_INFO);
    while(1)
    {
        ESP_LOGI("FTAG","FirstTask tickCount:%u",xTaskGetTickCount());
        vTaskDelay(1000/portTICK_RATE_MS);
    }

}
void SecondTaskFunction(void *args)
{
    esp_log_level_set("STAG",ESP_LOG_INFO);
    while(1)
    {
        ESP_LOGI("STAG","SecondTask tickCount:%u",xTaskGetTickCount());
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void app_main(void)
{
xTaskCreatePinnedToCore(FirstTaskFunction,"First Task",4096,NULL,5,FirstTaskHandle,0);
xTaskCreatePinnedToCore(SecondTaskFunction,"Second Task",4096,NULL,5,SecondTaskFunction,1);
}

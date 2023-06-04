#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#define LED_Pin 26

xSemaphoreHandle xSMutex;
TaskHandle_t LedOn;
TaskHandle_t Ledoff;
void LedControl(bool LedStatus){
    gpio_set_level(LED_Pin,LedStatus);
}
void LedOffTask(void *args)
{

while(1){

    if(xSemaphoreTake(xSMutex,portMAX_DELAY)){
        LedControl(0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        xSemaphoreGive(xSMutex);
    }
    vTaskDelay(1000/portTICK_PERIOD_MS);
}
}
void LedOnTask(void *args)
{
    
    while(1){
        if(xSemaphoreTake(xSMutex,portMAX_DELAY)){
            LedControl(1);
            vTaskDelay(1000/portTICK_PERIOD_MS);
            xSemaphoreGive(xSMutex);
        }
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}
void app_main(void)
{
gpio_config_t led_conf;
led_conf.pin_bit_mask=(1ULL<<LED_Pin);
led_conf.mode=GPIO_MODE_OUTPUT;
gpio_config(&led_conf);

xSMutex=xSemaphoreCreateMutex();
xSemaphoreGive(xSMutex);
gpio_set_level(LED_Pin,1);
ESP_LOGI("here","here");
xTaskCreate(LedOnTask,"Led On",1024,NULL,5,LedOn);
xTaskCreate(LedOffTask,"Led Off",1024,NULL,5,Ledoff);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define B1_Button_PIN 33
#define B2_Button_PIN 34

typedef enum{
    ButtonStateLow,
    ButtonStateHigh
}ButtonStateTypes;



EventGroupHandle_t eventGroup;
EventBits_t uxBits;
const int GetButtonPressed1=BIT0;
const int GetButtonPressed2=BIT1;

TaskHandle_t B1_Handle;
TaskHandle_t B2_Handle;
TaskHandle_t BInf_Handle;
void Button1_ReadFunction(void *args)
{
gpio_config_t b1_gpio_conf;
b1_gpio_conf.pin_bit_mask=(1ULL<<B1_Button_PIN);
b1_gpio_conf.mode=GPIO_MODE_INPUT;
gpio_config(&b1_gpio_conf);
TickType_t LastButtonChangeTime=0;
ButtonStateTypes B1_State=ButtonStateLow;
while(true)
{
    if(gpio_get_level(B1_Button_PIN)&&(B1_State==ButtonStateLow)&&(xTaskGetTickCount()-LastButtonChangeTime>pdMS_TO_TICKS(200)))
    {
        xEventGroupSetBits(eventGroup,GetButtonPressed1);
        B1_State=ButtonStateHigh;
        LastButtonChangeTime=xTaskGetTickCount();
    }else if((!gpio_get_level(B1_Button_PIN))&&(B1_State==ButtonStateHigh)&&(xTaskGetTickCount()-LastButtonChangeTime>pdMS_TO_TICKS(200)))
    {
        
        B1_State=ButtonStateLow;
        LastButtonChangeTime=xTaskGetTickCount();
    }
    vTaskDelay(100/portTICK_PERIOD_MS);
}
vTaskDelete(B1_Handle);
}
void Button2_ReadFunction(void *args)
{
gpio_config_t b2_gpio_conf;
b2_gpio_conf.pin_bit_mask=(1ULL<<B2_Button_PIN);
b2_gpio_conf.mode=GPIO_MODE_INPUT;
gpio_config(&b2_gpio_conf);
TickType_t LastButtonChangeTime=0;
ButtonStateTypes B2_State=ButtonStateLow;
while(true)
{
    if(gpio_get_level(B2_Button_PIN)&&(B2_State==ButtonStateLow)&&(xTaskGetTickCount()-LastButtonChangeTime>pdMS_TO_TICKS(200)))
    {
        xEventGroupSetBits(eventGroup,GetButtonPressed2);
        B2_State=ButtonStateHigh;
        LastButtonChangeTime=xTaskGetTickCount();
    }else if((!gpio_get_level(B2_Button_PIN))&&(B2_State==ButtonStateHigh)&&(xTaskGetTickCount()-LastButtonChangeTime>pdMS_TO_TICKS(200)))
    {
        
        B2_State=ButtonStateLow;
        LastButtonChangeTime=xTaskGetTickCount();
    }
    vTaskDelay(100/portTICK_PERIOD_MS);
}
vTaskDelete(B2_Handle);
}
void ButtonInfoTask(void *args)
{
    while(true)
    {
        uxBits=xEventGroupWaitBits(eventGroup,GetButtonPressed1|GetButtonPressed2,true,false,portMAX_DELAY);
        if(uxBits&GetButtonPressed1)
        {
            ESP_LOGI("BUTTON1","Pressed");
        }
        if(uxBits&GetButtonPressed2)
        {
            ESP_LOGI("BUTTON2","Pressed");
        }
        vTaskDelay(100/portTICK_PERIOD_MS);
    }

}
void app_main(void)
{
eventGroup=xEventGroupCreate();
xTaskCreate(ButtonInfoTask,"Button Info Handle",2048,NULL,5,BInf_Handle);
xTaskCreate(Button1_ReadFunction,"Button 1 Read",2048,NULL,5,B1_Handle);
xTaskCreate(Button2_ReadFunction,"Button 2 Read",2048,NULL,5,B2_Handle);
}

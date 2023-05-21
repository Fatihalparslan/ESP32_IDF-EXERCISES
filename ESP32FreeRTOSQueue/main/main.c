
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "driver/gpio.h"

typedef enum {
    ButtonLOW,
    ButtonHIGH
}ButtonStateTypes;

#define ButtonPIN 33
#define LedPIN    26

TaskHandle_t  ButtonTaskHandle=NULL;
TaskHandle_t  LedTaskHandle=NULL;
QueueHandle_t ButtonToLedQueue;

void ButtonTaskFunc(void *args);
void LedTaskFunc(void *args);
void app_main(void)
{
    xTaskCreatePinnedToCore(ButtonTaskFunc,"Button Task",4096,NULL,5,&ButtonTaskHandle,0);
    xTaskCreatePinnedToCore(LedTaskFunc,"Led Task",4096,NULL,5,&LedTaskHandle,1);
}

void LedTaskFunc(void *args)
{
    gpio_config_t led_gpio_cnf;
    led_gpio_cnf.pin_bit_mask=(1ULL<<LedPIN);
    led_gpio_cnf.mode=GPIO_MODE_OUTPUT;
    gpio_config(&led_gpio_cnf);
    
    int RecvDataFromQueue;
    while(1)
    {
        if(xQueueReceive(ButtonToLedQueue,&RecvDataFromQueue,(TickType_t)5))
        {
            ESP_LOGI("QRECV","Button is %s",((RecvDataFromQueue==0)?"RELEASED":"PRESSED"));
            gpio_set_level(LedPIN,RecvDataFromQueue);
        }
        vTaskDelay(500/portTICK_RATE_MS);
    }
}
void ButtonTaskFunc(void *args)
{
    gpio_config_t btn_gpio_cnf;
    btn_gpio_cnf.pin_bit_mask=(1ULL<<ButtonPIN);
    btn_gpio_cnf.mode=GPIO_MODE_INPUT;
    gpio_config(&btn_gpio_cnf);
    ButtonStateTypes ButtonState = ButtonLOW;
    
    ButtonToLedQueue=xQueueCreate(10,5);
    if(ButtonToLedQueue==0)
    {
        ESP_LOGE("QUEUEER","Failed to create Queue!");
    }
    uint8_t ButtonStatus[1];
    TickType_t lastButtonChangeTime = 0;
    while(1)
    {   
        if((gpio_get_level(ButtonPIN))&&(ButtonState==ButtonLOW)&&(xTaskGetTickCount() - lastButtonChangeTime > pdMS_TO_TICKS(500)))
        {
            lastButtonChangeTime = xTaskGetTickCount();
            ButtonStatus[0]=ButtonHIGH;
            xQueueSend(ButtonToLedQueue,(void *)ButtonStatus,(TickType_t)0);
            printf("ButtonPressed\n");
            ButtonState=ButtonHIGH;
        }else if((!gpio_get_level(ButtonPIN))&&(ButtonState==ButtonHIGH)&&(xTaskGetTickCount() - lastButtonChangeTime > pdMS_TO_TICKS(500)))
        {
            ButtonStatus[0]=ButtonLOW;
            lastButtonChangeTime = xTaskGetTickCount();
            xQueueSend(ButtonToLedQueue,(void *)ButtonStatus,(TickType_t)0);
            printf("ButtonReleased\n");
            ButtonState=ButtonLOW;
        }
        vTaskDelay(100/portTICK_RATE_MS);
    }
}
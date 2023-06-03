#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"

SemaphoreHandle_t xSemaphore=NULL;
TaskHandle_t  ButtonTask_h=NULL;
TaskHandle_t  LedTask_h=NULL;

#define ButtonPIN 33
#define LedPIN    26

typedef enum {
    ButtonLOW,
    ButtonHIGH
}ButtonStateTypes;

void ButtonTask(void *args){

    gpio_config_t btn_gpio_cnf;
    btn_gpio_cnf.pin_bit_mask=(1ULL<<ButtonPIN);
    btn_gpio_cnf.mode=GPIO_MODE_INPUT;
    gpio_config(&btn_gpio_cnf);
    ButtonStateTypes ButtonState = ButtonLOW;
    uint8_t ButtonStatus[1];
    TickType_t lastButtonChangeTime = 0;
    while(1)
    {   
        if((gpio_get_level(ButtonPIN))&&(ButtonState==ButtonLOW)&&(xTaskGetTickCount() - lastButtonChangeTime > pdMS_TO_TICKS(500)))
        {
            lastButtonChangeTime = xTaskGetTickCount();
            ButtonStatus[0]=ButtonHIGH;
            printf("ButtonPressed\n");
            xSemaphoreGive(xSemaphore);
            ButtonState=ButtonHIGH;
        }else if((!gpio_get_level(ButtonPIN))&&(ButtonState==ButtonHIGH)&&(xTaskGetTickCount() - lastButtonChangeTime > pdMS_TO_TICKS(500)))
        {
            ButtonStatus[0]=ButtonLOW;
            lastButtonChangeTime = xTaskGetTickCount();
            printf("ButtonReleased\n");
            ButtonState=ButtonLOW;
        }
        vTaskDelay(100/portTICK_RATE_MS);
    }
    
}
void LedTask(void *args){

    gpio_config_t led_gpio_cnf;
    led_gpio_cnf.pin_bit_mask=(1ULL<<LedPIN);
    led_gpio_cnf.mode=GPIO_MODE_INPUT_OUTPUT;
    gpio_config(&led_gpio_cnf);
    
    int ButtonState;
    while(1)
    {
        if(xSemaphoreTake(xSemaphore, portMAX_DELAY))
        {
            printf("Button is PRESSED");
            gpio_set_level(LedPIN,!gpio_get_level(LedPIN));
        }
        vTaskDelay(500/portTICK_RATE_MS);
    }
    
}
void app_main(void)
{
    xSemaphore=xSemaphoreCreateBinary();
    xTaskCreatePinnedToCore(ButtonTask,"Button Task",4096,NULL,5,ButtonTask_h,0);
    xTaskCreatePinnedToCore(LedTask,"Led Task",4096,NULL,5,LedTask_h,1);
}

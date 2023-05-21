#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "driver/gpio.h"
#include "esp_log.h"

#define LedPin  26
#define ButtonPin  33

TaskHandle_t InterruptTaskHandler = NULL;
TickType_t lastButtonClickTime = 0;

void IRAM_ATTR ButtonInterruptServiceHandler(void *args) {
  TickType_t currentTime = xTaskGetTickCount();
  if (currentTime - lastButtonClickTime > pdMS_TO_TICKS(500)) {
    lastButtonClickTime = currentTime;
    xTaskResumeFromISR(InterruptTaskHandler);
  }
}

void InterrupTaskFunc(void *args){

  while(1){
    vTaskSuspend(NULL);
    gpio_set_level(LedPin, !gpio_get_level(LedPin));
    ESP_LOGI("INT:","ButtonPressTick:%u",xTaskGetTickCount());
  }
}
void SetGPIO4Button(int BPin,void *IntTaskFonk,TaskHandle_t *IntTaskHndlr,gpio_isr_t *BtnISRHndlrService);
void SetGPIO4LED(int LEDPin);

void app_main(void)
{
  
  SetGPIO4LED(LedPin);
  SetGPIO4Button(ButtonPin,InterrupTaskFunc,&InterruptTaskHandler,ButtonInterruptServiceHandler);
  
   

}
void SetGPIO4LED(int LPin){
  gpio_config_t led_gpio_cfg; 
  led_gpio_cfg.pin_bit_mask=(1ULL<<LPin);
  led_gpio_cfg.mode=GPIO_MODE_INPUT_OUTPUT;
  gpio_config(&led_gpio_cfg);    
}
void SetGPIO4Button(int BPin,void *IntTaskFonk,TaskHandle_t *IntTaskHndlr,gpio_isr_t *BtnISRHndlrService){
  gpio_config_t btn_gpio_cfg; 
  btn_gpio_cfg.pin_bit_mask=(1ULL<<BPin);
  btn_gpio_cfg.mode=GPIO_MODE_INPUT;
  btn_gpio_cfg.intr_type=(gpio_int_type_t)(void *)GPIO_INTR_POSEDGE;
  gpio_config(&btn_gpio_cfg);
  gpio_install_isr_service(0);
  gpio_isr_handler_add(BPin, BtnISRHndlrService, NULL);
  xTaskCreate(IntTaskFonk, "interrupt Task", 4096, NULL, 5, IntTaskHndlr);
}
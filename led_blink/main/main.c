#include <stdio.h>
#include "driver/gpio.h"        //Allow us configure gpio pins 
#include "freertos/FreeRTOS.h"  //FreRTOS header
#include "freertos/task.h"     //FreeRTOS task header

#define LED_PIN 26 

#define DELAY_MS 1000   //suspend task for 1000 ms      
void app_main(void)
{
  gpio_reset_pin(LED_PIN);//set gpio pins to its default state
  gpio_set_direction(LED_PIN, GPIO_MODE_INPUT_OUTPUT);//GPIO_MODE_INPUT_OUTPUT ALLOW to  use a gpio pin for both input and output
  gpio_set_level(LED_PIN,0);
  while(true){
    bool curremtState=(bool)(gpio_get_level(LED_PIN));
    gpio_set_level(LED_PIN,!curremtState);
    /*
    vTaskDelay() is a non-blocking delay function that suspends the execution of the current task for a specified period of time. It takes a single parameter, which is the duration of the delay in ticks.
    */
    vTaskDelay(DELAY_MS / portTICK_PERIOD_MS);//portTICK_PERIOD_MS is number of ms in a TICK period,ITCK is unit of time for RTOS, RTOS scheduler measures time according to TICK
  }
}

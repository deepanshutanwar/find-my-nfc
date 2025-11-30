#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "pir.h"

#define PIR 4 //GPIO_4

void setupGPIOInputConfig(int GPIO_PIN)
{
    //configure GPIO
    gpio_config_t io_config={
        .pin_bit_mask = (1ULL<<GPIO_PIN),          //select GPIO 4
        .mode = GPIO_MODE_INPUT,              //set as input
        .pull_up_en = GPIO_PULLUP_DISABLE,    //disable pull up
        .pull_down_en = GPIO_PULLDOWN_ENABLE, //enable pull down
        .intr_type = GPIO_INTR_DISABLE        //disable interrupt
    };

    gpio_config(&io_config);
}

void setup()
{

    //setup GPIO input config
    setupGPIOInputConfig(PIR);

    while(1){
        bool level = gpio_get_level(PIR);
        if(level) printf("PIR ON\n");
        else printf("PIR OFF\n");
        vTaskDelay(100/portTICK_PERIOD_MS);
    }

}

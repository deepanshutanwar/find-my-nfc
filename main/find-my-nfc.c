#include <stdio.h>
#include "find-my-nfc.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define PIR_NUM GPIO_NUM_4 //GPIO_4

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

void app_main(void)
{
    //setup GPIO input config
    setupGPIOInputConfig(PIR_NUM);

    while(1){
        bool level = gpio_get_level(PIR_NUM);
        if(level) printf("PIR ON\n");
        else printf("PIR OFF\n");
        vTaskDelay(100/portTICK_PERIOD_MS);
    }

}

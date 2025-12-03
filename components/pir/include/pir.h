#pragma once
#include "driver/gpio.h"

class PIR{
public:
    void setup();

private:
    void setupGPIOInputConfig(int GPIO_PIN);
};
#include "sdkconfig.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>

#include <esp_log.h>

#include <driver/gpio.h>
#include <driver/ledc.h>

#include <system/Log.h>
#include <system/ButtonController.h>
#include <system/PWMDriver.h>

#include "Agent.h"

#include <cJSON.h>

static const std::string MAIN("main");
cima::system::Log logger(MAIN);

cima::Agent agent;
cima::system::ButtonController buttonController(GPIO_NUM_0);

const gpio_num_t BUILT_IN_LED_GPIO = GPIO_NUM_2;
const gpio_num_t PWM_RED_GPIO = GPIO_NUM_5;
cima::system::PWMDriver redLedDriver(PWM_RED_GPIO, LEDC_CHANNEL_0, false);

static uint32_t ledDutyCycle = 0;

extern "C" void app_main(void) { 
    logger.info("Hello from ESP");

    cima::system::PWMDriver::init();
    cima::system::PWMDriver::init();

    logger.info("Registering button handler");
    buttonController.initButton();
    buttonController.addHandler([&](){ 
        logger.info("Button pressed. Duty %d", ledDutyCycle);
        
        //one physical step (10bit) represented in 13bit resolution.
        ledDutyCycle += (0x01 << 3)*10; 
        ledDutyCycle &= 0x1FFF; //13bit mask = modulo 2^13
        redLedDriver.update(ledDutyCycle);
    });

    agent.registerToMainLoop([&](){buttonController.handleClicks();});

    agent.mainLoop();
}
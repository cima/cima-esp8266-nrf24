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

#include "Agent.h"

#include <cJSON.h>

cima::system::Log logger("main");

cima::Agent agent;
cima::system::ButtonController buttonController(GPIO_NUM_0);

extern "C" void app_main(void) { 
    logger.info("Hello from ESP");

    logger.info("Registering button handler");
    buttonController.initButton();
    buttonController.addHandler([&](){ 
        logger.info("Button pressed.");
    });

    //agent.registerToMainLoop(std::bind(&cima::system::ButtonController::handleClicks, &buttonController));
    agent.registerToMainLoop([&](){buttonController.handleClicks();});

    agent.mainLoop();
}
#include "sdkconfig.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>

#include <esp_log.h>

#include <driver/gpio.h>
#include <driver/ledc.h>


#include <cJSON.h>


extern "C" void app_main(void) { 
    ESP_LOGI("MAIN", "Hello from ESP");
}
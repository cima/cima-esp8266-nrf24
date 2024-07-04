#include <system/Log.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include <esp_log.h>

namespace cima::system {

    bool Log::started = false;

    void Log::init() {
        if( ! started) {
            started = true;
        }
    }

    void Log::debug(const char* format, ...) const {
        char buffer [512];

        va_list args;
        va_start(args, format);
   
        vsnprintf(buffer, 511, format, args);

        ESP_LOGD(loggerName.c_str(), "%s", buffer);

        va_end(args);   
    }

    void Log::info(const char* format, ...) const {
        char buffer [512];

        va_list args;
        va_start(args, format);
   
        vsnprintf(buffer, 511, format, args);

        ESP_LOGI(loggerName.c_str(), "%s", buffer);

        va_end(args);   
    }

    void Log::error(const char* format, ...) const {
        char buffer [512];

        va_list args;
        va_start(args, format);
   
        vsnprintf(buffer, 511, format, args);

        ESP_LOGE(loggerName.c_str(), "%s", buffer);

        va_end(args);   
    }

}
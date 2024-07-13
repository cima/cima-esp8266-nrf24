#pragma once

#include <list>
#include <mutex>
#include <queue>
#include <chrono>
#include <functional>

#include <driver/gpio.h>
#include <driver/ledc.h>

#include <boost/signals2/signal.hpp>

#include <system/Log.h>

namespace cima::system {
    class PWMDriver {
        ledc_channel_config_t ledc_channel;
        ledc_timer_config_t ledc_timer;

        const gpio_num_t pwmGpioPin;
        const ledc_channel_t channel;
        ledc_timer_bit_t resolution;
        const bool inverted = false;

    public:
        PWMDriver(gpio_num_t pwmGpioPin, ledc_channel_t channel, ledc_timer_bit_t resolution = LEDC_TIMER_13_BIT, bool inverted = false);

        void update(uint32_t dutyCycle);
    };
}
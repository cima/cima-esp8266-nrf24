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

        /* Even though the physical resolution of ESP8266's timer is 10bit,
        the ledc library unifies the resolution to 13bit and never respcets this setting.
        Our libs do use it for sofrware inversion of the duty cycle. */
        const ledc_timer_bit_t resolution;

        const bool inverted = false;

    public:
        PWMDriver(gpio_num_t pwmGpioPin, ledc_channel_t channel, bool inverted = false);

        void update(uint32_t dutyCycle);
    };
}
#include <system/PWMDriver.h>

namespace cima::system {
    PWMDriver::PWMDriver(gpio_num_t pwmGpioPin, ledc_channel_t channel, ledc_timer_bit_t resolution, bool inverted) 
            : pwmGpioPin(pwmGpioPin), channel(channel), resolution(resolution), inverted(inverted) {

        ledc_channel.gpio_num = this->pwmGpioPin;
        ledc_channel.speed_mode = LEDC_HIGH_SPEED_MODE;
        ledc_channel.channel = this->channel;
        ledc_channel.intr_type = LEDC_INTR_DISABLE;
        ledc_channel.timer_sel = LEDC_TIMER_0;
        ledc_channel.duty = 0;

        ledc_timer.speed_mode = LEDC_HIGH_SPEED_MODE; //TODO do proměnný
        ledc_timer.duty_resolution = resolution;
        ledc_timer.timer_num = LEDC_TIMER_0; //TODO do proměnný
        ledc_timer.freq_hz = 1000;

        ledc_channel_config(&ledc_channel);
        ledc_timer_config(&ledc_timer);

        ledc_fade_func_install(0);

        //Start with the half of full duty
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, this->channel, 0x01 << (resolution - 1));
	    ledc_update_duty(LEDC_HIGH_SPEED_MODE, this->channel);

    }

    void PWMDriver::update(uint32_t dutyCycle) {
        ledc_set_duty(LEDC_HIGH_SPEED_MODE, this->channel, inverted ? (0x01 << resolution) - dutyCycle : dutyCycle);
	    ledc_update_duty(LEDC_HIGH_SPEED_MODE, this->channel);
    }
}
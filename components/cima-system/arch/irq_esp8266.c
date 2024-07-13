#include <xtensa/xtruntime.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "irq_arch.h"

// At microsecond speeds, the functions from gpio.h are too heavy
#define GPIO_FAST_SET_1(gpio_num) GPIO.out_w1ts |= (0x1 << gpio_num)
#define GPIO_FAST_SET_0(gpio_num) GPIO.out_w1tc |= (0x1 << gpio_num)
#define GPIO_FAST_OUTPUT_ENABLE(gpio_num) GPIO.enable_w1ts |= (0x1 << gpio_num)
#define GPIO_FAST_OUTPUT_DISABLE(gpio_num) GPIO.enable_w1tc |= (0x1 << gpio_num)
#define GPIO_FAST_GET_LEVEL(gpio_num) ((GPIO.in >> gpio_num) & 0x1)

unsigned irq_disable(void) {
    return XTOS_DISABLE_ALL_INTERRUPTS;
}

unsigned irq_enable(void) {
    //TODO implement
    return 0;
}

void irq_restore(unsigned state) {
    XTOS_RESTORE_INTLEVEL(state);
}

int irq_is_in(void) {
    //TODO implement
    return 0;
}

unsigned int irq_arch_enable(void) {
    //TODO implement
    return 0;
}

unsigned int irq_arch_disable(void) {
    //TODO implement
    return 0;
}

void irq_arch_restore(unsigned int state) {
    //TODO implement
}

int irq_arch_in(void) {
    //TODO implement
    return 0;
}

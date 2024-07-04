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
    return 0;//XTOS_DISABLE_ALL_INTERRUPTS;
}

unsigned irq_enable(void) {
    //TODO implement
    return 0;
}

void irq_restore(unsigned state) {
    //XTOS_RESTORE_INTLEVEL(state);
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


//-------------------
uint32_t IRAM_ATTR onewire_read_bit(void) {
   uint32_t r = 0;

   uint32_t savedLevel = XTOS_DISABLE_ALL_INTERRUPTS;

   //GPIO_FAST_OUTPUT_ENABLE(ONEWIRE_PIN);
   //GPIO_FAST_SET_0(ONEWIRE_PIN);

   //ets_delay_us(3);

   //GPIO_FAST_OUTPUT_DISABLE(ONEWIRE_PIN);

   //ets_delay_us(10); // Somewhere near here, sometimes we still get 10us extra delay

   //r = GPIO_FAST_GET_LEVEL(ONEWIRE_PIN);

   XTOS_RESTORE_INTLEVEL(savedLevel);

  //usleep(53);

   return r;
}
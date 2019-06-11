#ifndef DEBOUNCED_PIN_H
#define DEBOUNCED_PIN_H

#include <stdint.h>
#include "driver/gpio.h"

void debounced_pin_init(uint32_t pin_index, gpio_num_t pin, int debounce_ms, uint32_t stack_size,
    uint32_t priority, uint32_t coreID, void (*handler)(void* arg, int state), void* arg);

#endif
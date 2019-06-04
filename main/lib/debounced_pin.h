#ifndef DEBOUNCED_PIN_H
#define DEBOUNCED_PIN_H

#include <stdint.h>
#include "driver/gpio.h"
#include "sdkconfig.h"

#define MAX_DEBOUNCED_PINS CONFIG_REED_SWITCH_NUMBER

void debounced_pin_init(uint32_t pin_index, gpio_num_t pin, int debounce_ms, uint32_t stack_size, uint32_t priority, uint32_t coreID, void (*handler)(void* arg, int state), void* arg);

#endif
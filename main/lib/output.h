#ifndef OUTPUT_H
#define OUTPUT_H

#include "driver/gpio.h"

#define PIN_BIT(x) (1ULL<<x)

void output_init(unsigned long long pin_select, unsigned long long inverted_select, const char** _pin_names);
void output_set(gpio_num_t pin, int level);
void output_on(gpio_num_t pin);
void output_off(gpio_num_t pin);
void output_toggle(gpio_num_t pin);

#endif
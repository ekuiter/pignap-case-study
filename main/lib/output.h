#ifndef OUTPUT_H
#define OUTPUT_H

#include "driver/gpio.h"
#include "driver/ledc.h"

#define PIN_BIT(x) (1ULL<<x)

void output_init(unsigned long long pin_select, unsigned long long inverted_select, const char** _pin_names);
void output_set(gpio_num_t pin, int level);
void output_on(gpio_num_t pin);
void output_off(gpio_num_t pin);
void output_toggle(gpio_num_t pin);
void output_init_pwm(ledc_timer_bit_t resolution, uint32_t frequency);
void output_enable_pwm(gpio_num_t pin, ledc_channel_t channel, uint32_t duty);
void output_disable_pwm(gpio_num_t pin, ledc_channel_t channel);
void output_flash_leds(int times, int delay);

#endif
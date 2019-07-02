#ifndef I2C_H
#define I2C_H

#include "driver/gpio.h"

void i2c_init(gpio_num_t sda_pin, gpio_num_t scl_pin);
void i2c_write(uint8_t addr, uint8_t data);

#endif
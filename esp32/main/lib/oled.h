#ifndef OLED_H
#define OLED_H

#include "../config.h"

#ifdef USE_OLED
#include "u8g2.h"
#include "i2cdev.h"

void oled_init(i2c_dev_t* dev);
u8g2_t* oled_u8g2();
#endif

#endif
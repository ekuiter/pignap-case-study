#ifndef OLED_H
#define OLED_H

#include "../config/config.h"

#ifdef USE_OLED
#include "u8g2.h"
#include "i2cdev.h"

#define OLED_CALCULATE_HORIZONTAL_CENTER(width) ((OLED_WIDTH - (width)) / 2)
#define OLED_CALCULATE_VERTICAL_CENTER(height) ((OLED_HEIGHT - (height)) / 2)

typedef enum {
    OLED_ALIGN_LEFT, OLED_ALIGN_CENTER, OLED_ALIGN_RIGHT
} oled_align_t;

void oled_init(i2c_dev_t* dev);
u8g2_t* oled_handle();
void oled_begin();
void oled_end();
void oled_print(char* buf, const uint8_t* font, uint8_t y, oled_align_t align);
#endif

#endif
#ifndef LCD_H
#define LCD_H

// see https://github.com/maxsydney/ESP32-HD44780

#include <stdint.h>
#include "../config.h"

#ifdef LCD_ENABLED
#define LCD_INIT(...) _lcd_init(__VA_ARGS__)
#define LCD_LOG(...) _lcd_log(__VA_ARGS__)
#else
#define LCD_INIT(...)
#define LCD_LOG(...)
#endif

void _lcd_init(uint8_t addr, uint8_t cols, uint8_t rows);
void _lcd_log(const char *str, ...);
void lcd_set_cursor(uint8_t col, uint8_t row);
void lcd_home();
void lcd_clear();
void lcd_write_char(char c);
void lcd_write(char* str);

#endif
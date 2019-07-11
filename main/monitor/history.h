#ifndef HISTORY_H
#define HISTORY_H

#include "../lib/rtc.h"

void history_read_begin();
uint16_t history_read_next(rtc_date_t* date, uint16_t* counter);
void history_read_today(uint16_t* counter);
void history_write_today(uint16_t counter);
// TODO: take special care that if a day passes while the device is on, today's counter is flushed to memory
esp_err_t history_read(rtc_date_t date, uint16_t* counter); // TODO: ?
esp_err_t history_write(rtc_date_t date, uint16_t counter);

#endif
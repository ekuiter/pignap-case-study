#ifndef HISTORY_H
#define HISTORY_H

#include "../lib/rtc.h"

typedef struct {
    rtc_date_t today_date;
    uint16_t today, filter, isoflurane;
} history_counters_t;

void history_init();
void history_reset();
void history_update();
history_counters_t history_get_counters();
history_counters_t history_increment_counters();
history_counters_t history_reset_filter_counter();
history_counters_t history_reset_isoflurane_counter();
int history_read_begin();
int history_read_next(rtc_date_t* date, uint16_t* counter);

#endif
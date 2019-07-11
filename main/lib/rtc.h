#ifndef RTC_H
#define RTC_H

#include <time.h>
#include "mem.h"
#include "i2cdev.h"

bool rtc_lost_power(i2c_dev_t* dev);
bool rtc_is_maintenance_required(i2c_dev_t* dev, const char* compile_date);
void rtc_set_time(i2c_dev_t* dev, const char* compile_date, const char* compile_time);
void rtc_get_time(i2c_dev_t* dev, struct tm* t);
void rtc_get_date(i2c_dev_t* dev, mem_date_t* date);
int rtc_format_time(i2c_dev_t* dev, char* buf, size_t buf_len);

#endif
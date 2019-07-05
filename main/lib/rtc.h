#ifndef RTC_H
#define RTC_H

#include <time.h>
#include "i2cdev.h"

bool rtc_is_invalid(i2c_dev_t* dev);
void rtc_set_time(i2c_dev_t* dev, const char* date, const char* time);
void rtc_get_time(i2c_dev_t* dev, struct tm* t);

#endif
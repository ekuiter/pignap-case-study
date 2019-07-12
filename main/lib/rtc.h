#ifndef RTC_H
#define RTC_H

#include <time.h>
#include "i2cdev.h"

#define DATE_FORMAT "%04d-%02d-%02d"
#define DATE_ARGS(date) (date).year, (date).month, (date).day

typedef struct {
    uint16_t year;
    uint8_t month, day;
} rtc_date_t;

void _rtc_init(i2c_dev_t* dev);
bool rtc_lost_power(i2c_dev_t* dev);
bool rtc_is_maintenance_required(i2c_dev_t* dev);
rtc_date_t rtc_date_add(rtc_date_t date, int days);
int rtc_date_subtract(rtc_date_t date1, rtc_date_t date2);
void rtc_reset_time(i2c_dev_t* dev);
void rtc_get_time(i2c_dev_t* dev, struct tm* t);
rtc_date_t rtc_get_date(i2c_dev_t* dev);
int rtc_format_time(i2c_dev_t* dev, char* buf, size_t buf_len);
int rtc_format_datetime_local(i2c_dev_t* dev, char* buf, size_t buf_len);
int rtc_format_datetime_local_compile_date_and_time(char* buf, size_t buf_len);
bool rtc_set_datetime_local(i2c_dev_t* dev, char* datetime_local, bool* past_date);

#endif
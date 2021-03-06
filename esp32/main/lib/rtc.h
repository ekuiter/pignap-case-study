#ifndef RTC_H
#define RTC_H

#include "wtime/wtime.h"
#include "i2cdev.h"

#define DATE_FORMAT "%04d-%02d-%02d"
#define DATE_ARGS(date) (date).year, (date).month, (date).day

typedef struct {
    uint16_t year;
    uint8_t month, day;
} rtc_date_t;

void _rtc_init(i2c_dev_t* dev);
rtc_date_t rtc_date_add(rtc_date_t date, int days);
int rtc_date_subtract(rtc_date_t date1, rtc_date_t date2);
rtc_date_t rtc_get_date(i2c_dev_t* dev);
int64_t rtc_time_subtract(wtime_t timestamp1, wtime_t timestamp2);
wtime_t rtc_get_time(i2c_dev_t* dev);
int rtc_format_datetime_local(i2c_dev_t* dev, char* buf, size_t buf_len);
bool rtc_set_datetime_local(i2c_dev_t* dev, char* datetime_local, bool* past_date, bool debug);

#endif
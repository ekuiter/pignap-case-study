#ifndef BATTERY_H
#define BATTERY_H

#include "rtc.h"

void battery_init(i2c_dev_t* dev);
bool battery_is_invalid(i2c_dev_t* dev);
bool battery_is_maintenance_required(i2c_dev_t* dev);
bool battery_may_update(i2c_dev_t* dev);
void battery_updated(i2c_dev_t* dev, rtc_date_t date);

#endif
#ifndef DISPLAY_H
#define DISPLAY_H

#include "../lib/i2cdev.h"

typedef enum {
    REFRESH_STATISTICS, FILTER_WARN, FILTER_ERROR, FILTER_RESET_DONE, AIR_ERROR, AIR_ERROR_RESOLVED, BATTERY_INVALID, BATTERY_MAINTENANCE_REQUIRED, BATTERY_UPDATED
} display_event_t;

void display_send(display_event_t ev);
void display_init(i2c_dev_t* dev);

#endif
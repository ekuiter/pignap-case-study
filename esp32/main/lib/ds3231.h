/**
 * @file ds3231.h
 *
 * ESP-IDF driver for DS3231 high precision RTC module
 *
 * Ported from esp-open-rtos
 * Copyright (C) 2015 Richard A Burton <richardaburton@gmail.com>
 * Copyright (C) 2016 Bhuvanchandra DV <bhuvanchandra.dv@gmail.com>
 * Copyright (C) 2018 Ruslan V. Uss <unclerus@gmail.com>
 * MIT Licensed as described in the file LICENSE
 * https://github.com/UncleRus/esp-idf-lib/
 */

#ifndef __DS3231_H__
#define __DS3231_H__

#include "wtime/wtime.h"
#include <stdbool.h>
#include "i2cdev.h"

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * Alarms
 */
typedef enum {
    DS3231_ALARM_NONE = 0,//!< No alarms
    DS3231_ALARM_1,       //!< First alarm
    DS3231_ALARM_2,       //!< Second alarm
    DS3231_ALARM_BOTH     //!< Both alarms
} ds3231_alarm_t;

/**
 * First alarm rate
 */
typedef enum {
    DS3231_ALARM1_EVERY_SECOND = 0,
    DS3231_ALARM1_MATCH_SEC,
    DS3231_ALARM1_MATCH_SECMIN,
    DS3231_ALARM1_MATCH_SECMINHOUR,
    DS3231_ALARM1_MATCH_SECMINHOURDAY,
    DS3231_ALARM1_MATCH_SECMINHOURDATE
} ds3231_alarm1_rate_t;

/**
 * Second alarm rate
 */
typedef enum {
    DS3231_ALARM2_EVERY_MIN = 0,
    DS3231_ALARM2_MATCH_MIN,
    DS3231_ALARM2_MATCH_MINHOUR,
    DS3231_ALARM2_MATCH_MINHOURDAY,
    DS3231_ALARM2_MATCH_MINHOURDATE
} ds3231_alarm2_rate_t;

/**
 * Squarewave frequency
 */
typedef enum {
    DS3231_SQWAVE_1HZ    = 0x00,
    DS3231_SQWAVE_1024HZ = 0x08,
    DS3231_SQWAVE_4096HZ = 0x10,
    DS3231_SQWAVE_8192HZ = 0x18
} ds3231_sqwave_freq_t;

/**
 * @brief Set the time on the rtc
 * Timezone agnostic, pass whatever you like.
 * I suggest using GMT and applying timezone and DST when read back.
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_set_time(i2c_dev_t *dev, wtm_t *time);

/**
 * @brief Set alarms
 * alarm1 works with seconds, minutes, hours and day of week/month, or fires every second
 * alarm2 works with minutes, hours and day of week/month, or fires every minute
 * not all combinations are supported, see DS3231_ALARM1_* and DS3231_ALARM2_* defines
 * for valid options you only need to populate the fields you are using in the tm struct,
 * and you can set both alarms at the same time (pass DS3231_ALARM_1/DS3231_ALARM_2/DS3231_ALARM_BOTH)
 * if only setting one alarm just pass 0 for tm struct and option field for the other alarm
 * if using DS3231_ALARM1_EVERY_SECOND/DS3231_ALARM2_EVERY_MIN you can pass 0 for tm stuct
 * if you want to enable interrupts for the alarms you need to do that separately
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_set_alarm(i2c_dev_t *dev, ds3231_alarm_t alarms, wtm_t *time1,
        ds3231_alarm1_rate_t option1, wtm_t *time2, ds3231_alarm2_rate_t option2);

/**
 * @brief Check if oscillator has previously stopped, e.g. no power/battery or disabled
 * sets flag to true if there has been a stop
 * @param dev Device descriptor
 * @param[out] flag Stop flag
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_get_oscillator_stop_flag(i2c_dev_t *dev, bool *flag);

/**
 * @brief Clear the oscillator stopped flag
 * @param dev Device descriptor
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_clear_oscillator_stop_flag(i2c_dev_t *dev);

/**
 * @brief Check which alarm(s) have past
 * sets alarms to DS3231_ALARM_NONE/DS3231_ALARM_1/DS3231_ALARM_2/DS3231_ALARM_BOTH
 * @param dev Device descriptor
 * @param[out] alarms Alarms
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_get_alarm_flags(i2c_dev_t *dev, ds3231_alarm_t *alarms);

/**
 * @brief Clear alarm past flag(s)
 * pass DS3231_ALARM_1/DS3231_ALARM_2/DS3231_ALARM_BOTH
 * @param dev Device descriptor
 * @param alarms Alarms
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_clear_alarm_flags(i2c_dev_t *dev, ds3231_alarm_t alarms);

/**
 * @brief enable alarm interrupts (and disables squarewave)
 * pass DS3231_ALARM_1/DS3231_ALARM_2/DS3231_ALARM_BOTH
 * if you set only one alarm the status of the other is not changed
 * you must also clear any alarm past flag(s) for alarms with
 * interrupt enabled, else it will trigger immediately
 * @param dev Device descriptor
 * @param alarms Alarms
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_enable_alarm_ints(i2c_dev_t *dev, ds3231_alarm_t alarms);

/**
 * @brief Disable alarm interrupts (does not (re-)enable squarewave)
 * @param dev Device descriptor
 * @param alarms Alarm
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_disable_alarm_ints(i2c_dev_t *dev, ds3231_alarm_t alarms);

/**
 * @brief Enable the output of 32khz signal
 * @param dev Device descriptor
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_enable_32khz(i2c_dev_t *dev);

/**
 * @brief Disable the output of 32khz signal
 * @param dev Device descriptor
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_disable_32khz(i2c_dev_t *dev);

/**
 * @brief Enable the squarewave output (disables alarm interrupt functionality)
 * @param dev Device descriptor
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_enable_squarewave(i2c_dev_t *dev);

/**
 * @brief Disable the squarewave output (which re-enables alarm interrupts, but individual
 * alarm interrupts also need to be enabled, if not already, before they will trigger)
 * @param dev Device descriptor
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_disable_squarewave(i2c_dev_t *dev);

/**
 * @brief Set the frequency of the squarewave output (but does not enable it)
 * @param dev Device descriptor
 * @param freq Squarewave frequency
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_set_squarewave_freq(i2c_dev_t *dev, ds3231_sqwave_freq_t freq);

/**
 * @brief Get the raw temperature value
 * @param dev Device descriptor
 * @param[out] temp Raw temperature value
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_get_raw_temp(i2c_dev_t *dev, int16_t *temp);

/**
 * @brief Get the temperature as an integer
 * @param dev Device descriptor
 * @param[out] temp Temperature, degrees Celsius
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_get_temp_integer(i2c_dev_t *dev, int8_t *temp);

/**
 * @brief Get the temperature as a float
 * @param dev Device descriptor
 * @param[out] temp Temperature, degrees Celsius
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_get_temp_float(i2c_dev_t *dev, float *temp);

/**
 * @brief Get the time from the RTC, populates a supplied tm struct
 * @param dev Device descriptor
 * @param[out] time RTC time
 * @return ESP_OK to indicate success
 */
esp_err_t ds3231_get_time(i2c_dev_t *dev, wtm_t *time);

#ifdef	__cplusplus
}
#endif

#endif  /* __DS3231_H__ */

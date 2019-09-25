/**************************************************************************/
/*! 
    @file     FRAM_MB85RC_I2C.h
    @author   SOSAndroid.fr (E. Ha.)

    Driver for the MB85RC I2C FRAM from Fujitsu.
*/
/**************************************************************************/
#ifndef _FRAM_MB85RC_I2C_H_
#define _FRAM_MB85RC_I2C_H_

#include <stdint.h>
#include <stdbool.h>
#include "i2cdev.h"
#include "../config.h"

typedef i2c_dev_t fram_t[FRAM_PAGE_NUM];

esp_err_t fram_read(fram_t fram, uint16_t framAddr, uint8_t items, uint8_t value[]);
esp_err_t fram_write(fram_t fram, uint16_t framAddr, uint8_t items, uint8_t value[]);
esp_err_t fram_read_u8(fram_t fram, uint16_t framAddr, uint8_t *value);
esp_err_t fram_write_u8(fram_t fram, uint16_t framAddr, uint8_t value);
esp_err_t fram_read_u16(fram_t fram, uint16_t framAddr, uint16_t *value);
esp_err_t fram_write_u16(fram_t fram, uint16_t framAddr, uint16_t value);
esp_err_t fram_read_u32(fram_t fram, uint16_t framAddr, uint32_t *value);
esp_err_t fram_write_u32(fram_t fram, uint16_t framAddr, uint32_t value);
esp_err_t fram_reset(fram_t fram);

#endif

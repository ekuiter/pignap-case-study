#ifndef MEM_H
#define MEM_H

#include "esp_err.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t year;
    uint8_t month, day;
} mem_date_t;

esp_err_t _mem_init(uint16_t cell_default, uint16_t idx_default, mem_date_t date_default);
bool mem_is_readonly();
esp_err_t mem_read_cell(uint16_t idx, uint16_t* val);
esp_err_t mem_write_cell(uint16_t idx, uint16_t val);
esp_err_t mem_read_index(uint16_t* idx);
esp_err_t mem_write_index(uint16_t idx);
esp_err_t mem_read_date(mem_date_t* date);
esp_err_t mem_write_date(mem_date_t date);
esp_err_t mem_dump();

#endif
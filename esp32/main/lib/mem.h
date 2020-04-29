#ifndef MEM_H
#define MEM_H

#include "esp_err.h"
#include "rtc.h"
#include <stdint.h>
#include <stdbool.h>

esp_err_t _mem_init(uint16_t cell_default, uint16_t idx_default, rtc_date_t date_default,
    uint32_t total_counter, uint16_t filter_counter, uint16_t prefilter_counter,
    uint64_t shutdown_time, uint32_t filter_reset_date, uint32_t prefilter_reset_date, bool reset);
esp_err_t mem_reset();
bool mem_is_readonly();
void mem_set_readonly(bool _readonly);
esp_err_t mem_read_cell(uint16_t cell, uint16_t* counter);
esp_err_t mem_write_cell(uint16_t cell, uint16_t counter);
esp_err_t mem_read_index(uint16_t* idx);
esp_err_t mem_write_index(uint16_t idx);
esp_err_t mem_read_date(rtc_date_t* date);
esp_err_t mem_write_date(rtc_date_t date);
esp_err_t mem_read_total_counter(uint32_t* total_counter);
esp_err_t mem_write_total_counter(uint32_t total_counter);
esp_err_t mem_read_filter_counter(uint16_t* filter_counter);
esp_err_t mem_write_filter_counter(uint16_t filter_counter);
esp_err_t mem_read_prefilter_counter(uint16_t* prefilter_counter);
esp_err_t mem_write_prefilter_counter(uint16_t prefilter_counter);
esp_err_t mem_read_shutdown_time(wtime_t* shutdown_time);
esp_err_t mem_write_shutdown_time(wtime_t shutdown_time);
esp_err_t mem_read_filter_reset_date(rtc_date_t* date);
esp_err_t mem_write_filter_reset_date(rtc_date_t date);
esp_err_t mem_read_prefilter_reset_date(rtc_date_t* date);
esp_err_t mem_write_prefilter_reset_date(rtc_date_t date);
esp_err_t mem_dump(char* dump_buf);

#endif
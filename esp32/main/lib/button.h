#ifndef BUTTON_H
#define BUTTON_H

// see https://github.com/craftmetrics/esp32-button/
// and https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/

#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#define PIN_BIT(x) (1ULL<<x)
#define BUTTON_DOWN (1)
#define BUTTON_UP (2)
#define BUTTON_INITIALLY_DOWN (3)
#define BUTTON_INITIALLY_UP (4)
#define BUTTON_HOLD (5)

typedef struct {
	uint8_t pin;
    uint8_t event;
} button_event_t;

QueueHandle_t* button_init(unsigned long long pin_select, unsigned long long inverted_select,
    unsigned long long pullup_select, const char** _pin_names);

#endif
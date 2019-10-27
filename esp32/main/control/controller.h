#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef enum {
    TREATMENT_DONE, RESET_FILTER, AIR_READY, AIR_NOT_READY
} controller_event_t;

typedef enum {
    FINE, WARN, ERROR
} controller_commodity_state_t;

void controller_send(controller_event_t ev);
controller_commodity_state_t controller_get_filter_state();
controller_commodity_state_t controller_get_air_state();
void controller_init();

#endif
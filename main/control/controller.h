#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef enum {
    TREATMENT_DONE, RESET_FILTER, RESET_ISOFLURANE, POWER_OFF
} controller_event_t;

typedef enum {
    FINE, WARN, ERROR
} controller_commodity_state_t;

void controller_send(controller_event_t ev);
int controller_get_today_counter();
int controller_get_filter_counter();
int controller_get_isoflurane_counter();
controller_commodity_state_t controller_get_filter_state();
controller_commodity_state_t controller_get_isoflurane_state();
void controller_init();

#endif
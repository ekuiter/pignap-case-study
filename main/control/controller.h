#ifndef CONTROLLER_H
#define CONTROLLER_H

typedef enum {
    TREATMENT_DONE, RESET_FILTER, RESET_ISOFLURANE
} controller_event_t;

void controller_init();
void controller_send(controller_event_t ev);

#endif
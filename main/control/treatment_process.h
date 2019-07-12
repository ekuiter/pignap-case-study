#ifndef TREATMENT_PROCESS_H
#define TREATMENT_PROCESS_H

typedef enum {
    PIGLET_INSERTED, PIGLET_REMOVED, BLOCK, UNBLOCK, SHUTDOWN_TREATMENT
} treatment_process_event_t;

typedef enum {
    IDLE, PHASE_1, PHASE_2, BLOCKED
} treatment_process_state_t;

void treatment_process_send(int idx, treatment_process_event_t ev);
treatment_process_state_t treatment_process_get_state(int idx);
void treatment_process_init();

#endif
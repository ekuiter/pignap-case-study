#ifndef TREATMENT_PROCESS_H
#define TREATMENT_PROCESS_H

typedef enum {
	START, STOP
} treatment_process_event_t;

void treatment_process_init();
void treatment_process_send(int idx, treatment_process_event_t ev);

#endif
#ifndef TREATMENT_PROCESS_H
#define TREATMENT_PROCESS_H

typedef enum {
	REED_SWITCH_DOWN, REED_SWITCH_UP
} treatment_process_event_t;

void treatment_process_init();
void treatment_process_send(int idx, treatment_process_event_t ev);

#endif
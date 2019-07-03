#ifndef CONFIG_H
#define CONFIG_H

#include "lib/output.h"
#include "lib/button.h"

// OUTPUTS
#define OUTPUT_GPIO_LED_1_GREEN       14
#define OUTPUT_GPIO_LED_1_RED         12
#define OUTPUT_GPIO_LED_2_GREEN       13
#define OUTPUT_GPIO_LED_2_RED         15
#define OUTPUT_GPIO_LED_3_GREEN       2
#define OUTPUT_GPIO_LED_3_RED         4
#define OUTPUT_GPIO_LED_4_GREEN       23
#define OUTPUT_GPIO_LED_4_RED         19
#define OUTPUT_GPIO_LED_FILTER_FULL   9
#define OUTPUT_GPIO_LED_NO_ISOFLURANE 10
#define OUTPUT_GPIO_MAGNETIC_VALVE_1  25
#define OUTPUT_GPIO_MAGNETIC_VALVE_2  26
#define OUTPUT_GPIO_MAGNETIC_VALVE_3  32
#define OUTPUT_GPIO_MAGNETIC_VALVE_4  33
#define OUTPUT_GPIO_COUNTER           18

extern const char* output_pin_names[]; // only used for logging

// bit mask that configures output pins
#define OUTPUT_PIN_SELECT \
    (PIN_BIT(OUTPUT_GPIO_LED_1_GREEN)       | PIN_BIT(OUTPUT_GPIO_LED_1_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_2_GREEN)      | PIN_BIT(OUTPUT_GPIO_LED_2_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_3_GREEN)      | PIN_BIT(OUTPUT_GPIO_LED_3_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_4_GREEN)      | PIN_BIT(OUTPUT_GPIO_LED_4_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_FILTER_FULL)  | PIN_BIT(OUTPUT_GPIO_LED_NO_ISOFLURANE) \
    | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_1) | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_2) \
    | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_3) | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_4) \
    | PIN_BIT(OUTPUT_GPIO_COUNTER))

// bit mask that determines which outputs have inverted logic
// inverted means: HIGH = output off, LOW = output on
// TODO: I use this to simulate some pins with a seven-segment display,
// this must be changed for the final product!
#define OUTPUT_INVERTED_SELECT \
    (PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_1) | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_2) \
    | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_3) | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_4) \
    | PIN_BIT(OUTPUT_GPIO_COUNTER))

// BUTTONS
#define BUTTON_GPIO_REED_SWITCH_1    37
#define BUTTON_GPIO_REED_SWITCH_2    38
#define BUTTON_GPIO_REED_SWITCH_3    34
#define BUTTON_GPIO_REED_SWITCH_4    35
#define BUTTON_GPIO_RESET_FILTER     27
#define BUTTON_GPIO_RESET_ISOFLURANE 0
#define BUTTON_GPIO_VOLTAGE_MONITOR  5

extern const char* button_pin_names[]; // only used for logging

// bit mask that configures buttons as input pins
#define BUTTON_PIN_SELECT \
    (PIN_BIT(BUTTON_GPIO_REED_SWITCH_1)  | PIN_BIT(BUTTON_GPIO_REED_SWITCH_2) \
    | PIN_BIT(BUTTON_GPIO_REED_SWITCH_3) | PIN_BIT(BUTTON_GPIO_REED_SWITCH_4) \
    | PIN_BIT(BUTTON_GPIO_RESET_FILTER) | PIN_BIT(BUTTON_GPIO_RESET_ISOFLURANE) \
    | PIN_BIT(BUTTON_GPIO_VOLTAGE_MONITOR))

// bit mask that determines which buttons have inverted logic
// inverted means: HIGH = button up, LOW = button down
// TODO: on my development board, only GPIO 0 is inverted, this
// must be changed for the final product!
// the voltage monitor is considered a button too, it is "pressed down"
// when the voltage drops and the device must save its data
#define BUTTON_INVERTED_SELECT \
    (PIN_BIT(BUTTON_GPIO_RESET_ISOFLURANE) | PIN_BIT(BUTTON_GPIO_VOLTAGE_MONITOR))

// TREATMENT PROCESS
#define TREATMENT_PROCESS_NUM      4
#define TREATMENT_PHASE_1_DURATION 5 // 75
#define TREATMENT_PHASE_2_DURATION 4 // 15
#define TREATMENT_TOTAL_DURATION   (TREATMENT_PHASE_1_DURATION + TREATMENT_PHASE_2_DURATION)

// I2C
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

// LCD
// comment the next line out to remove logging to LCD display
#define LCD_ENABLED
#define LCD_I2C_ADDRESS 0x27
#define LCD_NUM_COLS    16
#define LCD_NUM_ROWS    2

// TASKS
// control tasks are pinned to core 0, all others to core 1

// responsible for intercepting and debouncing button presses
#define BUTTON_TASK_CORE_ID    0
#define BUTTON_TASK_STACK_SIZE 4096
#define BUTTON_TASK_PRIORITY   10

// handles button presses, blocks until button_task fills its
// queue, so priority is lower than button_task
#define BUTTON_HANDLER_TASK_CORE_ID    0
#define BUTTON_HANDLER_TASK_STACK_SIZE 4096
#define BUTTON_HANDLER_TASK_PRIORITY   9

// controls the treatment process, is informed by higher-priority
// tasks about the environment
#define TREATMENT_PROCESS_TASK_CORE_ID    0
#define TREATMENT_PROCESS_TASK_STACK_SIZE 4096
#define TREATMENT_PROCESS_TASK_PRIORITY   8

// MISC
// fixes code assistance in Visual Studio Code
#ifndef CONFIG_FREERTOS_HZ
#define CONFIG_FREERTOS_HZ 100
#endif

#endif
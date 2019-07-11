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

// PWM channels for blinking LEDs
#define OUTPUT_CHANNEL_LED_1_RED LEDC_CHANNEL_1
#define OUTPUT_CHANNEL_LED_2_RED LEDC_CHANNEL_2
#define OUTPUT_CHANNEL_LED_3_RED LEDC_CHANNEL_3
#define OUTPUT_CHANNEL_LED_4_RED LEDC_CHANNEL_4

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
#define TREATMENT_PROCESS_NUM          4
#define TREATMENT_PHASE_1_DURATION     2 // TODO: 75
#define TREATMENT_PHASE_2_DURATION     2 // TODO: 15
#define TREATMENT_TOTAL_DURATION       (TREATMENT_PHASE_1_DURATION + TREATMENT_PHASE_2_DURATION)
#define TREATMENT_LED_BLINK_RESOLUTION LEDC_TIMER_10_BIT
#define TREATMENT_LED_BLINK_FREQUENCY  1
#define TREATMENT_LED_BLINK_DUTY       512

// CONTROLLER
#define CONTROLLER_COUNTER_ON_DURATION  1000
#define CONTROLLER_COUNTER_OFF_DURATION 500
#define CONTROLLER_FILTER_WARN          8 // TODO
#define CONTROLLER_ISOFLURANE_WARN      10 // TODO
#define CONTROLLER_FILTER_TOLERANCE     2 // TODO
#define CONTROLLER_ISOFLURANE_TOLERANCE 2 // TODO
#define CONTROLLER_FILTER_MAX           (CONTROLLER_FILTER_WARN + CONTROLLER_FILTER_TOLERANCE)
#define CONTROLLER_ISOFLURANE_MAX       (CONTROLLER_ISOFLURANE_WARN + CONTROLLER_ISOFLURANE_TOLERANCE)

// I2C
#define I2C_SDA_PIN   21
#define I2C_SCL_PIN   22
#define I2C_FREQUENCY 100000

// LCD
// comment the next line out to remove logging to LCD display
#define LCD_ENABLED
#define LCD_I2C_ADDRESS 0x27
#define LCD_NUM_COLS    16
#define LCD_NUM_ROWS    2

// RTC
#define RTC_I2C_ADDRESS             0x68
// Add an offset for our timezone CET (UTC+1).
// Note that we ignore daylight saving time, this means today's treatments from
// midnight to 1am are assigned to yesterday - which should not be a problem.
#define RTC_TIMEZONE_OFFSET         1
// This defines a number of years after which the device should be maintained, that is,
// after how many years the battery should be replaced and the device re-flashed.
// After this number of years, all LEDs on the device blink 2 times after booting.
#define RTC_MAINTENANCE_AFTER_YEARS 10
// If the battery is low, all LEDs on the device blink 4 times after booting.
// To replace the battery and force an update of the RTC time:
// - flash the software
// - turn off the device
// - replace the battery
// - turn on the device, all LEDs should blink 4 times
// - if turned off and on again (not reset), no LEDs should blink
// The device should be turned on not too long after flashing to avoid time drift!

extern const char* rtc_compile_date, * rtc_compile_time; // used for resetting the RTC

// WIFI
#define WIFI_SETTING_BUF_LEN    48

// WIFI ACCESS POINT
#define WIFI_AP_SSID            "PIGNAP"
#define WIFI_AP_DEFAULT_PSK     ***REMOVED***
#define WIFI_AP_MAX_CONNECTIONS 5

// WIFI STATION
#define WIFI_STA_HOSTNAME       "pignap"
#define WIFI_STA_DEFAULT_SSID   ""
#define WIFI_STA_DEFAULT_PSK    ""
#define WIFI_STA_MAX_RETRIES    5

// MEMORY
#define MEM_CELL_NUM                   366
#define MEM_CELL_DEFAULT               0
#define MEM_INDEX_DEFAULT              0
#define MEM_FILTER_COUNTER_DEFAULT     0
#define MEM_ISOFLURANE_COUNTER_DEFAULT 0
#define MEM_CELLS_PER_ROW              20

// TASKS
// Control tasks are pinned to core 1, monitoring tasks to core 0.
// This guarantees a separation of concerns. The default system loop,
// which handles networking events, is already pinned to core 0 by ESP-IDF.

// responsible for intercepting and debouncing button presses
#define BUTTON_TASK_CORE_ID    1
#define BUTTON_TASK_STACK_SIZE 4096
#define BUTTON_TASK_PRIORITY   10

// handles button presses, blocks until button_task fills its
// queue, so priority is lower than button_task
#define BUTTON_HANDLER_TASK_CORE_ID    1
#define BUTTON_HANDLER_TASK_STACK_SIZE 4096
#define BUTTON_HANDLER_TASK_PRIORITY   9

// controls the treatment process, is informed by higher-priority
// tasks about the environment
#define TREATMENT_PROCESS_TASK_CORE_ID    1
#define TREATMENT_PROCESS_TASK_STACK_SIZE 4096
#define TREATMENT_PROCESS_TASK_PRIORITY   8

// increments the counter, checks if filter and isoflurane are ready
#define CONTROLLER_TASK_CORE_ID    1
#define CONTROLLER_TASK_STACK_SIZE 4096
#define CONTROLLER_TASK_PRIORITY   7

// writes to the LCD display
// has a higher priority than the default system loop to avoid
// being interrupted during Wifi initialization
#define LCD_LOG_TASK_CORE_ID    0
#define LCD_LOG_TASK_STACK_SIZE 4096
#define LCD_LOG_TASK_PRIORITY   25

// runs an HTTP server
#define HTTP_TASK_CORE_ID    0
#define HTTP_TASK_STACK_SIZE 4096
#define HTTP_TASK_PRIORITY   11

// starts a Wifi access point
#define WIFI_TASK_CORE_ID    0
#define WIFI_TASK_STACK_SIZE 4096
#define WIFI_TASK_PRIORITY   10

// MISC
#define MAIN_HEAP_INFO_INTERVAL 60

// fixes code assistance in Visual Studio Code
#ifndef CONFIG_FREERTOS_HZ
#define CONFIG_FREERTOS_HZ 100
#endif

#ifndef CONFIG_HTTPD_MAX_REQ_HDR_LEN
#define CONFIG_HTTPD_MAX_REQ_HDR_LEN 512
#endif

#ifndef CONFIG_HTTPD_MAX_URI_LEN
#define CONFIG_HTTPD_MAX_URI_LEN 512
#endif

#ifndef CONFIG_ESP32_WIFI_STATIC_RX_BUFFER_NUM
#define CONFIG_ESP32_WIFI_STATIC_RX_BUFFER_NUM 10
#endif

#ifndef CONFIG_ESP32_WIFI_DYNAMIC_RX_BUFFER_NUM
#define CONFIG_ESP32_WIFI_DYNAMIC_RX_BUFFER_NUM 32
#endif

#ifndef CONFIG_ESP32_WIFI_TX_BUFFER_TYPE
#define CONFIG_ESP32_WIFI_TX_BUFFER_TYPE 1
#endif

#ifndef CONFIG_LWIP_MAX_SOCKETS
#define CONFIG_LWIP_MAX_SOCKETS 10
#endif

#endif
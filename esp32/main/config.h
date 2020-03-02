#ifndef CONFIG_H
#define CONFIG_H

#include "lib/output.h"
#include "lib/button.h"

// 1 = my first development board
// 2 = my second development board
// 3 = device prototype (LEDs inverted)
// 4 = device prototype (IO0/5 swapped) - currently used at HCP
#define BOARD_VERSION 4

// if not defined, treatment durations are shorter
#define IS_PRODUCTION

// 0 = use internal non-volatile flash memory for one-year history (which is less endurable)
// 1 = FM24CL16B (2 kilobyte FRAM storing the initially proposed one-year history)
// 2 = FM24CL64B (8 kilobyte FRAM storing the now prescribed three-year history)
#define FRAM_VERSION 2

// address of FRAM on I2C bus
// 0x50 for FM24CL16B, for FM24CL64B: 0x50 for A123=000 (at HCP); 0x57 for A123=111 (RTC board)
#define FRAM_I2C_ADDRESS 0x50

// if defined, show statistics on the OLED display
#define USE_OLED

// define this to check output and button GPIOs
// #define GPIO_TEST

extern const char* output_pin_names_v1[], * output_pin_names_v2[],
    * button_pin_names_v1[], * button_pin_names_v2[], * button_pin_names_v4[]; // only used for logging

// OUTPUTS
#if BOARD_VERSION == 2 || BOARD_VERSION == 3 || BOARD_VERSION == 4
#define OUTPUT_GPIO_LED_1_GREEN      12
#define OUTPUT_GPIO_LED_1_RED        14
#define OUTPUT_GPIO_LED_2_GREEN      15
#define OUTPUT_GPIO_LED_2_RED        13
#define OUTPUT_GPIO_LED_3_GREEN      4
#define OUTPUT_GPIO_LED_3_RED        2
#define OUTPUT_GPIO_LED_4_GREEN      19
#define OUTPUT_GPIO_LED_4_RED        23
#define OUTPUT_GPIO_LED_FILTER       10
#define OUTPUT_GPIO_LED_PREFILTER    27 /* connected to an input in versions 2 and 3 (originally used as isoflurane reset) */
#define OUTPUT_GPIO_LED_POWER        9
#define OUTPUT_GPIO_MAGNETIC_VALVE_1 25
#define OUTPUT_GPIO_MAGNETIC_VALVE_2 26
#define OUTPUT_GPIO_MAGNETIC_VALVE_3 32
#define OUTPUT_GPIO_MAGNETIC_VALVE_4 33
#define OUTPUT_PIN_NAMES              output_pin_names_v2
#elif BOARD_VERSION == 1
#define OUTPUT_GPIO_LED_1_GREEN      14
#define OUTPUT_GPIO_LED_1_RED        12
#define OUTPUT_GPIO_LED_2_GREEN      13
#define OUTPUT_GPIO_LED_2_RED        15
#define OUTPUT_GPIO_LED_3_GREEN      2
#define OUTPUT_GPIO_LED_3_RED        4
#define OUTPUT_GPIO_LED_4_GREEN      23
#define OUTPUT_GPIO_LED_4_RED        19
#define OUTPUT_GPIO_LED_FILTER       9
#define OUTPUT_GPIO_LED_PREFILTER    0
#define OUTPUT_GPIO_LED_POWER        10
#define OUTPUT_GPIO_MAGNETIC_VALVE_1 25
#define OUTPUT_GPIO_MAGNETIC_VALVE_2 26
#define OUTPUT_GPIO_MAGNETIC_VALVE_3 32
#define OUTPUT_GPIO_MAGNETIC_VALVE_4 33
#define OUTPUT_PIN_NAMES              output_pin_names_v1
#endif

// bit mask that configures output pins
#define OUTPUT_PIN_SELECT \
    (PIN_BIT(OUTPUT_GPIO_LED_1_GREEN)       | PIN_BIT(OUTPUT_GPIO_LED_1_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_2_GREEN)      | PIN_BIT(OUTPUT_GPIO_LED_2_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_3_GREEN)      | PIN_BIT(OUTPUT_GPIO_LED_3_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_4_GREEN)      | PIN_BIT(OUTPUT_GPIO_LED_4_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_FILTER)       | PIN_BIT(OUTPUT_GPIO_LED_PREFILTER) \
    | PIN_BIT(OUTPUT_GPIO_LED_POWER)        | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_1) \
    | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_2) | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_3) \
    | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_4))

// bit mask that determines which outputs have inverted logic
// inverted means: HIGH = output off, LOW = output on
#if BOARD_VERSION == 3 || BOARD_VERSION == 4
#define OUTPUT_INVERTED_SELECT \
    (PIN_BIT(OUTPUT_GPIO_LED_1_GREEN)  | PIN_BIT(OUTPUT_GPIO_LED_1_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_2_GREEN) | PIN_BIT(OUTPUT_GPIO_LED_2_RED) \
	| PIN_BIT(OUTPUT_GPIO_LED_3_GREEN) | PIN_BIT(OUTPUT_GPIO_LED_3_RED) \
    | PIN_BIT(OUTPUT_GPIO_LED_4_GREEN) | PIN_BIT(OUTPUT_GPIO_LED_4_RED) \
	| PIN_BIT(OUTPUT_GPIO_LED_FILTER)  | PIN_BIT(OUTPUT_GPIO_LED_PREFILTER) \
    | PIN_BIT(OUTPUT_GPIO_LED_POWER))
#elif BOARD_VERSION == 2
#define OUTPUT_INVERTED_SELECT \
    (PIN_BIT(OUTPUT_GPIO_LED_FILTER) | PIN_BIT(OUTPUT_GPIO_LED_PREFILTER) \
    | PIN_BIT(OUTPUT_GPIO_LED_POWER))
#elif BOARD_VERSION == 1
#define OUTPUT_INVERTED_SELECT \
    (PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_1)  | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_2) \
    | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_3) | PIN_BIT(OUTPUT_GPIO_MAGNETIC_VALVE_4) \
    | PIN_BIT(OUTPUT_GPIO_LED_PREFILTER))
#endif

// PWM channels for blinking LEDs
#define OUTPUT_CHANNEL_LED_1_RED LEDC_CHANNEL_1
#define OUTPUT_CHANNEL_LED_2_RED LEDC_CHANNEL_2
#define OUTPUT_CHANNEL_LED_3_RED LEDC_CHANNEL_3
#define OUTPUT_CHANNEL_LED_4_RED LEDC_CHANNEL_4

// BUTTONS
#if BOARD_VERSION == 4
#define BUTTON_GPIO_REED_SWITCH_1 37
#define BUTTON_GPIO_REED_SWITCH_2 38
#define BUTTON_GPIO_REED_SWITCH_3 34
#define BUTTON_GPIO_REED_SWITCH_4 35
#define BUTTON_GPIO_RESET         5
#define BUTTON_PIN_NAMES          button_pin_names_v4
#elif BOARD_VERSION == 2 || BOARD_VERSION == 3
#define BUTTON_GPIO_REED_SWITCH_1 37
#define BUTTON_GPIO_REED_SWITCH_2 38
#define BUTTON_GPIO_REED_SWITCH_3 34
#define BUTTON_GPIO_REED_SWITCH_4 35
#define BUTTON_GPIO_RESET         0
#define BUTTON_PIN_NAMES          button_pin_names_v2
#elif BOARD_VERSION == 1
#define BUTTON_GPIO_REED_SWITCH_1 37
#define BUTTON_GPIO_REED_SWITCH_2 38
#define BUTTON_GPIO_REED_SWITCH_3 34
#define BUTTON_GPIO_REED_SWITCH_4 35
#define BUTTON_GPIO_RESET  27
#define BUTTON_PIN_NAMES          button_pin_names_v1
#endif

// bit mask that configures buttons as input pins
#define BUTTON_PIN_SELECT \
    (PIN_BIT(BUTTON_GPIO_REED_SWITCH_1)  | PIN_BIT(BUTTON_GPIO_REED_SWITCH_2) \
    | PIN_BIT(BUTTON_GPIO_REED_SWITCH_3) | PIN_BIT(BUTTON_GPIO_REED_SWITCH_4) \
    | PIN_BIT(BUTTON_GPIO_RESET))

// bit mask that determines which buttons have inverted logic
// inverted means: HIGH = button up, LOW = button down
#if BOARD_VERSION == 2 || BOARD_VERSION == 3 || BOARD_VERSION == 4
#define BUTTON_INVERTED_SELECT \
    (PIN_BIT(BUTTON_GPIO_REED_SWITCH_1)  | PIN_BIT(BUTTON_GPIO_REED_SWITCH_2) \
    | PIN_BIT(BUTTON_GPIO_REED_SWITCH_3) | PIN_BIT(BUTTON_GPIO_REED_SWITCH_4) \
    | PIN_BIT(BUTTON_GPIO_RESET))
#elif BOARD_VERSION == 1
#define BUTTON_INVERTED_SELECT \
    (0)
#endif

// bit mask that determines which buttons should have internal pull up resistor enabled
#if BOARD_VERSION == 2 || BOARD_VERSION == 3 || BOARD_VERSION == 4
#define BUTTON_PULLUP_SELECT \
    (PIN_BIT(BUTTON_GPIO_RESET))
#elif BOARD_VERSION == 1
#define BUTTON_PULLUP_SELECT \
    (0)
#endif

// TREATMENT PROCESS
#define TREATMENT_PROCESS_NUM          4
#define TREATMENT_LED_BLINK_RESOLUTION LEDC_TIMER_10_BIT
#define TREATMENT_LED_BLINK_FREQUENCY  1
#define TREATMENT_LED_BLINK_DUTY       512
#ifdef IS_PRODUCTION
#define TREATMENT_PHASE_1_DURATION     55
#define TREATMENT_PHASE_2_DURATION     15
#define TREATMENT_PHASE_3_DURATION     10
#else
#define TREATMENT_PHASE_1_DURATION     2
#define TREATMENT_PHASE_2_DURATION     2
#define TREATMENT_PHASE_3_DURATION     1
#endif

// CONTROLLER
#define CONTROLLER_FILTER_MAX          (CONTROLLER_FILTER_WARN + CONTROLLER_FILTER_TOLERANCE)
#define CONTROLLER_PREFILTER_MAX       (CONTROLLER_PREFILTER_WARN + CONTROLLER_PREFILTER_TOLERANCE)
#ifdef IS_PRODUCTION
#define CONTROLLER_FILTER_WARN         500
#define CONTROLLER_FILTER_TOLERANCE    30
#define CONTROLLER_PREFILTER_WARN      1200
#define CONTROLLER_PREFILTER_TOLERANCE 50
#define CONTROLLER_PREPARE_COOLDOWN    (60 * 60)
#define CONTROLLER_HEAT_UP_DURATION    (3 * 60)
#define CONTROLLER_BLOW_UP_DURATION    15
#else
#define CONTROLLER_FILTER_WARN         8
#define CONTROLLER_FILTER_TOLERANCE    2
#define CONTROLLER_PREFILTER_WARN      12
#define CONTROLLER_PREFILTER_TOLERANCE 3
#define CONTROLLER_PREPARE_COOLDOWN    (3 * 60)
#define CONTROLLER_HEAT_UP_DURATION    20
#define CONTROLLER_BLOW_UP_DURATION    5
#endif

// I2C
#define I2C_SDA_PIN   21
#define I2C_SCL_PIN   22
#define I2C_FREQUENCY 100000

// LCD
#if BOARD_VERSION == 1
#define USE_LCD
#endif
#define LCD_I2C_ADDRESS 0x27
#define LCD_NUM_COLS    16
#define LCD_NUM_ROWS    2

// RTC
#define RTC_I2C_ADDRESS                 0x68
// Add an offset for our timezone CET (UTC+1).
// Note that we ignore daylight saving time, this means today's treatments from
// midnight to 1am are assigned to yesterday - which should not be a problem.
#define RTC_TIMEZONE_OFFSET             1
// Defines a minimum valid year for the RTC time. This is used to detect whether
// the battery is low / has been reset.

// BATTERY
#define BATTERY_MINIMUM_VALID_YEAR      2019
// This defines a number of years after which the device should be maintained, that is,
// after how many years the battery should be replaced and the device re-flashed.
// After this number of years, all LEDs on the device blink 2 times after booting.
#define BATTERY_MAINTENANCE_AFTER_YEARS 10
// see PHP script
#define BATTERY_MAC_FORMAT              "%02X:%02X:%02X"
#define BATTERY_MAC_ARGS(mac)           (mac)[3], (mac)[4], (mac)[5]
#define BATTERY_CODE_ENCODING { \
        ***REMOVED*** \
        ***REMOVED*** \
        ***REMOVED*** \
    }
#define BATTERY_PIN_SALTS { \
        ***REMOVED*** \
		***REMOVED*** \
		"***REMOVED*** \
		***REMOVED*** \
    }

// WIFI
#define WIFI_SETTING_BUF_LEN 48

// WIFI ACCESS POINT
#define WIFI_MAC_FORMAT          "%02X:%02X:%02X:%02X:%02X:%02X"
#define WIFI_MAC_SHORT_FORMAT    "%02X:%02X:%02X"
#define WIFI_MAC_ARGS(mac)       (mac)[0], (mac)[1], (mac)[2], (mac)[3], (mac)[4], (mac)[5]
#define WIFI_MAC_SHORT_ARGS(mac) (mac)[3], (mac)[4], (mac)[5]
#define WIFI_AP_SSID_FORMAT      "Pignap " WIFI_MAC_SHORT_FORMAT
#define WIFI_AP_DEFAULT_PSK      ""
#define WIFI_AP_MAX_CONNECTIONS  5

// WIFI STATION
#define WIFI_STA_HOSTNAME       "pignap"
#define WIFI_STA_DEFAULT_SSID   ""
#define WIFI_STA_DEFAULT_PSK    ""
#define WIFI_STA_MAX_RETRIES    5

// HTTP SERVER
#define HTTP_AUTH_USERNAME ***REMOVED***
#define HTTP_AUTH_PASSWORD ***REMOVED***

// FRAM
#if FRAM_VERSION == 0
#elif FRAM_VERSION == 1
#define USE_FRAM
#define FRAM_MAX_ADDRESS 2048
#define FRAM_PAGE_NUM    8
#elif FRAM_VERSION == 2
#define USE_FRAM
#define FRAM_MAX_ADDRESS 8192
#define FRAM_PAGE_NUM    1
#endif

// OLED
#define OLED_I2C_ADDRESS 0x3c
#define OLED_CONSTRUCTOR u8g2_Setup_ssd1306_i2c_128x64_noname_f
#define OLED_ROTATION    U8G2_R0
#define OLED_WIDTH       128
#define OLED_HEIGHT      64

// DISPLAY
#define DISPLAY_SPLASH_DURATION  2000
#define DISPLAY_MESSAGE_DURATION 4000
#define DISPLAY_WAIT_DURATION    1000
#define DISPLAY_REFRESH_INTERVAL 1000

// MEMORY
#if FRAM_VERSION == 0 || FRAM_VERSION == 1
#define MEM_CELL_NUM                  (365 + 1) // one year + leap day (366 days)
#elif FRAM_VERSION == 2
#define MEM_CELL_NUM                  (3 * 365 + 1) // three years + leap day (1096 days)
#endif
#define MEM_CELL_DEFAULT              0
#define MEM_INDEX_DEFAULT             0
#define MEM_TOTAL_COUNTER_DEFAULT     0
#define MEM_FILTER_COUNTER_DEFAULT    0
#define MEM_PREFILTER_COUNTER_DEFAULT 0
#define MEM_SHUTDOWN_TIME_DEFAULT     0
#define MEM_CELLS_PER_ROW             20
#define MEM_DUMP_LINE_BUF_LEN         128
#define MEM_DUMP_BUF_LEN              10000
#define MEM_CSV_ROW_LEN               20
#define MEM_VIRTUAL_CELL_NUM          180

// HISTORY
#define HISTORY_INVALIDATE_INTERVAL 60

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

// increments the counter, checks if filter is ready
#define CONTROLLER_TASK_CORE_ID    1
#define CONTROLLER_TASK_STACK_SIZE 4096
#define CONTROLLER_TASK_PRIORITY   7

// these two tasks have a higher priority than the default system loop
// to avoid being interrupted during Wifi initialization
// writes to the OLED display
#define DISPLAY_TASK_CORE_ID    0
#define DISPLAY_TASK_STACK_SIZE 4096
#define DISPLAY_TASK_PRIORITY   26

// writes to the LCD display (only on board version 1)
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
#define MAIN_INTERVAL 60

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
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
#define FRAM_VERSION 1
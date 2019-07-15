#ifndef WTIME_H
#define WTIME_H

// see https://github.com/NuxiNL/cloudlibc/blob/master/src/libc/time/

#include <stdint.h>
#include <stdbool.h>

typedef int64_t wtime_t; // "wide time" type (eliminates year 2038 problem with default time_t)

typedef struct {
  int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
  int tm_min;			/* Minutes.	[0-59] */
  int tm_hour;			/* Hours.	[0-23] */
  int tm_mday;			/* Day.		[1-31] */
  int tm_mon;			/* Month.	[0-11] */
  int tm_year;			/* Year	- 1900.  */
  int tm_wday;			/* Day of week.	[0-6] */
  int tm_yday;			/* Days in year.[0-365]	*/
  int tm_isdst;			/* DST.		[-1/0/1]*/
} wtm_t;

inline bool wtime_is_leap(wtime_t year) {
  year %= 400;
  if (year < 0)
    year += 400;
  return ((year % 4) == 0 && (year % 100) != 0) || year == 100;
}

inline const short *wtime_get_months_cumulative(wtime_t year) {
  static const short leap[13] = {
      0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366,
  };
  static const short common[13] = {
      0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365,
  };
  return wtime_is_leap(year) ? leap : common;
}

int wlocaltime(wtime_t timer, wtm_t *tm);
wtime_t wmktime(wtm_t *tm);

#endif
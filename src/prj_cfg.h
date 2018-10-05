#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H

#include "prj_variants.h"
#include <gttc_timer.h>
/////// Platform configuration /////////
#define CYCLE_TIME_IN_MICROS 2000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L

//////// Main Configuration ///////////
#define CTE_BLINK_PERIOD CALC_CYCLE_COUNT_FOR_TIME(1000000)

//////// Debug Configuration ///////////
#define DEBUG_CYCLE_TIME

//#define DEBUG_BLINK

#define DEBUG_BUT

#endif /* _PRJ_CFG_H */

#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H

#include "prj_variants.h"
#include <gttc_timer.h>
/////// Platform configuration /////////
#define CYCLE_TIME_IN_MICROS 1000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L

//////// Main Configuration ///////////

//////// Debug Configuration ///////////
#define DEBUG_CYCLE_TIME
#define DEBUG_BLINK

#ifdef DEBUG_BLINK
#define CTE_BLINK_PERIOD CALC_CYCLE_COUNT_FOR_TIME(1000000)
#endif

#endif /* _PRJ_CFG_H */

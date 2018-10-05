#include "BATModePrj.h"

/**
 Vector with the frontier values for discretization 
 */
uint16_t bat_mode_values[] = {
    BAT_LOW_CAL,
    BAT_DEGRADED_LOW_CAL,
    BAT_NORMAL_CAL,
    BAT_DEGRADED_HIGH_CAL,
    BAT_HIGH_CAL




};


/**
 Vector with the frontier values for discretization, 
 * with hystheresis value applied
 */
uint16_t bat_mode_hyst_values[] = {
    BAT_LOW_HYST_CAL,
    BAT_DEGRADED_LOW_HYST_CAL,
    BAT_NORMAL_HYST_CAL,
    BAT_DEGRADED_HIGH_HYST_CAL,
    BAT_HIGH_HYST_CAL




};


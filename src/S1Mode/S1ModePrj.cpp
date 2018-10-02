#include "S1ModePrj.h"

/**
 Vector with the frontier values for discretization 
 */
uint16_t s1_mode_values[] = {
    S1_LOW_CAL,
    S1_DEGRADED_LOW_CAL,
    S1_NORMAL_CAL,
    S1_DEGRADED_HIGH_CAL,
    S1_HIGH_CAL




};


/**
 Vector with the frontier values for discretization, 
 * with hystheresis value applied
 */
uint16_t s1_mode_hyst_values[] = {
    S1_LOW_HYST_CAL,
    S1_DEGRADED_LOW_HYST_CAL,
    S1_NORMAL_HYST_CAL,
    S1_DEGRADED_HIGH_HYST_CAL,
    S1_HIGH_HYST_CAL




};


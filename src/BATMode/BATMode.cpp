#include "BATMode.h"
#include "../DRE.h"
/**
 Vector with the frontier values for discretization
 */
uint16_t BAT_mode_values[] = {
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
uint16_t BAT_mode_hyst_values[] = {
    BAT_LOW_HYST_CAL,
    BAT_DEGRADED_LOW_HYST_CAL,
    BAT_NORMAL_HYST_CAL,
    BAT_DEGRADED_HIGH_HYST_CAL,
    BAT_HIGH_HYST_CAL




};

extern t_dre dre;
t_timefilter_block BAT_timefilter_block;
t_d1d_block BAT_d1d_block;

void BATModeInit(void) {
    BAT_d1d_block.input = dre.BATSense;
    BAT_d1d_block.num_ranges = (uint8_t) (sizeof (BAT_mode_values) / sizeof (uint16_t));
    BAT_d1d_block.range_values_up = BAT_mode_values;
    BAT_d1d_block.range_values_down = BAT_mode_hyst_values;
    Discretizer1DInit(&BAT_d1d_block);
    BAT_timefilter_block.input = BAT_d1d_block.range_idx;
    BAT_timefilter_block.stability_time = T_BAT_RANGE_STABILITY_TIME;
    TimeFilterInit(&BAT_timefilter_block);
    dre.BATMode = (t_enum_BATMode) BAT_timefilter_block.output;
}

void BATMode(void) {
    BAT_d1d_block.input = dre.BATSense;
    Discretizer1D(&BAT_d1d_block);
    BAT_timefilter_block.input = BAT_d1d_block.range_idx;
    TimeFilter(&BAT_timefilter_block);
    dre.BATMode = (t_enum_BATMode) BAT_timefilter_block.output;
}

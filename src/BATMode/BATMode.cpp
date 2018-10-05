#include "BATMode.h"
#include "../DRE.h"
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

extern t_dre dre;
t_timefilter_block bat_timefilter_block;
t_d1d_block bat_d1d_block;

void BATModeInit(void) {
    bat_d1d_block.input = dre.batSense;
    bat_d1d_block.num_ranges = (uint8_t) (sizeof (bat_mode_values) / sizeof (uint16_t));
    bat_d1d_block.range_values_up = bat_mode_values;
    bat_d1d_block.range_values_down = bat_mode_hyst_values;
    Discretizer1DInit(&bat_d1d_block);
    bat_timefilter_block.input = bat_d1d_block.range_idx;
    bat_timefilter_block.stability_time = T_BAT_RANGE_STABILITY_TIME;
    TimeFilterInit(&bat_timefilter_block);
    dre.batMode = (t_enum_batMode) bat_timefilter_block.output;
}

void BATMode(void) {
    bat_d1d_block.input = dre.batSense;
    Discretizer1D(&bat_d1d_block);
    bat_timefilter_block.input = bat_d1d_block.range_idx;
    TimeFilter(&bat_timefilter_block);
    dre.batMode = (t_enum_batMode) bat_timefilter_block.output;
}
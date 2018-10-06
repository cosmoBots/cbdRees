#include "S1Mode.h"
#include "../DRE.h"
/**
 Vector with the frontier values for discretization
 */
uint16_t S1_mode_values[] = {
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
uint16_t S1_mode_hyst_values[] = {
    S1_LOW_HYST_CAL,
    S1_DEGRADED_LOW_HYST_CAL,
    S1_NORMAL_HYST_CAL,
    S1_DEGRADED_HIGH_HYST_CAL,
    S1_HIGH_HYST_CAL




};

extern t_dre dre;
t_timefilter_block S1_timefilter_block;
t_d1d_block S1_d1d_block;

void S1ModeInit(void) {
    S1_d1d_block.input = dre.S1Sense;
    S1_d1d_block.num_ranges = (uint8_t) (sizeof (S1_mode_values) / sizeof (uint16_t));
    S1_d1d_block.range_values_up = S1_mode_values;
    S1_d1d_block.range_values_down = S1_mode_hyst_values;
    Discretizer1DInit(&S1_d1d_block);
    S1_timefilter_block.input = S1_d1d_block.range_idx;
    S1_timefilter_block.stability_time = T_S1_RANGE_STABILITY_TIME;
    TimeFilterInit(&S1_timefilter_block);
    dre.S1Mode = (t_enum_S1Mode) S1_timefilter_block.output;
}

void S1Mode(void) {
    S1_d1d_block.input = dre.S1Sense;
    Discretizer1D(&S1_d1d_block);
    S1_timefilter_block.input = S1_d1d_block.range_idx;
    TimeFilter(&S1_timefilter_block);
    dre.S1Mode = (t_enum_S1Mode) S1_timefilter_block.output;
}

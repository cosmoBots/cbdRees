#include "S1Mode.h"
#include "../DRE.h"
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

extern t_dre dre;
t_timefilter_block s1_timefilter_block;
t_d1d_block s1_d1d_block;

void S1ModeInit(void) {
    s1_d1d_block.input = dre.s1Sense;
    s1_d1d_block.num_ranges = (uint8_t) (sizeof (s1_mode_values) / sizeof (uint16_t));
    s1_d1d_block.range_values_up = s1_mode_values;
    s1_d1d_block.range_values_down = s1_mode_hyst_values;
    Discretizer1DInit(&s1_d1d_block);
    s1_timefilter_block.input = s1_d1d_block.range_idx;
    s1_timefilter_block.stability_time = T_S1_RANGE_STABILITY_TIME;
    TimeFilterInit(&s1_timefilter_block);
    dre.s1Mode = (t_enum_s1Mode) s1_timefilter_block.output;
}

void S1Mode(void) {
    s1_d1d_block.input = dre.s1Sense;
    Discretizer1D(&s1_d1d_block);
    s1_timefilter_block.input = s1_d1d_block.range_idx;
    TimeFilter(&s1_timefilter_block);
    dre.s1Mode = (t_enum_s1Mode) s1_timefilter_block.output;
}
#include "S1ModePrj.h"

t_d1d_block s1_d1d_block;

void S1Discretizer1DInit(void) {
    s1_d1d_block.num_ranges = (uint8_t) (sizeof (s1_mode_values) / sizeof (uint16_t));
    s1_d1d_block.range_values_up = s1_mode_values;
    s1_d1d_block.range_values_down = s1_mode_hyst_values;
    Discretizer1DInit(&s1_d1d_block);
}

void S1Discretizer1D(void) {
    Discretizer1D(&s1_d1d_block);
}

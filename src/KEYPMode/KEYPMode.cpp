#include "KEYPMode.h"
#include "../DRE.h"

#include "KEYPMode_autogen_c.h"

extern t_dre dre;
t_timefilter_block KEYP_timefilter_block;
t_d1d_block KEYP_d1d_block;

void KEYPModeInit(void) {
    KEYP_d1d_block.input = dre.KEYPSense;
    KEYP_d1d_block.num_ranges = (uint8_t) (sizeof (KEYPMode_values) / sizeof (uint16_t));
    KEYP_d1d_block.range_values_up = KEYPMode_values;
    KEYP_d1d_block.range_values_down = KEYPMode_hyst_values;
    Discretizer1DInit(&KEYP_d1d_block);
    KEYP_timefilter_block.input = KEYP_d1d_block.range_idx;
    KEYP_timefilter_block.stability_time = T_KEYP_RANGE_STABILITY_TIME;
    TimeFilterInit(&KEYP_timefilter_block);
    dre.KEYPMode = (t_enum_KEYPMode) KEYP_timefilter_block.output;
}

void KEYPMode(void) {
    KEYP_d1d_block.input = dre.KEYPSense;
    Discretizer1D(&KEYP_d1d_block);
    KEYP_timefilter_block.input = KEYP_d1d_block.range_idx;
    TimeFilter(&KEYP_timefilter_block);
    dre.KEYPMode = (t_enum_KEYPMode) KEYP_timefilter_block.output;
}

#include "S1ModePrj.h"
#include "../DRE.h"

extern t_dre dre;

void S1ModeSchedulerInit(void)
{
    dre.s1Mode = S1_NORMAL_IDX;
    s1_d1d_block.input = dre.s1Sense;
    S1Discretizer1DInit();
    s1_timefilter_block.input = s1_d1d_block.range_idx;
    S1TimeFilterInit();
    dre.s1Mode = (t_enum_s1Mode) s1_timefilter_block.output;
}

void S1ModeScheduler(void)
{
    s1_d1d_block.input = dre.s1Sense;
    S1Discretizer1D();
    s1_timefilter_block.input = s1_d1d_block.range_idx;
    S1TimeFilter();
    dre.s1Mode = (t_enum_s1Mode) s1_timefilter_block.output;
}

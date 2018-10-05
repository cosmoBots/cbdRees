#include "BATModePrj.h"
#include "../DRE.h"

extern t_dre dre;

void BATModeSchedulerInit(void) {
    dre.batMode = BAT_NORMAL_IDX;
    bat_d1d_block.input = dre.batSense;
    BATDiscretizer1DInit();
    bat_timefilter_block.input = bat_d1d_block.range_idx;
    BATTimeFilterInit();
    dre.batMode = (t_enum_batMode) bat_timefilter_block.output;
}

void BATModeScheduler(void) {
    bat_d1d_block.input = dre.batSense;
    BATDiscretizer1D();
    bat_timefilter_block.input = bat_d1d_block.range_idx;
    BATTimeFilter();
    dre.batMode = (t_enum_batMode) bat_timefilter_block.output;
}

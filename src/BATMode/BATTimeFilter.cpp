#include "BATModePrj.h"

t_timefilter_block bat_timefilter_block;

static void createBATTimefilterContext(void) {
    bat_timefilter_block.stability_time = T_BAT_RANGE_STABILITY_TIME;
    tf_block = &bat_timefilter_block;
}

static void saveBATTimefilterContext(void) {
    tf_block->current_state = getCurrentTimeFilterState();
}

static void restoreBATTimefilterContext(void) {
    tf_block = &bat_timefilter_block;
    setCurrentTimeFilterState(tf_block->current_state);
}

void BATTimeFilterInit(void) {
    createBATTimefilterContext();
    TimeFilterInit();
    saveBATTimefilterContext();
}

void BATTimeFilter(void) {
    restoreBATTimefilterContext();
    TimeFilter();
    saveBATTimefilterContext();
}

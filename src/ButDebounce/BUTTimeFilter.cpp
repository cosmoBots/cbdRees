#include "BUTDebouncePrj.h"

t_timefilter_block but_timefilter_block;

static void createBUTTimefilterContext(void) {
    but_timefilter_block.stability_time = T_BUT_RANGE_STABILITY_TIME;
    tf_block = &but_timefilter_block;
}

static void saveBUTTimefilterContext(void) {
    tf_block->current_state = getCurrentTimeFilterState();
}

static void restoreBUTTimefilterContext(void) {
    tf_block = &but_timefilter_block;
    setCurrentTimeFilterState(tf_block->current_state);
}

void BUTTimeFilterInit(void) {
    createBUTTimefilterContext();
    TimeFilterInit();
    saveBUTTimefilterContext();
}

void BUTTimeFilter(void) {
    restoreBUTTimefilterContext();
    TimeFilter();
    saveBUTTimefilterContext();
}

#include "S1ModePrj.h"

t_timefilter_block s1_timefilter_block;

static void createS1TimefilterContext(void)
{
    s1_timefilter_block.stability_time = T_S1_RANGE_STABILITY_TIME;
    tf_block = &s1_timefilter_block;
}

static void saveS1TimefilterContext(void)
{
    tf_block->current_state = getCurrentTimeFilterState();
}

static void restoreS1TimefilterContext(void)
{
    tf_block = &s1_timefilter_block;
    setCurrentTimeFilterState(tf_block->current_state);
}

void S1TimeFilterInit(void)
{
    createS1TimefilterContext();
    TimeFilterInit();
    saveS1TimefilterContext();
}

void S1TimeFilter(void)
{
        restoreS1TimefilterContext();
        TimeFilter();
        saveS1TimefilterContext();
}

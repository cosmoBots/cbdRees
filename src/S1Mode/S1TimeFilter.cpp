#include "S1ModePrj.h"

t_timefilter_block s1_timefilter_block;

void S1TimeFilterInit(void) {
    s1_timefilter_block.stability_time = T_S1_RANGE_STABILITY_TIME;
    TimeFilterInit(&s1_timefilter_block);
}

void S1TimeFilter(void) {
    TimeFilter(&s1_timefilter_block);
}

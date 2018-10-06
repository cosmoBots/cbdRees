#include "BUTDebounce.h"
#include "../DRE.h"

extern t_dre dre;
t_timefilter_block BUT_timefilter_block;

void BUTDebounceInit(void) {
    BUT_timefilter_block.input = (uint16_t) dre.BUTDI;
    BUT_timefilter_block.stability_time = T_BUT_RANGE_STABILITY_TIME;
    TimeFilterInit(&BUT_timefilter_block);
    dre.BUT = BUT_timefilter_block.output;
}

void BUTDebounce(void) {
    BUT_timefilter_block.input = (uint16_t) dre.BUTDI;
    TimeFilter(&BUT_timefilter_block);
    dre.BUT = BUT_timefilter_block.output;
}

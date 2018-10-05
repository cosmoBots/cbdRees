#include "BUTDebouncePrj.h"
#include "../DRE.h"

extern t_dre dre;

void BUTDebounceSchedulerInit(void) {
    dre.but = HIGH;
    but_timefilter_block.input = (uint16_t) dre.butDI;
    BUTTimeFilterInit();
    dre.but = but_timefilter_block.output;
}

void BUTDebounceScheduler(void) {
    but_timefilter_block.input = (uint16_t) dre.butDI;
    BUTTimeFilter();
    dre.but = but_timefilter_block.output;
}

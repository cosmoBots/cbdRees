#include "BUTDebounce.h"
#include "../DRE.h"

extern t_dre dre;
t_timefilter_block but_timefilter_block;

void BUTDebounceInit(void) {
    dre.but = HIGH;
    but_timefilter_block.input = (uint16_t) dre.butDI;
    but_timefilter_block.stability_time = T_BUT_RANGE_STABILITY_TIME;
    TimeFilterInit(&but_timefilter_block);    
    dre.but = but_timefilter_block.output;
}

void BUTDebounce(void) {
    but_timefilter_block.input = (uint16_t) dre.butDI;
    TimeFilter(&but_timefilter_block);
    dre.but = but_timefilter_block.output;
}

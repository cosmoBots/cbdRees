#include "{$replace}Debounce.h"
#include "../DRE.h"

extern t_dre dre;
t_timefilter_block {$replace}_timefilter_block;

void {$replace}DebounceInit(void) {
    {$replace}_timefilter_block.input = (uint16_t) dre.{$replace}DI;
    {$replace}_timefilter_block.stability_time = T_{$replace}_RANGE_STABILITY_TIME;
    TimeFilterInit(&{$replace}_timefilter_block);
    dre.{$replace} = {$replace}_timefilter_block.output;
}

void {$replace}Debounce(void) {
    {$replace}_timefilter_block.input = (uint16_t) dre.{$replace}DI;
    TimeFilter(&{$replace}_timefilter_block);
    dre.{$replace} = {$replace}_timefilter_block.output;
}

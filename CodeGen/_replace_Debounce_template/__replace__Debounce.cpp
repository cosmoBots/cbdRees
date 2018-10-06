#include "{$replace}Debounce.h"
#include "../DRE.h"

extern t_dre dre;
t_timefilter_block {$replace}_timefilter_block;

void {$replace}DebounceInit(void) {
    {$replace}_timefilter_block.input = dre.{$replace}Raw;
    {$replace}_timefilter_block.stability_time = T_{$replace}_RANGE_STABILITY_TIME;
    TimeFilterInit(&{$replace}_timefilter_block);
    dre.{$replace}Filt = {$replace}_timefilter_block.output;
}

void {$replace}Debounce(void) {
    {$replace}_timefilter_block.input = dre.{$replace}Raw;
    TimeFilter(&{$replace}_timefilter_block);
    dre.{$replace}Filt = {$replace}_timefilter_block.output;
}

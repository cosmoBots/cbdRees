#include "{$replace}Mode.h"
#include "../DRE.h"

#include "{$replace}Mode_autogen_c.h"


extern t_dre dre;
t_timefilter_block {$replace}_timefilter_block;
t_d1d_block {$replace}_d1d_block;

void {$replace}ModeInit(void) {
    {$replace}_d1d_block.input = dre.{$replace}Sense;
    {$replace}_d1d_block.num_ranges = (uint8_t) (sizeof ({$replace}_mode_values) / sizeof (uint16_t));
    {$replace}_d1d_block.range_values_up = {$replace}_mode_values;
    {$replace}_d1d_block.range_values_down = {$replace}_mode_hyst_values;
    Discretizer1DInit(&{$replace}_d1d_block);
    {$replace}_timefilter_block.input = {$replace}_d1d_block.range_idx;
    {$replace}_timefilter_block.stability_time = T_{$replace}_RANGE_STABILITY_TIME;
    TimeFilterInit(&{$replace}_timefilter_block);
    dre.{$replace}Mode = (t_enum_{$replace}Mode) {$replace}_timefilter_block.output;
}

void {$replace}Mode(void) {
    {$replace}_d1d_block.input = dre.{$replace}Sense;
    Discretizer1D(&{$replace}_d1d_block);
    {$replace}_timefilter_block.input = {$replace}_d1d_block.range_idx;
    TimeFilter(&{$replace}_timefilter_block);
    dre.{$replace}Mode = (t_enum_{$replace}Mode) {$replace}_timefilter_block.output;
}

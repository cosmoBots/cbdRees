#include "BATModePrj.h"

t_d1d_block bat_d1d_block;

static void createBATD1dContext(void) {
    bat_d1d_block.num_ranges = (uint8_t) (sizeof (bat_mode_values) / sizeof (uint16_t));
    bat_d1d_block.range_values_up = bat_mode_values;
    bat_d1d_block.range_values_down = bat_mode_hyst_values;
    d1d_block = &bat_d1d_block;
}

static void restoreBATD1dContext(void) {
    d1d_block = &bat_d1d_block;
}

static void saveBATD1dContext(void) {
}

void BATDiscretizer1DInit(void) {
    createBATD1dContext();
    Discretizer1DInit();
    saveBATD1dContext();
}

void BATDiscretizer1D(void) {
    restoreBATD1dContext();
    Discretizer1D();
    saveBATD1dContext();
}

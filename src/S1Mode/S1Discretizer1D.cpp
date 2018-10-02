#include "S1ModePrj.h"

t_d1d_block s1_d1d_block;

static void createS1D1dContext(void)
{
    s1_d1d_block.num_ranges = (uint8_t) (sizeof (s1_mode_values) / sizeof (uint16_t));
    s1_d1d_block.range_values_up = s1_mode_values;
    s1_d1d_block.range_values_down = s1_mode_hyst_values;
    d1d_block = &s1_d1d_block;
}

static void restoreS1D1dContext(void)
{
    d1d_block = &s1_d1d_block;
}

static void saveS1D1dContext(void)
{
}

void S1Discretizer1DInit(void)
{
    createS1D1dContext();
    Discretizer1DInit();
    saveS1D1dContext();
}

void S1Discretizer1D(void)
{
    restoreS1D1dContext();
    Discretizer1D();
    saveS1D1dContext();
}

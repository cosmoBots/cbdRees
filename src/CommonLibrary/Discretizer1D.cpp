#include "CommonLibrary.h"

void Discretizer1DUpRangeInit(void) {

}

void Discretizer1DUpRange(void) {
    uint8_t idx;
    bool found = FALSE;
    for (idx = 1; (found == FALSE) && (idx < (d1d_block->num_ranges)); idx++) {
        if (d1d_block->input < d1d_block->range_values_up[idx]) {
            found = TRUE;
            d1d_block->range_up_idx = idx - 1;
        }
    }
    /* PLEASE NOTE THAT SUCCESS MUST BE GUARANTEED BY DESIGN!!! */
    if (found != TRUE) {
        d1d_block->range_up_idx = (d1d_block->num_ranges) - 1;
    }

}

void Discretizer1DDownRangeInit(void) {

}

void Discretizer1DDownRange(void) {
    uint8_t idx;
    bool found = FALSE;
    for (idx = 1; (found == FALSE) && (idx < (d1d_block->num_ranges)); idx++) {
        if (d1d_block->input < d1d_block->range_values_down[idx]) {
            found = TRUE;
            d1d_block->range_down_idx = idx - 1;
        }
    }
    /* PLEASE NOTE THAT SUCCESS MUST BE GUARANTEED BY DESIGN!!! */
    if (found != TRUE) {
        d1d_block->range_down_idx = (d1d_block->num_ranges) - 1;
    }
}

void Discretizer1DSolverInit(void) {
    /* -- action de la transicio inicial -- */
    d1d_block->range_idx = d1d_block->range_up_idx;
}

void Discretizer1DSolver(void) {
    /* -- entry de l estat Combinational -- */
    /* PLEASE NOTE THAT RANGES MUST GUARANTEE BY DESIGN THAT THIS FUNCTION IS SUCCESSFUL */
    if (d1d_block->range_up_idx == d1d_block->range_down_idx) {
        d1d_block->range_idx = d1d_block->range_up_idx;
    } else {
        if (d1d_block->range_down_idx < d1d_block->range_idx) {
            d1d_block->range_idx = d1d_block->range_down_idx;
        }
        if (d1d_block->range_up_idx > d1d_block->range_idx) {
            d1d_block->range_idx = d1d_block->range_up_idx;
        }
    }
}

void Discretizer1DInit(void) {
    Discretizer1DUpRangeInit();
    Discretizer1DDownRangeInit();
    Discretizer1DSolverInit();
}

void Discretizer1D(void) {
    Discretizer1DUpRange();
    Discretizer1DDownRange();
    Discretizer1DSolver();
}

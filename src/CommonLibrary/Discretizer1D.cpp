#include "CommonLibrary.h"

void Discretizer1DUpRangeInit(t_d1d_block *d1d_block) {

}

void Discretizer1DUpRange(t_d1d_block *d1d_block) {
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

void Discretizer1DDownRangeInit(t_d1d_block *d1d_block) {

}

void Discretizer1DDownRange(t_d1d_block *d1d_block) {
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

void Discretizer1DSolverInit(t_d1d_block *d1d_block) {
    /* -- action de la transicio inicial -- */
    d1d_block->range_idx = d1d_block->range_up_idx;
}

void Discretizer1DSolver(t_d1d_block *d1d_block) {
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

void Discretizer1DInit(t_d1d_block *d1d_block) {
    Discretizer1DUpRangeInit(d1d_block);
    Discretizer1DDownRangeInit(d1d_block);
    Discretizer1DSolverInit(d1d_block);
}

void Discretizer1D(t_d1d_block *d1d_block) {
    Discretizer1DUpRange(d1d_block);
    Discretizer1DDownRange(d1d_block);
    Discretizer1DSolver(d1d_block);
}

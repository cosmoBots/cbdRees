#ifndef COMMON_LIBRARY_H
#define COMMON_LIBRARY_H

#include "../prj_types.h"

/** Type definition for the discretizer block
 */
typedef struct {
    /* Config values */
    uint8_t num_ranges; /*!< Number of ranges to discretize */
    uint16_t *range_values_up; /*!< Frontiers for changing current range to upper range */
    uint16_t *range_values_down; /*!< Frontiers for changing current range to lower range */
    /* Input value */
    uint16_t input; /*!< Input variable to discretize */
    /* Product values */
    uint8_t range_up_idx; /*!< Result of the discretization against upper frontiers in range_values_up */
    uint8_t range_down_idx; /*!< Result of the discretization against lower frontiers in range_values_down */
    /* Output value */
    uint8_t range_idx; /*!< Result of the discretization */
} t_d1d_block;


typedef enum {
    STATE_TIMEFILTER_NOTCHANGEDETECTED = 1,
    STATE_TIMEFILTER_CHANGEDETECTED = 2,
    STATE_0_TIMEFILTER = 0
} t_state_timefilter;

/**
 Type definition for the time filter block */
typedef struct {
    /* Config values */
    uint16_t stability_time; /*!< Filter time */
    /* Input value */
    uint16_t input; /*!< Input variable to filter */
    /* Product values */
    uint8_t current_state; /*!< Internal state of the FSM */
    uint16_t time; /*!< Internal time of the FSM */
    uint16_t new_value_detected; /*!< In the case a new value appears, it is stored here */
    /* Output value */
    uint16_t output; /*!< The filtered variable */
    t_state_timefilter state;
} t_timefilter_block;

typedef enum {
    STATE_FLAGQUALIFIER_NOTQUALIFIED = 1,
    STATE_FLAGQUALIFIER_QUALIFIED = 2,
    STATE_0_FLAGQUALIFIER = 0
} t_state_flagqualifier;

/**
 Type definition for the flag qualifier block */
typedef struct {
    /* Config values */
    uint16_t qualify_time; /*!< Qualification time */
    uint16_t heal_time; /*!< Healing time */
    /* Input value */
    bool input; /*!< Input variable to filter */
    /* Product values */
    uint8_t current_state; /*!< Internal state of the FSM */
    uint16_t time; /*!< Internal time of the FSM */
    /* Output value */
    bool output; /*!< The filtered variable */
    t_state_flagqualifier state;
} t_flagqualifier_block;

/**** FSM includes ****/
/** Discretizer1D API **/
void Discretizer1DInit(t_d1d_block *d1d_block);
void Discretizer1D(t_d1d_block *d1d_block); /*!< Discretizes one variable into ranges, using upper and lower frontier vectors */
void Discretizer1DUpRangeInit(t_d1d_block *d1d_block);
void Discretizer1DUpRange(t_d1d_block *d1d_block); /*!< Discretizes one variable into ranges using upper vector */
void Discretizer1DDownRangeInit(t_d1d_block *d1d_block);
void Discretizer1DDownRange(t_d1d_block *d1d_block); /*!< Discretizes one variable into ranges using lower vector */
void Discretizer1DSolverInit(t_d1d_block *d1d_block);
void Discretizer1DSolver(t_d1d_block *d1d_block); /*!< Solves conflicts between upper and lower discretizations */

/** TimeFilter API **/
void TimeFilterInit(t_timefilter_block *tf_block);
void TimeFilter(t_timefilter_block *tf_block); /*!< Filterss one variable in time */

/** FlagQualifier API **/
void FlagQualifierInit(t_flagqualifier_block *fq_block);
void FlagQualifier(t_flagqualifier_block *fq_block); /*!< Filterss one variable in time */

#endif /* COMMONLIBRARY_H */

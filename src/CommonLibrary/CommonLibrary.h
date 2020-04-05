/**
 * CommonLibrary include some software modules designed to perform common actions
 * in embedded systems applications, such as discretizing a continuous value in some ranges
 * (called modes) or debouncing a signal.
 * Please take into consideration that, for safety, you should not use the same basic 
 * functionality at several places, because if this basic functionality is corrupted
 * all the features using it will fail.
 * You can use mechanisms for replicating these functions source code so each functionality
 * is using its own discretizer, debouncer.
 * A recommended guideline is this: 
 * * if your application requirements do not include safety, use this library to save 
 *   memory and eeprom, as is.
 * * if your application requirements include safety, use this library only for not safety
 * * related features, and use it for safety related ones BUT ONLY DURING R+D PHASE, BECAUSE
 * * IT IS FASTER AND MORE COMFORTABLE, BUT THE USE OF IT MUST NOT ARRIVE TO PRODUCTION EVER.
 */ 
#ifndef COMMON_LIBRARY_H
#define COMMON_LIBRARY_H

#include "../prj_types.h"

/** A little introduction to these modules
 * In order to use this code to implement several featrues of your application, you have to 
 * configure a "block" record per use.  This block record contains 
 * all the input and output values, and also some supporting variables (like the time counters)
 * which will be used by the internal FSMs of the CommonLibrary functions.
 * You can easily understand the concept thinking that the CommonLibrary function is a 
 * videogames console unit, and the block is the videogame cartridge, so you use always 
 * the same videogames console unit, but you can play several games simply changing the 
 * active videogames cartridge.
 * Using a mechanism similar to the context change of multiprocessing, you should
 * call the CommonLibrary functions passing the block to be used */

/////////////// COMMONLIBRARY FUNCTIONS ///////////////////
/** 
 * Currently, the CommonLibrary functions (or modules) include:
 * - Discretizer1D: having one uint16_t input, an having some ranges defined by some
 *     frontier values, the module output is the range identifier where 
 *     the input value is included in.  Does not filter, in an application like a debouncer
 *     or a mode selector, the discretizer output is commonly connected to the input of a 
 *     TimeFilter function.
 * - TimeFilter: having one uint16_t input and some filtering parameters, the output is 
 *     the filtered value.
 * - FlagQualifier: In some cases a flag must be protected from spurious activations.  This is
 *     the case of alarms or autodiagnostics flags.  The input flag (f.i. the detection of a 
 *     low voltage value) must be present during a certain time to be "qualified" (f.i. half a 
 *     second) and then, the output qualified flag is raised.  FlagQualifier takes the unqualified
 *     flag as input and generates a qualified one as output, using the qualification time 
 *     as a parameter */

///////// DISCRETIZER1D ////////////

/** 
 * States for the TimeFilter function FSM
 */ 
/* THIS FUNCTION DOES NOT USE AN INTERNAL FSM, NO STATES NEEDED */

/** 
 * Type definition for the discretizer block
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

/** Discretizer1D API **/
/** WARNING: The user must provide the block with correctly set range_values_up and range_values_down
 * vectors.   These vectors have to be correctly set, ensuring all the possible values of the 
 * uint16_t input (from 0 to 2^16) fit in one of the ranges. The function is not responsible of
 * working if the given ranges are wrong.
 */
void Discretizer1DInit(t_d1d_block *d1d_block);
void Discretizer1D(t_d1d_block *d1d_block); /*!< Discretizes one variable into ranges, using upper and lower frontier vectors */

///////// TIMEFILTER ////////////
/** 
 * States for the TimeFilter function FSM
 */ 
 typedef enum {
    STATE_TIMEFILTER_NOTCHANGEDETECTED = 1,
    STATE_TIMEFILTER_CHANGEDETECTED = 2,
    STATE_0_TIMEFILTER = 0
} t_state_timefilter;

/**
 Type definition for the time filter block 
*/
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

/** TimeFilter API **/
void TimeFilterInit(t_timefilter_block *tf_block);
void TimeFilter(t_timefilter_block *tf_block); /*!< Filterss one variable in time */


///////// FLAGQUALIFIER ////////////
/** 
 * States for the FlagQualifier function FSM
 */ 
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


/** FlagQualifier API **/
void FlagQualifierInit(t_flagqualifier_block *fq_block);
void FlagQualifier(t_flagqualifier_block *fq_block); /*!< Filterss one variable in time */

#endif /* COMMONLIBRARY_H */

#ifndef S1_MODE_H
#define S1_MODE_H

#include "../CommonLibrary/CommonLibrary.h"

#include "S1Mode_autogen.h"

/*!< Time to filter the appearance of a new mode */
#define T_S1_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  

/**** FSM includes ****/
void S1ModeInit(void);
void S1Mode(void); /*!< Manager that commands the mode detection */

#endif /* S1_MODE_H */

#ifndef KEYP_MODE_H
#define KEYP_MODE_H

#include "../CommonLibrary/CommonLibrary.h"

#include "KEYPMode_autogen.h"

/*!< Time to filter the appearance of a new mode */
#define T_KEYP_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000*5))  

/**** FSM includes ****/
void KEYPModeInit(void);
void KEYPMode(void); /*!< Manager that commands the mode detection */


#endif /* KEYP_MODE_H */

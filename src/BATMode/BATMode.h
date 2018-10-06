#ifndef BAT_MODE_H
#define BAT_MODE_H

#include "../CommonLibrary/CommonLibrary.h"

#include "BATMode_autogen.h"

/*!< Time to filter the appearance of a new mode */
#define T_BAT_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  

/**** FSM includes ****/
void BATModeInit(void);
void BATMode(void); /*!< Manager that commands the mode detection */


#endif /* BAT_MODE_H */

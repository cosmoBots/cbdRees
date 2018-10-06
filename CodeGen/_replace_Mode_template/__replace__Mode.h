#ifndef {$replace}_MODE_H
#define {$replace}_MODE_H

#include "../CommonLibrary/CommonLibrary.h"

#include "{$replace}Mode_autogen.h"

/*!< Time to filter the appearance of a new mode */
#define T_{$replace}_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  

/**** FSM includes ****/
void {$replace}ModeInit(void);
void {$replace}Mode(void); /*!< Manager that commands the mode detection */


#endif /* {$replace}_MODE_H */

#ifndef {$replace}_DEBOUNCE_H
#define {$replace}_DEBOUNCE_H

#include "../CommonLibrary/CommonLibrary.h"

void {$replace}DebounceInit(void);
void {$replace}Debounce(void); /*!< Manager that commands the mode detection */

/*** Manually added definitions ***/
#define T_{$replace}_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  /*!< Time to filter the appearance of a new mode */

#endif /* {$replace}_DEBOUNCE_H */

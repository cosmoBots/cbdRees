#ifndef BUT_DEBOUNCE_H
#define BUT_DEBOUNCE_H

#include "../CommonLibrary/CommonLibrary.h"

void BUTDebounceInit(void);
void BUTDebounce(void); /*!< Manager that commands the mode detection */

/*** Manually added definitions ***/
#define T_BUT_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  /*!< Time to filter the appearance of a new mode */

#endif /* BUT_DEBOUNCE_H */

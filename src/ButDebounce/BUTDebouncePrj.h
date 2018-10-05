#ifndef BUT_DEBOUNCE_PRJ_H
#define BUT_DEBOUNCE_PRJ_H

#include "../CommonLibrary/CommonLibrary.h"

void BUTTimeFilterInit(void);
void BUTTimeFilter(void); /*!< Function that filters a value in time */
void BUTDebounceSchedulerInit(void);
void BUTDebounceScheduler(void); /*!< Manager that commands the mode detection */

/*** Manually added definitions ***/
#define T_BUT_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  /*!< Time to filter the appearance of a new mode */

extern t_timefilter_block but_timefilter_block; /*!< Block to allow time filter to be "retargetable" */


#endif /* BUT_DEBOUNCE_PRJ_H */

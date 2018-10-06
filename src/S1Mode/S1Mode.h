#ifndef S1_MODE_H
#define S1_MODE_H

#include "../CommonLibrary/CommonLibrary.h"

/**** Code generated from specification spreadsheet ****/


/*               _________________________________*/
/*          -----|                                */
/*          -----|          HIGH                  */
/*          18,5v| - - - - - - - - - - - - - - -  */
/*          18,4v| - - - - - - - - - - - - - - -  */
/*          -----|                                */
/*          -----|          DEGRADED_HIGH         */
/*          16,5v| - - - - - - - - - - - - - - -  */
/*          16,4v| - - - - - - - - - - - - - - -  */
/*          -----|                                */
/*          -----|          NORMAL                */
/*           7,5v| - - - - - - - - - - - - - - -  */
/*           7,4v| - - - - - - - - - - - - - - -  */
/*          -----|                                */
/*          -----|          DEGRADED_LOW          */
/*           6,5v| - - - - - - - - - - - - - - -  */
/*           6,4v| - - - - - - - - - - - - - - -  */
/*          -----|                                */
/*          -----|          LOW                   */
/*          -----|                                */
/*           0,0v|________________________________*/

#ifdef MICRO_5V

#define S1_LOW_CAL                              ((uint16_t)0x0000)      /* 0V 0 adc 0 Vadc */
#define S1_DEGRADED_LOW_CAL                     ((uint16_t)0x028F)      /* 6,5V 655 adc 0,799 Vadc */
#define S1_NORMAL_CAL                           ((uint16_t)0x02FE)      /* 7,5V 766 adc 0,935 Vadc */
#define S1_DEGRADED_HIGH_CAL                    ((uint16_t)0x0670)      /* 16,5V 1648 adc 2,012 Vadc */
#define S1_HIGH_CAL                             ((uint16_t)0x06EB)      /* 18,5V 1771 adc 2,162 Vadc */

#define S1_LOW_HYST_CAL                         ((uint16_t)0x0000)      /* -0,1V 0 adc 0 Vadc */
#define S1_DEGRADED_LOW_HYST_CAL                ((uint16_t)0x0283)      /* 6,4V 643 adc 0,785 Vadc */
#define S1_NORMAL_HYST_CAL                      ((uint16_t)0x02F2)      /* 7,4V 754 adc 0,92 Vadc */
#define S1_DEGRADED_HIGH_HYST_CAL               ((uint16_t)0x066A)      /* 16,4V 1642 adc 2,005 Vadc */
#define S1_HIGH_HYST_CAL                        ((uint16_t)0x06E6)      /* 18,4V 1766 adc 2,156 Vadc */

#else
#define S1_LOW_CAL                              ((uint16_t)0x0000)      /* 0V 0 adc 0 Vadc */
#define S1_DEGRADED_LOW_CAL                     ((uint16_t)0x03E0)      /* 6,5V 992 adc 0,799 Vadc */
#define S1_NORMAL_CAL                           ((uint16_t)0x0489)      /* 7,5V 1161 adc 0,935 Vadc */
#define S1_DEGRADED_HIGH_CAL                    ((uint16_t)0x09C1)      /* 16,5V 2497 adc 2,012 Vadc */
#define S1_HIGH_CAL                             ((uint16_t)0x0A7C)      /* 18,5V 2684 adc 2,162 Vadc */

#define S1_LOW_HYST_CAL                         ((uint16_t)0x0000)      /* -0,1V 0 adc 0 Vadc */
#define S1_DEGRADED_LOW_HYST_CAL                ((uint16_t)0x03CF)      /* 6,4V 975 adc 0,785 Vadc */
#define S1_NORMAL_HYST_CAL                      ((uint16_t)0x0477)      /* 7,4V 1143 adc 0,92 Vadc */
#define S1_DEGRADED_HIGH_HYST_CAL               ((uint16_t)0x09B9)      /* 16,4V 2489 adc 2,005 Vadc */
#define S1_HIGH_HYST_CAL                        ((uint16_t)0x0A74)      /* 18,4V 2676 adc 2,156 Vadc */

#endif

/**
 Typedef for enumerating S1 modes */
typedef enum {
    S1_LOW_IDX,
    S1_DEGRADED_LOW_IDX,
    S1_NORMAL_IDX,
    S1_DEGRADED_HIGH_IDX,
    S1_HIGH_IDX




} t_enum_S1Mode;

/**** FSM includes ****/
void S1ModeInit(void);
void S1Mode(void); /*!< Manager that commands the mode detection */

/*** Manually added definitions ***/
#define T_S1_RANGE_STABILITY_TIME ((uint16_t)CALC_CYCLE_COUNT_FOR_TIME(50000))  /*!< Time to filter the appearance of a new mode */

#endif /* S1_MODE_H */

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

#define {$replace}_LOW_CAL                              ((uint16_t)0x0000)      /* 0V 0 adc 0 Vadc */
#define {$replace}_DEGRADED_LOW_CAL                     ((uint16_t)0x03E0)      /* 6,5V 992 adc 0,799 Vadc */
#define {$replace}_NORMAL_CAL                           ((uint16_t)0x0489)      /* 7,5V 1161 adc 0,935 Vadc */
#define {$replace}_DEGRADED_HIGH_CAL                    ((uint16_t)0x09C1)      /* 16,5V 2497 adc 2,012 Vadc */
#define {$replace}_HIGH_CAL                             ((uint16_t)0x0A7C)      /* 18,5V 2684 adc 2,162 Vadc */

#define {$replace}_LOW_HYST_CAL                         ((uint16_t)0x0000)      /* -0,1V 0 adc 0 Vadc */
#define {$replace}_DEGRADED_LOW_HYST_CAL                ((uint16_t)0x03CF)      /* 6,4V 975 adc 0,785 Vadc */
#define {$replace}_NORMAL_HYST_CAL                      ((uint16_t)0x0477)      /* 7,4V 1143 adc 0,92 Vadc */
#define {$replace}_DEGRADED_HIGH_HYST_CAL               ((uint16_t)0x09B9)      /* 16,4V 2489 adc 2,005 Vadc */
#define {$replace}_HIGH_HYST_CAL                        ((uint16_t)0x0A74)      /* 18,4V 2676 adc 2,156 Vadc */

/**
 Typedef for enumerating {$replace} modes */
typedef enum {
    {$replace}_LOW_IDX,
    {$replace}_DEGRADED_LOW_IDX,
    {$replace}_NORMAL_IDX,
    {$replace}_DEGRADED_HIGH_IDX,
    {$replace}_HIGH_IDX




} t_enum_{$replace}Mode;

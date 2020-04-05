/**** Code generated from specification spreadsheet ****/


 /*          -----_________________________________*/
 /*          -----|                                */
 /*          -----|          EMGCY_HIGH            */
 /*          -----|                                */
 /*          16,0v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          NORMAL                */
 /*          -----|                                */
 /*          12,1v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          LOW                   */
 /*          -----|                                */
 /*          11,9v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          EMGCY_LOW             */
 /*          -----|                                */
 /*           0,0v|________________________________*/


#define BAT_EMGCY_LOW_CAL                        ((uint16_t)0x0000)      /* 0V 0 adc 0 Vadc */
#define BAT_LOW_CAL                              ((uint16_t)0x0985)      /* 11.9V 2437 adc 2.975 Vadc */
#define BAT_NORMAL_CAL                           ((uint16_t)0x09AE)      /* 12.1V 2478 adc 3.025 Vadc */
#define BAT_EMGCY_HIGH_CAL                       ((uint16_t)0x0CCD)      /* 16V 3277 adc 4 Vadc */

#define BAT_EMGCY_LOW_HYST_CAL                   ((uint16_t)0x0000)      /* -0.05V 0 adc 0 Vadc */
#define BAT_LOW_HYST_CAL                         ((uint16_t)0x097B)      /* 11.85V 2427 adc 2.962 Vadc */
#define BAT_NORMAL_HYST_CAL                      ((uint16_t)0x09A4)      /* 12.05V 2468 adc 3.012 Vadc */
#define BAT_EMGCY_HIGH_HYST_CAL                  ((uint16_t)0x0CC3)      /* 15.95V 3267 adc 3.987 Vadc */

/**
 Typedef for enumerating BAT modes */
typedef enum {
BAT_EMGCY_LOW_IDX,
BAT_LOW_IDX,
BAT_NORMAL_IDX,
BAT_EMGCY_HIGH_IDX
} t_enum_BATMode;



typedef enum {
BAT_EMGCY_LOW_HYST_IDX,
BAT_LOW_HYST_IDX,
BAT_NORMAL_HYST_IDX,
BAT_EMGCY_HIGH_HYST_IDX
} t_enum_BATMode_hyst;


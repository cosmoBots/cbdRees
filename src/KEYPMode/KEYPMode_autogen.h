/**** Code generated from specification spreadsheet ****/

 /*               _________________________________*/
 /*          -----|                                */
 /*          -----|          NONE                  */
 /*           4.2v| - - - - - - - - - - - - - - -  */                    
 /*           4.0v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          SELECT                */
 /*           3.2v| - - - - - - - - - - - - - - -  */                    
 /*           3.0v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          LEFT                  */
 /*           2.2v| - - - - - - - - - - - - - - -  */                    
 /*           2.0v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          DOWN                  */
 /*           1.2v| - - - - - - - - - - - - - - -  */                    
 /*           1.0v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          UP                    */
 /*           0.2v| - - - - - - - - - - - - - - -  */                    
 /*           0.0v| - - - - - - - - - - - - - - -  */
 /*          -----|                                */
 /*          -----|          RIGHT                 */
 /*          -----|                                */
 /*           0,0v|________________________________*/



#define KEYP_RIGHT_CAL                           ((uint16_t)0x0000)      /* 0V 0 adc 0 Vadc */
#define KEYP_UP_CAL                              ((uint16_t)0x0032)      /* 0.244379276637341V 50 adc 0.244 Vadc */
#define KEYP_DOWN_CAL                            ((uint16_t)0x00FA)      /* 1.22189638318671V 250 adc 1.221 Vadc */
#define KEYP_LEFT_CAL                            ((uint16_t)0x01C2)      /* 2.19941348973607V 450 adc 2.199 Vadc */
#define KEYP_SELECT_CAL                          ((uint16_t)0x028B)      /* 3.17693059628543V 651 adc 3.176 Vadc */
#define KEYP_NONE_CAL                            ((uint16_t)0x0353)      /* 4.1544477028348V 851 adc 4.154 Vadc */

#define KEYP_RIGHT_HYST_CAL                      ((uint16_t)0x0000)      /* -0.2V 0 adc 0 Vadc */
#define KEYP_UP_HYST_CAL                         ((uint16_t)0x0009)      /* 0.0443792766373412V 9 adc 0.044 Vadc */
#define KEYP_DOWN_HYST_CAL                       ((uint16_t)0x00D1)      /* 1.02189638318671V 209 adc 1.021 Vadc */
#define KEYP_LEFT_HYST_CAL                       ((uint16_t)0x0199)      /* 1.99941348973607V 409 adc 1.999 Vadc */
#define KEYP_SELECT_HYST_CAL                     ((uint16_t)0x0262)      /* 2.97693059628543V 610 adc 2.976 Vadc */
#define KEYP_NONE_HYST_CAL                       ((uint16_t)0x032A)      /* 3.9544477028348V 810 adc 3.954 Vadc */

/**
 Typedef for enumerating KEYP modes */
typedef enum {
    KEYP_RIGHT_IDX,
    KEYP_UP_IDX,
    KEYP_DOWN_IDX,
    KEYP_LEFT_IDX,
    KEYP_SELECT_IDX,
    KEYP_NONE_IDX
} t_enum_KEYPMode;

typedef enum {
    KEYP_RIGHT_HYST_IDX,
    KEYP_UP_HYST_IDX,
    KEYP_DOWN_HYST_IDX,
    KEYP_LEFT_HYST_IDX,
    KEYP_SELECT_HYST_IDX,
    KEYP_NONE_HYST_IDX
} t_enum_KEYPMode_hyst;

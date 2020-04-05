/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include <stdio.h>
#include <stdlib.h>
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
#include "../prj_cfg.h"
#include "../DRE.h"
#include "SerialCmd.h"

extern t_dre dre;
extern t_diag diag;
/* ['Common declarations for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' declarations */
/* ['Common declarations for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */

/* ['Common declarations for 'State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* State ID data type */
typedef unsigned long STATE_T;

/* Declaration of code items used in state charts */
/*!
 * \brief Process a system command coming from the serial line.
 */
void process_led_cmd(  );
/* ['Common declarations for 'State Chart generator'' end (DON'T REMOVE THIS LINE!)] */

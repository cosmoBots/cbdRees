/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "SerialCmdFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['Common definitions for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' definitions */
/* ['Common definitions for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */

/* ['Common definitions for 'State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Code items' definitions */
void process_led_cmd(  )
{
    /* ['<global>::process_led_cmd' begin] */
    /* This actuates over the diagnostics layer to switch on and
    off the led */
    diag.enable_ledStatus = atoi(&(dre.cmd_storage[dre.cmd_base][1]));;
    diag.ledStatus = atoi(&(dre.cmd_storage[dre.cmd_base][2]));
    /* ['<global>::process_led_cmd' end] */
}
/* ['Common definitions for 'State Chart generator'' end (DON'T REMOVE THIS LINE!)] */

/**
 * This code implements the typical and simple task of reading 
 * the inputs from the ports, and storing them at the DRE
 * for normal input flows
 */

#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

/* DRE structure to write the read values to */
extern t_dre dre;

/* Diagnostic DRE structure, if needed */
#ifdef _DIAG_ACTIVE
extern t_diag diag;
#endif

/* Initialization of input flows */
void prjInputInit(void) {
    setup_KEYPSense();
    setup_BATSense();
    setup_BUTRaw();
}

/* Spin function to read input flows */
void prjInput(void) {
    acquire_KEYPSense();
    acquire_BATSense();
    acquire_BUTRaw();
}

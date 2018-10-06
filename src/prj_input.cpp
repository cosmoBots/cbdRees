#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

extern t_dre dre;

#ifdef _DIAG_ACTIVE
extern t_diag diag;
#endif

void prjInputInit(void) {
    setup_S1Sense();
    setup_BATSense();
    setup_BUTRaw();
}

void prjInput(void) {
    acquire_S1Sense();
    acquire_BATSense();
    acquire_BUTRaw();
}

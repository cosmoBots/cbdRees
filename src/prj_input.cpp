#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

extern t_dre dre;
extern t_diag diag;

void prjInputInit(void) {
    setup_s1Sense();
}

void prjInput(void) {
    acquire_s1Sense();
}

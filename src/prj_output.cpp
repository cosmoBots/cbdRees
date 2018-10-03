#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

extern t_dre dre;

void prjOutputInit(void) {
    setup_ledStatus();
}

void prjOutput(void) {
    synthesize_ledStatus();
}

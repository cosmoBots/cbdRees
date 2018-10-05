#include "DRE.h"
#include "prj_pinout.h"

// --- DRE data structure declaration ---
t_dre dre;


/// Inputs

void setup_s1Sense(void) {
    pinMode(PORT_s1Sense, INPUT);
};

void acquire_s1Sense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_s1Sense == TRUE) {
        dre.s1Sense = diag.s1Sense;
    } else {
#endif
        dre.s1Sense = analogRead(PORT_s1Sense);
#ifdef _DIAG_ACTIVE
    }
#endif
}
void setup_batSense(void) {
    pinMode(PORT_batSense, INPUT);
};

void acquire_batSense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_batSense == TRUE) {
        dre.s1Sense = diag.batSense;
    } else {
#endif
        dre.batSense = analogRead(PORT_batSense);
#ifdef _DIAG_ACTIVE
    }
#endif
}
/// Internals

void setup_s1Mode(void) {
    dre.s1Mode = S1_NORMAL_IDX;
}
void setup_batMode(void) {
    dre.batMode = BAT_NORMAL_IDX;
}
/// Outputs

void setup_ledStatus(void) {
    pinMode(PORT_ledStatus, OUTPUT);
}

void synthesize_ledStatus(void) {
    bool aux;
#ifdef _DIAG_ACTIVE
    if (diag.enable_ledStatus == TRUE) {
        aux = diag.ledStatus;
    } else {
#endif
        aux = dre.ledStatus;
#ifdef _DIAG_ACTIVE
    }
#endif
    digitalWrite(PORT_ledStatus, aux);
};

void dreInit(void) {
    setup_s1Mode();
    setup_batMode();
}

#include "prj_cfg.h"
#include "DRE.h"
#include "prj_pinout.h"

// --- DRE data structure declaration ---
t_dre dre;
#ifdef _DIAG_ACTIVE
t_diag diag;
#endif


/// Inputs

void setup_s1Sense(void) {
    pinMode(PORT_s1Sense, INPUT);
};

void acquire_s1Sense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_s1Sense) {
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
    if (diag.enable_batSense) {
        dre.s1Sense = diag.batSense;
    } else {
#endif
        dre.batSense = analogRead(PORT_batSense);
#ifdef _DIAG_ACTIVE
    }
#endif
}

void setup_butDI(void) {
    pinMode(PORT_butDI, INPUT_PULLUP);
};

void acquire_butDI(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_butDI) {
        dre.butDI = diag.butDI;
    } else {
#endif
        dre.butDI = (digitalRead(PORT_butDI) == LOW);
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

void setup_but(void) {
    dre.but = false;
}


/// Outputs

void setup_ledStatus(void) {
    pinMode(PORT_ledStatus, OUTPUT);
}


/* Note: the status led can be used to debug the button Input or the
program cycle (using a blink function).  Definitions DEBUG_BUT and
DEBUG_BLINK override the normal behaviour.  In normal mode, the led
follows the ledStatus DRE variable */
void synthesize_ledStatus(void) {
#ifdef DEBUG_BUT
    digitalWrite(PORT_ledStatus, dre.but);
#else
#ifdef DEBUG_BLINK
    digitalWrite(PORT_ledStatus, dre.blink.led);
#else
    bool aux;
#ifdef _DIAG_ACTIVE
    if (diag.enable_ledStatus) {
        aux = diag.ledStatus;
    } else {
#endif
        aux = dre.ledStatus;
#ifdef _DIAG_ACTIVE
    }
#endif
    digitalWrite(PORT_ledStatus, aux);
#endif
#endif
};


/// Structure initialization

void dreInit(void) {
    setup_s1Mode();
    setup_batMode();
    setup_but();
}

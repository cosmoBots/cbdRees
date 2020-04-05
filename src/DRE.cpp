#include "prj_cfg.h"
#include "DRE.h"
#include "prj_pinout.h"

// --- DRE data structure declaration ---
t_dre dre;
#ifdef _DIAG_ACTIVE
t_diag diag;
#endif

/// Inputs


void setup_BATSense(void) {
    pinMode(PORT_BATSense, INPUT);
};

void acquire_BATSense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_BATSense) {
        dre.BATSense = diag.BATSense;
    } else {
#endif
        dre.BATSense = analogRead(PORT_BATSense);
#ifdef _DIAG_ACTIVE
    }
#endif
}

void setup_BUTRaw(void) {
    pinMode(PORT_BUTRaw, INPUT_PULLUP);
};

void acquire_BUTRaw(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_BUTRaw) {
        dre.BUTRaw = diag.BUTRaw;
    } else {
#endif
        dre.BUTRaw = (digitalRead(PORT_BUTRaw) == LOW);
#ifdef _DIAG_ACTIVE
    }
#endif
}

#ifdef CFG_USE_UNO_LCD1602_KEYPAD
void setup_KEYPMode(void) {
    dre.KEYPMode = KEYP_NONE_IDX;
}
void setup_KEYPSense(void) {
    pinMode(PIN_KEYPSense,INPUT);
}

void acquire_KEYPSense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_KEYPSense) {
        dre.KEYPSense = diag.KEYPSense;
    } else {
#endif
        dre.KEYPSense = analogRead(PIN_KEYPSense);      // read the value from the sensor

#ifdef _DIAG_ACTIVE
    }
#endif
}
#endif
/// Internals

void setup_BATMode(void) {
    dre.BATMode = BAT_NORMAL_IDX;
}

void setup_BUTFilt(void) {
    dre.BUTFilt = false;
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
    digitalWrite(PORT_ledStatus, dre.BUTFilt);
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
    if (aux){
        digitalWrite(PORT_ledStatus, LOW);
    } else {
        digitalWrite(PORT_ledStatus, HIGH);
    }
#endif
#endif
};


/// Structure initialization

void dreInit(void) {
    dre.ledStatus = false;
    dre.blink.led = false;
    dre.blink.timer = 0;
    dre.emgcy_timer = 0;
    dre.emgcy_button = false;
    dre.emgcy_action = false;
    dre.ovr_emgcy_action = false;
    dre.cmd_emgcy_action = false;
#ifdef CFG_USE_UNO_LCD1602_KEYPAD    
    setup_KEYPMode();
#endif
    setup_BATMode();
    setup_BUTFilt();
}
void diagInit(void) {
    diag.blink.enable_led = false;
    diag.blink.led = false;
    diag.blink.enable_timer = false;
    diag.blink.timer = 0;

    diag.ledStatus = false;
    diag.enable_ledStatus = false;

    diag.enable_KEYPSense = false;
    diag.KEYPSense = 0;
    diag.enable_KEYPMode = false;
    diag.KEYPMode = KEYP_NONE_IDX;
}


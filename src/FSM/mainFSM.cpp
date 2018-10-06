/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "mainFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['Sample' begin (DON'T REMOVE THIS LINE!)] */
void Sample() {
    /* set initial state */
    static STATE_T state = ID_SAMPLE_INITIAL;

    switch (state) {
            /* State ID: ID_SAMPLE_INITIAL */
        case ID_SAMPLE_INITIAL:
        {
            /* Transition ID: ID_SAMPLE_TRANSITION_CONNECTION */
            state = ID_SAMPLE_ALWAYS;
            break;
        }
            /* State ID: ID_SAMPLE_ALWAYS */
        case ID_SAMPLE_ALWAYS:
        {
            /* Transition ID: ID_SAMPLE_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::genLedStatus' begin] */
            dre.ledStatus = (dre.BATMode != BAT_NORMAL_IDX);
            /* ['<global>::genLedStatus' end] */
            break;
        }
    }
}
/* ['Sample' end (DON'T REMOVE THIS LINE!)] */

/* ['Blink' begin (DON'T REMOVE THIS LINE!)] */
void Blink() {
    /* set initial state */
    static STATE_T state = ID_BLINK_INITIAL;

    switch (state) {
            /* State ID: ID_BLINK_INITIAL */
        case ID_BLINK_INITIAL:
        {
            /* Transition ID: ID_BLINK_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::ledOff' begin] */
            dre.blink.led = false;
            /* ['<global>::ledOff' end] */
            /* ['<global>::rstBlinkTimer' begin] */
            dre.blink.timer = 0;
            /* ['<global>::rstBlinkTimer' end] */
            state = ID_BLINK_OFF;
            break;
        }
            /* State ID: ID_BLINK_OFF */
        case ID_BLINK_OFF:
        {
            if (dre.blink.timer >= CTE_BLINK_PERIOD) {
                /* Transition ID: ID_BLINK_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::ledOn' begin] */
                dre.blink.led = true;
                /* ['<global>::ledOn' end] */
                /* ['<global>::rstBlinkTimer' begin] */
                dre.blink.timer = 0;
                /* ['<global>::rstBlinkTimer' end] */
                state = ID_BLINK_ON;
            } else {
                /* Transition ID: ID_BLINK_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::incrBlinkTimer' begin] */
                dre.blink.timer++;
                /* ['<global>::incrBlinkTimer' end] */
            }
            break;
        }
            /* State ID: ID_BLINK_ON */
        case ID_BLINK_ON:
        {
            if (dre.blink.timer >= CTE_BLINK_PERIOD) {
                /* Transition ID: ID_BLINK_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::ledOff' begin] */
                dre.blink.led = false;
                /* ['<global>::ledOff' end] */
                /* ['<global>::rstBlinkTimer' begin] */
                dre.blink.timer = 0;
                /* ['<global>::rstBlinkTimer' end] */
                state = ID_BLINK_OFF;
            } else {
                /* Transition ID: ID_BLINK_TRANSITION_CONNECTION */
                /* Actions: */
                /* ['<global>::incrBlinkTimer' begin] */
                dre.blink.timer++;
                /* ['<global>::incrBlinkTimer' end] */
            }
            break;
        }
    }
}
/* ['Blink' end (DON'T REMOVE THIS LINE!)] */

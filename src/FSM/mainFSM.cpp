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
            dre.ledStatus = (dre.s1Mode != S1_NORMAL_IDX);
            /* ['<global>::genLedStatus' end] */
            break;
        }
    }
}
/* ['Sample' end (DON'T REMOVE THIS LINE!)] */

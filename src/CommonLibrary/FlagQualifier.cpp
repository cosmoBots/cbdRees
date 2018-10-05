#include "CommonLibrary.h"
#include <gttc_timer.h>

static void FlagQualifier0(t_flagqualifier_block *fq_block);
static void NotQualified(t_flagqualifier_block *fq_block);
static void Qualified(t_flagqualifier_block *fq_block);

void FlagQualifierInit(t_flagqualifier_block *fq_block) {
    fq_block->state = STATE_0_FLAGQUALIFIER;

    FlagQualifier(fq_block);
}

void FlagQualifier(t_flagqualifier_block *fq_block) {
    switch (fq_block->state) {
        case STATE_0_FLAGQUALIFIER:
            FlagQualifier0(fq_block);
            break;
        case STATE_FLAGQUALIFIER_NOTQUALIFIED:
            NotQualified(fq_block);
            break;
        case STATE_FLAGQUALIFIER_QUALIFIED:
            Qualified(fq_block);
            break;
        default:
            fq_block->state = STATE_0_FLAGQUALIFIER;
            break;
    }
}

static void FlagQualifier0(t_flagqualifier_block *fq_block) {
    fq_block->output = FALSE;

    fq_block->output = FALSE;
    fq_block->time = 0;

    fq_block->state = STATE_FLAGQUALIFIER_NOTQUALIFIED;
}

static void NotQualified(t_flagqualifier_block *fq_block) {
    if (fq_block->time < TIME_MS_MAX) {

        fq_block->time++;

    }

    if (fq_block->input == FALSE) {

        fq_block->output = FALSE;
        fq_block->time = 0;

        fq_block->state = STATE_FLAGQUALIFIER_NOTQUALIFIED;
    } else

        if ((fq_block->input == TRUE) && (fq_block->time >= fq_block->qualify_time)) {

        fq_block->output = TRUE;
        fq_block->time = 0;

        fq_block->state = STATE_FLAGQUALIFIER_QUALIFIED;
    } else {
        fq_block->state = STATE_FLAGQUALIFIER_NOTQUALIFIED;
    }
}

static void Qualified(t_flagqualifier_block *fq_block) {
    if (fq_block->time < TIME_MS_MAX) {
        fq_block->time++;
    }

    if (fq_block->input == TRUE) {

        fq_block->output = TRUE;
        fq_block->time = 0;

        fq_block->state = STATE_FLAGQUALIFIER_QUALIFIED;
    } else if ((fq_block->input == FALSE) && (fq_block->time >= fq_block->heal_time)) {

        fq_block->output = FALSE;
        fq_block->time = 0;

        fq_block->state = STATE_FLAGQUALIFIER_NOTQUALIFIED;
    } else {

        fq_block->state = STATE_FLAGQUALIFIER_QUALIFIED;
    }
}

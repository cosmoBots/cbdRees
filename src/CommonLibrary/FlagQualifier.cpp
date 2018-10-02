#include "CommonLibrary.h"
#include <gttc_timer.h>

typedef enum {
    STATE_FLAGQUALIFIER_NOTQUALIFIED = 1,
    STATE_FLAGQUALIFIER_QUALIFIED = 2,
    STATE_0_FLAGQUALIFIER = 0
} t_state_flagqualifier;

static t_state_flagqualifier state_flagqualifier = STATE_0_FLAGQUALIFIER;

uint8_t GetCurrentFlagQualifierState(void)
{
    return (uint8_t) state_flagqualifier;
}

void SetCurrentFlagQualifierState(uint8_t state)
{
    state_flagqualifier = (t_state_flagqualifier) state;
}

static void FlagQualifier0(void);
static void NotQualified(void);
static void Qualified(void);

void FlagQualifierInit(void)
{
    state_flagqualifier = STATE_0_FLAGQUALIFIER;

    FlagQualifier();
}

void FlagQualifier(void)
{
    switch (state_flagqualifier) {
    case STATE_0_FLAGQUALIFIER:
        FlagQualifier0();
        break;
    case STATE_FLAGQUALIFIER_NOTQUALIFIED:
        NotQualified();
        break;
    case STATE_FLAGQUALIFIER_QUALIFIED:
        Qualified();
        break;
    default:
        state_flagqualifier = STATE_0_FLAGQUALIFIER;
        break;
    }
}

static void FlagQualifier0(void)
{
    fq_block->output = FALSE;

    fq_block->output = FALSE;
    fq_block->time = 0;

    state_flagqualifier = STATE_FLAGQUALIFIER_NOTQUALIFIED;
}

static void NotQualified(void)
{
    if (fq_block->time < TIME_MS_MAX) {

        fq_block->time++;

    }

    if (fq_block->input == FALSE) {

        fq_block->output = FALSE;
        fq_block->time = 0;

        state_flagqualifier = STATE_FLAGQUALIFIER_NOTQUALIFIED;
    } else

        if ((fq_block->input == TRUE) && (fq_block->time >= fq_block->qualify_time)) {

        fq_block->output = TRUE;
        fq_block->time = 0;

        state_flagqualifier = STATE_FLAGQUALIFIER_QUALIFIED;
    } else {

        /* No s ha activat cap transicio: ens quedem a l estat actual */
        state_flagqualifier = STATE_FLAGQUALIFIER_NOTQUALIFIED;
    }
}

static void Qualified(void)
{
    if (fq_block->time < TIME_MS_MAX) {
        fq_block->time++;
    }

    if (fq_block->input == TRUE) {

        fq_block->output = TRUE;
        fq_block->time = 0;

        state_flagqualifier = STATE_FLAGQUALIFIER_QUALIFIED;
    } else if ((fq_block->input == FALSE) && (fq_block->time >= fq_block->heal_time)) {

        fq_block->output = FALSE;
        fq_block->time = 0;

        state_flagqualifier = STATE_FLAGQUALIFIER_NOTQUALIFIED;
    } else {

        state_flagqualifier = STATE_FLAGQUALIFIER_QUALIFIED;
    }
}


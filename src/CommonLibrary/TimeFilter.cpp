#include "CommonLibrary.h"
#include <gttc_timer.h>

typedef enum {
    STATE_TIMEFILTER_NOTCHANGEDETECTED = 1,
    STATE_TIMEFILTER_CHANGEDETECTED = 2,
    STATE_0_TIMEFILTER = 0
} t_state_timefilter;

static t_state_timefilter state_timefilter = STATE_0_TIMEFILTER;

uint8_t getCurrentTimeFilterState(void) {
    return (uint8_t) state_timefilter;
}

void setCurrentTimeFilterState(uint8_t state) {
    state_timefilter = (t_state_timefilter) state;
}

static void TimeFilter0(void);
static void NotChangeDetected(void);
static void ChangeDetected(void);

void TimeFilterInit(void) {
    state_timefilter = STATE_0_TIMEFILTER;

    TimeFilter();
}

void TimeFilter(void) {
    switch (state_timefilter) {
        case STATE_0_TIMEFILTER:
            TimeFilter0();
            break;
        case STATE_TIMEFILTER_NOTCHANGEDETECTED:
            NotChangeDetected();
            break;
        case STATE_TIMEFILTER_CHANGEDETECTED:
            ChangeDetected();
            break;
        default:
            state_timefilter = STATE_0_TIMEFILTER;
            break;
    }
}

static void TimeFilter0(void) {
    tf_block->output = tf_block->input;

    state_timefilter = STATE_TIMEFILTER_NOTCHANGEDETECTED;
}

static void NotChangeDetected(void) {
    if (tf_block->input != tf_block->output) {
        tf_block->time = 0;
        tf_block->new_value_detected = tf_block->input;

        state_timefilter = STATE_TIMEFILTER_CHANGEDETECTED;
    } else {

        state_timefilter = STATE_TIMEFILTER_NOTCHANGEDETECTED;
    }
}

static void ChangeDetected(void) {
    if (tf_block->time < TIME_MS_MAX) {

        tf_block->time++;

    }

    if ((tf_block->input != tf_block->output) && (tf_block->input == tf_block->new_value_detected) && (tf_block->time >= tf_block->stability_time)) {
        tf_block->output = tf_block->input;
        state_timefilter = STATE_TIMEFILTER_NOTCHANGEDETECTED;
    } else if (tf_block->input == tf_block->output) {
        tf_block->output = tf_block->input;
        state_timefilter = STATE_TIMEFILTER_NOTCHANGEDETECTED;
    } else if ((tf_block->input != tf_block->output) && (tf_block->input != tf_block->new_value_detected)) {
        tf_block->time = 0;
        tf_block->new_value_detected = tf_block->input;
        state_timefilter = STATE_TIMEFILTER_CHANGEDETECTED;
    } else {
        state_timefilter = STATE_TIMEFILTER_CHANGEDETECTED;
    }
}

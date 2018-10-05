#include "CommonLibrary.h"
#include <gttc_timer.h>

static void TimeFilter0(t_timefilter_block *tf_block);
static void NotChangeDetected(t_timefilter_block *tf_block);
static void ChangeDetected(t_timefilter_block *tf_block);

void TimeFilterInit(t_timefilter_block *tf_block) {
    tf_block->state = STATE_0_TIMEFILTER;

    TimeFilter(tf_block);
}

void TimeFilter(t_timefilter_block *tf_block) {
    switch (tf_block->state) {
        case STATE_0_TIMEFILTER:
            TimeFilter0(tf_block);
            break;
        case STATE_TIMEFILTER_NOTCHANGEDETECTED:
            NotChangeDetected(tf_block);
            break;
        case STATE_TIMEFILTER_CHANGEDETECTED:
            ChangeDetected(tf_block);
            break;
        default:
            tf_block->state = STATE_0_TIMEFILTER;
            break;
    }
}

static void TimeFilter0(t_timefilter_block *tf_block) {
    tf_block->output = tf_block->input;

    tf_block->state = STATE_TIMEFILTER_NOTCHANGEDETECTED;
}

static void NotChangeDetected(t_timefilter_block *tf_block) {
    if (tf_block->input != tf_block->output) {
        tf_block->time = 0;
        tf_block->new_value_detected = tf_block->input;

        tf_block->state = STATE_TIMEFILTER_CHANGEDETECTED;
    } else {

        tf_block->state = STATE_TIMEFILTER_NOTCHANGEDETECTED;
    }
}

static void ChangeDetected(t_timefilter_block *tf_block) {
    if (tf_block->time < TIME_MS_MAX) {

        tf_block->time++;

    }

    if ((tf_block->input != tf_block->output) && (tf_block->input == tf_block->new_value_detected) && (tf_block->time >= tf_block->stability_time)) {
        tf_block->output = tf_block->input;
        tf_block->state = STATE_TIMEFILTER_NOTCHANGEDETECTED;
    } else if (tf_block->input == tf_block->output) {
        tf_block->output = tf_block->input;
        tf_block->state = STATE_TIMEFILTER_NOTCHANGEDETECTED;
    } else if ((tf_block->input != tf_block->output) && (tf_block->input != tf_block->new_value_detected)) {
        tf_block->time = 0;
        tf_block->new_value_detected = tf_block->input;
        tf_block->state = STATE_TIMEFILTER_CHANGEDETECTED;
    } else {
        tf_block->state = STATE_TIMEFILTER_CHANGEDETECTED;
    }
}

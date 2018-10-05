/* --------- This file is an example of a main file in an Arduino project -----------------------------
-- Additional files with gttc_ prefix are the gatArduinOSEK files, not to be modified in normal use --
-- Additional files with prj_ prefix are the ones that must be configured for each project, they    --
-- are part of the example.                                                                         --

 ***** Project configuration include (before OSEK includes to allow OSEK configuration ******/
#include <Arduino.h>

#include "prj_cfg.h"

/***** gatArduinOSEK includes *****/
/*** Types ***/
#include <gttc_types.h>
/*** Timer ***/
//#define TIMEBASE_USE_MS 1  // <-- Normally the timer unit is the us (microseconds) but you can use this define to use ms (milliseconds)
#include <gttc_timer.h>

/* ---------------------------------------*/

/***** Project includes *****/
#include "prj_pinout.h" // <-- The pinout of the project
#include "DRE.h"    // <-- The DRE of the project (global variables pools to share)
#include "prj_input.h"  // <-- The input module reads the microcontroller pinout
#include "prj_output.h"  // <-- The output module writes the microcontroller pinout
#include "FSM/mainFSM.h"

extern t_dre dre;

/***** FSM tasks *****/
void fsmTasksInit(void) {
    S1ModeSchedulerInit();
    BATModeSchedulerInit();
    Sample();
}

/***** FSM tasks *****/
void fsmTasks(void) {
    S1ModeScheduler();
    BATModeScheduler();
    Sample();
}

/***** Setup & Startup functions *****/

void setup() {

    Serial.begin(115200);

    ////////////// Platform init
    timerSetCycleTime(CYCLE_TIME_IN_MICROS);

    ////////////// DRE init
    dreInit();

    ////////////// Pinout init
    pinoutInit();

    ////////////// Input init
    prjInputInit();

    ////////////// FSM init
    fsmTasksInit();

    ////////////// Output Init
    prjOutputInit();
}

/* ---------------------------------------*/

/***** Main Loop *****/
int program_cycle_warnings = 0;

void loop() {
    // ----------- Functionality ----------------

    ////////////// Pinout task
    pinout();

    ////////////// Input task
    prjInput();

    ////////////// FSM tasks
    fsmTasks();

    // ----------- End of Cycle Synchronization ----------------
    boolean timSync = timerSync();
#ifdef DEBUG_CYCLE_TIME
    if (timSync) {
        Serial.println(">>>>>>>> Program Cycle Error! <<<<<<<<<");
    } else {
        if ((CYCLE_TIME_IN_MICROS - elapsedMicros) < CYCLE_SECURITY_TIME_MICROS) {
            Serial.print(">>>>>>>> Program Cycle Warning: ");
            Serial.print(program_cycle_warnings++);
            Serial.print(" : ellapsedMicros = ");
            Serial.println(elapsedMicros);
        }
    }
#endif
    while (timSync == false) {
        // timerSync returns true when the end of cycle syncronization time expired.
        timSync = timerSync();
    }
    ////////////// Output task
    prjOutput();
}

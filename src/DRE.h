/**
 * This header includes the definition of the Data Runtime Environment
 * global variables structure.  The DRE acts as a formal pool for sharing variables 
 * between modules ("processes") reducing the use of function arguments.
 * Using a global variable is commonly perceived as unsecure and unsafe in regular
 * (not embedded) software development.
 * In a not multitasking environment, if some coding guidelines are followed, the use 
 * of global variables reduces RAM and stack use, compared with arguments pass.
 * The DRE must be structured as a tree of records, and each record must be defined 
 * to give support o a software module.  To keep it secure, if is not clearly justified,
 * there must be ONLY ONE writer for every variable in the DRE.
 * If not clearly justified, the DRE root MUST BE THE ONLY AND UNIQUE GLOBAL VARIABLE.
 * If a variable must be shared between modules, it must be a function call argument or part of
 * the DRE structure.  If this guideline is used, the coder will be sure that every 
 * variable outside of the DRE must be local, and this reduces also the use of the "extern" 
 * attributes
 */ 
#ifndef _DRE_H
#define _DRE_H

/** 
 * Include types applying to the whole project
 */ 
#include "prj_types.h"
#include "prj_cfg.h"
/////////////////////////////////// (NORMAL) DRE //////////////////////////////////////////
/////////////////////////////////// (NORMAL) DRE //////////////////////////////////////////


/**
 * Include type definition headers for software modules
 */
#include "BATMode/BATMode.h"
#include "BUTDebounce/BUTDebounce.h"
#ifdef CFG_USE_UNO_LCD1602_KEYPAD
#include "KEYPMode/KEYPMode.h"
#define LCD_BUT_RIGHT 0
#define LCD_BUT_UP 1
#define LCD_BUT_DOWN 2
#define LCD_BUT_LEFT 3
#define LCD_BUT_SELECT 4
#define LCD_BUT_NONE 5
#endif

#ifdef CFG_USE_SERIALCMD
#define CFG_CMD_STORAGE_SIZE 4
#define CFG_CMD_LENGTH 12
#define CFG_EMGCY_QUALTIME CALC_CYCLE_COUNT_FOR_TIME(50000)
#define CFG_EMGCY_ACTTIME CALC_CYCLE_COUNT_FOR_TIME(5000000)
#endif

//////////////////  PARTIAL STRUCTURES THAT CONFORM DRE STRUCTURE TREE //////////////
/// Blink function structure
typedef struct {
    bool led;
    uint16_t timer;
} t_blink_function;

/// MechVentilation function structure
#include <AutoPID.h>
#include <FlexyStepper.h>
#include "Sensors/Sensors.h"

// Solenoid
#define SOLENOID_CLOSED 0
#define SOLENOID_OPEN 1
// Base de tiempos. Periodo de llamada a mechVentilation.update
#define MV_TIME_BASE 50 //msec
// Valores motor
#define STEPPER_MICROSTEPS 4
#define STEPPER_STEPS_PER_REVOLUTION 200

#define STEPPER_MICROSTEPS_PER_REVOLUTION (STEPPER_STEPS_PER_REVOLUTION * STEPPER_MICROSTEPS)
#define STEPPER_DIR 1
#define STEPPER_HOMING_DIRECTION    (-1)
#define STEPPER_HOMING_SPEED        (STEPPER_MICROSTEPS * 1000)   // Steps/s
// #define STEPPER_LOWEST_POSITION     (STEPPER_MICROSTEPS * -100)   // Steps
// #define STEPPER_HIGHEST_POSITION    (STEPPER_MICROSTEPS *   50)   // Steps
#define STEPPER_LOWEST_POSITION     (STEPPER_MICROSTEPS *  85)   // Steps
#define STEPPER_HIGHEST_POSITION    (STEPPER_MICROSTEPS * -100)   // Steps
#define STEPPER_SPEED_DEFAULT       (STEPPER_MICROSTEPS *  800)   // Steps/s
#define STEPPER_ACC_EXSUFFLATION    (STEPPER_MICROSTEPS *  600)   // Steps/s2
#define STEPPER_ACC_INSUFFLATION    (STEPPER_MICROSTEPS *  450)   // Steps/s2

// PID constants
// PID settings and gains
#define PID_MIN -10000 // TODO: check direction implementation
#define PID_MAX 10000
#define PID_KP 1000
#define PID_KI 40
#define PID_KD 0
#define PID_TS MV_TIME_BASE
#define PID_BANGBANG 4

typedef struct {
    bool homingReq;
    bool homingDone;
    bool homingError;
    /** Stepper speed. @todo Denote units. */
    float speed;    
    FlexyStepper *stepper;
}t_stepper;

typedef struct {
    /* Parameters */

    /* Local vars */
    int currentWaitTriggerTime;
    int currentStopInsufflationTime;
    float currentFlow;
    /* FSM vars */
    bool enable;
    bool running;

    /** Flow trigger activation. */
    bool hasTrigger;
    /** Flow trigger value in litres per minute. */
    float triggerThreshold;
    /**  Insufflation timeout in seconds. */
    short timeoutIns;
    /** Exsufflation timeout in seconds. */
    short timeoutEsp;
    /** Breaths per minute */
    uint8_t rpm;
    /** Peak inspiratory pressure */
    float pip;
    /** Peak espiratory pressure */
    float peep;

    bool sensor_error_detected;
    bool startWasTriggeredByPatient;
    SensorPressureValues_t pressures;
    t_stepper stp;
    AutoPID * pid;
    float currentPressure;
    float currentVolume;

    int totalCyclesInThisState;
    int currentTime;
    int flowSetpoint;
}t_mechvent;


/// Misc function structure
/// This structure contains variables needed by modules that have 
/// been integrated, but that must be moved to the modules which will be integrated
/// in the future
typedef struct {
    uint8_t solenoid;
    bool endstop;
}t_misc;

typedef struct {
    bool homing;
    bool sensor;
}t_failures;

////////////////// DRE STRUCTURE TREE //////////////

typedef struct {
    /// Inputs

    /// Outputs
    bool ledStatus;

    /// Functions
    t_blink_function blink;

    t_mechvent mv;
    t_misc misc;
    t_failures fail;

    Sensors * sensors;

    int emgcy_timer;
    bool emgcy_button;
    bool emgcy_action;
    bool ovr_emgcy_action;
    bool cmd_emgcy_action;

    /// Include here the DRE fragments defined by other software modules
    /// which have been coded to be DRE-compatible
#include "BATMode/BATMode_DRE.h"
#include "BUTDebounce/BUTDebounce_DRE.h"
#ifdef CFG_USE_UNO_LCD1602_KEYPAD
#include "KEYPMode/KEYPMode_DRE.h"
#endif
#ifdef CFG_USE_SERIALCMD
#include "SerialCmd/SerialCmd_DRE.h"
#endif
} t_dre;

/////////////////////////////////// DIAGNOSTICS DRE //////////////////////////////////////////
/////////////////////////////////// DIAGNOSTICS DRE //////////////////////////////////////////
/////////////////////////////////// DIAGNOSTICS DRE //////////////////////////////////////////


/**
 * In case Diagnostics are present in the system, an special DRE-like structure 
 * is defined to hold the variables used for diagnostics.
 * Normally, for each important flow (input/output/message) the diagnostics layer
 * DRE will provide a pair of variables: one enabler flag and one alternative value
 * The enabler flag is normally inactive, and in this situation considering the case of an
 * input flow, the input value read from the pin or the bus is passed directly 
 * to its corresponding variable in the DRE structure, so the functionalities can read it.
 * Considering the case of an output flow, the enabler flag inactive causes the corresponding
 * variable at the DRE to be written to the port or to the bus.
 * When the enabler flag is active, considering an input flow, the port or incomming message 
 * is ignored, and the value written on the DRE variable is copied from the alternative value
 * stored in the Diagnostics DRE.  With this mechanism you can diagnose functionality creating
 * simulated stimuli without needing to create a physical event.  For instance, to test the
 * reaction of the system to a overheating condition we can warm up the whole system in an oven
 * or substitute the value read by the sensor before injecting it to the software.  The diagnosis
 * mechanism allows you to do all this manipulation without "hacking" or "patching" the software.
 * Some commands can be added to the serial line connection, to allow changing the enabler flag 
 * and the alternative value from outside of the system.  There are standards like UDS or XCP that
 * can do this in a more productive and comfortable way, but a tiny custom protocol can be implemented
 * or a test button can be added to cause this Diagnostics DRE values change.
 * In the case of an output flow, the enabler causes de data in the DRE variable to be ignored, and 
 * the alternative value of the Diagnostics DRE is written in the port or in the outgoing message.
 * This mechanism is very useful to check leds or actuators, by de-coupling them from the regular 
 * functionality that handles them and giving the control to the diagnoser.
 * The Diagnostics DRE enables powerful, safe and easy maintenance and empower the team's issue fixing
 * capabilities.
 */
#ifdef _DIAG_ACTIVE


//////////////////  PARTIAL STRUCTURES THAT CONFORM DIAGNOSTICS DRE STRUCTURE TREE //////////////

/// Blink function diagnostics structure
typedef struct {
    bool enable_led;
    bool led;
    bool enable_timer;
    uint16_t timer;
} t_blink_function_diag;

//////////////////  DIAGNOSTICS DRE STRUCTURE TREE //////////////
typedef struct {
    bool enable_ledStatus;
    bool ledStatus;
    t_blink_function_diag blink;

    /// Include here the Diagnostics DRE fragments defined by other software modules
    /// which have been coded to be DRE-compatible
#include "BATMode/BATMode_DRE_diag.h"
#include "BUTDebounce/BUTDebounce_DRE_diag.h"
#ifdef CFG_USE_UNO_LCD1602_KEYPAD
#include "KEYPMode/KEYPMode_DRE_diag.h"
#endif
} t_diag;
#endif


/////////////////////////////////// INPUT FLOW ACQUISITION TO DRE API //////////////////////////////////////////
/////////////////////////////////// OUTPUT FLOW SYNTHESIS FROM DRE API //////////////////////////////////////////

/// Flow Input functions
void setup_key_lcd(void);
void acquire_key_lcd(void);
/// Internal Flows functions

/// Flow Output fucntions
void setup_ledStatus(void);
void synthesize_ledStatus(void);

/// Include here the DRE acqusition/synthesis fragments defined by other software modules
/// which have been coded to be DRE-compatible
#include "BATMode/BATMode_DRE_func.h"
#include "BUTDebounce/BUTDebounce_DRE_func.h"
#ifdef CFG_USE_UNO_LCD1602_KEYPAD
#include "KEYPMode/KEYPMode_DRE_func.h"
#endif

/**
 * DRE initialization function 
 */
void dreInit(void);

/**
 * Diagnostics DRE initialization function 
 */
void diagInit(void);
#endif /* _DRE_H */

#ifndef _DRE_H
#define _DRE_H

#include "prj_types.h"

#include "S1Mode/S1Mode.h"
#include "BATMode/BATMode.h"
#include "BUTDebounce/BUTDebounce.h"

/// Blink function structure

typedef struct {
    bool led;
    uint16_t timer;
} t_blink_function;

/// DRE Structure

typedef struct {
    /// Inputs

    /// Outputs
    bool ledStatus;

    /// Functions
    t_blink_function blink;

  int emgcy_timer;
  bool emgcy_button;
  bool emgcy_action;
  bool ovr_emgcy_action;
  bool cmd_emgcy_action;
  bool emgcy_action_pin;

    /// Modules
#include "BATMode/BATMode_DRE.h"
#include "S1Mode/S1Mode_DRE.h"
#include "BUTDebounce/BUTDebounce_DRE.h"

#ifdef CFG_USE_IOT
    /// IoT
#include "IoT/prj_iot_DRE.h"
#endif

#ifdef CFG_USE_SERIALCMD
#include "SerialCmd/SerialCmd_DRE.h"
#endif

} t_dre;

/// Blink function diagnostics structure
#ifdef _DIAG_ACTIVE

typedef struct {
    bool enable_led;
    bool led;
    bool enable_timer;
    uint16_t timer;
} t_blink_function_diag;

/// Diagnostics DRE structure

typedef struct {
    bool enable_ledStatus;
    bool ledStatus;
    t_blink_function_diag blink;

    /// Modules
#include "BATMode/BATMode_DRE_diag.h"
#include "S1Mode/S1Mode_DRE_diag.h"
#include "BUTDebounce/BUTDebounce_DRE_diag.h"
} t_diag;
#endif

// Initialization functions

/// Inputs

/// Internals

/// Outputs
void setup_ledStatus(void);
void synthesize_ledStatus(void);

#include "BATMode/BATMode_DRE_func.h"
#include "S1Mode/S1Mode_DRE_func.h"
#include "BUTDebounce/BUTDebounce_DRE_func.h"

void dreInit(void);

#endif /* _DRE_H */

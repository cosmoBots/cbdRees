/* This header file configures the main parameters of the application.
If variant exists, the specific parameters shall be defined
in prj_variants.h file, not here.  The active variant is also selected
in prj_variants.h file.
*/
#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H

/* Include variant specific configuration and active variant selection */
#include "prj_variants.h"
/* Include the real time time base for RTC main loop */
#include <gttc_timer.h>

/////// Real-time cycles configuration /////////
#define CYCLE_TIME_IN_MICROS 5000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L
#define uS_TO_S_FACTOR (1000000)

////////  Configuration of functionalities ///////////
#define CTE_BLINK_PERIOD CALC_CYCLE_COUNT_FOR_TIME(1000000)

/////// Diagnostics ////////////
/* Uncomment this directive if you want to activate the diagnostics handling */
#define _DIAG_ACTIVE

//////// Debug Configuration ///////////
/**
 * Set here the debugging directives to enable/disable the debug features of
 * different application features */
#define DEBUG_CYCLE_TIME
#define DEBUG_BLINK
#define DEBUG_BUT

/** 
 * Special features or layers that can be disabled
 * (we include here examples, but the draft do not include 
 * activable features by now)
 * */
#define CFG_USE_ROSSERIAL
#define CFG_USE_MQTT
#define CFG_USE_WIFI
#define CFG_USE_SERIALCMD
#define CFG_USE_UNO_LCD1602_KEYPAD

/**
 * Microcontroller/platform related layer switch 
 * Some features or layers can not be implemented in some platforms
 * When platformio compiles to an specific platform, sets the platform
 * directive (the information of the directives set is shown in platformi.ini file)
 * Here you can perform specific configuration of the project based on the target platform
 * Typical specific configuration examples are:
 * * unset a layer or feature 
 * ** (Arduino mega does not have wifi support, don't compile IOT, MQTT or WIFI)
 * * reconfigure a parameter
 * ** (Some microcontroller have little RAM, so the size of the buffers can be reduced here
 * ** or some resources hungry features disabled)
 * We include here an example with the hypothetical wifi and mqtt features
 * NOTE: DO NOT USE PLATFORM WHEN YOU NEED TO CONFIGURE VARIANTS.  USE THEM TO REFLECT
 * HOW TO REWRITE THE CODE TO ADAPT IT TO SPECIFIC PLATFORMS, DO NOT BASE YOUR VARIANT 
 * SELECTION OR CONFIGURATION ON THE TARGET THAT IS BEING COMPILED
 */
#ifdef ARDUINO_ESP8266_WEMOS_D1MINI
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif ARDUINO_ESP8266_ESP01
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif ARDUINO_ESP8266_NODEMCU
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif DARDUINO_ESP8266_ESP01
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif ARDUINO_ESP32_DEV
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif TEENSY31
#undef CFG_USE_MQTT
#undef CFG_USE_WIFI
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif ARDUINO_AVR_NANO
#undef CFG_USE_MQTT
#undef CFG_USE_WIFI
#undef CFG_USE_ROSSERIAL
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif ARDUINO_AVR_MEGA2560
#undef CFG_USE_MQTT
#undef CFG_USE_WIFI
#undef CFG_USE_UNO_LCD1602_KEYPAD
#elif ARDUINO_AVR_UNO
#undef CFG_USE_MQTT
#undef CFG_USE_WIFI
#undef CFG_USE_ROSSERIAL
#else
#error "No microcontroller defined"
#endif

#endif /* _PRJ_CFG_H */

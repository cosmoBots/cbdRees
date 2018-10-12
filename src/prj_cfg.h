#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H

#include "prj_variants.h"
#include <gttc_timer.h>
/////// Platform configuration /////////
#define CYCLE_TIME_IN_MICROS 5000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L

//////// Main Configuration ///////////
#define CTE_BLINK_PERIOD CALC_CYCLE_COUNT_FOR_TIME(1000000)

/////// Diagnostics ////////////
//#define _DIAG_ACTIVE

//////// Debug Configuration ///////////
#define DEBUG_CYCLE_TIME
#define DEBUG_BLINK
//#define DEBUG_BUT



#define CFG_USE_WIFI
//#define CFG_USE_DEEPSLEEP
#define CFG_USE_MQTT
#define CFG_USE_IOT
//#define DEBUG_IOT
//define CFG_USE_ROS

/* Microcontroller variants */
#ifdef ESP8266_WEMOS_D1MINI
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in ESP8266
#elif ARDUINO_ESP8266_ESP01
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in ESP8266
#elif ARDUINO_ESP8266_NODEMCU
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in ESP8266
#elif DARDUINO_ESP8266_ESP01
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in ESP8266
#elif ARDUINO_ESP32_DEV

#elif TEENSY31
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in TEENSY
#undef CFG_USE_WIFI
#undef CFG_USE_MQTT
#undef CFG_USE_IOT
#elif ARDUINO_AVR_NANO
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in Nano
#undef CFG_USE_WIFI
#undef CFG_USE_MQTT
#undef CFG_USE_IOT
#elif ARDUINO_AVR_MEGA2560
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in Nano
#undef CFG_USE_WIFI
#undef CFG_USE_MQTT
#undef CFG_USE_IOT
#elif ARDUINO_AVR_UNO
#undef CFG_USE_DEEPSLEEP  // Deep Sleep only implemented in ARDUINO_ESP32_DEV
// TODO: Implement deep sleep mode in Nano
#undef CFG_USE_WIFI
#undef CFG_USE_MQTT
#undef CFG_USE_IOT
#else
#error "No microcontroller defined"
#endif

#ifdef CFG_USE_WIFI
#if 0
#define WIFISSID "Casita" // Put your WifiSSID here
#define PASSWORD "3DOctubreD2011" // Put your wifi password here
#else
#define WIFISSID "iacext" // Put your WifiSSID here
#define PASSWORD ".redwifideliac." // Put your wifi password here
#endif
#endif

#define uS_TO_S_FACTOR (1000000)

#ifdef CFG_USE_DEEPSLEEP
#define TIME_TO_SLEEP 60
#endif

#ifdef CFG_USE_MQTT
#define TOKEN "A1E-1xeHahv04tI0E9tF5RzFyElleLNNrq" // Put your Ubidots' TOKEN
#define MQTT_CLIENT_NAME "cBotsDraft" // MQTT client Name, please enter your own 8-12 alphanumeric character ASCII string;
//it should be a random and unique ascii string and different from all other devices
#define CFG_PUBLISH_TIME CALC_CYCLE_COUNT_FOR_TIME(200000)
#define CMD_EMGCY_ACTION_LABEL "cmd_emgcy_action" // Assing the variable label
#define OVR_EMGCY_ACTION_LABEL "ovr_emgcy_action" // Assing the variable label
#define DEVICE_LABEL "cBotsDraft" // Assig the device label
#define CFG_MQTT_BROKER "things.ubidots.com"

#endif

#define CFG_USE_SERIALCMD

#define DEBUG_IOT

#endif /* _PRJ_CFG_H */

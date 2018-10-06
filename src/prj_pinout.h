/* ---- This file describes all the pin assignments of the microcontroller --- */

#ifndef _PRJ_PINOUT_H
#define _PRJ_PINOUT_H

#include <Arduino.h>
#include <gttc_types.h>
#include "prj_input.h"
#include "prj_output.h"

#ifdef ESP8266_WEMOS_D1MINI
//#error "TODO: Definir pines para el ESP8266_WEMOS_D1MINI"
#define PORT_ledStatus 13
#define PORT_S1Sense A0     // = DIO 14
#define PORT_BATSense A0    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_ESP8266_NODEMCU
//#error "TODO: Definir pines para el ARDUINO_ESP8266_NODEMCU"
#define PORT_ledStatus 13
#define PORT_S1Sense A0     // = DIO 14
#define PORT_BATSense A0    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_ESP32_DEV
#define A0 36
#define A1 37
#define PORT_ledStatus 13
#define PORT_S1Sense A0     // = DIO 14
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#elif TEENSY31
//#error "TODO: Definir pines para la TEENSY31"
#define PORT_ledStatus 13
#define PORT_S1Sense A0     // = DIO 14
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_AVR_NANO
//#error "TODO: Definir pines para la ARDUINO_AVR_NANO"
#define PORT_ledStatus 13
#define PORT_S1Sense A0     // = DIO 14
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#else
#error "No microcontroller defined"
#endif


void pinoutInit(void);
void pinout(void);

#endif // _PRJ_PINOUT_H

/* ---- This file describes all the pin assignments of the microcontroller --- */

#ifndef _PRJ_PINOUT_H
#define _PRJ_PINOUT_H

#include <Arduino.h>
#include <gttc_types.h>
#include "prj_input.h"
#include "prj_output.h"

#ifdef ARDUINO_ESP8266_WEMOS_D1MINI
//#error "TODO: Definir pines para el ESP8266_WEMOS_D1MINI"
#define PORT_ledStatus LED_BUILTIN
#define PORT_BATSense A0    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_ESP8266_ESP01
//#error "TODO: Definir pines para el ARDUINO_ESP8266_ESP01"
#define PORT_ledStatus 2
#define PORT_BATSense A0    // = DIO 15
#define PORT_BUTRaw 0
#elif ARDUINO_ESP8266_NODEMCU
//#error "TODO: Definir pines para el ARDUINO_ESP8266_NODEMCU"
#define PORT_ledStatus 2
#define PORT_BATSense A0    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_ESP32_DEV
#define PORT_ledStatus 27
#define PORT_BATSense 35
#define PORT_BUTRaw 26
#elif TEENSY31
//#error "TODO: Definir pines para la TEENSY31"
#define PORT_ledStatus 13
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_AVR_NANO
//#error "TODO: Definir pines para la ARDUINO_AVR_NANO"
#define PORT_ledStatus 13
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_AVR_MEGA2560
//#error "TODO: Definir pines para la ARDUINO_AVR_MEGA2560"
#define PORT_ledStatus LED_BUILTIN
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#elif ARDUINO_AVR_UNO
//#error "TODO: Definir pines para la ARDUINO_AVR_UNO"
#define PORT_ledStatus LED_BUILTIN
#define PORT_BATSense A1    // = DIO 15
#define PORT_BUTRaw 2
#ifdef CFG_USE_UNO_LCD1602_KEYPAD
#define PIN_LCD1 8
#define PIN_LCD2 9
#define PIN_LCD3 4
#define PIN_LCD4 5
#define PIN_LCD5 6
#define PIN_LCD6 7
#define PIN_KEYPSense A0
#endif
#else
#error "No microcontroller defined"
#endif

#endif // _PRJ_PINOUT_H

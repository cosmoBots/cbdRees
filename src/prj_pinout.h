/* ---- This file describes all the pin assignments of the microcontroller --- */

#ifndef _PRJ_PINOUT_H
#define _PRJ_PINOUT_H

#include <Arduino.h>
#include <gttc_types.h>
#include "prj_input.h"
#include "prj_output.h"

#define PORT_ledStatus 13
#define PORT_s1Sense A0     // = DIO 14
#define PORT_batSense A1    // = DIO 15
#define PORT_butDI 2

void pinoutInit(void);
void pinout(void);

#endif // _PRJ_PINOUT_H

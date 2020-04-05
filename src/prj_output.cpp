/**
 * This code implements the typical and simple task of writing 
 * the output to the ports, using the values storedat the DRE
 * for normal output flows
 */
#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

/* DRE structure to obtain the values to be written to the output ports */
extern t_dre dre;

#ifdef CFG_USE_UNO_LCD1602_KEYPAD

#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(PIN_LCD1, PIN_LCD2, PIN_LCD3, PIN_LCD4, PIN_LCD5, PIN_LCD6);

void init_lcd(void){
    lcd.begin(16, 2);              // start the library
    lcd.setCursor(0,0);
    lcd.print("Push the buttons"); // print a simple message       
}

void process_lcd(void){
    lcd.setCursor(9,1);            // move cursor to second line "1" and 9 spaces over
    lcd.print(millis()/1000);      // display seconds elapsed since power-up
    lcd.setCursor(0,1);            // move to the begining of the second line
    switch (dre.KEYPMode)               // depending on which button was pushed, we perform an action
    {
        case KEYP_RIGHT_IDX:
            lcd.print("RIGHT ");
            break;
        case KEYP_LEFT_IDX:
            lcd.print("LEFT   ");
            break;
        case KEYP_UP_IDX:
            lcd.print("UP    ");
            break;
        case KEYP_DOWN_IDX:
            lcd.print("DOWN  ");
            break;
        case KEYP_SELECT_IDX:
            lcd.print("SELECT");
            break;
        case KEYP_NONE_IDX:
            lcd.print("NONE  ");
            break;
    }

}
#endif

/* Initialization of output flows */
void prjOutputInit(void) {
    setup_ledStatus();
#ifdef CFG_USE_UNO_LCD1602_KEYPAD    
    init_lcd();
#endif
}

/* Spin function to write output flows */
void prjOutput(void) {
    synthesize_ledStatus();
#ifdef CFG_USE_UNO_LCD1602_KEYPAD    
    process_lcd();
#endif
}

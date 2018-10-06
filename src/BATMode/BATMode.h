#ifndef BAT_MODE_H
#define BAT_MODE_H

#include "../CommonLibrary/CommonLibrary.h"

#include "BATMode_autogen.h"

/**** FSM includes ****/
void BATModeInit(void);
void BATMode(void); /*!< Manager that commands the mode detection */


#endif /* BAT_MODE_H */

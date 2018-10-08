/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "IoT_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['FuncMngr' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FUNCMNGR_INITIAL 0
#define ID_FUNCMNGR_INIT 1
#define ID_FUNCMNGR_WORKING 2

void FuncMngr(  );
/* ['FuncMngr' end (DON'T REMOVE THIS LINE!)] */

/* ['IoTMng' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_IOTMNG_INITIAL 3
#define ID_IOTMNG_DISCONNECTING 4
#define ID_IOTMNG_CONNECTING 5
#define ID_IOTMNG_WORKINGONLINE 6
#define ID_IOTMNG_WORKINGOFFLINE 7

void IoTMng(  );
/* ['IoTMng' end (DON'T REMOVE THIS LINE!)] */

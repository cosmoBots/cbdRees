/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "SerialCmdFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['DispatchSysCmd' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DISPATCHSYSCMD_INITIAL 0
#define ID_DISPATCHSYSCMD_WAITING 1
#define ID_DISPATCHSYSCMD_DECODECMD 2
#define ID_DISPATCHSYSCMD_EMGCYCMD 3

void DispatchSysCmd(  );
/* ['DispatchSysCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['ReceiveSysCmd' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_RECEIVESYSCMD_INITIAL 4
#define ID_RECEIVESYSCMD_WAITING 5
#define ID_RECEIVESYSCMD_READCHAR 6

void ReceiveSysCmd(  );
/* ['ReceiveSysCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['Emergency' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_EMERGENCY_INITIAL 7
#define ID_EMERGENCY_NORMAL 8
#define ID_EMERGENCY_WARNINGFILTER 9
#define ID_EMERGENCY_EMERGENCY 10
#define ID_EMERGENCY_HEALING 11

void Emergency(  );
/* ['Emergency' end (DON'T REMOVE THIS LINE!)] */

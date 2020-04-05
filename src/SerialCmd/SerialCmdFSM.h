/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "SerialCmdFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['DispatchSysCmd' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DISPATCHSYSCMD_INITIAL 0
#define ID_DISPATCHSYSCMD_WAITING 1
#define ID_DISPATCHSYSCMD_DECODECMD 2
#define ID_DISPATCHSYSCMD_EMGCYCMD 3
#define ID_DISPATCHSYSCMD_DIAGLEDCMD 4

void DispatchSysCmd(  );
/* ['DispatchSysCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['ReceiveSysCmd' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_RECEIVESYSCMD_INITIAL 5
#define ID_RECEIVESYSCMD_WAITING 6
#define ID_RECEIVESYSCMD_READCHAR 7

void ReceiveSysCmd(  );
/* ['ReceiveSysCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['Emergency' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_EMERGENCY_INITIAL 8
#define ID_EMERGENCY_NORMAL 9
#define ID_EMERGENCY_HEALING 10
#define ID_EMERGENCY_WARNINGFILTER 11
#define ID_EMERGENCY_EMERGENCY 12

void Emergency(  );
/* ['Emergency' end (DON'T REMOVE THIS LINE!)] */

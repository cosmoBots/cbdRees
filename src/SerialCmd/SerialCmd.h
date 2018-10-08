#ifndef _SERIAL_CMD_H
#define _SERIAL_CMD_H

#include "../prj_cfg.h"

#define CFG_CMD_STORAGE_SIZE 4
#define CFG_CMD_LENGTH 12
#define CFG_EMGCY_QUALTIME CALC_CYCLE_COUNT_FOR_TIME(50000)
#define CFG_EMGCY_ACTTIME CALC_CYCLE_COUNT_FOR_TIME(5000000)

void process_received_command(void);

#endif /* _SERIAL_CMD_H */
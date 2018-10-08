#ifndef _SERIALCMD_DRE_H
#define _SERIALCMD_DRE_H

#include "SerialCmd.h"

  char incoming_bytes[32];
  int serial_counter;

  int cmd_counter;
  int cmd_base;
  char cmd_storage[CFG_CMD_STORAGE_SIZE][CFG_CMD_LENGTH];

#endif /* _SERIALCMD_DRE_H */
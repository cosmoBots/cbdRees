#ifndef _SERIAL_CMD_H
#define _SERIAL_CMD_H

#include <prj_cfg.h>

#ifdef CFG_USE_SERIALCMD
void process_received_command(void);
#endif
#endif /* _SERIAL_CMD_H */
#include "SerialCmd.h"

#include "../prj_cfg.h"
#include "../DRE.h"
extern t_dre dre;

void process_received_command(void){
  int tmpcursor;
  dre.incoming_bytes[dre.serial_counter-1] = '\0';
  if (dre.serial_counter>=2){
    if (dre.incoming_bytes[dre.serial_counter-2] == '\r'){
      dre.incoming_bytes[dre.serial_counter-2] = '\0';
    }
  }
  strcpy(dre.cmd_storage[dre.cmd_counter],dre.incoming_bytes);
  Serial.println("Comandos: ");
  for (tmpcursor = 0 ; tmpcursor < CFG_CMD_STORAGE_SIZE ; tmpcursor++){
    Serial.print(tmpcursor);
    Serial.print(" : ");
    Serial.print(dre.cmd_storage[tmpcursor]);
    if (tmpcursor == dre.cmd_counter) {
      Serial.print("[c]");
    }
    if (tmpcursor == dre.cmd_base) {
      Serial.print("[b]");
    }
    Serial.println();
  }
  dre.cmd_counter = (dre.cmd_counter + 1) % CFG_CMD_STORAGE_SIZE;
  dre.incoming_bytes[0] = '\0';
}

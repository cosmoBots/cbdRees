#ifndef _PRJ_IOT_DRE_H
#define _PRJ_IOT_DRE_H

/*** IoT Management ***/
bool iot_connected;
bool iot_go_online;
bool iot_go_offline;
bool iot_connect;
bool iot_disconnect;
char iot_payload[128];
bool iot_publish;
int iot_publish_timer;

int emgcy_timer;
bool emgcy_button;
bool emgcy_action;
bool ovr_emgcy_action;
bool cmd_emgcy_action;
bool emgcy_action_pin;

#endif /* _PRJ_IOT_DRE_H */

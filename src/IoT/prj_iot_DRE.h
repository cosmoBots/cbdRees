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

#endif /* _PRJ_IOT_DRE_H */

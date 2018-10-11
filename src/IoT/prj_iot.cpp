#include "../prj_cfg.h"
#include "prj_iot.h"
#include "../DRE.h"

#ifdef CFG_USE_WIFI

#ifdef ESP8266_WEMOS_D1MINI
#include <ESP8266WiFi.h>
#elif ARDUINO_ESP8266_NODEMCU
#include <ESP8266WiFi.h>
#elif ARDUINO_ESP8266_ESP01
#include <ESP8266WiFi.h>
#elif ARDUINO_ESP32_DEV
#include <WiFi.h>
#else
#error "No microcontroller defined"
#endif

#endif

#ifdef CFG_USE_MQTT
#include <PubSubClient.h>

extern t_dre dre;

/****************************************
* Define Constants
****************************************/
char mqttBroker[]  = CFG_MQTT_BROKER;
char topic[150];
char str_bat[10];
char str_emgcy_action[10];
char str_emgcy_action_pin[10];

const char * VARIABLE_LABEL_BAT = "bat"; // Assign the variable label
const char * VARIABLE_LABEL_BAT_MODE = "bat_mode"; // Assign the variable label
const char * VARIABLE_LABEL_EMGCY_ACTION= "emgcy_action"; // Assign the variable label
const char * VARIABLE_LABEL_EMGCY_ACTION_PIN= "emgcy_action_pin"; // Assign the variable label

/****************************************
* Auxiliar Functions
****************************************/
WiFiClient ubidots;
PubSubClient client(ubidots);

void iot_set_suscriptions(void){
  client.subscribe("/v1.6/devices/" DEVICE_LABEL "/" CMD_EMGCY_ACTION_LABEL "/lv");
  client.loop();
  client.subscribe("/v1.6/devices/" DEVICE_LABEL "/" OVR_EMGCY_ACTION_LABEL "/lv");
  client.loop();
}

void callback_ovr(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = '\0';
  String message(p);
  Serial.println(topic);
  if (strcmp_P(topic, "/v1.6/devices/" DEVICE_LABEL "/" OVR_EMGCY_ACTION_LABEL "/lv")==0){
    if (message == "0") {
      dre.ovr_emgcy_action = false;
      Serial.println("EMGCY: Not Override");
    } else {
      dre.ovr_emgcy_action = true;
      Serial.println("EMGCY: Override");
    }
  } else {
    if (strcmp_P(topic, "/v1.6/devices/" DEVICE_LABEL "/" CMD_EMGCY_ACTION_LABEL "/lv")==0){
      if (message == "0") {
        dre.cmd_emgcy_action = false;
        Serial.println("EMGCY: Relay Off");
      } else {
        dre.cmd_emgcy_action = true;
        Serial.println("EMGCY: Relay On");
      }
    } else {
          /* Do nothing */
    }
  }

  //Serial.write(payload, length);
  Serial.println();
}

void reconnect(void) {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");

    // Attemp to connect
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Connected");
      iot_set_suscriptions();
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}
#endif


void iot_init(void){
#ifdef CFG_USE_WIFI
#ifdef CFG_CREATE_WIFI
  boolean ap_created = WiFi.softAP(WIFISSID, PASSWORD,WIFICHANNEL,true,4);
  while(!ap_created){
    Serial.println("Failed!");
    delay(1000);
    ap_created = WiFi.softAP(WIFISSID, PASSWORD,WIFICHANNEL,true,4);
  }
  Serial.println("WiFi AP Ready, waiing for first client");
  int stationsnum = WiFi.softAPgetStationNum();
  while (stationsnum < 1){
    Serial.printf("Stations connected = %d\n", stationsnum);  
    delay(1000);
    stationsnum = WiFi.softAPgetStationNum();
  }
#else
  WiFi.begin(WIFISSID, PASSWORD);

  Serial.println();
  Serial.print("Wait for WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
#endif  
#endif /* CFG_USE_WIFI */

#ifdef CFG_USE_MQTT
  client.setServer(mqttBroker, 1883);
  client.setCallback(callback_ovr);
  iot_set_suscriptions();
  #endif
}

void prjIoTInit(void){
  #ifdef CFG_USE_MQTT
  if (dre.iot_connect == true){
    if (WiFi.status() != WL_CONNECTED){
      iot_init();
    }
    if (!client.connected()) {
      reconnect();
      iot_set_suscriptions();
    }
  }
  dre.iot_connected = client.connected();
  #endif
}

int payload_counter = 0;

void prjIoT(void){

  bool ret = false;

  #ifdef CFG_USE_MQTT
  if (dre.iot_connect == true){
    if (WiFi.status() != WL_CONNECTED){
      iot_init();
    }
    if (!client.connected()) {
      reconnect();
      iot_set_suscriptions();
    }
  }

  if (client.connected() && dre.iot_publish == true) {
    #ifdef DEBUG_IOT
    Serial.print("Connecting to IoT server with counter "); Serial.println(payload_counter);
    #endif

    switch (payload_counter){
      case 0:
        dtostrf(dre.BATSense, 4, 0, str_bat);
        sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
        dre.iot_payload[0] = '\0'; // Cleans the payload
        sprintf(dre.iot_payload, "{\"%s\": %s,", VARIABLE_LABEL_BAT, str_bat); // Adds the variable label
        dtostrf(dre.BATMode, 1, 0, str_bat);
        sprintf(dre.iot_payload, "%s\"%s\": %s}", dre.iot_payload, VARIABLE_LABEL_BAT_MODE, str_bat); // Adds the variable label
        break;
      case 1:
        dtostrf(dre.emgcy_action, 1, 0, str_emgcy_action);
        sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
        dre.iot_payload[0] = '\0'; // Cleans the payload
        sprintf(dre.iot_payload, "{\"%s\": %s}", VARIABLE_LABEL_EMGCY_ACTION_PIN, str_emgcy_action); // Adds the variable label
        break;
      case 2:
        dtostrf(dre.emgcy_action_pin, 1, 0, str_emgcy_action_pin);
        sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
        dre.iot_payload[0] = '\0'; // Cleans the payload
        sprintf(dre.iot_payload, "{\"%s\": %s}", VARIABLE_LABEL_EMGCY_ACTION, str_emgcy_action_pin); // Adds the variable label
        break;
    }
    payload_counter = (payload_counter + 1) % 3;
    /* 4 is mininum width, 2 is precision; float value is copied onto str_sensor*/

    /* Building the Ubidots request */

    /* Publish the request to Ubidots */
    #ifdef DEBUG_IOT
    Serial.print(topic);Serial.print(": ");Serial.println(dre.iot_payload);
    #endif
    ret = client.publish(topic, dre.iot_payload);
    if (ret == false) {
      Serial.println("Publication failed!");
    } else {
      #ifdef DEBUG_IOT
      Serial.println("Publication worked!");
      #endif
    }
    #ifdef DEBUG_IOT
    if (dre.iot_publish) {
      Serial.println(dre.iot_payload);
    }
    #endif

    client.loop();
  }
  dre.iot_connected = client.connected();
  #endif
}

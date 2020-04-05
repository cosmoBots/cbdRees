#include <prj_cfg.h>
#ifdef CFG_USE_ROSSERIAL
#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/UInt8.h>

/* Variables */
std_msgs::UInt8 keypad_msg;

/* ROS handler */
ros::NodeHandle  nh;

/* Callbacks */
void messageEmgcyCb( const std_msgs::UInt8& display_msg){
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
}

void messageDisplayCb( const std_msgs::UInt8& emgcy_msg){
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
}

/* PubSub */
ros::Subscriber<std_msgs::UInt8> display_sub("display_cmd", &messageDisplayCb );
ros::Subscriber<std_msgs::UInt8> emgcy_sub("emgcy_cmd", &messageEmgcyCb );
ros::Publisher keypad_pub("keypad_cmd", &keypad_msg);

/* Setup */
void prj_ros_setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.advertise(keypad_pub);
  nh.subscribe(display_sub);
  nh.subscribe(emgcy_sub);
}

/* Loop */
void prj_ros_loop()
{
  keypad_msg.data = 2;
  keypad_pub.publish( &keypad_msg );
  nh.spinOnce();
}

#endif
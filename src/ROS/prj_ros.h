#ifndef _PRJ_ROS_H
#define _PRJ_ROS_H

#include <prj_cfg.h>
#ifdef CFG_USE_ROSSERIAL
void prj_ros_setup();
void prj_ros_loop();

#endif
#endif
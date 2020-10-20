#ifndef _8059_VISION_LIB_OBJECT_ODOMETRY_HPP_
#define _8059_VISION_LIB_OBJECT_ODOMETRY_HPP_
#include "8059VisionLib/include/visionStructs.hpp"

#define SIG_RED_BALL 1
#define SIG_BLUE_BALL 2
#define SIG_GREEN_FLAG 3
extern VisionObject redBall;
extern VisionObject blueBall;
extern VisionObject greenFlag;

void objectOdometry(void * ignore);
#endif

/**
 * Header file for baseOdometry.cpp
 * Defines the Odometry task that constantly updates the robot's
 * position based on encoders' values
 * Other odometry functions and variables
 */
#ifndef _8059_MOTION_PROFILE_LIB_BASE_ODOMETRY_HPP_
#define _8059_MOTION_PROFILE_LIB_BASE_ODOMETRY_HPP_
#include "8059MotionProfileLib/include/structs.hpp"
#include "main.h"
/**
 * Essential variables for odometry task and functions
 */
//Tuning: turn at least 2 rotations and compare results in program & real life
#define baseWidth 10.83798252962012
//Tuning: go straight and compare results in program & real life
#define inPerDeg 0.0241043549920626
// Make Coordinates position a universally accessible object
extern Coordinates position;
/**
 * refer to baseOdometry.cpp for function documentation
 */

std::pair<double, double> getEncdVals(bool rawData);
void baseOdometry(void * ignore);
void setCoords(double x, double y, double angle);

#endif

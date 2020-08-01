/**
 * Header file for baseOdometry.cpp
 * Defines the Odometry task that constantly updates the robot's
 * position based on encoders' values
 * Other odometry functions and variables
 */
#ifndef _8059_MOTION_PROFILE_LIB_BASE_ODOMETRY_HPP_
#define _8059_MOTION_PROFILE_LIB_BASE_ODOMETRY_HPP_
#include "8059MotionProfileLib/include/structs.hpp"
/**
 * Essential variables for odometry task and functions
 */
#define baseWidth 8.267275602939487 //go straight and compare results in program & real life
#define inPerDeg 0.0241043549920626 //turn at least 2 rotations and compare results in program & real life

#define GET_ENCD_VALS_PROCESSED true
#define GET_ENCD_VALS_RAW false //use during debugging or testing encoders
extern Coordinates position;
extern Coordinates target;
/**
 * refer to baseOdometry.cpp for function documentation
 */
void baseOdometry(void * ignore);
void setCoords(double x, double y, double angle);

#endif

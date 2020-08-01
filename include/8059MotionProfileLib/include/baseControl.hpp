/**
 * Header file for baseControl.cpp
 * Defines baseMotorControl task that handles the power setting of the motors
 *
 */
#ifndef _8059_MOTION_PROFILE_LIB_BASE_CONTROL_HPP_
#define _8059_MOTION_PROFILE_LIB_BASE_CONTROL_HPP_
//0: None, 1: Odom, 2: Encd, 3: Pow
#define DEBUG_MODE 0
#define MAX_POW 100
//maximum power increment for every 20ms (refresh rate of baseMotorControl)
#define RAMPING_POW 8
#define BASERPM 200

#define DEFAULT_KP 0.5
#define DEFAULT_KD 2
#define DEFAULT_TURN_KP 0.7
#define DEFAULT_TURN_KD 0.3

#define DISTANCE_LEEWAY 3 //in inches
#endif

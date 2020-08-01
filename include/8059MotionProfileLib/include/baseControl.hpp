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

void baseMove(double dis, double kp = DEFAULT_KP, double kd = DEFAULT_KD);
void baseMove(double x, double y, double kp = DEFAULT_KP, double kd = DEFAULT_KD);
void baseTurn(double angleDeg, double kp = DEFAULT_TURN_KP, double kd = DEFAULT_TURN_KD);
void baseTurn(double x, double y, bool reverse = false, double kp = DEFAULT_TURN_KP, double kd = DEFAULT_TURN_KD)
void baseTurnRelative(double angle, double kp = DEFAULT_TURN_KP, double kd = DEFAULT_TURN_KD);

void waitBase(double cutoff);
void timerBase(double powL, double powR, double time);
void capBasePow(double pow);
void rmBaseCap();
void pauseBase(bool pause = true);
void forceStraight(bool straight = true);
void resetCoords(double x, double y, double angleDeg);


void baseControl(void * ignore);
void baseMotorControl(void * ignore);


#define DISTANCE_LEEWAY 3 //in inches
#endif

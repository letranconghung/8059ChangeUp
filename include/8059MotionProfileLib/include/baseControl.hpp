/**
 * Header file for baseControl.cpp
 * Defines baseMotorControl task that handles the power setting of the motors
 *
 */
#ifndef _8059_MOTION_PROFILE_LIB_BASE_CONTROL_HPP_
#define _8059_MOTION_PROFILE_LIB_BASE_CONTROL_HPP_
/**
 * DEBUG_MODE can be used to debug & test functions and tasks via the terminal (aka command line)
 * 0: None
 * 1: Odometry (print Coordinates position)
 * 2: Encoders (print errorEncdL & errorEncdR)
 * 3: Power (print powerL & powerR)
 * 4: Raw encoder values (print raw encdL & encdR)
 */
#define DEBUG_MODE -1
// Maximum power allowed
#define MAX_POW 100
/**
 * Maximum power increment every 20ms (20ms is the refresh rate of Task baseMotorControl)
 * This is to prevent too rapid changes to the motor power
 * Mathematically: |V - V previous| <= RAMPING_POW
 */
#define RAMPING_POW 8
/**
 * Default values of the proportional and derivative constants
 * for straight and turning movements.
 */
#define DEFAULT_KP 0.5
#define DEFAULT_KD 2
#define DEFAULT_TURN_KP 0.7
#define DEFAULT_TURN_KD 0.3
/**
 * DISTANCE_LEEWAY is the distance (in inches) within which from the target
 * the robot would register that it has arrived at the target.
 */
#define DISTANCE_LEEWAY 3
/**
 * refer to baseControl.cpp for function documentation
 */
void baseMove(double dis, double kp, double kd);
void baseMove(double dis);
void baseMove(double x, double y, double kp, double kd);
void baseMove(double x, double y);
void baseTurn(double angleDeg, double kp, double kd);
void baseTurn(double angleDeg);
void baseTurn(double x, double y, double kp, double kd, bool reverse);
void baseTurnRelative(double angle, double kp, double kd);

void waitBase(double cutoff);
void capBasePow(double cap);
void rmBaseCap();
void pauseBase(bool pause);
void timerBase(double powL, double powR, double time);
void resetCoords(double x, double y, double angleDeg);

void baseControl(void * ignore);
void baseMotorControl(void * ignore);

#endif

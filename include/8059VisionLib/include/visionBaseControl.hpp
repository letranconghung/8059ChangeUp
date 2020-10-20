#ifndef _8059_VISION_LIB_VISION_BASE_CONTROL_HPP_
#define _8059_VISION_LIB_VISION_BASE_CONTROL_HPP_

#define VISION_COMPETITION_MODE false
#define VISION_DEBUG_MODE 3
/**
 * 0: None
 * 1: Object Odometry
 * 2: error, targetPower, power
 * 3: Selected odometry
 */
#define W_LEEWAY 5
#define X_LEEWAY 5
#define MAX_POW 120
#define RAMPING_POW 8

void visionBaseMove(int sig, double xkp, double xkd, double wkp, double wkd);
void visionBaseMove(int sig);
void waitBase(double cutoff);
void visionBaseControl(void * ignore);
// void visionBaseMotorControl(void * ignore);
#endif

#ifndef _8059_VISION_LIB_VISION_BASE_CONTROL_HPP_
#define _8059_VISION_LIB_VISION_BASE_CONTROL_HPP_

#define VISION_COMPETITION_MODE false
#define VISION_DEBUG_MODE 0
/**
 * 0: None
 * 1: Object Odometry
 * 2: error, targetPower, power
 * 3: Selected odometry
 */
#define W_LEEWAY 3
#define X_LEEWAY 3
#define VISION_MAX_POW 120
#define VISION_RAMPING_POW 8

void visionBaseMove(int sig, double xkp, double xkd, double wkp, double wkd);
void visionBaseMove(int sig);
void visionWaitBase(double cutoff);
void visionBaseControl(void * ignore);
// void visionBaseMotorControl(void * ignore);
#endif

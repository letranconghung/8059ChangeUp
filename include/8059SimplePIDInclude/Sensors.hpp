#ifndef _8059_SIMPLE_PID_SENSORS_HPP_
#define _8059_SIMPLE_PID_SENSORS_HPP_
extern double encdL, encdR;
extern int intakeColorValue, shootColorValue;
extern int ball, alliance, optBall;
extern bool allianceBall;
void Sensors(void * ignore);
void VisSort(void * ignore);
#endif

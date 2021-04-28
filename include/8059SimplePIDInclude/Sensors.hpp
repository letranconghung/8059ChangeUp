#ifndef _8059_SIMPLE_PID_SENSORS_HPP_
#define _8059_SIMPLE_PID_SENSORS_HPP_
extern double encdL, encdR, bearing, angle;
extern int intakeColorValue, shootColorValue;
extern bool ballRed, allianceRed;
void Sensors(void * ignore);
void VisSort(void * ignore);
#endif

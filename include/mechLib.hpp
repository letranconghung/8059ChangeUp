/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
/** traditional-style mech library */
extern int intakeColorThreshold, shootColorThreshold;
extern double powerRollers, powerIndexer, powerShooter;
extern bool autoIndex, driverMode, slowMode;
void setMech(double r, double i, double s);
void setMech(double r, double i, double s, int t);
void asyncFrontIntake();
void asyncLoad();
void asyncFrontIntakeLoad();
void shoot(double t);
void resetMode();
void resetMech();
void MechControl(void * ignore);
void shootTop();
// void waitIntakeColor();
// void waitShootColor();
// void autoFrontIntake();
// void autoBackIntake();
// void autoLoad();
// void autoFrontIntakeLoad();
#endif

/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
/** traditional-style mech library */
extern int intakeColorThreshold, shootColorThreshold;
extern double powerRollers, powerIndexer, powerShooter;
extern bool autoIndex, visionSort;
void setMech(int r, int i, int s);
void resetMech();
void setMech(int r, int i, int s, int t);
void waitIntakeColor();
void waitShootColor();
void autoFrontIntake();
void autoBackIntake();
void autoLoad();
void autoFrontIntakeLoad();
void MechControl(void * ignore);
#endif

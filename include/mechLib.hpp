/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
/** traditional-style mech library */
extern int intakeColorValue, shootColorValue, intakeColorThreshold, shootColorThreshold;
extern bool pauseMech;
void setPauseMech(bool pm);
void setMech(int l, int r, int i, int s);
void resetMech();
void setMech(int l, int r, int i, int s, int t);
void waitIntakeColor();
void waitShootColor();
void autoFrontIntake();
void autoBackIntake();
void autoLoad();
void autoFrontIntakeLoad();
/* void auto2for2();
void auto2for1();
void auto1for1();
void auto1for0();
void auto2for0();
void shoot(int s, int t);
void centerpole();
void asyncFrontIntake();
void asyncBackIntake();
void asyncLoad();
void asyncFrontIntakeLoad();
void asyncDouble();
void asyncShoot(int s, int t);
void mechControl(void * ignore); */
#endif

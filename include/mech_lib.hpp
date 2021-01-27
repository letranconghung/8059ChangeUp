/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
/** traditional-style mech library */
void setMech(int l, int r, int i, int s);
void resetMech();
void setMech(int l, int r, int i, int s, int t);
void waitIntakeColor();
void waitShootColor();
void autoFrontIntake();
void autoBackIntake();
void autoLoad();
void autoFrontIntakeLoad();
void shoot(int s);
void shoot(int s, int t);
void mechControl(void * ignore);
/** async mech library for increased efficiency (not working) */
// enum MECH_MODE{
//   E_DEFAULT = 0,
//   E_AUTO_FRONT_INTAKE = 1,
//   E_AUTO_BACK_INTAKE = 2,
//   E_AUTO_LOAD = 3,
//   E_AUTO_INTAKE_LOAD = 4,
//   E_TIMED_CYCLE = 5,
//   E_TIMED_REVERSE_CYCLE = 6,
//   E_TIMED_COLUMN_CYCLE = 7,
//   E_MANUAL = 8,
//   E_TIMED_FRONT_OUTTAKE = 9
// };
// void mech(bool b);
// void setMechMode(int value);
// void mechBlock();
// void mechControl(void * ignore);
// void autoFrontIntake();
// void autoBackIntake();
// void autoLoad();
// void autoIntakeLoad();
// void timedCycle(int p_shooterSpeed, int duration);
// void timedReverseCycle(int duration);
// void timedColumnCycle(int p_shooterSpeed, int duration);
// void timedFrontOuttake(int duration);


#endif

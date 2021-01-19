/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
#endif
void waitIntakeColor();
void waitShootColor();
void mechBlock();
void mechControl(void * ignore);
void autoFrontIntake();
void autoBackIntake();
void autoLoad();
void autoIntakeLoad();
void timedCycle(int p_shooterSpeed, int duration);
void timedReverseCycle(int duration);
void timedColumnCycle(int p_shooterSpeed, int duration);

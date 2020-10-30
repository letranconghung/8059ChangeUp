/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
void intakeMove(int speed);
void waitCycle();
void cycle();
void setDiscard(bool value);
void forceStop();
void pickUp(int power);
void shooterControl(void * ignore);
void shooterMotorControl(void * ignore);
#endif

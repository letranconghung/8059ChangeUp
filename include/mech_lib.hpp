/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
void intakeMove(int speed);
void cycle();
void setDiscard(bool value);
void pickUp(int power);
void shoot(double speed, double time);
void shooterControl(void * ignore);
#endif

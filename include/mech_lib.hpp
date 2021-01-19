/** Header file for mech_lib.cpp */
#ifndef _MECH_LIB_HPP_
#define _MECH_LIB_HPP_
/** refer to mech_lib.cpp for function documentation */
#endif
void indexerControl(void * ignore);
void shooterControl(void * ignore);
void frontIntake();
void backIntake();
void load();
void suck(int duration);
void shoot(int shootDuration);
void loadshoot(int shootDuration);
void cycle(int duration);
void frontOuttake(int duration);
void waitIndexer();

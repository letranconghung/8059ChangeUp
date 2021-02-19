#ifndef _8059_SIMPLE_PID_CONTROL_HPP_
#define _8059_SIMPLE_PID_CONTROL_HPP_
extern double errorEncdL, errorEncdR, powerL, powerR;
void baseMove(double dis, double kp, double kd);
void baseMove(double dis);
void baseTurn(double bearing, double kp, double kd);
void baseTurn(double bearing);
void waitBase(double cutoff);
void Control(void * ignore);
void resetCoords(double x, double y);
#endif

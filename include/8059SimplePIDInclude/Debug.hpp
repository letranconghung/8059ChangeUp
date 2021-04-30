#ifndef _8059_SIMPLE_PID_DEBUG_HPP_
#define _8059_SIMPLE_PID_DEBUG_HPP_
extern bool driverView;
void Debug(void * ignore);
void printPosTerminal();
void printPosMaster();
void printEncdTerminal();
void printErrorEncdTerminal();
void printPowerTerminal();
#endif

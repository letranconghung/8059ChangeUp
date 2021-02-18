#include "main.h"
const double inPerDeg = 0.31212;
double X = 0, Y = 0;
void setCoords(double x, double y){
  X = x;
  Y = y;
}
void Odometry(void * ignore){
  double prevEncdL = 0, prevEncdR = 0;
  int count = 0;
  while(true){
    double encdChangeL = encdL-prevEncdL;
    double encdChangeR = encdR-prevEncdR;

    double distance = (encdChangeL + encdChangeR)/2*inPerDeg;
    X += distance*cos(angle);
    Y += distance*sin(angle);
    /** update prev variables */
		prevEncdL = encdL;
		prevEncdR = encdR;
    Task::delay(5);
  }
}

#include "main.h"
const double inPerDeg = 0.0372817639078584;
double X = 0, Y = 0;
void setCoords(double x, double y){
  X = x;
  Y = y;
}
void Odometry(void * ignore){
  double prevEncdL = 0, prevEncdR = 0;
  Imu imu (imuPort);
  while(true){
    if(!imu.is_calibrating()){
      double encdChangeL = encdL-prevEncdL;
      double encdChangeR = encdR-prevEncdR;

      double distance = (encdChangeL + encdChangeR)/2*inPerDeg;
      X += distance*cos(angle);
      Y += distance*sin(angle);
      /** update prev variables */
  		prevEncdL = encdL;
  		prevEncdR = encdR;
    }
    Task::delay(5);
  }
}

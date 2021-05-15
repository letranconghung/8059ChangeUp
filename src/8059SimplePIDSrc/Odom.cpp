#include "main.h"
const double inPerDeg = 0.000242;
const double baseWidth = 9.184739638761836;
double X = 0, Y = 0, bearing = 0, angle = halfPI, prevEncdL = 0, prevEncdR = 0;
void setCoords(double x, double y, double b){
  X = x;
  Y = y;
  bearing = b*toRad;
}
const int validThresh = 18;
void Odometry(void * ignore){
  Imu imu (imuPort);
  int count = 0;
  double changeX = 0, changeY = 0, changeBearing = 0;
  while(true){
    double encdChangeL = encdL-prevEncdL;
    double encdChangeR = encdR-prevEncdR;
    if(fabs(encdChangeL)>=validThresh || fabs(encdChangeR)>=validThresh){
      printf("valid\n: %.2f\t%.2f\n", encdChangeL, encdChangeR);
      double distance = (encdChangeL + encdChangeR)/2*inPerDeg;
      changeBearing = (encdChangeL - encdChangeR)*inPerDeg/baseWidth;
      changeX = distance * cos(angle);
      changeY = distance * sin(angle);
      /** update prev variables */
      X += changeX;
      Y += changeY;
      bearing += changeBearing;
      angle = halfPI - bearing;
    }else{
      printf("invalid\n");
    }
    prevEncdL = encdL;
    prevEncdR = encdR;
    Task::delay(5);
  }
}

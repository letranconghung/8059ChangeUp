#include "main.h"
#define RED 1
#define BLUE 2
bool ballRed = true;
bool allianceRed = true;
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;
int intakeColorValue = 0, shootColorValue = 0;
void Sensors(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);
  while(true){
    if(!imu.is_calibrating()){
      encdL = FL.get_position();
      encdR = FR.get_position();
      bearing = imu.get_rotation();
      angle = halfPI - bearing * toRad;
    }
    delay(5);
  }
}
void VisSort(void * ignore){
  Vision vis (visPort);
  int count = 0;
  while(true){
    vision_object_s_t blueBall = vis.get_by_sig(0, BLUE);
    vision_object_s_t redBall = vis.get_by_sig(0, RED);
    if(++count % 10 == 0){
      printf("RED: w: %d\t h: %d\n", redBall.width, redBall.height);
      printf("BLUE: w: %d\t h: %d\n", blueBall.width, blueBall.height);
    }
    if(redBall.width>= 40 && redBall.height>= 40){
      ballRed = true;
    } else{
      if (blueBall.width>= 40 && blueBall.height>= 40){
        ballRed = false;
      }
    }
    delay(5);
  }
}

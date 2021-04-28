#include "main.h"
#define SIG_RED 1
#define SIG_BLUE 7
bool redBall = true;
bool redAlliance = true;
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;
int intakeColorValue = 0, shootColorValue = 0;
void Sensors(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);
  Vision vis (visPort);
	ADIAnalogIn intakeColor (intakeColorPort);
	ADIAnalogIn shootColor (shootColorPort);
  while(true){
    if(!imu.is_calibrating()){
      encdL = FL.get_position();
      encdR = FR.get_position();
      bearing = imu.get_rotation();
      angle = halfPI - bearing * toRad;
    }
    intakeColorValue = intakeColor.get_value();
    shootColorValue = shootColor.get_value();
    // vision code
    vision_object_s_t size = vis.get_by_size(0);
    if(size.width >= 100 && size.height >= 100){
      int sig = size.signature;
      if(sig == SIG_RED){
        redBall = true;
      }else if(sig == SIG_BLUE){
        redBall = false;
      }
    }
    delay(5);
  }
}

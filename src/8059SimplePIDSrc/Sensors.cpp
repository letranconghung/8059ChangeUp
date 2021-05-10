#include "main.h"
#define SIG_RED 1
#define SIG_BLUE 7
bool allianceBall = true;
int ball = 1, alliance = 1;
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;
int intakeColorValue = 0, shootColorValue = 0;
int proximity = 0, width = 0, height = 0;
int wThreshold = 100, hThreshold = 100;
c::optical_rgb_s_t rgb;
int optBall = 0;
void Sensors(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);
  Vision vis (visPort);
	ADIAnalogIn intakeColor (intakeColorPort);
	ADIAnalogIn shootColor (shootColorPort);
  Optical opt(optPort);
  Rotation lRot(lRotPort);
  Rotation rRot(rRotPort);
  while(true){
    if(!imu.is_calibrating()){
      encdL = lRot.get_position();
      encdR = rRot.get_position();
      bearing = imu.get_rotation();
      angle = halfPI - bearing * toRad;
    }
    intakeColorValue = intakeColor.get_value();
    shootColorValue = shootColor.get_value();
    // vision code
    vision_object_s_t size = vis.get_by_size(0);
    width = size.width;
    height = size.height;
    if(width >= wThreshold && height >= hThreshold){
      int sig = size.signature;
      if(sig == SIG_RED){
        ball = 1;
      }else if(sig == SIG_BLUE){
        ball = 2;
      }
    }else{
      ball = 0;
    }
    allianceBall = (ball == alliance);
    // optical code
    rgb = opt.get_rgb();
    proximity = opt.get_proximity();
    // printf("prox: %d r: %.2f\t g: %.2f\t b: %.2f\n", proximity, rgb.red, rgb.blue, rgb.green);
    if(proximity > 200) optBall = ((rgb.red > rgb.blue? 1 : 2));
    else optBall = 0;
    delay(5);
  }
}

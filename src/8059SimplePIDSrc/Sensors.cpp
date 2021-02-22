#include "main.h"
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;

void Sensors(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);
  int count = 0;
  while(true){
    if(imu.is_calibrating()){
      if (++count % 10 == 0) printf("imu is calibrating...\n");
    }else{
      encdL = BL.get_position();
      encdR = BR.get_position();
      bearing = imu.get_rotation();
      angle = halfPI - bearing * toRad;
    }
    delay(5);
  }
}

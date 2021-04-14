#include "main.h"
double encdL = 0, encdR = 0, bearing = 0, angle = halfPI;

void Sensors(void * ignore){
  Motor L1(L1Port);
	Motor L2(L2Port);
	Motor L3(L3Port);
	Motor R1(R1Port);
	Motor R2(R2Port);
	Motor R3(R3Port);
  Imu imu (imuPort);
  while(true){
    if(!imu.is_calibrating()){
      encdL = L1.get_position();
      encdR = R1.get_position();
      bearing = imu.get_rotation();
      angle = halfPI - bearing * toRad;
    }
    delay(5);
  }
}

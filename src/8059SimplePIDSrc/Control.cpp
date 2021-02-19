#include "main.h"
#define DEFAULT_KP 0.525
#define DEFAULT_KD 0.15
#define DEFAULT_TURN_KP 0.525
#define DEFAULT_TURN_KD 0.15
#define RAMPING_POW 5
#define DISTANCE_LEEWAY 3
double targEncdL = 0, targEncdR = 0, targBearing = 0;
double errorEncdL = 0, errorEncdR = 0;
double powerL = 0, powerR = 0;
double targPowerL = 0, targPowerR = 0;
double kP = DEFAULT_KP, kD = DEFAULT_KD;

bool turnMode = false;

void baseMove(double dis, double kp, double kd){
  targEncdL += dis/inPerDeg;
  targEncdR += dis/inPerDeg;

  kP = kp;
  kD = kd;
}
void baseMove(double dis){
  baseMove(dis, DEFAULT_KP, DEFAULT_KD);
}

void baseTurn(double bearing, double kp, double kd){
  targBearing = bearing;
	kP = kp;
	kD = kd;
}
void baseTurn(double bearing){
  baseTurn(bearing, DEFAULT_TURN_KP, DEFAULT_TURN_KD);
}

void waitBase(double cutoff){
	double start = millis();
	while(fabs(targEncdL - encdL) > DISTANCE_LEEWAY && fabs(targEncdR - encdR) > DISTANCE_LEEWAY && (millis()-start) < cutoff) delay(20);

  targEncdL = encdL;
  targEncdR = encdR;
}

void Control(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);

  while(competition::is_autonomous()){
    if(!imu.is_calibrating()) {
      if(turnMode){
        double errorBearing = targBearing - bearing;
        targPowerL = errorBearing * kP;
        targPowerR = -errorBearing * kP;
      }else{
        double errorEncdL = targEncdL - encdL;
        double errorEncdR = targEncdR - encdR;

        targPowerL = errorEncdL * kP;
        targPowerR = errorEncdR * kP;
      }

      double deltaPowerL = targPowerL - powerL;
      powerL += abscap(deltaPowerL, RAMPING_POW);
      double deltaPowerR = targPowerR - powerR;
      powerR += abscap(deltaPowerR, RAMPING_POW);

      powerL = abscap(powerL, 127);
      powerR = abscap(powerR, 127);

      FL.move(powerL);
      BL.move(powerL);
      FR.move(powerR);
      BR.move(powerR);
    }
    delay(5);
  }
}

void resetCoords(double x, double y){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);

  setCoords(x, y);

  FL.tare_position();
  FR.tare_position();
  BL.tare_position();
  BR.tare_position();

  targEncdL = 0;
  targEncdR = 0;
}

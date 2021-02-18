#include "main.h"
#define DEFAULT_KP 0.525
#define DEFAULT_KD 0.15
#define DEFAULT_TURN_KP 0.525
#define DEFAULT_TURN_KD 0.15
#define RAMPING_POW 5
double targEncdL = 0, targEncdR = 0, targBearing = 0;
double errorEncdL = 0, errorEncdR = 0;
double powerL = 0, powerR = 0;
double targPowerL = 0, targPowerR = 0;
double kP = DEFAULT_KP, kD = DEFAULT_KD;

bool turnMode = false;

void baseMove(double dis, double kp, double kd){
  targetEncdL += dis/inPerDeg;
  targetEncdR += dis/inPerDeg;

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
	while(fabs(targetEncdL - encdL) > DISTANCE_LEEWAY && fabs(targetEncdR - encdR) > DISTANCE_LEEWAY && (millis()-start) < cutoff) delay(20);

  targetEncdL = encdL;
  targetEncdR = encdR;
}

void Control(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);

  while(true){
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

    double deltaPowerL = targetPowerL - powerL;
    powerL += abscap(deltaPowerL, RAMPING_POW);
    double deltaPowerR = targetPowerR - powerR;
    powerR += abscap(deltaPowerR, RAMPING_POW);

    powerL = abscap(powerL, 127);
    powerR = abscap(powerR, 127);

    FL.move(powerL);
    BL.move(powerL);
    FR.move(powerR);
    BR.move(powerR);
    delay(5);
  }
}

void resetCoords(double x, double y){
  setCoords(x, y);

  FL.tare_position();
  FR.tare_position();
  BL.tare_position();
  BR.tare_position();

  targetEncdL = 0;
  targetEncdR = 0;
}

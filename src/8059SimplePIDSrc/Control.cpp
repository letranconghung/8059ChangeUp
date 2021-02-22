#include "main.h"
#define DEFAULT_KP 0.35
#define DEFAULT_KD 0.1
#define DEFAULT_TURN_KP 1.25
#define DEFAULT_TURN_KD 0.10
#define RAMPING_POW 1.2
#define DISTANCE_LEEWAY 2
#define BEARING_LEEWAY 5
#define MAX_POW 100

double targEncdL = 0, targEncdR = 0, targBearing = 0;
double errorEncdL = 0, errorEncdR = 0;
double powerL = 0, powerR = 0;
double targPowerL = 0, targPowerR = 0;
double kP = DEFAULT_KP, kD = DEFAULT_KD;

bool turnMode = false, pauseBase = false;

void baseMove(double dis, double kp, double kd){
  turnMode = false;
  targEncdL += dis/inPerDeg;
  targEncdR += dis/inPerDeg;

  kP = kp;
  kD = kd;
}
void baseMove(double dis){
  baseMove(dis, DEFAULT_KP, DEFAULT_KD);
}

void baseTurn(double p_bearing, double kp, double kd){
  turnMode = true;
  targBearing = p_bearing;
	kP = kp;
	kD = kd;
}
void baseTurn(double bearing){
  baseTurn(bearing, DEFAULT_TURN_KP, DEFAULT_TURN_KD);
}

void powerBase(double l, double r) {
  pauseBase = true;
  powerL = l;
  powerR = r;
}

void timerBase(double l, double r, double t) {
  pauseBase = true;
  powerL = l;
  powerR = r;
  delay(t);
  powerL = 0;
  powerR = 0;
  pauseBase = false;
  resetCoords(X, Y);
}

void unPauseBase() {
  powerL = 0;
  powerR = 0;
  pauseBase = false;
  resetCoords(X, Y);
}

void waitBase(double cutoff){
	double start = millis();
  if(turnMode) {
    while(fabs(targBearing - bearing) > BEARING_LEEWAY && (millis()-start) < cutoff) delay(20);
  }else{
    while((fabs(targEncdL - encdL) > DISTANCE_LEEWAY && fabs(targEncdR - encdR) > DISTANCE_LEEWAY) || (millis()-start) < cutoff) delay(20);
  }

  targEncdL = encdL;
  targEncdR = encdR;
}

void Control(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);

  double prevErrorEncdL = 0, prevErrorEncdR = 0, prevErrorBearing = 0;
  while(competition::is_autonomous()){
    if(!imu.is_calibrating() && !pauseBase) {
      if(turnMode){
        double errorBearing = targBearing - bearing;
        double deltaErrorBearing = errorBearing - prevErrorBearing;

        targPowerL = errorBearing * kP + deltaErrorBearing * kD;
        targPowerR = -targPowerL;

        prevErrorBearing = errorBearing;
      }else{
        errorEncdL = targEncdL - encdL;
        errorEncdR = targEncdR - encdR;

        double deltaErrorEncdL = errorEncdL - prevErrorEncdL;
        double deltaErrorEncdR = errorEncdR - prevErrorEncdR;

        targPowerL = errorEncdL * kP + deltaErrorEncdL * kD;
        targPowerR = errorEncdR * kP + deltaErrorEncdR * kD;

        prevErrorEncdL = errorEncdL;
        prevErrorEncdR = errorEncdR;
      }

      double deltaPowerL = targPowerL - powerL;
      powerL += abscap(deltaPowerL, RAMPING_POW);
      double deltaPowerR = targPowerR - powerR;
      powerR += abscap(deltaPowerR, RAMPING_POW);

      powerL = abscap(powerL, MAX_POW);
      powerR = abscap(powerR, MAX_POW);
    }
    FL.move(powerL);
    BL.move(powerL);
    FR.move(powerR);
    BR.move(powerR);
    delay(5);
  }
}

void resetCoords(double x, double y){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);

  FL.tare_position();
  FR.tare_position();
  BL.tare_position();
  BR.tare_position();
  resetPrevEncd();

  targBearing = bearing;
  targEncdL = 0;
  targEncdR = 0;

  setCoords(x, y);
}

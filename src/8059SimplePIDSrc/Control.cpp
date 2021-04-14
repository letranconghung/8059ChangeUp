#include "main.h"
#define DEFAULT_KP 0.35
#define DEFAULT_KD 0.001
#define DEFAULT_TURN_KP 1.8
#define DEFAULT_TURN_KD 0.01
#define RAMPING_POW 3
#define DISTANCE_LEEWAY 12
#define BEARING_LEEWAY 1.5
#define MAX_POW 115

double targEncdL = 0, targEncdR = 0, targBearing = 0;
double errorEncdL = 0, errorEncdR = 0, errorBearing = 0;
double powerL = 0, powerR = 0;
double targPowerL = 0, targPowerR = 0;
double kP = DEFAULT_KP, kD = DEFAULT_KD;

bool turnMode = false, pauseBase = false;

void baseSpeed(double dis, double kp){

}
void baseMove(double dis, double kp, double kd){
  printf("baseMove: %.1f\t", dis);
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
  printf("baseTurn: %.1f\t", p_bearing);
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

void waitBase(int cutoff){
	int start = millis();
  if(turnMode) {
    while(fabs(targBearing - bearing) > BEARING_LEEWAY && (millis()-start) < cutoff) delay(20);
  }else{
    while((fabs(targEncdL - encdL) > DISTANCE_LEEWAY || fabs(targEncdR - encdR) > DISTANCE_LEEWAY) && (millis()-start) < cutoff) delay(20);
  }

  targEncdL = encdL;
  targEncdR = encdR;

  printf("time taken: %d ms\t cutoff: %d ms\n", millis() - start, cutoff);
}

void Control(void * ignore){
  Motor L1(L1Port);
	Motor L2(L2Port);
	Motor L3(L3Port);
	Motor R1(R1Port);
	Motor R2(R2Port);
	Motor R3(R3Port);
  Imu imu (imuPort);
  int count = 0;
  double prevErrorEncdL = 0, prevErrorEncdR = 0, prevErrorBearing = 0;
  while(true){
    if(!imu.is_calibrating() && !pauseBase) {
      if(turnMode){
        errorBearing = targBearing - bearing;
        double deltaErrorBearing = errorBearing - prevErrorBearing;

        targPowerL = errorBearing * kP + deltaErrorBearing * kD;
        targPowerR = -targPowerL;

        prevErrorBearing = errorBearing;

        // package
        double deltaPowerL = targPowerL - powerL;
        powerL += abscap(deltaPowerL, RAMPING_POW);
        double deltaPowerR = targPowerR - powerR;
        powerR += abscap(deltaPowerR, RAMPING_POW);

        powerL = abscap(powerL, MAX_POW);
        powerR = abscap(powerR, MAX_POW);
        // package
      }else{
        errorEncdL = targEncdL - encdL;
        errorEncdR = targEncdR - encdR;

        double deltaErrorEncdL = errorEncdL - prevErrorEncdL;
        double deltaErrorEncdR = errorEncdR - prevErrorEncdR;

        targPowerL = errorEncdL * kP + deltaErrorEncdL * kD;
        targPowerR = errorEncdR * kP + deltaErrorEncdR * kD;

        double deltaPowerL = targPowerL - powerL;
        powerL += abscap(deltaPowerL, RAMPING_POW);
        double deltaPowerR = targPowerR - powerR;
        powerR += abscap(deltaPowerR, RAMPING_POW);


        // moving straight factor
        double mod = 1;
        // double modConst;
        // if(errorEncdL < 0) modConst = 1.01;
        // else modConst = 1/1.001;
        // if(errorEncdR != 0) mod = modConst*errorEncdL/errorEncdR;

        powerL = abscap(powerL, MAX_POW);
        powerR = abscap(powerR, MAX_POW);

        // if(++count % 10 == 0) printf("power: %.1f %.1f", powerL, powerR);

        if(mod >= 1) powerR /= mod;
        else powerL /= mod;

        // if(count % 10 == 0) printf("\t modded power: %.1f %.1f\n", powerL, powerR);
        prevErrorEncdL = errorEncdL;
        prevErrorEncdR = errorEncdR;
      }
    }
    L1.move(powerL);
    L2.move(powerL);
    L3.move(powerL);
    R1.move(powerR);
    R2.move(powerR);
    R3.move(powerR);
    delay(5);
  }
}

void resetCoords(double x, double y){
  Motor L1(L1Port);
  Motor L2(L2Port);
  Motor L3(L3Port);
  Motor R1(R1Port);
  Motor R2(R2Port);
  Motor R3(R3Port);

  L1.tare_position();
  L2.tare_position();
  L3.tare_position();
  R1.tare_position();
  R2.tare_position();
  R3.tare_position();
  resetPrevEncd();

  targBearing = bearing;
  targEncdL = 0;
  targEncdR = 0;

  setCoords(x, y);
}

#include "main.h"
#define DEFAULT_KP 0.0012
#define DEFAULT_KD 0
#define DEFAULT_TURN_KP 0.95
#define DEFAULT_TURN_KD 0
#define RAMPING_POW 2.5
#define DISTANCE_LEEWAY 2000
#define BEARING_LEEWAY 1

// #define DEFAULT_KP 0.001275
// #define DEFAULT_KD 0
// #define DEFAULT_TURN_KP 0.95
// #define DEFAULT_TURN_KD 0
// #define RAMPING_POW 1
// #define DISTANCE_LEEWAY 4000
// #define BEARING_LEEWAY 0.4

// const double MAX_POW = 115;
const double MAX_POW = 120;
double targEncdL = 0, targEncdR = 0, targBearing = 0;
double errorEncdL = 0, errorEncdR = 0, errorBearing = 0;
double prevErrorEncdL = 0, prevErrorEncdR = 0, prevErrorBearing = 0;
double powerL = 0, powerR = 0;
double targPowerL = 0, targPowerR = 0;
double kP = DEFAULT_KP, kD = DEFAULT_KD;
bool turnMode = false, pauseBase = false;
bool baseBraking = false;
bool movementEnded = false;
void baseMove(double dis, double kp, double kd){
  pauseBase = false;
  movementEnded = false;
  printf("baseMove: %.1f\t", dis);
  turnMode = false;
  targEncdL = encdL + dis/inPerDeg;
  targEncdR = encdR + dis/inPerDeg;

  kP = kp;
  kD = kd;
}
void baseMove(double dis){
  baseMove(dis, DEFAULT_KP, DEFAULT_KD);
}
void baseTurn(double b, double kp, double kd){
  pauseBase = false;
  movementEnded = false;
  printf("baseTurn: %.1f\t", b);
  targBearing = bearing + boundDegTurn(b - bearing);
  printf("targBearing: %.1f\n", targBearing);
  turnMode = true;
	kP = kp;
	kD = kd;
}
void baseTurn(double b){
  baseTurn(b, DEFAULT_TURN_KP, DEFAULT_TURN_KD);
}
void powerBase(double l, double r) {
  pauseBase = true;
  movementEnded = false;
  powerL = l;
  powerR = r;
}
void timerBase(double l, double r, double t) {
  pauseBase = true;
  movementEnded = false;
  powerL = l;
  powerR = r;
  delay(t);
  powerL = 0;
  powerR = 0;
  // pauseBase = false;
  movementEnded = true;
  delay(15);
  pauseBase = false;
}
void unPauseBase() {
  powerL = 0;
  powerR = 0;
  pauseBase = false;
}

void waitBase(int cutoff){
	int start = millis();
  if(turnMode) {
    while(fabs(targBearing - bearing)*toDeg > BEARING_LEEWAY && (millis()-start) < cutoff) delay(5);
  }else{
    while((fabs(targEncdL - encdL) > DISTANCE_LEEWAY || fabs(targEncdR - encdR) > DISTANCE_LEEWAY) && (millis()-start) < cutoff)
    delay(5);
  }
  pauseBase = true;
  movementEnded = true;
  printf("\n\n\n\n");
  printf("time taken: %d ms\t cutoff: %d ms\n", millis() - start, cutoff);
  printf("\n\n\n\n");
}

void Control(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  int count = 0;
  prevErrorEncdL = 0, prevErrorEncdR = 0, prevErrorBearing = 0;
  while(true){
    if(!pauseBase) {
      if(turnMode){
        errorBearing = targBearing - bearing;
        double deltaErrorBearing = errorBearing - prevErrorBearing;

        targPowerL = errorBearing * kP + deltaErrorBearing * kD;
        targPowerR = -targPowerL;
        prevErrorBearing = errorBearing;

        double deltaPowerL = targPowerL - powerL;
        powerL += abscap(deltaPowerL, RAMPING_POW);
        double deltaPowerR = targPowerR - powerR;
        powerR += abscap(deltaPowerR, RAMPING_POW);

        powerL = abscap(powerL, MAX_POW);
        powerR = abscap(powerR, MAX_POW);

        // misc
        targEncdL = encdL;
        targEncdR = encdR;
      }else{
        errorEncdL = targEncdL - encdL;
        errorEncdR = targEncdR - encdR;
        // printf("\n");
        // printf("errorEncd: %.1f\t%.1f\n", errorEncdL, errorEncdR);
        double deltaErrorEncdL = errorEncdL - prevErrorEncdL;
        double deltaErrorEncdR = errorEncdR - prevErrorEncdR;
        // printf("prevErrorEncd: %.1f\t%.1f\n", prevErrorEncdL, prevErrorEncdR);
        // printf("deltaErrorEncd: %.1f\t%.1f\n", deltaErrorEncdL, deltaErrorEncdR);
        double pd_targPowerL = errorEncdL * kP + deltaErrorEncdL * kD;
        double pd_targPowerR = errorEncdR * kP + deltaErrorEncdR * kD;
        // printf("pd: %.2f\t%.2f\n", pd_targPowerL, pd_targPowerR);
        double pd_maxTargPower = std::max(fabs(pd_targPowerL), fabs(pd_targPowerR));
        double setPower = std::min(pd_maxTargPower, MAX_POW);
        // printf("setPower: %.2f\n", setPower);
        double lToR = ((pd_targPowerR != 0)? (pd_targPowerL/pd_targPowerR) : 1);
        if(lToR != 0){
            if(fabs(lToR)>=1){
              targPowerL = setPower*sign(pd_targPowerL);
              targPowerR = setPower*sign(pd_targPowerR)/fabs(lToR);
            } else{
              targPowerL = setPower*sign(pd_targPowerL)*fabs(lToR);
              targPowerR = setPower*sign(pd_targPowerR);
          }
        }
        // printf("targPower: %.2f\t%.2f\n", targPowerL, targPowerR);
        double deltaPowerL = targPowerL - powerL;
        double deltaPowerR = targPowerR - powerR;
        // printf("power: %.1f\t%.1f\n", powerL, powerR);
        // printf("delta: %.1f\t%.1f\n", deltaPowerL, deltaPowerR);
        deltaPowerL = abscap(deltaPowerL, RAMPING_POW);
        deltaPowerR = abscap(deltaPowerR, RAMPING_POW);
        // printf("capped delta: %.1f\t%.1f\n", deltaPowerL, deltaPowerR);
        powerL += deltaPowerL;
        powerR += deltaPowerR;
        // printf("updated power: %.1f\t%.1f\n", powerL, powerR);
        // manual base compensation factor
        double mod = 1; //>1 to make left faster, <1 to make right faster
        if(mod >= 1) powerR /= mod;
        else powerL *= mod;
        prevErrorEncdL = errorEncdL;
        prevErrorEncdR = errorEncdR;
      }
    }else if(movementEnded){
      // printf("******************\n");
      targEncdL = encdL;
      targEncdR = encdR;
      targBearing = bearing;
      errorEncdL = 0;
      errorEncdR = 0;
      errorBearing = 0;
      targPowerL = 0;
      targPowerR = 0;
      powerL = 0;
      powerR = 0;
      prevErrorEncdL = 0;
      prevErrorEncdR = 0;
      // printf("%.1f %.1f %.1f %.1f %.1f %.1f \n",targEncdL, errorEncdL, errorBearing, targPowerL, powerL, prevErrorEncdL);
    }
    FL.move(powerL);
    BL.move(powerL);
    FR.move(powerR);
    BR.move(powerR);
    if(baseBraking){
        if(powerL == 0 && powerR == 0){
            int brake = 5;
            FL.move(-brake * sign(powerL));
            BL.move(-brake * sign(powerL));
            FR.move(-brake * sign(powerR));
            BR.move(-brake * sign(powerR));
          }
        }
    delay(5);
  }
}

#include "main.h"
#define DEFAULT_KP 0.33
#define DEFAULT_KD 0
#define DEFAULT_TURN_KP 1
#define DEFAULT_TURN_KD 0
#define RAMPING_POW 5
#define DISTANCE_LEEWAY 3
#define BEARING_LEEWAY 1

const double MAX_POW = 100;

double targEncdL = 0, targEncdR = 0, targBearing = 0;
double errorEncdL = 0, errorEncdR = 0, errorBearing = 0;
double prevErrorEncdL = 0, prevErrorEncdR = 0, prevErrorBearing = 0;
double powerL = 0, powerR = 0;
double targPowerL = 0, targPowerR = 0;
double kP = DEFAULT_KP, kD = DEFAULT_KD;
bool turnMode = false, pauseBase = false;
bool baseBraking = false;
void baseMove(double dis, double kp, double kd){
  pauseBase = false;
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
  pauseBase = false;
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
    while((fabs(targEncdL - encdL) > DISTANCE_LEEWAY || fabs(targEncdR - encdR) > DISTANCE_LEEWAY) && (millis()-start) < cutoff) delay(5);
  }
  pauseBase = true;
  int brakepow = 1;
  powerL = brakepow*sign(errorEncdL);
  powerR = brakepow*sign(errorEncdR);
  delay(10);
  targEncdL = encdL;
  targEncdR = encdR;
  errorEncdL = 0;
  errorEncdR = 0;
  powerL = 0;
  powerR = 0;
  printf("time taken: %d ms\t cutoff: %d ms\n", millis() - start, cutoff);
}

void Control(void * ignore){
  Motor FL (FLPort);
  Motor BL (BLPort);
  Motor FR (FRPort);
  Motor BR (BRPort);
  Imu imu (imuPort);
  int count = 0;
  prevErrorEncdL = 0, prevErrorEncdR = 0, prevErrorBearing = 0;
  while(true){
    if(!imu.is_calibrating() && !pauseBase) {
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
      }else{
        errorEncdL = targEncdL - encdL;
        errorEncdR = targEncdR - encdR;

        double deltaErrorEncdL = errorEncdL - prevErrorEncdL;
        double deltaErrorEncdR = errorEncdR - prevErrorEncdR;

        double pd_targPowerL = errorEncdL * kP + deltaErrorEncdL * kD;
        double pd_targPowerR = errorEncdR * kP + deltaErrorEncdR * kD;
        // printf("pd: %.2f\t%.2f\n", pd_targPowerL, pd_targPowerR);
        double pd_maxTargPower = std::max(fabs(pd_targPowerL), fabs(pd_targPowerR));
        double setPower = std::min(pd_maxTargPower, MAX_POW);
        // printf("setPower: %.2f\n", setPower);
        double lToR = ((pd_targPowerR != 0)? (pd_targPowerL/pd_targPowerR) : 1);
        // double avgErrorEncd = (errorEncdL + errorEncdR)/2;
        // double adjustmentFactor = avgErrorEncd/10000;
        // adjustmentFactor = 0;
        // double allowance = 0.005;
        // if(fabs(lToR-1)<=allowance) adjustmentFactor = 0;
        // if(++count % 20 == 0) printf("adjustmentFactor: %.7f \n", adjustmentFactor);

        // if(lToR >= 1){
        //   lToR += adjustmentFactor;
        //   targPowerL = setPower;
        //   targPowerR = setPower/lToR;
        // }else{
        //   lToR -= adjustmentFactor;
        //   targPowerL = setPower*lToR;
        //   targPowerR = setPower;
        // }
        if(lToR != 0){
          // printf("got inside here\n");
            if(fabs(lToR)>=1){
              // printf("setPower: %.2f\t sign: %d\t%d\n", setPower, sign(targPowerL), sign(targPowerR));
              targPowerL = setPower*sign(pd_targPowerL);
              targPowerR = setPower*sign(pd_targPowerR)/fabs(lToR);
            } else{
              // printf("setPower: %.2f\t sign: %d\t%d\n", setPower, sign(targPowerL), sign(targPowerR));
              targPowerL = setPower*sign(pd_targPowerL)*fabs(lToR);
              targPowerR = setPower*sign(pd_targPowerR);
          }
        }
        double deltaPowerL = targPowerL - powerL;
        double deltaPowerR = targPowerR - powerR;
        // if(deltaPowerL > RAMPING_POW || deltaPowerR > RAMPING_POW){
        //   double deltaPowerMax = std::max(deltaPowerL, deltaPowerR);
        //   deltaPowerL = RAMPING_POW/deltaPowerMax*deltaPowerL;
        //   deltaPowerR = RAMPING_POW/deltaPowerMax*deltaPowerR;
        // }
        deltaPowerL = abscap(deltaPowerL, RAMPING_POW);
        deltaPowerR = abscap(deltaPowerR, RAMPING_POW);
        powerL += deltaPowerL;
        powerR += deltaPowerR;
        // manual base compensation factor
        double mod = 0.98; //>1 to make left faster, <1 to make right faster
        if(mod >= 1) powerR /= mod;
        else powerL *= mod;
        prevErrorEncdL = errorEncdL;
        prevErrorEncdR = errorEncdR;
      }
    }
    FL.move(powerL);
    BL.move(powerL);
    FR.move(powerR);
    BR.move(powerR);
    if(baseBraking){
      printf("base braking on \n");
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

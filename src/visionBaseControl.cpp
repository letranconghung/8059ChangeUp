#include "main.h"
Motor FL (FLport);
Motor BL (BLport);
Motor FR (FRport);
Motor BR (BRport);
#define DEFAULT_X_KP .6
#define DEFAULT_X_KD .1
#define DEFAULT_W_KP 1.0
#define DEFAULT_W_KD .2
int targSig;
double targetPowerL = 0, targetPowerR = 0;
double powerL = 0, powerR = 0;
double XkP = DEFAULT_X_KP, XkD = DEFAULT_X_KD, WkP = DEFAULT_W_KP, WkD = DEFAULT_W_KD;
double errorX = 0, errorW = 0;
void visionBaseMove(int sig, double xkp, double xkd, double wkp, double wkd){
  targSig = sig;
  XkP = xkp;
  XkD = xkd;
  WkP = wkp;
  WkD = wkd;
}
void visionBaseMove(int sig){
  targSig = sig;
  XkP = DEFAULT_X_KP;
  XkD = DEFAULT_X_KD;
  WkP = DEFAULT_W_KP;
  WkD = DEFAULT_W_KD;
}
void waitBase(double cutoff){
  double start = millis();
  while((fabs(errorX) > X_LEEWAY || fabs(errorW) > W_LEEWAY) && (millis()-start) < cutoff) delay(20);
  /** stop the motors */
  FL.move(0);
  BL.move(0);
  FR.move(0);
  BR.move(0);
}
void visionBaseControl(void * ignore){
  Controller master(E_CONTROLLER_MASTER);
  int i = 0;
  double prevErrorX = 0, prevErrorW = 0;
  while(competition::is_autonomous() || !VISION_COMPETITION_MODE){
    VisionObject v;
    switch(targSig){
      case 1: v = redBall; break;
      case 2: v = blueBall; break;
      case 3: v = greenFlag; break;
      // default: printf("Invalid move in visionBaseControl\n");
    }
    errorX = v.targ.x - v.curr.x;
    errorW = v.targ.w - v.curr.w;
    double deltaErrorX = errorX - prevErrorX;
    double deltaErrorW = errorW - prevErrorW;

    prevErrorX = errorX;
    prevErrorW = errorW;

    double move = WkP*errorW + WkD*prevErrorW;
    double turn = XkP*errorX + XkD*prevErrorX;

    targetPowerL = move - turn;
    targetPowerR = move + turn;

    double deltaPowerL = targetPowerL - powerL;
    powerL += abscap(deltaPowerL, RAMPING_POW);
    double deltaPowerR = targetPowerR - powerR;
    powerR += abscap(deltaPowerR, RAMPING_POW);

    powerL = abscap(powerL, MAX_POW);
    powerR = abscap(powerR, MAX_POW);
    FL.move(powerL);
    BL.move(powerL);
    FR.move(powerR);
    BR.move(powerR);
    if(VISION_DEBUG_MODE == 2 && (++i % 10 == 0)){
      master.print(2, 0, "PWR: %3.1f %3.1f",powerL,powerR);
      printf("-----------------------------------------------------------------\n");
      printf("ErrorX: %3.0f \t ErrorW: %3.0f\n",errorX,errorW);
      printf("move: %3.1f \t turn: %3.1f\t", move, turn);
      printf("TargetPower: %3.1f \t %3.1f\n",targetPowerL,targetPowerR);
      printf("Power: %3.1f \t %3.1f\n",powerL,powerR);
    }
    Task::delay(10);
  }
}

// void visionBaseMotorControl(void * ignore){
//   double powerL = 0, powerR = 0;
//   while(competition::is_autonomous() || !VISION_COMPETITION_MODE){
//     double deltaPowerL = targetPowerL - powerL;
//     powerL += abscap(deltaPowerL, RAMPING_POW);
//     double deltaPowerR = targetPowerR - powerR;
//     powerR += abscap(deltaPowerR, RAMPING_POW);
//
//     powerL = abscap(powerL, MAX_POW);
//     powerR = abscap(powerR, MAX_POW);
//
//     // FL.move(powerL);
//     // BL.move(powerL);
//     // FR.move(powerR);
//     // BR.move(powerR);
//     if(VISION_DEBUG_MODE == 2) printf("%3.0f \t %3.0f\n",powerL,powerR);
//     Task::delay(10);
//   }
// }

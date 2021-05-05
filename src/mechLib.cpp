/** Other mechanical functions. */
#include "main.h"
#include "mechLib.hpp"
/** declare motors and sensors */
/** thresholds */
int iMax = 127;
int rMax = 127;
int iLoad = 127;
int intakeColorThreshold = 2850;
int shootColorThreshold = 2830; // working 2830
double powerRollers = 0, powerIndexer = 0, powerShooter = 0;
bool autoIndex = true;
bool autoCycle = false;
int stage = 0;
int nOpp = 1;
void setMech(int r, int i, int s){
  powerRollers = r;
  powerIndexer = i;
  powerShooter = s;
}
void resetMech(){
  setMech(0, 0, 0);
}
void setMech(int r, int i, int s, int t){
  setMech(r, i, s);
  delay(t);
  resetMech();
}
void waitIntakeColor(){
  // printf("wait intake color \t value: %d\n", shootColorValue);
  while(intakeColorValue>intakeColorThreshold) delay(5);
}
void waitShootColor(){
  // printf("wait Shoot color \t value: %d\n", shootColorValue);
  while(shootColorValue>shootColorThreshold) delay(5);
}
void autoFrontIntake(){
  setMech(rMax, iMax, 0);
  waitIntakeColor();
  resetMech();
}
void autoBackIntake(){
  setMech(0, iMax, 0);
  waitIntakeColor();
  resetMech();
}
/** can be used for backIntakeLoad */
void autoLoad(){
  printf("auto load\n");
  setMech(0, iLoad, 0);
  waitShootColor();
  resetMech();
}
void startAutoCycle(int n){
  printf("pressed: %d\n", n);
  nOpp = n;
  autoCycle = true;
  stage = 0;
}
void stopAutoCycle(){
  autoCycle = false;
  stage = 0;
}
void MechControl(void * ignore){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor indexer (indexerPort);
  Motor shooter (shooterPort);
  double indexerMove = 0, shooterMove = 0, rollersMove = 0;
  while(true){
    if(autoCycle){
      if(nOpp == 2){
        if(stage == 0){
          rollersMove = 1;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance) stage = 1;
        }
        if(stage == 1){
          rollersMove = 1;
          indexerMove = 0.5;
          shooterMove = -1;
          if(optBall == 3 - alliance) stage = 2;
        }
        if(stage == 2){
          rollersMove = 0;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance) stopAutoCycle();
        }
      }else{
        if(stage == 0){
          rollersMove = 1;
          indexerMove = 1;
          shooterMove = 1;
          if(optBall == 3 - alliance) stage = 1;
        }
        if(stage == 1){
          rollersMove = 0;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance) stopAutoCycle();
        }
      }
      powerRollers = 127*rollersMove;
      powerIndexer = 127*indexerMove;
      powerShooter = 127*shooterMove;
    }
    lRoller.move(powerRollers);
    rRoller.move(powerRollers);
    indexer.move(powerIndexer);
    shooter.move(powerShooter);
    delay(5);
  }
}

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
int mechMode = 0;
double powerRollers = 0, powerIndexer = 0, powerShooter = 0;
bool firstStageDone = false;
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
void MechControl(void * ignore){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor indexer (indexerPort);
  Motor shooter (shooterPort);
  while(true){
    if(mechMode == 1){
      // vision sort
    }else if(mechMode == 2){
      // auto indexing
    }
    lRoller.move(powerRollers);
    rRoller.move(powerRollers);
    indexer.move(powerIndexer);
    shooter.move(powerShooter);
    delay(5);
  }
}

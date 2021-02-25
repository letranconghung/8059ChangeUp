/** Other mechanical functions. */
#include "main.h"
#include "mechLib.hpp"
/** declare motors and sensors */
/** thresholds */
int iMax = 127;
int rMax = 127;
int intakeColorValue = 0, shootColorValue = 0;
int intakeColorThreshold = 2900;
int shootColorThreshold = 2800;
bool pauseMech = false;
int mechMode = 0;
bool firstStageDone = false;
void setMech(int l, int r, int i, int s){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor shooter (shooterPort);
  Motor indexer (indexerPort);
  lRoller.move(l);
  rRoller.move(r);
  indexer.move(i);
  shooter.move(s);
}
void resetMech(){
  setMech(0, 0, 0, 0);
}
void setMech(int l, int r, int i, int s, int t){
  pauseMech = true;
  setMech(l, r, i, s);
  delay(t);
  resetMech();
  pauseMech = false;
}
void waitIntakeColor(){
  printf("wait intake color \t value: %d\n", shootColorValue);
  while(intakeColorValue>intakeColorThreshold) delay(5);
}
void waitShootColor(){
  printf("wait Shoot color \t value: %d\n", shootColorValue);
  while(shootColorValue>shootColorThreshold) delay(5);
}
void autoFrontIntake(){
  pauseMech = true;
  setMech(rMax, rMax, iMax, 0);
  waitIntakeColor();
  resetMech();
  pauseMech = false;
}
void autoBackIntake(){
  pauseMech = true;
  setMech(0, 0, iMax, 0);
  waitIntakeColor();
  resetMech();
  pauseMech = false;
}
/** can be used for backIntakeLoad */
void autoLoad(){
  pauseMech = true;
  printf("auto load\n");
  setMech(0, 0, 80, 0);
  waitShootColor();
  resetMech();
  pauseMech = false;
}
/** not recommended as it will accidentally intake other balls while loading (?) */
void autoFrontIntakeLoad(){
  pauseMech = true;
  setMech(rMax, rMax, iMax, 0);
  waitShootColor();
  resetMech();
  pauseMech = false;
}
void shoot(int s, int t){
  printf("shoot: speed: %d, time: %d\n", s, t);
  pauseMech = true;
  setMech(0, 0, 80, s);
  delay(t);
  resetMech();
  printf("shoot complete\n");
  pauseMech = false;
}
void asyncFrontIntake(){
  mechMode = 1;
}
void asyncBackIntake(){
  mechMode = 2;
}
void asyncLoad(){
  mechMode = 3;
}
void asyncFrontIntakeLoad(){
  mechMode = 4;
}
void asyncDouble(){
  mechMode = 5;
}
void mechControl(void * ignore){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor shooter (shooterPort);
  Motor indexer (indexerPort);
  ADIAnalogIn intakeColor(intakeColorPort);
  ADIAnalogIn shootColor(shootColorPort);
  while(true){
    intakeColorValue = intakeColor.get_value();
    shootColorValue = shootColor.get_value();
    if(!pauseMech){
      switch(mechMode){
        case 0:{
          resetMech();
          break;
        }
        case 1:{
          //frontIntake
          setMech(rMax, rMax, iMax, 0);
          if(intakeColorValue<intakeColorThreshold) mechMode = 0;
          break;
        }
        case 2:{
          //backIntake
          setMech(0, 0, iMax, 0);
          if(intakeColorValue<intakeColorThreshold) mechMode = 0;
          break;
        }
        case 3:{
          //load
          setMech(0, 0, iMax, 0);
          if(shootColorValue<shootColorThreshold) mechMode = 0;
          break;
        }
        case 4:{
          //frontIntakeLoad
          setMech(rMax, rMax, iMax, 0);
          if(shootColorValue<shootColorThreshold) mechMode = 0;
          break;
        }
        case 5:{
          //double
          setMech(rMax, rMax, iMax, 0);
          if(!firstStageDone){
            if(shootColorValue<shootColorThreshold) firstStageDone = true;
          }else{
            if(intakeColorValue<intakeColorThreshold){
              mechMode = 0;
              firstStageDone = false;
            }
          }
        }
      }
    }
    delay(5);
  }
}

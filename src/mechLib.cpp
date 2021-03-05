/** Other mechanical functions. */
#include "main.h"
#include "mechLib.hpp"
/** declare motors and sensors */
/** thresholds */
int iMax = 127;
int rMax = 127;
int iLoad = 80;
int sLoad = 0;
int intakeColorValue = 0, shootColorValue = 0;
int intakeColorThreshold = 2850;
int shootColorThreshold = 2830; // working 2875
bool pauseMech = false;
int mechMode = 0;
int shooterSpeed = 0, shooterTime = 0;
int start;
bool firstStageDone = false;
void setPauseMech(bool pm){
  pauseMech = pm;
}
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
  setMech(10, 10, 10, 10);
}
void setMech(int l, int r, int i, int s, int t){
  pauseMech = true;
  setMech(l, r, i, s);
  delay(t);
  resetMech();
  pauseMech = false;
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
  setMech(0, 0, iLoad, sLoad);
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
void auto2for2(){
  pauseMech = true;
  setMech(rMax, rMax, iLoad, 127);
  powerBase(90, 90);
  delay(600);
  setMech(rMax, rMax, iMax, 127);
  while(shootColorValue > shootColorThreshold){
    printf("> threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  while(shootColorValue < shootColorThreshold){
    printf("< threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  while(shootColorValue > shootColorThreshold){
    printf("> threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  resetMech();
  powerBase(0, 0);
  unPauseBase();
  pauseMech = false;
}
void auto2for1(){
  pauseMech = true;
  setMech(rMax, rMax, iLoad, 127);
  powerBase(90, 90);
  delay(600);
  setMech(rMax, rMax, iMax, 127);
  while(shootColorValue > shootColorThreshold){
    printf("> threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  setMech(-127, -127, iMax, 127);
  while(shootColorValue < shootColorThreshold){
    printf("< threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  while(shootColorValue > shootColorThreshold){
    printf("> threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  resetMech();
  powerBase(0, 0);
  unPauseBase();
  pauseMech = false;
}
void auto1for1(){
  pauseMech = true;
  setMech(rMax, rMax, iLoad, 127);
  powerBase(90, 90);
  delay(400);
  setMech(-rMax, -rMax, iMax, 0);
  while(shootColorValue > shootColorThreshold){
    printf("> threshold shootColorValue: %d\n", shootColorValue);
    delay(5);
  }
  resetMech();
  powerBase(0, 0);
  unPauseBase();
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
void centerpole(){
  printf("centerpole\n");
  pauseMech = true;
  setMech(127, 127, -127, 127);
  delay(5000);
  resetMech();
  printf("centerpole complete\n");
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
void asyncShoot(int s, int t){
  start = millis();
  shooterSpeed = s;
  shooterTime = t;
  mechMode = 6;
}
void asyncIntakeNoRollers(){
  mechMode = 7;
}
void mechControl(void * ignore){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor shooter (shooterPort);
  Motor indexer (indexerPort);
  ADIAnalogIn intakeColor(intakeColorPort);
  ADIAnalogIn shootColor(shootColorPort);
  while(competition::is_autonomous()){
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
          setMech(0, 0, iLoad, sLoad);
          if(shootColorValue<shootColorThreshold){
            mechMode = 0;
            printf("got out of asyncload\n");
          }
          break;
        }
        case 4:{
          //frontIntakeLoad
          setMech(rMax, rMax, iMax, sLoad);
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
          break;
        }
        case 6:{
          //asyncshoot
          setMech(-127, -127, iMax, shooterSpeed);
          if(millis() - start > shooterTime){
            mechMode = 0;
          }
          break;
        }
        case 7:{
          setMech(0, 0, iLoad, 0);
          if(intakeColorValue < intakeColorThreshold) mechMode = 0;
          break;
        }

      }
    }
    delay(5);
  }
}

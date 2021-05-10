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
bool autoIndex = false;
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
const int LONG_PRESS_CUTOFF = 150;
const int DOUBLE_TAP_INTERVAL = 250;
bool driverMode = false;
void MechControl(void * ignore){
  Motor lRoller (lRollerPort);
  Motor rRoller (rRollerPort);
  Motor indexer (indexerPort);
  Motor shooter (shooterPort);
  Controller master(E_CONTROLLER_MASTER);
  double indexerMove = 0, shooterMove = 0, rollersMove = 0;
  int mode = 0, pressTimeStamp = millis(), releaseTimeStamp = millis();
  while(true){
    if(driverMode){
      printf("mode: %d\n", mode);
      if(master.get_digital_new_press(DIGITAL_RIGHT)){
        stage = 0;
        mode = 0;
        printf("reset mode: %d\n", mode);
      }
      if(mode == 0){
        rollersMove = master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_R2);
        indexerMove = 0;
        shooterMove = 0;
        if(autoIndex){
          if(intakeColorValue< intakeColorThreshold && shootColorValue < shootColorThreshold) indexerMove = 0;
          else indexerMove = 1;
        }
        if(master.get_digital(DIGITAL_R2)){
          indexerMove = -1;
          shooterMove = -1;
        }
      }
      if(master.get_digital_new_press(DIGITAL_R1) && mode == 0){
        pressTimeStamp = millis();
        mode = 1;
      }
      if(mode == 1){
        if(millis() - pressTimeStamp > LONG_PRESS_CUTOFF){
          mode = 2;
        }
        if(!master.get_digital(DIGITAL_R1)){
          mode = 3;
          releaseTimeStamp = millis();
        }
      }
      if(mode == 2){
        // R1 is pressed
        rollersMove = master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_R2);
        indexerMove = 1;
        shooterMove = 1;
        printf("long press\n");
        if(!master.get_digital(DIGITAL_R1)){
          mode = 0;
          printf("long press released\n");
          releaseTimeStamp = millis();
        }
      }
      if(mode == 3){
        if(millis() - releaseTimeStamp < DOUBLE_TAP_INTERVAL && master.get_digital(DIGITAL_R1)){
          pressTimeStamp = millis();
          printf("double tap\t %d\n", millis() - releaseTimeStamp);
          mode = 5; // double tap
        }
        if(millis() - releaseTimeStamp > DOUBLE_TAP_INTERVAL){
          printf("single tap\t %d\n", millis() - releaseTimeStamp);
          mode = 4; // single tap
        }
      }
      if(mode == 4){
        if(stage == 0){
          rollersMove = 1;
          indexerMove = 1;
          shooterMove = 1;
          if(optBall == 3 - alliance) stage = 1;
        }else if(stage == 1){
          rollersMove = 0;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance){
            stage = 0;
            mode = 0;
          }
        }
      }else if (mode == 5){
        if(stage == 0){
          rollersMove = 1;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance) stage = 1;
        }else if(stage == 1){
          rollersMove = 1;
          indexerMove = 0.5;
          shooterMove = -1;
          if(optBall == 3 - alliance) stage = 2;
        }else if(stage == 2){
          rollersMove = 0;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance){
            stage = 0;
            mode = 0;
          }
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

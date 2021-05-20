/** Other mechanical functions. */
#include "main.h"
#include "mechLib.hpp"
/** declare motors and sensors */
/** thresholds */
int iMax = 127, rMax = 127, sMax = 127;
int intakeColorThreshold = 2850, shootColorThreshold = 2830; // working 2830
bool slowMode = false;
bool autoIndex = false;
int stage = 0, mode = 0;
double indexerMove = 0, shooterMove = 0, rollersMove = 0;
void setMech(double r, double i, double s){
  rollersMove = r;
  indexerMove = i;
  shooterMove = s;
}
void setMech(double r, double i, double s, int t){
  setMech(r, i, s);
  delay(t);
  resetMech();
}
void asyncFrontIntake(){
  mode = 1;
}
void asyncLoad(){
  mode = 2;
}
void asyncFrontIntakeLoad(){
  mode = 3;
}
void shoot(double t){
  mode = 0;
  setMech(0,1,1,t);
  resetMech();
}
void resetMode(){
  printf("reset mode\n");
  mode = 0;
  stage = 0;
}
void resetMech(){
  printf("reset mech\n");
  resetMode();
  setMech(0, 0, 0);
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
  int pressTimeStamp;
  while(true){
    if(driverMode){
      if(mode != 0) printf("mode: %d\tstage: %d\n",mode, stage);
      if(master.get_digital(DIGITAL_R1) || master.get_digital(DIGITAL_R2) || master.get_digital(DIGITAL_L1)){
        resetMode();
      }
      if(mode == 0){
        rollersMove = master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_R2);
        indexerMove = 0;
        shooterMove = 0;
        if(autoIndex){
          if(intakeColorValue < intakeColorThreshold && shootColorValue < shootColorThreshold) indexerMove = 0;
          else indexerMove = 1;
        }
        if(master.get_digital(DIGITAL_R2)){
          indexerMove = -1;
          shooterMove = -1;
        }else if(master.get_digital(DIGITAL_R1)){
          indexerMove = 1;
          shooterMove = 1;
        }
      }
      if(master.get_digital_new_press(DIGITAL_UP)){
        if(mode == 0){
          pressTimeStamp = millis();
          mode = 1;
        }else if (mode == 1 && millis() - pressTimeStamp){
          printf("double tap\n");
          mode = 3;
        }
      }
      if(mode == 1 && millis() - pressTimeStamp > DOUBLE_TAP_INTERVAL){
        printf("single tap\n");
        mode = 2;
      }
      if(mode == 2){
        if(stage == 0){
          rollersMove = 1;
          indexerMove = 1;
          shooterMove = 1;
          if(optBall == 3 - alliance) stage = 1;
        }else if(stage == 1){
          rollersMove = 0;
          indexerMove = 1;
          shooterMove = 1;
          if(ball == 3 - alliance) resetMode();
        }
      }else if (mode == 3){
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
          if(ball == 3 - alliance) resetMode();
        }
      }
    }else{
      // async
      switch(mode){
        case 0: break;
        case 1:{
          // front intake
          if(intakeColorValue > intakeColorThreshold) setMech(1, 1, 0);
          else resetMech();
          break;
        }
        case 2:{
          // load
          if(shootColorValue > shootColorThreshold) setMech(0, 1, 0);
          else resetMech();
          break;
        }
        case 3:{
          // front intake load
          if(stage == 0){
            if(intakeColorValue > shootColorThreshold) setMech(1, 1, 0);
            else stage = 1;
          }
          if(stage == 1){
            if(shootColorValue > shootColorThreshold) setMech(0, 1, 0);
            else{
              resetMech();
              break;
            }
          }
        }
      }
    }
    double rMultiplier = (slowMode? 0.6 : 1);
    double iMultiplier = (slowMode? 0.85 : 1);
    double sMultiplier = (slowMode? 0.7 : 1);
    lRoller.move(rMax*rollersMove*rMultiplier);
    rRoller.move(rMax*rollersMove*rMultiplier);
    indexer.move(iMax*indexerMove*iMultiplier);
    shooter.move(sMax*shooterMove*sMultiplier);
    delay(5);
  }
}

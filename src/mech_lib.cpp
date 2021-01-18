/** Other mechanical functions. */
#include "main.h"
#include "mech_lib.hpp"
/** declare motors and sensors */
Motor lRoller (lRollerPort);
Motor rRoller (rRollerPort);
Motor shooter (shooterPort);
Motor indexer (indexerPort);
int intakeColorThreshold = 2700;
int shootColorThreshold = 2400;
int indexerMode = 0;
void indexerControl(void * ignore){
  ADIAnalogIn shootColor(shootColorPort);
  ADIAnalogIn intakeColor(intakeColorPort);
  while(true){
    printf("current color value: %d\n", shootColor.get_value());
    switch(indexerMode){
      case 1: {
        while(intakeColor.get_value()>intakeColorThreshold){
          lRoller.move(127);
          rRoller.move(127);
          indexer.move(127);
          pros::delay(5);
        }
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        indexerMode = 0;
        break;
      }
      case 2: {
        printf("initial color value: %d\n", intakeColor.get_value());
        while(intakeColor.get_value()>intakeColorThreshold){
          indexer.move(127);
          pros::delay(5);
        }
        indexer.move(0);
        indexerMode = 0;
        break;
      }
      case 3: {
        while(shootColor.get_value()>shootColorThreshold){
          indexer.move(127);
          pros::delay(5);
        }
        indexer.move(0);
        indexerMode = 0;
        break;
      }
      case 4: {
        indexer.move(127);
        delay(300);
        indexer.move(0);
        indexerMode = 0;
        break;
      }
      case 5: {
        indexer.move(127);
        delay(600);
        indexer.move(0);
        indexerMode = 0;
        break;
      }
    }
    Task::delay(10);
  }
}
void frontIntake(){
  indexerMode = 1;
}
void backIntake(){
  printf("entered back intake\n");
  indexerMode = 2;
}
void load(){
  indexerMode = 3;
}
int shooterMode = 0;
void shooterControl(void * ignore){
  while(true){
    if(shooterMode == 1){
      shooter.move(127);
      delay(1000);
      shooter.move(0);
      shooterMode = 0;
    }
    Task::delay(10);
  }
}
void loadshoot(){
  indexerMode = 5;
  shooterMode = 1;
}
void shoot(){
  indexerMode = 4;
  shooterMode = 1;
}

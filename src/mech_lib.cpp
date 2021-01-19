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
int indexerDuration = 0;
std::queue<int> indexerOrders;
void indexerControl(void * ignore){
  ADIAnalogIn shootColor(shootColorPort);
  ADIAnalogIn intakeColor(intakeColorPort);
  while(true){
    if(indexerOrders.empty()){
      indexerMode = 0;
    }else{
      indexerMode = indexerOrders.front();
      indexerOrders.pop();
    }
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
        delay(indexerDuration);
        indexer.move(0);
        indexerMode = 0;
        break;
      }
      case 5: {
        lRoller.move(127);
        rRoller.move(127);
        indexer.move(127);
        delay(indexerDuration);
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        indexerMode = 0;
        break;
      }
      case 6: {
        lRoller.move(-127);
        rRoller.move(-127);
        indexer.move(-127);
        delay(indexerDuration);
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        indexerMode = 0;
        break;
      }
    }
    Task::delay(5);
  }
}
void frontIntake(){
  indexerOrders.push(1);
}
void backIntake(){
  indexerOrders.push(2);
}
void load(){
  indexerOrders.push(3);
}

int shooterMode = 0;
int shootDuration = 0;
void shooterControl(void * ignore){
  while(true){
    if(shooterMode == 1){
      shooter.move(127);
      delay(shootDuration);
      shooter.move(0);
      shooterMode = 0;
    }else if(shooterMode == 2){
      shooter.move(-127);
      delay(shootDuration);
      shooter.move(0);
      shooterMode = 0;
    }
    Task::delay(10);
  }
}
void shoot(int duration){
  indexerOrders.push(4);
  indexerDuration = duration;
  shooterMode = 1;
  shootDuration = duration;
}
void waitIndexer(){
  delay(100);
  while(indexerMode != 0){
    printf("waiting index\n");
    delay(5);
  }
}
void frontOuttake(int duration){
  indexerOrders.push(6);
  indexerDuration = duration;
  shooterMode = 2;
  shootDuration = duration;
}
void cycle(int duration){
  indexerOrders.push(5);
  indexerDuration = duration;
  shooterMode = 1;
  shootDuration = duration;
}
void suck(int duration){
  indexerOrders.push(5);
  indexerDuration = duration;
}

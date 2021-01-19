/** Other mechanical functions. */
#include "main.h"
#include "mech_lib.hpp"
/** declare motors and sensors */
Motor lRoller (lRollerPort);
Motor rRoller (rRollerPort);
Motor shooter (shooterPort);
Motor indexer (indexerPort);
/** thresholds */
int intakeColorThreshold = 2700;
int shootColorThreshold = 2400;
int mechDuration = 0;
int mechMode = 0;
/** control shooterSpeed to shoot or eject */
int shooterSpeed = 0;
std::queue<int> mechOrders;
enum MECH_MODE{
  E_AUTO_FRONT_INTAKE = 1,
  E_AUTO_BACK_INTAKE = 2,
  E_AUTO_LOAD = 3,
  E_AUTO_INTAKE_LOAD = 4,
  E_TIMED_CYCLE = 5,
  E_TIMED_REVERSE_CYCLE = 6,
  E_TIMED_COLUMN_CYCLE = 7,
};
void waitIntakeColor(){
  ADIAnalogIn intakeColor(intakeColorPort);
  while(intakeColor.get_value()>intakeColorThreshold) delay(5);
}
void waitShootColor(){
  ADIAnalogIn shootColor(shootColorPort);
  while(shootColor.get_value()>shootColorThreshold) delay(5);
}
/** block the program until mech task is done */
void mechBlock(){
  /** time for mechControl to refresh mechMode */
  delay(50);
  while(mechMode != 0) delay(5);
}
void mechControl(void * ignore){
  ADIAnalogIn shootColor(shootColorPort);
  ADIAnalogIn intakeColor(intakeColorPort);
  while(true){
    if(mechOrders.empty()){
      mechMode = 0;
    }else{
      mechMode = mechOrders.front();
      mechOrders.pop();
    }
    switch(mechMode){
      case MECH_MODE::E_AUTO_FRONT_INTAKE: {
        lRoller.move(127);
        rRoller.move(127);
        indexer.move(127);
        waitIntakeColor();
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        mechMode = 0;
        break;
      }
      case MECH_MODE::E_AUTO_BACK_INTAKE: {
        indexer.move(127);
        waitIntakeColor();
        indexer.move(0);
        mechMode = 0;
        break;
      }
      case MECH_MODE::E_AUTO_LOAD: {
        indexer.move(127);
        waitShootColor();
        indexer.move(0);
        mechMode = 0;
        break;
      }
      case MECH_MODE::E_AUTO_INTAKE_LOAD: {
        lRoller.move(127);
        rRoller.move(127);
        indexer.move(127);
        waitShootColor();
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        mechMode = 0;
        break;
      }
      case MECH_MODE::E_TIMED_CYCLE: {
        lRoller.move(127);
        rRoller.move(127);
        indexer.move(127);
        shooter.move(shooterSpeed);
        delay(mechDuration);
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        shooter.move(0);
        mechMode = 0;
        break;
      }
      case MECH_MODE::E_TIMED_REVERSE_CYCLE: {
        lRoller.move(-127);
        rRoller.move(-127);
        indexer.move(-127);
        shooter.move(-127);
        delay(mechDuration);
        lRoller.move(0);
        rRoller.move(0);
        indexer.move(0);
        shooter.move(0);
        mechMode = 0;
        break;
      }
      case MECH_MODE::E_TIMED_COLUMN_CYCLE: {
        indexer.move(127);
        shooter.move(shooterSpeed);
        delay(mechDuration);
        indexer.move(0);
        shooter.move(0);
        mechMode = 0;
        break;
      }
    }
    Task::delay(5);
  }
}
void autoFrontIntake(){
  mechOrders.push(MECH_MODE::E_AUTO_FRONT_INTAKE);
}
void autoBackIntake(){
  mechOrders.push(MECH_MODE::E_AUTO_BACK_INTAKE);
}
void autoLoad(){
  mechOrders.push(MECH_MODE::E_AUTO_LOAD);
}
void autoIntakeLoad(){
  mechOrders.push(MECH_MODE::E_AUTO_INTAKE_LOAD);
}
void timedCycle(int p_shooterSpeed, int duration){
  mechOrders.push(MECH_MODE::E_TIMED_CYCLE);
  shooterSpeed = p_shooterSpeed;
  mechDuration = duration;
}
void timedReverseCycle(int duration){
  mechOrders.push(MECH_MODE::E_TIMED_REVERSE_CYCLE);
  mechDuration = duration;
}
void timedColumnCycle(int p_shooterSpeed, int duration){
  mechOrders.push(MECH_MODE::E_TIMED_COLUMN_CYCLE);
  shooterSpeed = p_shooterSpeed;
  mechDuration = duration;
}
// void suck(int duration){
//   mechOrders.push(5);
//   mechDuration = duration;
// }

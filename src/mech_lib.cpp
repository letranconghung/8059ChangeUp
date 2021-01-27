/** Other mechanical functions. */
#include "main.h"
#include "mech_lib.hpp"
/** declare motors and sensors */

/** thresholds */
int iMax = 127;
int rMax = 127;
int intakeColorValue = 0, shootColorValue = 0;
int intakeColorThreshold = 2800;
int shootColorThreshold = 2400;
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
  setMech(l, r, i, s);
  delay(t);
  resetMech();
}
void waitIntakeColor(){
  printf("wait intake color \t value: %d\n", shootColorValue);
  while(intakeColorValue>intakeColorThreshold) delay(5);
}
void waitShootColor(){
  printf("wait Shoot color \t value: %d\n", shootColorValue);
  while(shootColorValue>shootColorThreshold){
    delay(5);
  }
}
void autoFrontIntake(){
  setMech(rMax, rMax, iMax, 0);
  waitIntakeColor();
  resetMech();
}
void autoBackIntake(){
  setMech(0, 0, iMax, 0);
  waitIntakeColor();
  resetMech();
}
/** can be used for backIntakeLoad */
void autoLoad(){
  printf("auto load\n");
  setMech(0, 0, iMax, 0);
  waitShootColor();
  resetMech();
}
/** not recommended as it will accidentally intake other balls while loading (?) */
void autoFrontIntakeLoad(){
  setMech(rMax, rMax, iMax, 0);
  waitShootColor();
  resetMech();
}
void shoot(int s, int t){
  setMech(0, 0, iMax, s);
  delay(t);
  resetMech();
}
void shoot(int s){
  setMech(0, 0, iMax, s);
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
    delay(5);
  }
}






























/** async mech library */
// int mechDuration = 0;
// int mechMode = 0;
// /** control shooterSpeed to shoot or eject */
// int shooterSpeed = 0;
// std::queue<int> mechOrders;
// // void waitIntakeColor(){
// //   ADIAnalogIn intakeColor(intakeColorPort);
// //   while(intakeColor.get_value()>intakeColorThreshold) delay(5);
// // }
// // void waitShootColor(){
// //   ADIAnalogIn shootColor(shootColorPort);
// //   while(shootColor.get_value()>shootColorThreshold) delay(5);
// // }
// /** block the program until mech task is done */
// int timer;
// void setMechMode(int value){
//   mechMode = value;
// }
// void setMech(int l, int r, int i, int s){
//   lRoller.move(l);
//   rRoller.move(r);
//   indexer.move(i);
//   shooter.move(s);
// }
// void mechBlock(){
//   /** time for mechControl to refresh mechMode */
//   delay(50);
//   while(mechMode != 0) delay(5);
// }
// bool mechEnabled = true;
// void mech(bool b){
//   mechEnabled = b;
// }
// void mechControl(void * ignore){
//   ADIAnalogIn shootColor(shootColorPort);
//   ADIAnalogIn intakeColor(intakeColorPort);
//   int count = 0;
//   bool doneOrder = true;
//   while(mechEnabled){
//     if(doneOrder){
//       if(mechOrders.empty()){
//         mechMode = MECH_MODE::E_DEFAULT;
//       }else{
//         timer = millis();
//         mechMode = mechOrders.front();
//         mechOrders.pop();
//         doneOrder = false;
//       }
//     }
//     switch(mechMode){
//       case MECH_MODE::E_DEFAULT: {
//         if (++count % 20 == 0) printf("default behavior\n");
//         setMech(0, 0, 0, 0);
//         break;
//       }
//       case MECH_MODE::E_AUTO_FRONT_INTAKE: {
//         if (++count % 20 == 0) printf("auto front intake\n");
//         setMech(127, 127, 90, 0);
//         if(intakeColor.get_value()<intakeColorThreshold){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_AUTO_BACK_INTAKE: {
//         if (++count % 20 == 0) printf("auto back intake\n");
//         setMech(0, 0, 90, 0);
//         if(intakeColor.get_value()<intakeColorThreshold){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_AUTO_LOAD: {
//         if (++count % 20 == 0) printf("auto load\n");
//         setMech(0, 0, 90, 0);
//         if(shootColor.get_value()<shootColorThreshold){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_AUTO_INTAKE_LOAD: {
//         if (++count % 20 == 0) printf("auto intake load\n");
//         setMech(127, 127, 90, 0);
//         if(shootColor.get_value()<shootColorThreshold){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_TIMED_CYCLE: {
//         if (++count % 20 == 0) printf("timed cycle\n");
//         setMech(127, 127, 127, shooterSpeed);
//         if(millis() - timer > mechDuration){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_TIMED_REVERSE_CYCLE: {
//         if (++count % 20 == 0) printf("timed reverse cycle\n");
//         setMech(-127, -127, -127, -127);
//         if(millis() - timer > mechDuration){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_TIMED_COLUMN_CYCLE: {
//         if (++count % 20 == 0) printf("timed column cycle\n");
//         setMech(0, 0, 127, shooterSpeed);
//         if(millis() - timer > mechDuration){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//       case MECH_MODE::E_TIMED_FRONT_OUTTAKE: {
//         if (++count % 20 == 0) printf("timed front outtake\n");
//         setMech(-127, -127, 0, 0);
//         if(millis() - timer > mechDuration){
//           mechMode = 0;
//           doneOrder = true;
//         }
//         break;
//       }
//     }
//     Task::delay(5);
//   }
// }
// void autoFrontIntake(){
//   mechOrders.push(MECH_MODE::E_AUTO_FRONT_INTAKE);
// }
// void autoBackIntake(){
//   mechOrders.push(MECH_MODE::E_AUTO_BACK_INTAKE);
// }
// void autoLoad(){
//   mechOrders.push(MECH_MODE::E_AUTO_LOAD);
// }
// void autoIntakeLoad(){
//   printf("intakeload\n");
//   mechOrders.push(MECH_MODE::E_AUTO_INTAKE_LOAD);
// }
// void timedCycle(int p_shooterSpeed, int duration){
//   mechOrders.push(MECH_MODE::E_TIMED_CYCLE);
//   shooterSpeed = p_shooterSpeed;
//   mechDuration = duration;
// }
// void timedReverseCycle(int duration){
//   mechOrders.push(MECH_MODE::E_TIMED_REVERSE_CYCLE);
//   mechDuration = duration;
// }
// void timedColumnCycle(int p_shooterSpeed, int duration){
//   mechOrders.push(MECH_MODE::E_TIMED_COLUMN_CYCLE);
//   shooterSpeed = p_shooterSpeed;
//   mechDuration = duration;
// }
// void timedFrontOuttake(int duration){
//   mechOrders.push(MECH_MODE::E_TIMED_FRONT_OUTTAKE);
//   mechDuration = duration;
// }

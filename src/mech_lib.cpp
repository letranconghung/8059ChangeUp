#include "main.h"
#include "mech_lib.hpp"

Motor lRoller (lRollerPort);
Motor rRoller (rRollerPort);
Motor indexer (indexerPort);
Motor shooter (shooterPort);
ADIAnalogIn color (colorPort);

double cycleSpeed = 127, colorThreshold = 2900;
bool cycleTrigger = false, isDiscard = false, limitOccupied = false;
// double targetIndexerPower = 0, targetShooterPower = 0;
// double indexerKP = 1, shooterKP = 1;

void intakeMove(int speed) {
  lRoller.move(speed);
  rRoller.move(speed);
}

void cycle() {
  cycleTrigger = true;
}

void setDiscard(bool value) {
  isDiscard = value;
}

void waitCycle() {
  while(color.get_value() > colorThreshold) delay(5);
}

void pickUp(int power) {
  intakeMove(127);
  powerBase(power, power);
  cycle();
  waitCycle();
  powerBase(0, 0);
  pauseBase(false);
  // intakeMove(0);
}

void shooterControl(void * ignore) {
  // while(true) {
  //   printf("color value: %d\n", color.get_value());
  //   delay(500);
  // }
  shooter.set_brake_mode(MOTOR_BRAKE_HOLD);
  while(true) {
    shooter.move(0);
    if (isDiscard) {
      indexer.move(cycleSpeed);
      shooter.move(-cycleSpeed);
    }else if(cycleTrigger) {
      indexer.move(cycleSpeed);
      shooter.move(cycleSpeed);
      waitCycle();
      cycleTrigger = false;
    }else {
      indexer.move(0);
      shooter.move(0);
    }
    delay(5);
  }
}

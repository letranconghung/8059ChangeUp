#include "main.h"
#include "mech_lib.hpp"
Motor lRoller (lRollerPort);
Motor rRoller (rRollerPort);
Motor indexer (indexerPort);
Motor shooter (shooterPort);
ADIDigitalIn limit (limitPort);
ADIAnalogIn color (colorPort);

double cycleSpeed = 127;
bool cycleTrigger = false, isDiscard = false, forceStopTrigger = false, limitOccupied = false;
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
  forceStopTrigger = value;
}

void forceStop() {
  forceStopTrigger = true;
}

void waitCycle() {
  while(!limit.get_value() && !forceStopTrigger) delay(5);
  while(limit.get_value() && !forceStopTrigger) delay(5);
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
  shooter.set_brake_mode(MOTOR_BRAKE_HOLD);
  while(true) {
    shooter.move(0);
    if (isDiscard) {
      indexer.move(cycleSpeed / 2);
      shooter.move(-cycleSpeed);
    }else if(cycleTrigger) {
      forceStopTrigger = false;
      indexer.move(cycleSpeed);
      shooter.move(cycleSpeed);

      while(!limit.get_value() && !forceStopTrigger) delay(5);
      while(limit.get_value() && !forceStopTrigger) delay(5);

      cycleTrigger = false;
    }else {
      indexer.move(0);
      shooter.move(0);
    }
    delay(5);
  }
}

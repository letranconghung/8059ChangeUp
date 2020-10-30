/** Other mechanical functions. */
#include "main.h"
#include "mech_lib.hpp"
/** declare motors and sensors */
Motor lRoller (lRollerPort);
Motor rRoller (rRollerPort);
Motor indexer (indexerPort);
Motor shooter (shooterPort);
ADIDigitalIn limit (limitPort);
ADIAnalogIn color (colorPort);
double cycleSpeed = 110;
double shootSpeed, shootTime;
/** boolean flags for shooter Task */
bool cycleTrigger = false, isDiscard = false, shootTrigger = false;
/**
 * Control power of intake rollers.
 * @param speed
 * speed of intake rollers
 */
void intakeMove(int speed) {
  lRoller.move(speed);
  rRoller.move(speed);
}
/** Cycle ball by flipping boolean flag cycleTrigger. */
void cycle() {
  cycleTrigger = true;
}
/**
 * Shoot ball.
 * @param speed
 * shooter speed
 *
 * @param time
 * shooting duration
 */
void shoot(double speed, double time){
  shootTrigger = true;
  shootSpeed = speed;
  shootTime = time;
}
/**
 * Discard ball.
 * @param value
 * boolean flag value for isDiscard
 */
void setDiscard(bool value) {
  isDiscard = value;
}
/** Delay function for cycle() to finish: limit switch is triggered and de-triggered. */
void waitCycle() {
  while(!limit.get_value()) delay(5); //wait till limit is pressed
  while(limit.get_value()) delay(5); // wait till limit is released
}
/**
 * Ball pick-up function: move forward until ball is successfully cycled.
 * @param power
 * pickup base powers
 */
void pickUp(int power) {
  intakeMove(127);
  powerBase(power, power);
  cycle();
  waitCycle();
  powerBase(0, 0);
  pauseBase(false);
}
/** Async Task that control all functions related to shooter. */
void shooterControl(void * ignore) {
  shooter.set_brake_mode(MOTOR_BRAKE_HOLD);
  while(true) {
    shooter.move(0);
    if (isDiscard) {
      indexer.move(cycleSpeed / 2);
      shooter.move(-cycleSpeed);
    }else if(cycleTrigger) {
      indexer.move(cycleSpeed);
      shooter.move(cycleSpeed);
      waitCycle();
      cycleTrigger = false;
    }else if(shootTrigger){
      indexer.move(shootSpeed);
      shooter.move(shootSpeed);
      delay(shootTime);
      indexer.move(0);
      shooter.move(0);
      shootTrigger = false;
    }else{
      indexer.move(0);
      shooter.move(0);
    }
    delay(5);
  }
}

/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  Imu imu(imuPort);
  Controller master(E_CONTROLLER_MASTER);
  /** shoot */
  /** intake 1st and 2nd blue balls */
  powerBase(127, 127);
  shoot(127,700);
  autoFrontIntakeLoad();
  autoFrontIntake();
  pauseBase(false);
  resetTargets();
  baseMove(-7);
  setMech(-127, -127, 0, 0);
  waitBase(1000);
  resetMech();
  delay(500);
  shoot(110, 1000);
  /** move out */
  baseMove(-25);
  /** hypothesis: autoLoad is providing the delay for the base movements */
  autoLoad(); //also serve as backIntake
  waitBase(1000);
  delay(500);

  baseTurn(-25);
  waitBase(1000);
  delay(500);

  baseMove(-31);
  waitBase(2000);
  delay(500);

  baseTurn(60);
  waitBase(1000);
  delay(500);

  // scoring 2nd goal
  baseMove(10);
  waitBase(1000);
  delay(500);

  shoot(127,300);
  powerBase(127, 127);
  autoFrontIntake();
  pauseBase(false);
  resetTargets();

  baseMove(-35);
  shoot(80,700);
  autoLoad();
  waitBase(500);
  delay(500);
  master.print(2, 0, "value: %.2f", imu.get_rotation());
  delay(2000);
  baseMove(13);
  waitBase(1000);
  delay(500);

  baseTurn(-30);
  waitBase(2000);
  delay(500);

  baseMove(-48);
  autoBackIntake();
  waitBase(2500);
  delay(500);


  baseTurn(100);
  waitBase(1000);
  delay(500);

  baseMove(10);
  waitBase(1000);
  delay(500);

  shoot(127, 300);
  powerBase(127, 127);
  autoLoad();
  autoFrontIntake();
  shoot(127, 300);
  autoLoad();
  autoFrontIntake();
  pauseBase(false);
  setMech(-127, -127, 0, 0);
  baseMove(-20);
  waitBase(1000);
  delay(500);
  resetMech();

  baseTurn(60);
  waitBase(1000);
  delay(500);
  setMech(-127, -127, -127, -127, 1000);

  baseMove(-55);
  autoLoad();
  waitBase(500);
  delay(500);

  baseTurn(150);
  waitBase(1000);
  delay(500);

  // scoring 4th goal
  baseMove(15);
  waitBase(1000);
  delay(500);

  shoot(127,300);
  powerBase(127, 127);
  autoFrontIntake();
  pauseBase(false);
  baseMove(-30);
  setMech(-80, -80, -127, -127, 800);
  autoLoad();
  waitBase(500);
  delay(500);


}
/** Autonomous routine for blue left spawn. */
void blueLeft(){
  baseMove(48,0.525,0.3);
}
/** Autonomous routine for blue right spawn. */
void blueRight(){
  baseTurn(180, 0.5975, 0.12);
}
/** Autonomous routine for red left spawn. */
void redLeft(){
  // visionBaseMove(SIG_RED_BALL);
  // visionWaitBase(2000);
}
/** Autonomous routine for red right spawn. */
void redRight(){
}

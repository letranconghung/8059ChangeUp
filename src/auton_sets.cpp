/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  // Imu imu(imuPort);
  /** shoot */
  shoot(127,700);
  /** intake 1st and 2nd blue balls */
  powerBase(127, 127);
  autoFrontIntakeLoad();
  autoFrontIntake();
  pauseBase(false);
  baseMove(-7);
  setMech(-127, -127, 0, 0);
  waitBase(1000);
  resetMech();
  delay(500);
  baseTurn(-15);
  waitBase(1000);
  delay(500);
  shoot(110, 1000);
  /** move out */
  baseMove(-25);
  /** hypothesis: autoLoad is providing the delay for the base movements */
  autoLoad(); //also serve as backIntake
  waitBase(1000);
  delay(500);

  baseTurn(-30);
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
  baseMove(-35);
  setMech(-80, -80, -127, -127, 800);
  autoLoad();
  waitBase(500);
  delay(500);

  baseMove(13);
  waitBase(1000);
  delay(500);

  baseTurn(-50);
  waitBase(2000);
  delay(500);

  baseMove(-54);
  autoBackIntake();
  waitBase(2500);
  delay(500);


  baseTurn(110);
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
  baseMove(40,0.525,0.3);
}
/** Autonomous routine for blue right spawn. */
void blueRight(){
  baseTurn(90, 0.525, 0.15);
}
/** Autonomous routine for red left spawn. */
void redLeft(){
}
/** Autonomous routine for red right spawn. */
void redRight(){
  resetCoords(0, 0);
  double speed = 130;
  powerBase(speed, speed);

  delay(500);
  std::pair<double, double> init = getEncdVals(true);
  delay(500);
  std::pair<double, double> final = getEncdVals(true);

  printf("%.2f %.2f %.2f\n", battery::get_capacity(), final.first - init.first, final.second - init.second);
  powerBase(0, 0);

}

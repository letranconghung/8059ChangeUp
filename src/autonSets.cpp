/** Autonomous routines */
#include "main.h"
/** programming skills run */
void score2for2(){
  shoot(127, 500);
  autoLoad();
  autoFrontIntake();
  shoot(127, 500);
  autoLoad();
  autoFrontIntake();
}
void score2for1(){
  shoot(127, 500);
  autoLoad();
  autoFrontIntake();
  shoot(127, 500);
  asyncLoad();
}
void score1for1(){
  shoot(127,500);
  autoFrontIntake();
}
void skills(){
  double initAngle = 65;
  int d = 300;
  int progStart = millis();
  resetCoords(0, 0);
  delay(100);

  // ----------------------- going for 1st goal --------------------------------
  baseMove(50);
  asyncDouble();
  waitBase(5000);
  delay(d);

  baseMove(-16);
  waitBase(1000);
  delay(d);

  baseTurn(135-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(20);
  waitBase(1000);
  delay(d);

  score2for2();

  baseMove(-53);
  asyncShoot(120,1500);
  waitBase(4000);
  delay(d);

  baseTurn(180-initAngle);
  waitBase(2000);
  delay(d);

  baseMove(-30);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(88-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(40);
  asyncFrontIntake();
  waitBase(2000);
  delay(d);

  score2for1();

  // // ---------------------------- going for 3rd pole ---------------------------------
  baseMove(-10);
  waitBase(2000);
  delay(d);

  baseTurn(165-initAngle);
  waitBase(2000);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-53);
  delay(600);
  asyncLoad();
  waitBase(2000);
  delay(d);

  baseTurn(110-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(25);
  asyncFrontIntake();
  waitBase(2000);
  delay(d);

  baseMove(-20);
  waitBase(2000);
  delay(d);

  baseTurn(45-initAngle);
  waitBase(2000);
  delay(d);

  baseMove(40);
  waitBase(2000);
  delay(d);

  score2for2();

  // -------------------------------------------- going for 4th pole ------------------
  baseMove(-53);
  asyncShoot(120,1500);
  waitBase(4000);
  delay(d);

  baseTurn(90-initAngle);
  waitBase(2000);
  delay(d);

  baseMove(-30);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(0-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(40);
  asyncFrontIntake();
  waitBase(2000);
  delay(d);

  score1for1();

  // // ---------------------------------------- going for 5th pole ------------------------------------
  baseMove(-10);
  waitBase(2000);
  delay(d);

  baseTurn(90-initAngle);
  waitBase(2000);
  delay(d);

  asyncShoot(127, 500);
  baseMove(-40);
  delay(500);
  asyncLoad();
  waitBase(2000);

  baseTurn(-110-initAngle);
  waitBase(6000);
  delay(d);

  baseMove(25);
  asyncFrontIntake();
  waitBase(2000);
  delay(d);

  baseMove(-20);
  waitBase(2000);
  delay(d);

  baseTurn(-45-initAngle);
  waitBase(2000);
  delay(d);

  baseMove(40);
  waitBase(2000);
  delay(d);

  score2for2();

  // // ---------------------------- going for 6th pole ----------------------
  baseMove(-53);
  asyncShoot(120,1500);
  waitBase(4000);
  delay(d);

  baseTurn(0-initAngle);
  waitBase(2000);
  delay(d);

  baseMove(-30);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(-90-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(40);
  asyncFrontIntake();
  waitBase(2000);
  delay(d);

  score2for1();

  // ------------------------------------- going for 7th pole ------------------
  // // initAngle = -90;
  baseMove(-10);
  waitBase(2000);
  delay(d);

  baseTurn(-15-initAngle);
  waitBase(2000);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-53);
  delay(600);
  asyncLoad();
  waitBase(2000);
  delay(d);

  baseTurn(-70-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(25);
  asyncFrontIntake();
  waitBase(2000);
  delay(d);

  baseMove(-20);
  waitBase(2000);
  delay(d);

  baseTurn(-135-initAngle);
  waitBase(2000);
  delay(d);

  baseMove(40);
  waitBase(2000);
  delay(d);

  score2for2();

  // ------------------------------------------- going for 8th pole -------------------
  baseMove(-15);
  waitBase(1000);
  delay(d);

  baseTurn(-90-initAngle);
  waitBase(1000);
  delay(d);

  asyncShoot(127, 1000);
  baseMove(-70);
  delay(1000);
  asyncLoad();
  waitBase(4000);
  delay(d);

  baseMove(18);
  waitBase(2000);
  delay(d);

  baseTurn(-180-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(20);
  waitBase(1000);
  delay(d);

  score1for1();

  // ------------------------ going for 9th center pole ------------------------
  baseMove(-15);
  waitBase(1000);
  delay(d);

  baseTurn(0-initAngle);
  waitBase(5000);
  delay(d);

  // printf("start centerpoling\n");
  // baseMove(30);
  // autoFrontIntake();
  // setPauseMech(true);
  // setMech(127, 127, -127, 127);
  // waitBase(1500);
  // powerBase(127, 127);
  // delay(5000);
  // timerBase(-127, -127, 500);
  printf("AUTON TIME TAKEN: %.1f s\n", (float)(millis() - progStart)/1000);
}
/** Autonomous routine for blue left spawn. */
void blueLeft(){
  resetCoords(0, 0);
  delay(100);

  // baseMove(-15);
  // asyncLoad();
  // waitBase(1000);
}
/** Autonomous routine for blue right spawn. */
void blueRight(){
}
/** Autonomous routine for red left spawn. */
void redLeft(){
}
/** Autonomous routine for red right spawn. */
void redRight(){
  // resetCoords(0, 0);
  // delay(100);
  //
  // baseMove(10);
  // autoFrontIntake();
  // waitBase(2000);
  // baseTurn(90);
  // waitBase(1000);
  // delay(500);
}

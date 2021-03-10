/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  double initAngle = 65;
  int d = 100;
  int progStart = millis();
  resetCoords(0, 0);
  delay(100);

  // ----------------------- going for 1st goal --------------------------------
  baseMove(51);
  asyncDouble();
  waitBase(1700);
  delay(d);

  baseMove(-18);
  waitBase(1000);
  delay(d);

  baseTurn(135-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(16);
  waitBase(1000);
  delay(d);
  auto2for2();
  // --------------------------------- going for 2nd goal -----------------------

  // // SET 1
  baseMove(-55);
  asyncShoot(0, 500);
  delay(500);
  asyncShoot(120, 300);
  delay(200);
  asyncShoot(120, 1000);
  waitBase(1500);
  delay(d);

  baseTurn(180-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-28);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(89-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(29);
  asyncFrontIntake();
  waitBase(1400);
  delay(d);
  // END

  auto2for1();
  //
  // // // ---------------------------- going for 3rd pole ---------------------------------
  //
  // // SET 2
  baseMove(-13);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(165-initAngle);
  waitBase(800);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-55);
  delay(600);
  asyncLoad();
  waitBase(2500);
  delay(d);

  baseTurn(110-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(25);
  asyncFrontIntake();
  waitBase(1200);
  delay(d);

  baseMove(-20);
  waitBase(1200);
  delay(d);

  baseTurn(45-initAngle);
  waitBase(800);
  delay(d);

  baseMove(19);
  waitBase(1000);
  delay(d);

  // END
  auto2for2();

  // // -------------------------------------------- going for 4th pole ------------------
  // // ------------- 90, 0 (3), auto1for1 -----------------
  // // // SET 1
  // // // SET 1
  // // SET 1
  baseMove(-55);
  asyncShoot(0, 500);
  delay(500);
  asyncShoot(120, 300);
  delay(200);
  asyncShoot(120, 1500);
  waitBase(1500);
  delay(d);

  baseTurn(90-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-26.2);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(0-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(29);
  asyncFrontIntake();
  waitBase(1400);
  delay(d);
  // END
  // END
  auto1for1();
  // //
  // // // // ---------------------------------------- going for 5th pole ------------------------------------
  // // // 90, -110, -45, auto2for2
  //
  // // SET 3 cus not diagonal
  baseMove(-13);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(90-initAngle);
  waitBase(800);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-40);
  delay(600);
  asyncLoad();
  waitBase(2500);
  delay(d);

  baseTurn(-110-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(26);
  asyncFrontIntake();
  waitBase(1200);
  delay(d);

  baseMove(-19);
  waitBase(1200);
  delay(d);

  baseTurn(-45-initAngle);
  waitBase(800);
  delay(d);

  baseMove(19);
  waitBase(1000);
  delay(d);

  // // // END
  auto2for2();
  // //
  // // // // ---------------------------- going for 6th pole ----------------------
  // // // SET 1
  // // // ------ 0, -90, auto2for1
  // //
  // // // SET 1
  // // SET 1
  baseMove(-55);
  asyncShoot(0, 500);
  delay(500);
  asyncShoot(120, 300);
  delay(200);
  asyncShoot(120, 1000);
  waitBase(1500);
  delay(d);

  baseTurn(0-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-25.5);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(-90-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(29);
  asyncFrontIntake();
  waitBase(1400);
  delay(d);
  // // // END
  auto2for1();
  // //
  // // // ------------------------------------- going for 7th pole ------------------
  // // // -------- -15, -70, -135, auto2for2
  // //
  // // // SET 2
  // // SET 2
  baseMove(-13);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(-15-initAngle);
  waitBase(800);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-55);
  delay(600);
  asyncLoad();
  waitBase(2500);
  delay(d);

  baseTurn(-70-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(27);
  asyncFrontIntake();
  waitBase(1200);
  delay(d);

  baseMove(-20);
  waitBase(1200);
  delay(d);

  baseTurn(-135-initAngle);
  waitBase(800);
  delay(d);

  baseMove(19);
  waitBase(1000);
  delay(d);
  // // // END
  auto2for2();
  // //
  // // // ------------------------------------------- going for 8th pole -------------------
  // baseMove(-18);
  // waitBase(1000);
  // delay(d);
  //
  // baseTurn(-90-initAngle);
  // waitBase(1000);
  // delay(d);
  //
  // asyncShoot(127, 1000);
  // baseMove(-70);
  // delay(1000);
  // asyncLoad();
  // waitBase(3000);
  // delay(d);
  //
  // baseMove(14);
  // waitBase(1000);
  // delay(d);
  //
  // baseTurn(-180-initAngle);
  // waitBase(1000);
  // delay(d);
  //
  // baseMove(8);
  // waitBase(1000);
  // delay(d);
  //
  // auto1for1();
  //
  // // // // ------------------------ going for 9th center pole ------------------------
  // baseMove(-15);
  // waitBase(1000);
  // delay(d);
  //
  // baseTurn(0-initAngle);
  // waitBase(5000);
  // delay(d);

  // // printf("start centerpoling\n");
  // // baseMove(30);
  // // autoFrontIntake();
  // // setPauseMech(true);
  // // setMech(127, 127, -127, 127);
  // // waitBase(1500);
  // // powerBase(127, 127);
  // // delay(5000);
  // // timerBase(-127, -127, 500);
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
  resetCoords(0, 0);
  delay(100);

  auto1for1();
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

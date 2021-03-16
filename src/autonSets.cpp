/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  double initAngle = 65;
  int d = 100;
  int progStart = millis();
  resetCoords(0, 0);
  delay(100);

  // // ----------------------- going for 1st goal --------------------------------
  baseMove(52);
  asyncDouble();
  waitBase(1700);
  delay(d);

  baseMove(-15.2);
  waitBase(1000);
  delay(d);

  baseTurn(135-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(20);
  waitBase(1000);
  delay(d);
  auto2for2();
  // --------------------------------- going for 2nd goal -----------------------

  // // SET 1
  baseMove(-50);
  asyncShoot(0, 500);
  delay(500);
  asyncShoot(120, 300);
  delay(200);
  asyncShoot(120, 1000);
  waitBase(1200);
  //reduced from 1500
  delay(d);

  baseTurn(180-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-25);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(89-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(34);
  asyncFrontIntake();
  waitBase(1400);
  delay(d);
  // END

  auto2for1();
  //
  // // // ---------------------------- going for 3rd pole ---------------------------------
  //
  // // SET 2

  baseMove(-11);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(165-initAngle);
  waitBase(800);
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

  baseMove(26);
  asyncFrontIntake();
  waitBase(1500);
  delay(d);

  baseMove(-16);
  waitBase(1200);
  delay(d);

  baseTurn(45-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(21);
  waitBase(1000);
  delay(d);

  // END
  auto2for2();

  // // -------------------------------------------- going for 4th pole ------------------
  // // ------------- 90, 0 (3), auto1for1 -----------------
  // // // SET 1
  // // // SET 1
  // // SET 1

  initAngle = 45-bearing;
  baseMove(-53);
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

  baseMove(-22);
  asyncLoad();
  waitBase(2000);
  delay(d);

  baseTurn(0-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(32);
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
  baseMove(-11);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(90-initAngle);
  asyncShoot(100, 500);
  waitBase(800);
  delay(d);

  baseMove(-40);
  asyncLoad();
  // autoLoad();

  waitBase(1000);
  delay(d);

  baseTurn(245-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(21);
  asyncFrontIntake();
  waitBase(1500);
  delay(d);

  baseMove(-15);
  waitBase(1200);
  delay(d);

  baseTurn(315-initAngle);
  waitBase(1500);
  delay(d);

  baseMove(19);
  waitBase(1000);
  delay(d);

  // // // END
  auto2for2();
  // //
  // // // // ---------------------------- going for 6th pole ----------------------
  // // // SET 1
  // // // ------ 360, 270, auto2for1
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

  baseTurn(360-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-21.5);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(268-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(32);
  asyncFrontIntake();
  waitBase(1400);
  delay(d);
  // // // END
  auto2for1();
  // //
  // // // ------------------------------------- going for 7th pole ------------------
  // // // -------- 345, 290, 225, auto2for2
  // //
  // // SET 2
  baseMove(-13);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(345-initAngle);
  waitBase(800);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-50);
  delay(600);
  asyncLoad();
  waitBase(2500);
  delay(d);

  baseTurn(283-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(27);
  asyncFrontIntake();
  waitBase(1500);
  delay(d);

  baseMove(-18);
  waitBase(1200);
  delay(d);

  baseTurn(225-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(19);
  waitBase(1000);
  delay(d);
  // // // END
  auto2for2();



  // //
  // // // ------------------------------------------- going for 8th pole -------------------
  initAngle = 225 - bearing;
  baseMove(-18);
  waitBase(1000);
  delay(d);

//previous 270
  baseTurn(271.5-initAngle);
  waitBase(1000);
  delay(d);

  asyncShoot(127, 1000);
  baseMove(-63);
  delay(1000);
  asyncLoad();
  waitBase(2000);
  delay(d);
  delay(300);

  baseMove(16);
  waitBase(1000);
  delay(d);

  baseTurn(180-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(8);
  waitBase(1000);
  delay(d);

  auto1for1();

  // // // ------------------------ going for 9th center pole ------------------------
  baseMove(-15);
  delay(200);
  asyncShoot(100, 400);
  delay(400);
  waitBase(1000);


  baseTurn(270-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(3);
  waitBase(500);
  delay(d);

  baseTurn(360-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(25);
  asyncFrontIntakeLoad();
  waitBase(1500);
  delay(d);
  centerpole();
  printf("AUTON TIME TAKEN: %.1f s\n", (float)(millis() - progStart)/1000);
}
/** Autonomous routine for blue left spawn. */
void blueLeft(){
  resetCoords(0, 0);
  delay(100);

  // baseMove(-15);
  // asyncLoad();
  // waitBase(1000);
  // baseTurn(90);
  // waitBase(3000);
  // delay(200);

  baseMove(48);
  waitBase(3000);
  delay(200);

}
/** Autonomous routine for blue right spawn. */
void blueRight(){
  resetCoords(0, 0);
  delay(100);

  auto2for2();
}
/** Autonomous routine for red left spawn. */
void redLeft(){
  baseMove(48);
  waitBase(2000);
  delay(500);
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

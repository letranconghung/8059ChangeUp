/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){ /*
  Controller master(E_CONTROLLER_MASTER);
  double initAngle = 65;
  int d = 0;
  int progStart = millis();
  resetCoords(0, 0);
  delay(100);

  // // ----------------------- going for 1st goal --------------------------------
  baseMove(52);
  asyncDouble();
  waitBase(1700);
  delay(d);

  baseMove(-14);
  waitBase(800);
  delay(d);

  baseTurn(135-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(17); //20
  waitBase(800);
  delay(d);
  auto2for2();
  // --------------------------------- going for 2nd goal -----------------------

  // // SET 1
  baseMove(-52);
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

  baseMove(-26);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(89-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(34);
  asyncFrontIntake();
  waitBase(1000);
  delay(d);
  // END

  auto2for1();
  //
  // // // ---------------------------- going for 3rd pole ---------------------------------
  //
  // // SET 2

  baseMove(-9.8);
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
  waitBase(1000);
  delay(d);

  baseTurn(110-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(27.2);
  asyncFrontIntake();
  waitBase(1500);
  delay(d);

  baseMove(-17.5);
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
  baseMove(-49);
  asyncShoot(0, 500);
  delay(500);
  asyncShoot(120, 300);
  delay(200);
  asyncShoot(120, 1500);
  waitBase(1500);
  delay(d);

  baseTurn(91.5-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-27);
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

  baseTurn(90.5-initAngle);
  asyncShoot(127, 400);
  waitBase(800);
  delay(d+400);

  baseMove(-42);
  asyncLoad();
  // autoLoad();

  waitBase(2000);
  delay(d);

  baseTurn(245-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(23);
  asyncFrontIntake();
  waitBase(1000);
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
  baseMove(-50);
  asyncShoot(0, 500);
  delay(500);
  asyncShoot(120, 300);
  delay(200);
  asyncShoot(120, 1000);
  waitBase(1500);
  delay(d);

  baseTurn(363.3-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(-26.5);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(268-initAngle);
  waitBase(1200);
  delay(d);

  baseMove(32);
  asyncFrontIntake();
  waitBase(1000);
  delay(d);
  // // // END
  auto2for1();
  // //
  // // // ------------------------------------- going for 7th pole ------------------
  // // // -------- 345, 290, 225, auto2for2
  // //
  // // SET 2
  baseMove(-9.5);
  asyncShoot(0, 500);
  waitBase(1000);
  delay(d);

  baseTurn(346-initAngle);
  waitBase(1000);
  delay(d);
  asyncShoot(100, 500);

  baseMove(-53);
  delay(600);
  asyncLoad();
  waitBase(1500);
  delay(d);

  baseTurn(283-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(27.2);
  asyncFrontIntake();
  waitBase(1500);
  delay(d);

  baseMove(-18);
  waitBase(1200);
  delay(d);

  baseTurn(225-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(20);
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
  baseTurn(274.7-initAngle);
  waitBase(1000);
  delay(d);

  asyncShoot(127, 1000);
  baseMove(-63);
  delay(1000);
  asyncLoad();
  waitBase(1000);
  delay(d);

  baseMove(16);
  waitBase(1000);
  delay(d);

  baseTurn(180-initAngle);
  waitBase(700);
  delay(d);

  baseMove(8);
  waitBase(500);
  delay(d);

  auto1for1();

  // // // ------------------------ going for 9th center pole ------------------------
  baseMove(-15);
  delay(200);
  asyncShoot(127, 600);
  waitBase(1000);


  baseTurn(270-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(2);
  waitBase(300);
  delay(d);

  baseTurn(361.7-initAngle);
  waitBase(1000);
  delay(d);

  baseMove(25);
  asyncFrontIntakeLoad();
  waitBase(1500);
  delay(d);
  centerpole();
  int timeTaken = millis() - progStart;
  printf("time: %.1f s\n", (float)timeTaken/1000.0);
  while(true){
    master.print(1, 0, "time: %.1f s", (float)timeTaken/1000.0);
    delay(5);
  }*/
}
/** Autonomous routine for blue left spawn. */
void blueRight1(){
  //Goal1 - Goal C
  setMech(0,0,90,0);
  baseMove(-3.5);
  waitBase(600);
  delay(5);
  setMech(0,0,-127,0,400); //eject ball

  //Goal 2 - Goal B
  baseMove(5.2);
  waitBase(700);
  baseTurn(75.3);//face goal -77
  waitBase(850);
  baseMove(47);//45
  waitBase(1200);
  setMech(-127,-127,-127,0,400); //eject ball

  //Goal3 - Goal F
  baseMove(-14);
  waitBase(700);
  baseTurn(25); //face ball
  waitBase(800);
  setMech(127,127,127,0);
  baseMove(25); //intake ball
  waitBase(900);
  delay(10);
  baseMove(-5);
  waitBase(300);
  baseTurn(-77); //face goal
  waitBase(1100);
  setMech(0,0,0,0);
  timerBase(127,127,1200);
  delay(10);
  setMech(-127,-127,127,115,400); //shoot
  delay(10);

  //Goal4 - Goal I
  setMech(0,0,0,0);
  baseMove(-13);
  waitBase(500);
  baseTurn(-39.8); //face goal -40.5
  waitBase(600);
  timerBase(127,127,1280);
  timerBase(20,127,450); //ram ball in
  baseMove(-16.8); //reverse -20
  waitBase(600);
  setMech(0,0,0,0);

  //auto9 letsgooooo
  baseTurn(90);
  waitBase(1200);
  timerBase(127,127,500);
  timerBase(127,50,500);
  timerBase(127,127,300);
  delay(5);
  timerBase(-127,-127,200);
  /*baseMove(34);
  waitBase(900);
  baseTurn(150); //face goal
  waitBase(900);
  baseMove(18);
  waitBase(800);*/


}
/** Autonomous routine for blue right spawn. */
void blueRight2(){

}
/** Autonomous routine for red left spawn. */
void redRight2(){

  //Goal1 - red right goal
  setMech(0,0,80,0);
  baseMove(-3.5);
  waitBase(500);
  delay(50);
  setMech(0,0,-127,0,400); //eject ball

  //Goal 2 - middle right goal
  baseMove(5.2);
  waitBase(700);
  baseTurn(77);//face goal
  waitBase(800);
  baseMove(47);
  waitBase(1200);
  setMech(-127,-127,-127,0,400); //eject ball

  //Goal3 - red middle goal
  baseMove(-14);
  waitBase(1000);
  baseTurn(25); //face ball
  waitBase(1000);
  setMech(127,127,127,0);
  baseMove(25); //intake ball
  waitBase(1000);
  delay(80);
  baseMove(-5);
  waitBase(300);
  baseTurn(-76); //face goal
  waitBase(1200);
  setMech(0,0,0,0);
  timerBase(127,127,1300);
  setMech(0,0,127,127,380); //shoot
  delay(20);

  //Goal 4 centre goal
  timerBase(10,127,300);
  setMech(0,0,-127,0);
  baseMove(-50);
  waitBase(800);

  //Goal4 - red left goal
  /*
  baseMove(-18);
  waitBase(1000);
  baseTurn(-41); //face goal -40
  waitBase(1000);
  setMech(127,127,127,0);
  timerBase(127,127,1500);
  timerBase(20,127,400); //align -500
  setMech(0,0,127,127,550);
  delay(50);
  setMech(-127,-127,0,0);
  baseMove(-10); //reverse
  waitBase(500);
  setMech(0,0,0,0);
  */
}
/** Autonomous routine for red right spawn. */
void redRight1(){

  //Goal1 - red right goal
  setMech(0,0,80,0);
  baseMove(-3.5);
  waitBase(500);
  delay(5);
  setMech(0,0,-127,0,400); //eject ball

  //Goal 2 - middle right goal
  baseMove(5.2);
  waitBase(700);
  baseTurn(77);//face goal
  waitBase(850);
  baseMove(47);//45
  waitBase(1200);
  setMech(-127,-127,-127,0,400); //eject ball

  //Goal3 - red middle goal
  baseMove(-14);
  waitBase(700);
  baseTurn(25); //face ball
  waitBase(800); //1000
  setMech(127,127,127,0);
  baseMove(25); //intake ball
  waitBase(900); //1000
  delay(10);
  baseMove(-5);
  waitBase(300);
  baseTurn(-76); //face goal
  waitBase(1100);
  setMech(0,0,0,0);
  timerBase(127,127,1200);
  delay(5);
  setMech(0,0,127,127,400); //shoot
  delay(10);

  //Goal4 - red left goal
  baseMove(-17); //18
  waitBase(600); //1000
  baseTurn(-40.5); //face goal -40
  waitBase(600);
  setMech(115,115,127,0);
  timerBase(127,127,1480);
  delay(5);
  timerBase(20,127,400); //align -500
  setMech(0,0,127,127,650);
  delay(10);
  setMech(-127,-127,0,0);
  baseMove(-10); //reverse
  waitBase(500);
  setMech(0,0,0,0);

}

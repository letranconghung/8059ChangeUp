/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
  baseMove(30);
  waitBase(1000);
  baseTurn(180, 0.89, 0);
  waitBase(2000);
  baseMove(30);
  waitBase(1000);
  // 0.95 for 90, 0.88 for 180
}
/** Autonomous routine for blue homerow. */
void BHR(){
  //Goal C
  asyncFrontIntake();
  baseMove(5.8, 0.002,0); //intake ball
  waitBase(500);
  baseTurn(30, 1.7, 0);
  waitBase(500);
  // baseMove(6,0.002,0); //align
  // waitBase(500);
  shoot(350);
  asyncLoad();

  //Goal F
  baseMove(-15); //12.5
  waitBase(1000);
  baseTurn(0, 1.7, 0);
  waitBase(500);
  delay(500);
  baseMove(-44); //move to goal -45
  waitBase(1500);
  baseTurn(90); //face goal
  waitBase(1000);
  baseMove(9); //11.3
  waitBase(1000);
  shoot(400);

  //Goal I
  baseMove(-10);//17
  waitBase(1000);
  baseTurn(180);
  waitBase(1000);
  baseMove(50.5);
  waitBase(1500);
  baseTurn(135,1.7,0);
  waitBase(1000);
  asyncFrontIntakeLoad();
  baseMove(15);
  waitBase(1000);
  delay(200);
  shoot(400);

  // //Goal E
  // baseMove(-30);
  // waitBase(1500);
  // baseTurn(270); //face ball
  // waitBase(1000);
  // asyncFrontIntake();
  // baseMove(29);
  // waitBase(1500);
  // baseMove(-30); //24
  // waitBase(1000);
  // baseTurn(220,1.7,0); //face goal
  // waitBase(1000);
  // baseMove(29);
  // waitBase(1500);
  // setMech(-1,-1,0,600);
  // baseMove(-10);
  // waitBase(500);

}

/** Autonomous routine for blue homerow + 2. */
void BHR8(){
  //Goal C
  asyncFrontIntake();
  baseMove(5.8, 0.002,0); //intake ball
  waitBase(500);
  baseTurn(30, 1.7, 0);
  waitBase(500);
  // baseMove(6,0.002,0); //align
  // waitBase(500);
  shoot(350);
  asyncLoad();

  //Goal F
  baseMove(-15); //12.5
  waitBase(1000);
  baseTurn(0, 1.7, 0);
  waitBase(500);
  delay(500);
  baseMove(-44); //move to goal -45
  waitBase(1500);
  baseTurn(90); //face goal
  waitBase(1000);
  baseMove(9); //11.3
  waitBase(1000);
  shoot(400);

  //Goal I
  baseMove(-10);//17
  waitBase(1000);
  baseTurn(180);
  waitBase(1000);
  baseMove(50.5);
  waitBase(1500);
  baseTurn(135,1.7,0);
  waitBase(1000);
  asyncFrontIntakeLoad();
  baseMove(15);
  waitBase(1000);
  delay(200);
  shoot(400);
}

/*Autonomous routine for blue middle row. */
void BMR() {

}

/* Autonomous routine for red homerow. */
void RHR(){

}
/* Autonomous routine for red homerow + 2. */
void RHR8(){

}

/*Autonomous routine for red middle row. */
void RMR() {

}

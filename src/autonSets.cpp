/** Autonomous routines */
#include "main.h"
/** programming skills run */
int del = 10;
void move(double d, double kp, double kd, double t){
  baseMove(d, kp, kd);
  waitBase(t);
  delay(del);
}
void move(double d, double t){
  baseMove(d);
  waitBase(t);
  delay(del);
}
void turn(double a, double kp, double kd, double t){
  baseTurn(a, kp, kd);
  waitBase(t);
  delay(del);
}
void turn(double a, double t){
  baseTurn(a);
  waitBase(t);
  delay(del);
}
void test(){
  move(48,2000);
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
void BHR10(){
  double initAngle = 32;

  //Goal F
  setMech(0,1,1,500);

  //Goal I
  move(-30,1500);
  turn(297-initAngle,0.95,0,1000); //face first ball
  delay(2000); // -99
  asyncFrontIntakeLoad();
  move(39.5,1500); //40
  move(-19,1000); //20
  turn(242-initAngle,1.2,0,800); //face second ball
  delay(2000); // -155
  asyncFrontIntake();
  move(18,1000); //20

  move(-25,1500);
  turn(133-initAngle,0.88,0,800); //face goal // -259
  delay(2000);
  delay(1000);
  setMech(1,0,0);
  move(46.5,1800);
  setMech(0,1,1,400);
  delay(5);
  setMech(-1,0,0); //stuff ball
  move(-10,0.001,0,500);
  move(-10,1000);
  resetMech();

  //Goal C
  turn(0-initAngle,0.9,0,2000);
  delay(2000);
  move(93,3000);
  asyncFrontIntake();
  turn(45-initAngle,1.3,0,1000);
  move(14,1000);
  shoot(800);
}

/*Autonomous routine for blue middle row. */
void BMR() {

}

/* Autonomous routine for red homerow. */
void RHR(){

}
/* Autonomous routine for red homerow + 2. */
void RHR10(){

}

/*Autonomous routine for red middle row. */
void RMR() {

}
//BHR8
// //Goal C
// asyncFrontIntake();
// baseMove(5.8, 0.002,0); //intake ball
// waitBase(500);
// baseTurn(30, 1.7, 0);
// waitBase(500);
// // baseMove(6,0.002,0); //align
// // waitBase(500);
// shoot(350);
// asyncLoad();
//
// //Goal F
// baseMove(-15); //12.5
// waitBase(1000);
// baseTurn(0, 1.7, 0);
// waitBase(500);
// delay(500);
// baseMove(-44); //move to goal -45
// waitBase(1500);
// baseTurn(90); //face goal
// waitBase(1000);
// baseMove(9); //11.3
// waitBase(1000);
// shoot(400);
//
// //Goal I
// baseMove(-10);//17
// waitBase(1000);
// baseTurn(180);
// waitBase(1000);
// baseMove(50.5);
// waitBase(1500);
// baseTurn(135,1.7,0);
// waitBase(1000);
// asyncFrontIntakeLoad();
// baseMove(15);
// waitBase(1000);
// delay(200);
// shoot(400);

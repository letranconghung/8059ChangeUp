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
  // move(48,2000);
  // turn(-30, 0.95, 0, 1000);
  timerBase(60, 120, 500);
  // 0.95 for 90, 0.88 for 180
}
void BHR11(){
  // #define DEFAULT_KP 0.0012
  // setMech(1, 0, 0);
  // move(4, 0.004, 0, 500);
  // resetMech();
  // asyncLoad();
  // turn(-35, 1.7, 0, 500);
  // move(4.5, 0.0015, 0, 500);
  setMech(1, 0, 0);
  timerBase(45, 127, 500);
  setMech(-0.8, 0.7,1,600);
  // setMech(-1, -1, 0,400);
  setMech(-0.4, 0, 0);
  move(-23, 1000);
  resetMech();
  // delay(200);
  turn(90, 0.93, 0, 800);
  // delay(200);
  asyncFrontIntakeLoad();
  move(37, 1400);
  // delay(1000);
  move(-21, 900);
  // delay(500);
  turn(145,1.42,0,700);
  delay(200);
  asyncFrontIntake();
  // delay(200);
  move(30,1200);
  // delay(1000);
  move(-5.5,300);
  turn(92,1.4,0,500);
  setMech(1, 0, 0);
  move(10,500);
  move(-20, 900);
  turn(-120,0.9,0,800);
  delay(200);
  move(30,1000);
  setMech(-0.8, 0.7, 1, 400);
  setMech(-0.5, 1, 0);
  move(-10, 0.003, 0, 500);
  asyncLoad();
  turn(180, 1.4, 0, 500);
  delay(200);
  move(48,1500);
  // turn(-135, 1.42, 0, 500);
  // move(20,500);
  // setMech(0, 1, 1);
  timerBase(120,80,700);
  setMech(0, 1, 1);
}
void RHR11(){

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
  double initAngle = 30;
  timerBase(-50,-50,400);
  setMech(0, 1, 1);
  timerBase(50,50,400);
  //Goal F
  //Goal I
  move(-22,1000); //-28
  turn(293-initAngle,1.1,0,500); //face first ball // 1, 800
  // delay(2000); // -99
  delay(300);
  asyncFrontIntakeLoad();
  move(41,1300); //40
  move(-19,800); //20
  turn(244-initAngle,1.45,0,450); //face second ball //800
  asyncFrontIntake();
  move(19,800); //20
  move(-23.5,900);
  // delay(200);
  asyncLoad();
  // turn(135-initAngle,1.08,0,500); //face goal // blue side
  turn(137-initAngle,1.05,0,500); //red side 
  delay(300);
  setMech(1,0,0);
  move(46.5,1200);
  setMech(-1,1,1,400);
  setMech(-0.5,0,0); //stuff ball
  move(-19, 900);
  resetMech();

  //Goal C
  asyncLoad();
  turn(0-initAngle,0.88,0,750);
  delay(300);
  move(93.5,2200);
  turn(45-initAngle,1.8,0,600);
  powerBase(80,80);
  setMech(0, 1, 1);
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

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
void cage(){
  move(10,1000);
  turn(90,0.88,0,1000);
  move(-10,1000);
  turn(45,1.2,0,1000);
  setMech(0,-1,0);
  move(-10,1000);

}
void BHR10(){
  double initAngle = 30;
  timerBase(-50,-50,400);
  setMech(0, 1, 1);
  timerBase(50,50,430);
  //Goal F
  //Goal I
  move(-21,1000); //-28
  turn(293-initAngle,1.1,0,500); //face first ball
  // delay(2000); // -99
  delay(400);
  asyncFrontIntakeLoad();
  move(42.4,1300); // blue side
  // move(42.5,1300); // red side
  move(-20,800); //20
  turn(244-initAngle,1.45,0,450); //face second ball
  asyncFrontIntake();
  move(22,850);
  move(-24.5,930);
  // delay(200);
  asyncLoad();
  turn(137-initAngle,1.05,0,500); // 137
  delay(400);
  setMech(1,0,0);
  move(46.5,1200);
  setMech(-1,1,1,400);
  setMech(-0.5,0,0); //stuff ball
  move(-21, 950);
  resetMech();

  //Goal C
  asyncLoad();
  turn(0-initAngle,0.88,0,750);
  delay(300);
  move(93.5,2200); // blue side
  // move(92,2200); // red side
  turn(45-initAngle,1.8,0,600);
  powerBase(80,80);
  setMech(0, 1, 1);
}
/* Autonomous routine for red homerow + 2. */
void RHR10(){
  double initAngle = 30;
  timerBase(-50,-50,400);
  setMech(0, 1, 1);
  timerBase(50,50,430);
  //Goal F
  //Goal I
  move(-21,1000); //-28
  turn(293-initAngle,1.1,0,500); //face first ball
  // delay(2000); // -99
  delay(400);
  asyncFrontIntakeLoad();
  move(42.4,1300); // blue side
  // move(42.5,1300); // red side
  move(-20,800); //20
  turn(244-initAngle,1.45,0,450); //face second ball
  asyncFrontIntake();
  move(22,850);
  move(-23,900);
  // delay(200);
  asyncLoad();
  turn(137-initAngle,1.05,0,500); // 137
  delay(400);
  setMech(1,0,0);
  move(46.5,1200);
  setMech(-1,1,1,480);
  setMech(-0.5,0,0); //stuff ball
  move(-21, 900);
  resetMech();

  //Goal C
  asyncLoad();
  turn(0-initAngle,0.88,0,750);
  delay(300);
  move(93,2200); // blue side
  // move(92,2200); // red side
  turn(45-initAngle,1.8,0,600);
  powerBase(80,80);
  setMech(0, 1, 1);
}
void BHR(){
  //Goal C
  asyncFrontIntake();
  move(5,0.002,0,500);
  turn(38,1.5,0,800);
  move(4,0.002,0,400);
  setMech(0, 1, 0.8, 400);
  asyncLoad();

  //Goal F
  move(-21, 900);
  turn(0, 1.6, 0, 600);
  delay(500);
  move(-44, 1500);
  turn(90, 800);
  move(16, 1000);
  setMech(0, 1, 0.8, 500);

  //Goal I
  move(-12, 1000);
  turn(180, 800);
  delay(200);
  move(46,1500);
  turn(135,1.7,0,800);
  // asyncFrontIntakeLoad();
  move(15, 1000);
  // shoot(400);
}

/** Autonomous routines */
#include "main.h"
/** programming skills run */
void score2for2(){
  shoot(127, 500);
  autoLoad();
  autoFrontIntake();
  shoot(127, 600);
  autoLoad();
  autoFrontIntake();
}
void skills(){
  int d = 300;
  resetCoords(0, 0);
  delay(100);

  baseMove(50);
  asyncDouble();
  waitBase(5000);
  delay(d);

  baseMove(-10);
  waitBase(1000);
  delay(d);

  baseTurn(83);
  waitBase(1000);
  delay(d);

  baseMove(20);
  waitBase(1000);
  delay(d);

  score2for2();
}
/** Autonomous routine for blue left spawn. */
void blueLeft(){
  resetCoords(0, 0);
  delay(100);

  baseTurn(90);
  waitBase(1000);
}
/** Autonomous routine for blue right spawn. */
void blueRight(){

}
/** Autonomous routine for red left spawn. */
void redLeft(){
}
/** Autonomous routine for red right spawn. */
void redRight(){

}

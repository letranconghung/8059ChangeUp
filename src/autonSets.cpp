/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
  baseMove(48);
  waitBase(3000);
}
/** Autonomous routine for blue left spawn. */
void BHR(){
  //Goal C
  setMech(127,80,0);
  baseMove(6.5); //intake ball
  waitBase(500);
  baseTurn(30, 1.5, 0);
  waitBase(1000);
  resetMech();
  baseMove(8); //align
  waitBase(1000);
  setMech(0, 127, 127, 350);

  //Goal F
  baseMove(-30);
  waitBase(1500);
  baseTurn(3, 1.4, 0);
  waitBase(1000);
  delay(500);
  baseMove(-32.5); //move to goal
  waitBase(2000);
  setMech(0,80,0);
  baseTurn(90); //face goal
  waitBase(1000);
  baseMove(10);
  waitBase(1000);
  setMech(0,127,127,400);

  //Goal I
  baseMove(-15);
  waitBase(1000);
  baseTurn(160); //face ball
  waitBase(1000);
  setMech(127,127,0);
  baseMove(54);
  waitBase(2000);
  baseTurn(145); //face goal
  waitBase(1000);
  setMech(0,80,0);
  baseMove(8);
  waitBase(1000);
  setMech(0,127,127);
}

/** Autonomous routine for blue right spawn. */
void BMR(){
}
/* Autonomous routine for red left spawn. */
void RHR(){

}
/* Autonomous routine for red right spawn. */
void RMR(){

}

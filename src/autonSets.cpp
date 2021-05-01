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
  baseMove(6.5, 0.5, 0); //intake ball
  waitBase(500);
  baseTurn(30, 1.7, 0);
  waitBase(500);
  resetMech();
  baseMove(8, 0.5, 0); //align
  waitBase(500);
  setMech(0, 127, 127, 350);

  //Goal F
  baseMove(-30, 0.4, 0);
  waitBase(1500);
  baseTurn(0, 1.5, 0);
  waitBase(500);
  delay(500);
  baseMove(-32.5); //move to goal
  waitBase(1500);
  setMech(0,80,0);
  baseTurn(90); //face goal
  waitBase(1000);
  baseMove(11.3);
  waitBase(1000);
  setMech(0,127,127,400);

  //Goal I
  baseMove(-14, 0.4, 0);
  waitBase(1000);
  baseTurn(160, 1.2, 0); //face ball
  waitBase(700);
  setMech(127,100,0);
  baseMove(53);
  waitBase(1500);
  baseTurn(134, 1.5, 0); //face goal
  waitBase(800);
  setMech(0,80,0);
  baseMove(11, 0.4, 0);
  waitBase(800);
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

/** Autonomous routines */
#include "main.h"
/** programming skills run */
void test(){
  baseMove(48);
  waitBase(2000);
}
void skills(){

}
/** Autonomous routine for blue left spawn. */
void BHR(){

}

/** Autonomous routine for blue right spawn. */
void BMR(){

}
/* Autonomous routine for red left spawn. */
void RHR(){

  //Goal 1 - G
  setMech(127,127,40,0);
  baseMove(8.5);
  waitBase(500);
  baseTurn(40);
  waitBase(600);
  baseMove(5);
  waitBase(500);
  setMech(0,0,127,127,400);
  delay(10);

  //Goal 2 - D
  baseMove(-22);
  waitBase(800);
  baseTurn(0);
  waitBase(600);
  baseMove(-41);
  waitBase(2000);
  baseTurn(90);
  waitBase(1000);
  baseMove(8);
  waitBase(800);
  setMech(0,0,127,127,600);
  delay(20);

  //Goal 3 - A
  baseMove(-10);
  waitBase(800);
  baseTurn(160);
  waitBase(1000);
  setMech(127,127,60,0);
  baseMove(55);
  waitBase(2000);
  baseTurn(135);
  waitBase(1000);
  baseMove(8);
  waitBase(800);
  setMech(0,0,127,127,500);
  delay(20);
  baseMove(-10);
  waitBase(800);
  setMech(0,0,0,0);




}
/* Autonomous routine for red right spawn. */
void RMR(){

}

/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  resetCoords(0, 0);
  delay(100);

//Goal1 (middle goal)
  setMech(127, 127, 0, 0);
  timerBase(127,0,400);
  setMech(127,127,127,127,550);//
  delay(10);
  timerBase(-127,-11,350);
  setMech(-127,-127,-127,0,500);
  delay(100);
  setMech(0,0,127,0);
  baseMove(-58);
  waitBase(2000);

  setMech(127, 127, 0, 0);

  baseTurn(90);
  waitBase(2000);
  baseMove(20);
  waitBase(2000);
  timerBase(100,20,400);
  setMech(127,127,127,127,750);
  delay(90);
  baseMove(-10);
  setMech(-127,-127,-127,0,700);
  delay(90);
  timerBase(-127,0,100);
  baseMove(-30);
  // angle need to tune
  // move bake abit more to outtake 
  //setMech(-127,-127,-127,-127);
  /*
  delay(100);
  ball_intake(127,10,0);
  setMech(0,0,127,0);
  baseMove(-40);
  waitBase(1900);
  setMech(0,0,0,0);
  //until the edge
  //Goal2
  //baseMove(5);
  //baseTurn(90);
*/





}
/** Autonomous routine for blue left spawn. */
void blueLeft(){

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

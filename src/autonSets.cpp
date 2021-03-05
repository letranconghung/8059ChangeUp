/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  resetCoords(0, 0);
  delay(100);

//Goal1 (middle goal)
  setMech(127, 127, 0, 0);
  timerBase(127,0,350);
  setMech(127,127,127,127,450);//
  timerBase(-127,-17,400);
  //setMech(-127,-127,-127,-127);
  /*setMech(-127,-127,-127,0,500);
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

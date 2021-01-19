/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  cycle(500);
  suck(700);
  timerBase(80, 80, 500);
  waitIndexer();
  delay(1000);
  baseMove(-10);
  frontOuttake(700);
  waitBase(1000);
  delay(500);
  baseMove(-15);
  backIntake();
  waitBase(1000);
  baseTurn(-33);
  waitBase(1000);
  load();
  baseMove(-35);
  waitBase(2000);
  baseTurn(70);
  waitBase(1000);
  baseMove(5);
  waitBase(1000);
  shoot(700);
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

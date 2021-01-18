/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  loadshoot();
  delay(1000);
  backIntake();
  baseMove(-30);
  waitBase(1000);
  baseTurn(-25);
  waitBase(500);
  load();
  baseMove(-32);
  waitBase(2000);
  baseTurn(70);
  waitBase(1000);
  baseMove(5);
  waitBase(500);
  shoot();
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

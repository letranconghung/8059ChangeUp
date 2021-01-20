/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  /** shoot */
  timedCycle(127,700);
  /** intake 1st and 2nd blue balls */
  autoIntakeLoad();
  autoFrontIntake();
  timerBase(80, 80, 500);
  mechBlock();
  /** delay for debugging */
  delay(1000);
  /** move out */
  baseMove(-15);
  waitBase(1000);
  timedCycle(100,700);
  autoLoad(); //also serve as backIntake
  baseMove(-15);
  waitBase(1000);
  baseTurn(-33);
  waitBase(1000);
  baseMove(-35);
  waitBase(2000);
  baseTurn(70);
  waitBase(1000);
  baseMove(5);
  waitBase(1000);
  timedCycle(127,300);
  autoIntakeLoad();
  mechBlock();
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

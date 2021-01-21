/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
  /** shoot */
  timedColumnCycle(127,700);
  /** intake 1st and 2nd blue balls */
  autoIntakeLoad();
  autoFrontIntake();
  timedFrontOuttake(1000);
  timerBase(100, 100, 1000);
  mechBlock();
  /** delay for debugging */
  delay(2000);
  /** move out */
  baseMove(-7);
  waitBase(1000);
  delay(500);

  timedColumnCycle(127,700);
  autoLoad(); //also serve as backIntake
  baseMove(-18);
  waitBase(1000);
  delay(500);

  baseTurn(-35);
  waitBase(1000);
  delay(500);

  baseMove(-40);
  waitBase(2000);
  delay(500);

  baseTurn(55);
  waitBase(1000);
  delay(500);

  baseMove(10);
  waitBase(1000);
  delay(500);

  timedColumnCycle(127,300);
  autoFrontIntake();
  timerBase(80, 80, 500);
  mechBlock();
  autoLoad();

  autoFrontIntake();
  baseMove(-10);
  waitBase(1000);
  delay(500);

  baseTurn(148);
  waitBase(1000);
  delay(500);

  baseMove(53);
  waitBase(2500);
  delay(500);

  baseTurn(100);
  waitBase(1000);
  delay(500);

  baseMove(20);
  waitBase(1000);
  delay(500);
  /** shoot */
  timedColumnCycle(127,300);
  autoLoad();
  autoFrontIntake();
  timedColumnCycle(127,300);
  autoLoad();
  autoFrontIntake();
  timerBase(80, 80, 1000);
  mechBlock();

  baseMove(-20);
  waitBase(1000);
  delay(500);

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

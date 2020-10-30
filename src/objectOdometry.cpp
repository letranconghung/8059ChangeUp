/**
 * Vision task that constantly updates the largest (and therefore closest) red ball, blue ball and green flag
 */
#include "main.h"
const VisionCoordinates TARG_RED_BALL{0, 168, 44, 114, 891};
const VisionCoordinates TARG_BLUE_BALL{0, 146, 127, 92, 49};
/** VisionObject objects that bundle current ball locations with target ball locations */
VisionObject redBall(VisionCoordinates(), TARG_RED_BALL);
VisionObject blueBall(VisionCoordinates(), TARG_RED_BALL);
Vision visBall(visBallport);
void objectOdometry(void * ignore){
  int i = 0;
  while(!VISION_COMPETITION_MODE || competition::is_autonomous()){
    /** import output from Vision Sensor */
    redBall.curr.getFromObject(visBall.get_by_sig(0, SIG_RED_BALL));
    blueBall.curr.getFromObject(visBall.get_by_sig(0, SIG_BLUE_BALL));
    ++i;
    /** debugging */
    if(VISION_DEBUG_MODE == 1 && (i % 100 == 0)){
      printf("---------------------------------------------------------\n");
      redBall.curr.print();
      blueBall.curr.print();
      greenFlag.curr.print();
    }
    if(VISION_DEBUG_MODE == 3 && (i % 10 == 0)){
      redBall.curr.printMaster();
      redBall.curr.print();
    }
    Task::delay(10);
  }
}

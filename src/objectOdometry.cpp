#include "main.h"
const VisionCoordinates TARG_RED_BALL{0, 168, 44, 96, 891};
const VisionCoordinates TARG_BLUE_BALL{0, 146, 127, 102, 49};
VisionObject redBall(VisionCoordinates(), TARG_RED_BALL);
VisionObject blueBall(VisionCoordinates(), TARG_BLUE_BALL);
// Vision visFlag(visFlagport); //give reading every 10ms (think so empirical)
Vision visBall(visBallport);
void objectOdometry(void * ignore){
  int i = 0;
  while(!VISION_COMPETITION_MODE || competition::is_autonomous()){
    redBall.curr.getFromObject(visBall.get_by_sig(0, SIG_RED_BALL));
    blueBall.curr.getFromObject(visBall.get_by_sig(0, SIG_BLUE_BALL));
    // greenFlag.curr.getFromObject(visFlag.get_by_sig(0, SIG_GREEN_FLAG));
    // ++i;
    if(VISION_DEBUG_MODE == 1 && (i % 100 == 0)){
      printf("---------------------------------------------------------\n");
      redBall.curr.print();
      blueBall.curr.print();
      greenFlag.curr.print();
    }
    if(VISION_DEBUG_MODE == 3 && (i % 100 == 0)){
      blueBall.curr.printMaster();
      blueBall.curr.print();
    }
    Task::delay(10);
  }
}

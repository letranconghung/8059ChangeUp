#include "main.h"
const VisionCoordinates TARG_BALL{0, 143, 102, 136,74};
const VisionCoordinates TARG_FLAG{0,180,53,63,900};
VisionObject redBall(VisionCoordinates(), TARG_BALL);
VisionObject blueBall(VisionCoordinates(), TARG_BALL);
VisionObject greenFlag(VisionCoordinates(), TARG_FLAG);
Vision visFlag(visFlagport); //give reading every 10ms (think so empirical)
Vision visBall(visBallport);
void objectOdometry(void * ignore){
  int i = 0;
  while(!VISION_COMPETITION_MODE || competition::is_autonomous()){
    redBall.curr.getFromObject(visBall.get_by_sig(0, SIG_RED_BALL));
    blueBall.curr.getFromObject(visBall.get_by_sig(0, SIG_BLUE_BALL));
    greenFlag.curr.getFromObject(visFlag.get_by_sig(0, SIG_GREEN_FLAG));
    ++i;
    if(VISION_DEBUG_MODE == 1 && (i % 100 == 0)){
      printf("---------------------------------------------------------\n");
      redBall.curr.print();
      blueBall.curr.print();
      greenFlag.curr.print();
    }
    if(VISION_DEBUG_MODE == 3 && (i % 100 == 0)){
      redBall.curr.printMaster();
      redBall.curr.print();
    }
    Task::delay(10);
  }
}

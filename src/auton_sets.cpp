/**
 * Autonomous routines:
 * - Skills run
 * - 15s auton runs for each spawn
 */
#include "main.h"
/**
 * Programming skills run
 * @return void
 */
void skills(){
	resetCoords(0, 0, 0);

	// intakeMove(127);
	// visionBaseMove(SIG_RED_BALL);
	// visionWaitBase(3000);
	// pickUp(20);
	// printf("yo I eneded \n");
	// delay(1000);
	// visionBaseMove(SIG_RED_BALL);
	// visionWaitBase(3000);

	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(3000);
	cycle();
}
/**
 * Starting position on the left of the blue alliance spawn.
 * @return void
 */
void blueLeft(){

}
/**
 * Starting position on the right of the blue alliance spawn.
 * @return void
 */
void blueRight(){

}
/**
 * Starting position on the left of the red alliance spawn.
 * @return void
 */
void redLeft(){

}
/**
 * Starting position on the right of the prevEncdR alliance spawn.
 * @return void
 */
void redRight(){

}

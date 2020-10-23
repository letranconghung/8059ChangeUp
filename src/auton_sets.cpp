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

	baseMove(-4);
	waitBase(500);
	delay(300);
	baseTurn(173);
	waitBase(1000);
	delay(300);
	baseMove(4);
	waitBase(500);
	intakeMove(127);
	delay(1000);
	pickUp(40);
	delay(2000);
	intakeMove(0);

	baseMove(45);
	waitBase(1500);
	delay(500);
	baseTurn(58);
	waitBase(1000);
	delay(300);

	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1500);
	pauseBase(true);
	cycle();
	delay(1000);
	pauseBase(false);
	delay(2000);

	baseTurn(125);
	waitBase(1000);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(1200);
	pickUp(40);
	intakeMove(0);

	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1500);
	pauseBase(true);
	cycle();
	delay(1000);
	pauseBase(false);
	delay(3000);

	baseTurn(195);
	waitBase(1200);
	delay(500);
	baseMove(25);
	waitBase(1000);
	delay(300);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(1200);
	pickUp(40);
	intakeMove(0);

	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1500);
	pauseBase(true);
	cycle();
	delay(1000);
	pauseBase(false);
	delay(3000);


	// pauseBase(true);
	// setTargetsToCurr();
	// delay(3000);
	// pauseBase(false);

	// intakeMove(127);
	// visionBaseMove(SIG_RED_BALL);
	// visionWaitBase(3000);
	// pickUp(20);
	// printf("yo I eneded \n");
	// delay(1000);
	// visionBaseMove(SIG_RED_BALL);
	// visionWaitBase(3000);

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

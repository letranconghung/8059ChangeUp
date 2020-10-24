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
	resetCoords(0, 0, -58);
	delay(500);
	baseMove(-4);
	waitBase(500);
	delay(300);
	baseTurn(115);
	waitBase(1000);
	delay(300);
	baseMove(4);
	waitBase(500);
	intakeMove(127);
	delay(1000);
	pickUp(40);
	delay(2000);
	intakeMove(0);


	baseTurn(100);
	waitBase(1000);
	delay(500);
	baseMove(44);
	waitBase(3000);
	delay(500);

//2nd pole
	baseTurn(0);
	waitBase(1200);
	delay(500);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(2000);
	cycle();
	pauseBase(true);
	delay(2000);
	pauseBase(false);

	//center pole
	baseMove(-10);
	waitBase(700);
	delay(500);
	baseTurn(180,0.35,0.15);
	waitBase(3000);
	delay(500);
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(1500);
	delay(500);
	pickUp(40);
	delay(1000);
	baseTurn(170);
	waitBase(1000);
	delay(500);
	intakeMove(0);
	baseMove(33);
	waitBase(1000);
	powerBase(100, 0);
	delay(1000);
	pauseBase(false);
	waitBase(1000);
	delay(1000);
	cycle();
	pauseBase(true);
	delay(500);
	pauseBase(false);

	baseMove(-15);
	waitBase(2000);
	delay(500);

	//fourth pole
	baseTurn(45);
	waitBase(2000);
	delay(500);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(3000);
	delay(500);
	pickUp(40);
	delay(500);
	intakeMove(0);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(2000);
	cycle();
	pauseBase(true);
	delay(2000);
	pauseBase(false);

	baseMove(-10);
	waitBase(1000);
	delay(500);

	//fifth pole
	baseTurn(180);
	waitBase(2000);
	delay(500);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(3000);
	delay(500);
	pickUp(40);
	delay(500);
	intakeMove(0);

	baseMove(13);
	waitBase(1500);
	delay(500);

	baseTurn(90);
	waitBase(1000);
	delay(500);

	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1000);
	delay(500);
	cycle();
	pauseBase(true);
	delay(2000);
	pauseBase(false);

	//sixth pole
	baseMove(-15);
	waitBase(1000);
	delay(500);

	baseTurn(195);
	waitBase(2000);
	delay(500);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(2000);
	delay(500);
	pickUp(40);
	delay(500);
	intakeMove(0);

	baseTurn(140);
	waitBase(1000);
	delay(500);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1500);
	delay(500);
	cycle();
	pauseBase(true);
	delay(2000);
	pauseBase(false);

	//7th
	baseMove(-10);
	waitBase(1000);
	delay(500);
	baseTurn(-60);
	waitBase(1000);
	delay(500);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(2000);
	delay(500);
	pickUp(40);
	delay(500);
	intakeMove(0);

	baseTurn(190);
	waitBase(1000);
	delay(500);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(2000);
	delay(500);
	cycle();
	pauseBase(true);
	delay(2000);
	pauseBase(false);

	//8th pole
	baseMove(-10);
	waitBase(1000);
	delay(500);
	baseTurn(-90);
	waitBase(1000);
	delay(500);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(2000);
	delay(500);
	pickUp(40);
	delay(500);
	intakeMove(0);

	baseTurn(-105);
	waitBase(800);
	delay(500);

	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(2000);
	delay(500);
	cycle();
	pauseBase(true);
	delay(2000);
	pauseBase(false);



	// baseMove(45);
	// waitBase(1500);
	// delay(500);
	// baseTurn(58);
	// waitBase(1000);
	// delay(300);
	//
	// visionBaseMove(SIG_GREEN_FLAG);
	// visionWaitBase(1500);
	// pauseBase(true);
	// cycle();
	// delay(1000);
	// pauseBase(false);
	// delay(2000);
	//
	// baseTurn(125);
	// waitBase(1000);
	//
	// visionBaseMove(SIG_RED_BALL);
	// visionWaitBase(1200);
	// pickUp(40);
	// intakeMove(0);
	//
	// visionBaseMove(SIG_GREEN_FLAG);
	// visionWaitBase(1500);
	// pauseBase(true);
	// cycle();
	// delay(1000);
	// pauseBase(false);
	// delay(3000);
	//
	// baseTurn(195);
	// waitBase(1200);
	// delay(500);
	// baseMove(25);
	// waitBase(1000);
	// delay(300);
	//
	// visionBaseMove(SIG_RED_BALL);
	// visionWaitBase(1200);
	// pickUp(40);
	// intakeMove(0);
	//
	// visionBaseMove(SIG_GREEN_FLAG);
	// visionWaitBase(1500);
	// pauseBase(true);
	// cycle();
	// delay(1000);
	// pauseBase(false);
	// delay(3000);


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

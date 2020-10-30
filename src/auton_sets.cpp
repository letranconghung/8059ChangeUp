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
int stdDelay = 200;
int pickUpDelay = 1500;
int poleDelay = 1000;
int stdRedWait = 2000;
int stdBlueWait = 2000;
void skills(){
	Controller master (E_CONTROLLER_MASTER);
	double start = millis();
	resetCoords(0, 0, -58);
	for(int i = 0; i < 80; i++) {
		cycle();
		delay(10);
	}
	waitCycle();
	setDiscard(true);
	delay(800);
	setDiscard(false);
	delay(stdDelay);
	baseMove(-4);
	waitBase(500);
	delay(stdDelay);
	baseTurn(115);
	waitBase(1000);
	delay(stdDelay);
	baseMove(4);
	waitBase(500);
	intakeMove(127);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);

	baseTurn(103,0.5,0.15);
	waitBase(1000);
	delay(stdDelay);
	baseMove(44);
	waitBase(3000);
	delay(stdDelay);

	//2nd pole
	baseTurn(0);
	waitBase(2000);
	delay(stdDelay);
	visionBaseMove(SIG_BLUE_BALL);
	visionWaitBase(stdBlueWait);
	delay(stdDelay);
	baseMove(9);
	waitBase(1000);
	delay(stdDelay);
	setDiscard(true);
	pauseBase(true);
	delay(poleDelay);
	setDiscard(false);
	pauseBase(false);

	//3rd center pole
	baseMove(-10);
	waitBase(1000);
	delay(stdDelay);
	baseTurn(180);
	waitBase(3000);
	delay(stdDelay);
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);

	visionBaseMove(SIG_BLUE_BALL);
	visionWaitBase(stdBlueWait);
	delay(stdDelay);

	timerBase(100, 50, 300);
	timerBase(0, 100, 300);
	setDiscard(true);
	pauseBase(true);
	delay(poleDelay);
	setDiscard(false);
	pauseBase(false);
	delay(1000);
	intakeMove(0);
	//4th pole
	delay(stdDelay);
	baseTurn(55);
	waitBase(2000);
	delay(stdDelay);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);
	visionBaseMove(SIG_BLUE_BALL);
	visionWaitBase(stdBlueWait);
	delay(stdDelay);
	baseMove(14);
	waitBase(1000);
	delay(stdDelay);
	setDiscard(true);
	pauseBase(true);
	delay(poleDelay);
	setDiscard(false);
	pauseBase(false);

	baseMove(-10);
	waitBase(1000);
	delay(stdDelay);

	//5th pole
	baseTurn(175);
	waitBase(2000);
	delay(stdDelay);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);

	baseMove(19);
	waitBase(1500);
	delay(stdDelay);

	baseTurn(85);
	waitBase(1000);
	delay(stdDelay);

	// visionBaseMove(SIG_BLUE_BALL);
	// visionWaitBase(stdBlueWait);
	delay(stdDelay);
	baseMove(6);
	waitBase(1000);
	delay(stdDelay);
	setDiscard(true);
	pauseBase(true);
	delay(poleDelay);
	setDiscard(false);
	pauseBase(false);

	//6th pole
	baseMove(-15);
	waitBase(1000);
	delay(stdDelay);

	baseTurn(200);
	waitBase(2000);
	delay(stdDelay);

	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);

	baseTurn(130);
	waitBase(1000);
	delay(stdDelay);
	visionBaseMove(SIG_BLUE_BALL);
	visionWaitBase(stdBlueWait);
	delay(stdDelay);
	baseMove(14);
	waitBase(1000);
	delay(stdDelay);
	setDiscard(true);
	pauseBase(true);
	delay(poleDelay);
	setDiscard(false);
	pauseBase(false);
	double time = millis() - start;
	while(true) master.print(1, 0, "%f", time);
	delay(2000);
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

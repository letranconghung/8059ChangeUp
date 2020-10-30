/** Autonomous routines */
#include "main.h"
/** situational delay constants for flexible global adjustments */
int stdDelay = 200;
int pickUpDelay = 1500;
int poleDelay = 1000;
int stdRedWait = 2000;
int stdBlueWait = 2000;
/** programming skills run */
void skills(){
	Controller master (E_CONTROLLER_MASTER);
	double start = millis();
	/** set initial position */
	resetCoords(0, 0, -58);
	/** flip out */
	for(int i = 0; i < 80; i++) {
		cycle();
		delay(10);
	}
	waitCycle();
	setDiscard(true);
	delay(800);
	setDiscard(false);
	delay(stdDelay);
	/** pick up red ball */
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
	/** score 2nd goal */
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
	/** turn to red ball */
	baseMove(-10);
	waitBase(1000);
	delay(stdDelay);
	baseTurn(180);
	waitBase(3000);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	/** score 3rd (center) goal */
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
	delay(stdDelay);
	/** turn to red ball */
	baseTurn(55);
	waitBase(2000);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);
	/** score 4th goal */
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
	/** turn to red ball */
	baseTurn(175);
	waitBase(2000);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);
	baseMove(19);
	waitBase(1500);
	delay(stdDelay);
	/** score 5th goal */
	baseTurn(85);
	waitBase(1000);
	delay(stdDelay);
	delay(stdDelay);
	baseMove(6);
	waitBase(1000);
	delay(stdDelay);
	setDiscard(true);
	pauseBase(true);
	delay(poleDelay);
	setDiscard(false);
	pauseBase(false);
	baseMove(-15);
	waitBase(1000);
	delay(stdDelay);
	/** turn to red ball */
	baseTurn(200);
	waitBase(2000);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(stdRedWait);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);
	baseTurn(130);
	waitBase(1000);
	delay(stdDelay);
	/** score 6th goal */
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

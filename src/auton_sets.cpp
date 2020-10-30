/** Autonomous routines */
#include "main.h"
/** programming skills run */
void skills(){
	/** situational delay constants for flexible global adjustments */
	int stdDelay = 350;
	int pickUpDelay = 1000;
	int poleDelay = 1000;
	int shootDelay = 800;
	/** flip out */
	cycle();
	delay(700);
	shoot(127,1000);
	/** set initial position */
	resetCoords(0, 0, -60);
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
	intakeMove(0);
	delay(pickUpDelay);
	/** score 2nd goal */
	baseTurn(100);
	waitBase(1000);
	delay(stdDelay);
	baseMove(44);
	waitBase(2000);
	delay(stdDelay);
	baseTurn(0);
	waitBase(1200);
	delay(stdDelay);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1000);
	shoot(127,shootDelay);
	delay(poleDelay);
	/** turns to red ball */
	baseMove(-8);
	waitBase(1000);
	delay(stdDelay);
	baseTurn(180,0.3,0.15);
	waitBase(800);
	delay(stdDelay);
	/** picks up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(1000);
	delay(stdDelay);
	pickUp(40);
	intakeMove(0);
	delay(pickUpDelay);
	/** score 3rd goal */
	baseTurn(166);
	waitBase(1000);
	delay(stdDelay);
	baseMove(33);
	waitBase(1500);
	timerBase(100,0,500);
	waitBase(1000);
	delay(300);
	shoot(127,shootDelay);
	delay(800);
	/** turn to red ball */
	baseMove(-15);
	waitBase(1000);
	delay(stdDelay);
	baseTurn(89.2,-5.8,0.4,0.1,false);
	waitBase(1000);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(1750);
	delay(stdDelay);
	pickUp(40);
	delay(pickUpDelay);
	intakeMove(0);
	/** score 4th goal */
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(3000);
	shoot(127,shootDelay);
	delay(poleDelay);
	/** turn to red ball */
	baseMove(-10);
	waitBase(1000);
	delay(stdDelay);
	baseTurn(98.4,-51,0.4,0.1,false);
	waitBase(900);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(1700);
	delay(stdDelay);
	pickUp(40);
	intakeMove(0);
	delay(pickUpDelay);
	/** score 5th goal */
	baseMove(18);
	waitBase(1500);
	delay(stdDelay);
	baseTurn(90);
	waitBase(1000);
	delay(stdDelay);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1000);
	delay(stdDelay);
	shoot(127,shootDelay);
	delay(poleDelay);
	/** turn to red ball */
	baseMove(-13);
	waitBase(1000);
	delay(stdDelay);
	baseTurn(180);
	waitBase(1000);
	delay(stdDelay);
	/** pick up red ball */
	visionBaseMove(SIG_RED_BALL);
	visionWaitBase(2000);
	delay(stdDelay);
	pickUp(40);
	intakeMove(0);
	delay(pickUpDelay);
	/** score 6th goal */
	baseTurn(140);
	waitBase(700);
	delay(stdDelay);
	visionBaseMove(SIG_GREEN_FLAG);
	visionWaitBase(1500);
	delay(stdDelay);
	baseMove(3);
	waitBase(500);
	shoot(127,shootDelay);
	delay(poleDelay);
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

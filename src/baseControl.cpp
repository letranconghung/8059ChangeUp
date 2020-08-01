#include "main.h"
Motor FL (FLport);
Motor BL (BLport);
Motor FR (FRport);
Motor BR (BRport);

double targetEncdL=0,targetEncdR=0;
double kP,kD;
double targetPowerL=0,targetPowerR=0;
double cutoff;
/**
 * forceStraight:
 * when set to true, baseControl would insist the left and right motors/encoders to move/rotate the same distance (setting the same targetEncdL and targetEncdR)
 *
 * However, this does not mean that the robot's path would not be a straight line.
 * The path would have very minute deviations from a line (due to uncertainties etc.) but to the human eyes, it would still be a line.
 */
bool straightForced = false;
void forceStraight(bool straight = true){
  straightForced = straight;
}
/**
 * generic moving straight function for the robot
 * @param dis distance to be moved
 * @param kp  proportional constant
 * @param kd  derivative constant
 */
void baseMove(double dis, double kp = DEFAULT_KP, double kd = DEFAULT_KD){
  targetEncdL += dis/inPerDeg;
  targetEncdR += dis/inPerDeg;

  kP = kp;
  kD = kd;
}

//must be facing the direction (roughly) before moving there
void baseMove(double x, double y, double kp = DEFAULT_KP, double kd = DEFAULT_KD){
	double errorX = x-position.x;
  double errorY = y-position.y;
	double distance = sqrt(errorX * errorX + errorY * errorY);
	double targAngle = atan2(errorX,errorY);
	//printf("Angle: %f %f", targAngle, position.angle);
	//printf("Distance: %f",distance);

	int reverse = 1;
  if(fabs(targAngle-position.angle) >= PI/2) reverse = -1;

  targetEncdL += distance/inPerDeg*reverse;
  targetEncdR += distance/inPerDeg*reverse;

  kP = kp;
  kD = kd;
}

void baseTurn(double angle, double kp = DEFAULT_TURN_KP, double kd = DEFAULT_TURN_KD){
	double error = angle*toRad - position.angle;
	double diff = error*baseWidth/inPerDeg/2.0;
	targetEncdL += diff;
	targetEncdR += -diff;

	kP = kp;
	kD = kd;
}

void baseTurnRelative(double angle, double kp = DEFAULT_TURN_KP, double kd = DEFAULT_TURN_KD){
  double diff = angle*toRad*baseWidth/inPerDeg/2.0;
  targetEncdL += diff;
  targetEncdR += -diff;

  kP = kp;
  kD = kd;
}

void baseTurn(double x, double y, bool reverse = false, double kp = DEFAULT_TURN_KP, double kd = DEFAULT_TURN_KD){
	double targAngle = atan2((x-position.x),(y-position.y));
	if(reverse) targAngle += PI;
	if(targAngle-position.angle > PI) targAngle -= twoPI;
	if(targAngle-position.angle < -PI) targAngle += twoPI;
  double diff = (targAngle - position.angle)*baseWidth/inPerDeg/2;
	//printf("%f, %f\n", targAngle, diff);
  targetEncdL += diff;
  targetEncdR += -diff;
  kP = kp;
  kD = kd;
}


void baseControl(void * ignore){
  double prevErrorEncdL = 0, prevErrorEncdR = 0;
  while(competition::is_autonomous()){
    double errorEncdL = targetEncdL - BL.get_position();
    double errorEncdR = targetEncdR - BR.get_position();

		if(!straightForced){
	    double deltaErrorEncdL = errorEncdL - prevErrorEncdL;
	    double deltaErrorEncdR = errorEncdR - prevErrorEncdR;

	    prevErrorEncdL = errorEncdL;
	    prevErrorEncdR = errorEncdR;

	    targetPowerL = kP*errorEncdL+kD*deltaErrorEncdL;
	    targetPowerR = kP*errorEncdR+kD*deltaErrorEncdR;
		}
		else{
			double combErrorEncdWithkP = (errorEncdL+errorEncdR)/2*kP;

			prevErrorEncdL = errorEncdL;
	    prevErrorEncdR = errorEncdR;

			targetPowerL = errorEncdL>0?combErrorEncdWithkP:-combErrorEncdWithkP;
	    targetPowerR = errorEncdR>0?combErrorEncdWithkP:-combErrorEncdWithkP;
		}

		if(DEBUG_MODE == 2) printf("Error: %f %f\n",errorEncdL,errorEncdR);
		Task::delay(20);
  }
}
//
bool basePowCapped = false;
double absPowerCap;

void capBasePow(double pow){
	basePowCapped = true;
	absPowerCap = pow;
}
void rmBaseCap(){
	basePowCapped = false;
}
//-------------END OF CUSTOM CAP------------//
bool basePaused = false;
void pauseBase(bool pause = true){
  basePaused = pause;
}
//--------------------------------pause baseMotorControl---------//
void baseMotorControl(void * ignore){
  double powerL=0,powerR=0;
  while(competition::is_autonomous()){
    // limit power increments to below RAMPING_POW
    double deltaPowerL = targetPowerL - powerL;
    if(fabs(deltaPowerL) > RAMPING_POW) powerL += deltaPowerL>0?RAMPING_POW:-RAMPING_POW;
    else powerL = targetPowerL;

    double deltaPowerR = targetPowerR - powerR;
    if(fabs(deltaPowerR) > RAMPING_POW) powerR += deltaPowerR>0?RAMPING_POW:-RAMPING_POW;
    else powerR = targetPowerR;
    //handle custom speed caps
		if(basePowCapped){
      powerL = abscap(powerL, absPowerCap);
      powerR = abscap(powerR, absPowerCap);
		}
		else{
			powerL = abscap(powerL, MAX_POW);
      powerR = abscap(powerR, MAX_POW);
		}
    //handle custom basePaused
		if(!basePaused){
			FL.move(powerL);
			BL.move(powerL);
			FR.move(powerR);
			BR.move(powerR);
		}

		if(DEBUG_MODE == 3) printf("%4.0f \t %4.0f\n",powerL,powerR);

    Task::delay(20);
  }
}

void timerBase(double powL, double powR, double time){
  double start = millis();
  pauseBase();
  FL.move(powL);
  BL.move(powL);
  FR.move(powR);
  BR.move(powR);
  while(millis() - start < time) delay(20);
	FL.move(0);
	BL.move(0);
	FR.move(0);
	BR.move(0);
	pauseBase(false);
}

void waitBase(double cutoff){
	double start = millis();
	while(fabs(targetEncdL - BL.get_position()) > DISTANCE_LEEWAY && fabs(targetEncdR - BR.get_position()) > DISTANCE_LEEWAY && (millis()-start) < cutoff) delay(20);
	FL.move(0);
	BL.move(0);
	FR.move(0);
	BR.move(0);
}

void resetCoords(double x, double y, double angleDeg){
  position.setCoords(x, y, angleDeg);
  FL.tare_position();
	FR.tare_position();
	BL.tare_position();
	BR.tare_position();

  targetEncdL = 0;
  targetEncdR = 0;
}

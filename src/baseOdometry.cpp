/**
 * Odometry functions and task that constantly updates the robot's position
 * - Retrieve & package encoder values function
 * - Odometry task
 */
#include "main.h"
/** to test odometry in opcontrol() when not in competition */
#define COMPETITION_MODE false
/** declare encoders */
ADIEncoder encoderL(encdL_port, encdL_port + 1);
ADIEncoder encoderR(encdR_port, encdR_port + 1);
/** encdL, encdR = value of respective encoders */
double encdL = 0, encdR = 0;
/** position: object of class Coordinates - position of the robot */
Coordinates position(0, 0, 0);
/**
 * Retrive encoder values.
 * @param processed
 * whether the returned values should be in inches (default) or encoder degrees
 *
 * @return
 * encoder values packaged in a pair
 */
std::pair<double, double> getEncdVals(bool rawData = false){
  if(!rawData) return std::make_pair((double) encoderL.get_value()*inPerDeg, (double) encoderR.get_value()*inPerDeg);
  else return std::make_pair((double)encoderL.get_value(), (double)encoderR.get_value());
}
/** Update the robot's position using side encoders values. */
void baseOdometry(void * ignore){
  /** previous encoder values; to be used in calculations */
  double prevEncdL = 0;
  double prevEncdR = 0;
  double prevAngle = 0;
  /** indexer */
  int count = 0;
  while(!COMPETITION_MODE || competition::is_autonomous()){
    /** retrieve & update encoder values */
    encdL = getEncdVals().first;
    encdR = getEncdVals().second;
    /** refer to Odometry Documentation.docx for mathematical proof */
    // position.angle = boundRad((encdL - encdR)/baseWidth);
    position.angle = (encdL - encdR)/baseWidth;
    /** difference of current encoder values from previous encoder values */
    double encdChangeL = (encdL-prevEncdL);
    double encdChangeR = (encdR-prevEncdR);
    /** refer to Odometry Documentation.docx for mathematical proof */
    double sumEncdChange = encdChangeL + encdChangeR;
    double deltaAngle = (encdChangeL - encdChangeR)/baseWidth;
    /** update x- and y-coordinates */
    if(deltaAngle == 0) {
      /** handle 0 as the formula involves division by deltaAngle */
      /** refer to Odometry Documentation.docx for mathematical proof */
			position.x += sumEncdChange/2*sin(position.angle);
			position.y += sumEncdChange/2*cos(position.angle);
		}
		else {
      /** refer to Odometry Documentation.docx for mathematical proof */
			double halfDeltaAngle = deltaAngle/2;
			position.x += (sumEncdChange/deltaAngle)*sin(halfDeltaAngle)*sin(prevAngle+halfDeltaAngle);
			position.y += (sumEncdChange/deltaAngle)*sin(halfDeltaAngle)*cos(prevAngle+halfDeltaAngle);
		}
    /** Update prev variables */
		prevEncdL = encdL;
		prevEncdR = encdR;
		prevAngle = position.angle;
    /** print to assist debugging */
    if(!COMPETITION_MODE) position.printCoordsMaster();
    if((DEBUG_MODE == 1) && (count++ % 10 == 0)) position.printCoordsTerminal();
    if(DEBUG_MODE == 4) printf("%4.0f \t %4.0f\n",getEncdVals(true).first,getEncdVals(true).second);
    /** refresh rate of Task */
    Task::delay(5);
  }
}

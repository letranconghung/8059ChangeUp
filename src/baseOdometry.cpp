/**
 * odometry functions and task that constantly updates the robot's position
 */
#include "main.h"
// set to false to test odometry during driver opcontrol()
#define COMPETITION_MODE false
// declaration of encoders
ADIEncoder encoderL(encdL_port, encdL_port + 1);
ADIEncoder encoderR(encdR_port, encdR_port + 1);
/**
 * encdL, encdR = value of respective encoders
 * position: object of class Coordinates - position of the robot
 * target: object of class Coordinates - target of the current/next movement
 */
double encdL = 0, encdR = 0;
Coordinates position(0, 0, 0);
/**
 * get the encoders' values
 * @param processed whether the returned values should be in inches (default) or encoder ticks
 * @return          encoder values packaged in a pair
 */
std::pair<double, double> getEncdVals(bool processed = true){
  if(processed) return std::make_pair((double) encoderL.get_value()*inPerDeg, (double) encoderR.get_value()*inPerDeg);
  else return std::make_pair((double)encoderL.get_value(), (double)encoderR.get_value());
}
/**
 * Main odometry task that updates the robot's position every 20ms
 */
void baseOdometry(void * ignore){
  /**
   * Previous encoder values to be used in calculations
   * initialized at 0
   */
  double prevEncdL = 0;
  double prevEncdR = 0;
  double prevAngle = 0;
  //indexer
  int count = 0;
  while(!COMPETITION_MODE || competition::is_autonomous()){
    // refer to Odometry Documentation.docx for mathematical proof
    position.angle = boundRad((encdL - encdR)/baseWidth);
    // retrive encoders' values
    encdL = getEncdVals().first;
    encdR = getEncdVals().second;
    // difference of current encoder values from previous encoder values
    double encdChangeL = (encdL-prevEncdL);
    double encdChangeR = (encdR-prevEncdR);
    // sum of change in encoder values
    double sumEncdChange = encdChangeL + encdChangeR;
    // calculate the change from previous angle to current angle
    double deltaAngle = (encdChangeL - encdChangeR)/baseWidth;
    /**
     * calculate change in x- and y-coordinates based on deltaAngle
     * @param deltaAngle change from previous angle to current angle
     */
    if(deltaAngle == 0) {
      // Cannot divide by 0
      // refer to Odometry Documentation.docx for mathematical proof
			position.x += sumEncdChange/2*sin(position.angle);
			position.y += sumEncdChange/2*cos(position.angle);
		}
		else {
      // refer to Odometry Documentation.docx for mathematical proof
			double halfDeltaAngle = deltaAngle/2;
			position.x += (sumEncdChange/deltaAngle)*sin(halfDeltaAngle)*sin(prevAngle+halfDeltaAngle);
			position.y += (sumEncdChange/deltaAngle)*sin(halfDeltaAngle)*cos(prevAngle+halfDeltaAngle);
		}
    // Update prev variables
		prevEncdL = encdL;
		prevEncdR = encdR;
		prevAngle = position.angle;
    // print the coordinates to master controller or the terminal for debugging
    if(!COMPETITION_MODE) position.printCoordsMaster();
    if((DEBUG_MODE == 1) && (count++ % 10 == 0)) position.printCoordsTerminal();
    // refresh rate
    Task::delay(5);
  }
}

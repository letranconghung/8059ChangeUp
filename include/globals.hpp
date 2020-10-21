/** Declare the robot's set up variables: Motor and sensor ports */
#ifndef _GLOBALS_HPP_
#define _GLOBALS_HPP_

// base ports
#define FLPort 11
#define BLPort 12
#define FRPort 19
#define BRPort 18

// mech ports
#define rRollerPort 16
#define lRollerPort 15
#define indexerPort 6
#define shooterPort 5

//sensor ports
#define encdL_port 1
#define encdR_port 3
#define limitPort 5
#define colorPort 6
#define visBallport 1
#define visFlagport 2

extern bool useVision;

#endif

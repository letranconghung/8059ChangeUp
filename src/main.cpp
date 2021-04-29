#include "main.h"
extern bool redBall, redAlliance;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	/** declaration and initialization of motors, encoders and controller */
	Motor FL (FLPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor BL (BLPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor FR (FRPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor BR (BRPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor lRoller (lRollerPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	Motor rRoller (rRollerPort, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
	Motor shooter (shooterPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	Motor indexer (indexerPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
	Controller master(E_CONTROLLER_MASTER);
	Imu imu(imuPort);
	ADIDigitalIn intakeColor(intakeColorPort);
	ADIDigitalIn shootColor(shootColorPort);
	// ADIEncoder encoderL (encdL_port,encdL_port+1,false);
	// ADIEncoder encoderR (encdR_port,encdR_port+1,true);
	/** tare all motors and reset encoder counts */

	Vision vis(visPort);
	FL.tare_position();
	FR.tare_position();
	BL.tare_position();
	BR.tare_position();
	imu.reset();
	resetCoords(0, 0);
	// encoderL.reset();
	// encoderR.reset();
	/** declaration and initialization of asynchronous Tasks */
	//Task mechControlTask(mechControl, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
	Task ControlTask(Control);
	Task DebugTask(Debug);
	Task OdometryTask(Odometry);
	Task SensorsTask(Sensors);
	Task MechControlTask(MechControl);
	// Task visSortTask(VisSort);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	Imu imu (imuPort);
	// while(imu.is_calibrating()) delay(5);
	/** numerical choice of which autonomous set to run */
	int autonNum = 4;
	switch (autonNum){
		case 0: skills(); break;
		case 1: BHR(); break;
		case 2: BMR(); break;
		case 3: RHR(); break;
		case 4: RMR(); break;
		case 5: test(); break;
	}
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	/** braking */
	double BRAKE_POW = 0;
	Motor FL (FLPort);
	Motor BL (BLPort);
	Motor FR (FRPort);
	Motor BR (BRPort);
	Motor lRoller (lRollerPort);
	Motor rRoller (rRollerPort);
	Motor indexer (indexerPort);
	Motor shooter (shooterPort);
	Controller master(E_CONTROLLER_MASTER);
	Vision vis (visPort);
	bool tankDrive = true;
	pauseBase = true;
	bool slowMode = false;
	baseBraking = false;
	while (true) {
		double indexerMove = 0, shooterMove = 0;
		if(master.get_digital_new_press(DIGITAL_Y)) tankDrive = !tankDrive;
		if(master.get_digital_new_press(DIGITAL_DOWN)) slowMode = !slowMode;
		double baseMultiplier = (slowMode? 0.5: 1);
		if(tankDrive){
	     int l = master.get_analog(ANALOG_LEFT_Y);
	     int r = master.get_analog(ANALOG_RIGHT_Y);
			powerL = l;
			powerR = r;
	  }else{
	     int y = master.get_analog(ANALOG_LEFT_Y);
	     int x = master.get_analog(ANALOG_RIGHT_X);
			 powerL = y+x;
			 powerR = y-x;
	  }
		if(powerL != 0) signPowerL = ((powerL > 0)? 1 : -1);
		if(powerR != 0) signPowerR = ((powerR > 0)? 1 : -1);
		double shootMultiplier = (slowMode? 0.5: 1);
		double rollerMultiplier = (slowMode? 0.7: 1);
		if(master.get_digital_new_press(DIGITAL_A)) autoIndex = !autoIndex;
		if(master.get_digital_new_press(DIGITAL_B)) redAlliance = !redAlliance;
		if(master.get_digital_new_press(DIGITAL_X)) baseBraking = !baseBraking;
		if(autoIndex){
			if(intakeColorValue< intakeColorThreshold && shootColorValue < shootColorThreshold) indexerMove = 0;
			else indexerMove = 1;
		}
		if(master.get_digital(DIGITAL_R2)){
			indexerMove = -1;
		}else if(master.get_digital(DIGITAL_R1)){
			indexerMove = 1;
		}
		if(master.get_digital(DIGITAL_R1)){
			if(master.get_digital(DIGITAL_L2)){
				shooterMove = ((redBall == redAlliance)? 1:-1);
				if(shootColorValue < shootColorThreshold) indexerMove = (redBall == redAlliance)? 1: 0.5;
			}else shooterMove = 1;
		}
		if(master.get_digital(DIGITAL_R2)) shooterMove = -1;
		powerL *= baseMultiplier;
		powerR *= baseMultiplier;
		powerRollers = (master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_R2))*127 *rollerMultiplier;
		powerIndexer = 127*indexerMove;
		powerShooter = 127*shooterMove*shootMultiplier;
		pros::delay(5);
	}
}

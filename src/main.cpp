#include "main.h"
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
	Rotation lRot(lRotPort);
	Rotation rRot(rRotPort);
	Vision vis(visPort);
	Optical opt(optPort);
	/** taring */
	lRot.reset_position();
	rRot.reset_position();
	lRot.reverse();
	imu.reset();

	/** declaration and initialization of asynchronous Tasks */
	Task ControlTask(Control);
	Task DebugTask(Debug);
	Task OdometryTask(Odometry);
	Task SensorsTask(Sensors);
	Task MechControlTask(MechControl);
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
	Optical opt(optPort);
	opt.set_led_pwm(0);
	pauseBase = false;
	baseBraking = false;
	driverMode = false;
	autoIndex = false;
	movementEnded = false;
	resetMode();
	// while(imu.is_calibrating()) delay(5);
	/** numerical choice of which autonomous set to run */
	int autonNum = 6;
	switch (autonNum){
		case 1: BHR10(); break;
		case 2: RHR10(); break;
		case 3: test(); break;
		case 4: cage(); break;
		case 5: RHR(); break;
		case 6: RHR8(); break;
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
	Optical opt(optPort);
	opt.set_led_pwm(100);
	bool tankDrive = true;
	pauseBase = true;
	baseBraking = false;
	driverMode = true;
	autoIndex = true;
	movementEnded = false;
	resetMode();
	while (true) {
		double indexerMove = 0, shooterMove = 0, rollersMove = 0;
		if(master.get_digital_new_press(DIGITAL_Y)) tankDrive = !tankDrive;
		slowMode = (master.get_digital(DIGITAL_L2)? true: false);
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
		powerL *= baseMultiplier;
		powerR *= baseMultiplier;
		if(master.get_digital_new_press(DIGITAL_A)) autoIndex = !autoIndex;
		if(master.get_digital_new_press(DIGITAL_B)) alliance = 3 - alliance;
		if(master.get_digital_new_press(DIGITAL_X)) baseBraking = !baseBraking;
		pros::delay(5);
	}
}

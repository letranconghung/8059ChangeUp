#include "main.h"

#define BRAKE_POW 3 //5
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	Motor FL (FLport, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor BL (BLport, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor FR (FRport, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor BR (BRport, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);

	ADIEncoder encoderL(encdL_port,encdL_port+1,true);
	ADIEncoder encoderR(encdR_port,encdR_port+1,false);

	// taring all motors and reset encoder counts
	FL.tare_position();
	FR.tare_position();
	BL.tare_position();
	BR.tare_position();
	encoderL.reset();
	encoderR.reset();

	Controller master(E_CONTROLLER_MASTER);
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
	Motor FL (FLport);
	Motor BL (BLport);
	Motor FR (FRport);
	Motor BR (BRport);
	Controller master(E_CONTROLLER_MASTER);
	master.clear();

	bool tankDrive = false;
	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
    int right = master.get_analog(ANALOG_RIGHT_Y);
    FL.move(left);
    BL.move(left);
    FR.move(right);
    BR.move(right);

		if(master.get_digital_new_press(DIGITAL_Y)) tankDrive = !tankDrive;
		if(tankDrive){
      int l = master.get_analog(ANALOG_LEFT_Y);
      int r = master.get_analog(ANALOG_RIGHT_Y);
      FL.move(l-BRAKE_POW);
      BL.move(l+BRAKE_POW);
      FR.move(r-BRAKE_POW);
      BR.move(r+BRAKE_POW);
    } else{
      int y = master.get_analog(ANALOG_LEFT_Y);
      int x = master.get_analog(ANALOG_RIGHT_X);
      FL.move(y+x-BRAKE_POW);
      BL.move(y+x+BRAKE_POW);
      FR.move(y-x-BRAKE_POW);
      BR.move(y-x+BRAKE_POW);
    }
		pros::delay(5);
	}
}

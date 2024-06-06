#include "main.h"
#include "config.hpp"
#include "pros/llemu.hpp"

enum class AutonSelector { NONE, LEFT, RIGHT };
AutonSelector auton_runner = AutonSelector::NONE;

void btn_l1_actions();
void btn_l2_actions();
void btn_r1_actions();
void btn_r2_actions();
void btn_up_actions();
void btn_down_actions();
void btn_left_actions();
void btn_right_actions();
void btn_x_actions();
void btn_a_actions();
void btn_b_actions();
void btn_y_actions();

// Drivetrain
pros::MotorGroup drive_group_l({1, 2, 3}, pros::MotorGears::rpm_600,
                               pros::MotorUnits::counts);
pros::MotorGroup drive_group_r({4, 5, 6}, pros::MotorGears::rpm_600,
                               pros::MotorUnits::counts);

// Movement
pros::Imu inertial(11);

// Controllers
pros::Controller con_player(pros::E_CONTROLLER_MASTER);

void left_callback() {
  auton_runner = AutonSelector::LEFT;
  pros::lcd::print(6, "Left Side Autonomous");
}

void center_callback() {
  auton_runner = AutonSelector::RIGHT;
  pros::lcd::print(6, "Right Side Autonomous");
}

void right_callback() {
  auton_runner = AutonSelector::NONE;
  pros::lcd::print(6, "No Autonomous");
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Calibrating Inertial...");
  inertial.reset();
  while (inertial.is_calibrating()) {
    pros::delay(20);
  }
  // TODO: Add autonomous selector callback here
  pros::lcd::set_text(1, "Good to go.");
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
  switch (auton_runner) {
    case AutonSelector::LEFT: // left Side Program Here
      break;
    case AutonSelector::RIGHT: // Right Side Program Here
      break;
    case AutonSelector::NONE:
      break;
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
  while (true) {

      
      // Button Binding
      // Use get_digital if pressing, get_digital_new_press if toggling
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
        btn_l1_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
        btn_l2_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
        btn_r1_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
        btn_r2_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
        btn_up_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
        btn_down_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))
        btn_left_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
        btn_right_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_X))
        btn_x_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_A))
        btn_a_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_B))
        btn_b_actions();
      if (con_player.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
        btn_y_actions();
    pros::delay(20);           // Run for 20 ms then update
  }
}
#include "main.h" // IWYU pragma: export
#include "pros/motor_group.hpp"

#ifndef _CONFIG_H_
#define _CONFIG_H_

// Drivetrain
extern pros::Motor drive_motor_l1;
extern pros::Motor drive_motor_l2;
extern pros::Motor drive_motor_l3;
extern pros::Motor drive_motor_r1;
extern pros::Motor drive_motor_r2;
extern pros::Motor drive_motor_r3;
extern pros::MotorGroup drive_group_l;
extern pros::MotorGroup drive_group_r;

// Movement
extern pros::Imu inertial;

extern pros::Controller con_player;

#endif
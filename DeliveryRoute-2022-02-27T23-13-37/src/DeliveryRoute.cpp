#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
//brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor ArmMotor = motor(PORT8, ratio18_1, false);

motor ClawMotor = motor(PORT3, ratio18_1, false);

motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);



#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {brian}                                                   */
/*    Created:      {2-25}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

void drivepath() {
  Drivetrain.driveFor(forward,500,mm); //drives backwards
  wait(1,seconds);
  if(-48.0>=ArmMotor.position(degrees)>=-40.0) { //detects if arm is near floor (holding block)
    Drivetrain.turnFor(left,210,degrees); //spins around
    wait(1,seconds);
    ArmMotor.setStopping(hold);
    ArmMotor.setMaxTorque(60, percent);
    ArmMotor.setTimeout(2, seconds);
    ArmMotor.spinToPosition(-240,degrees); //raises arm
    wait(1,seconds);
  } else { //if arm is above ground (without block)
    ArmMotor.setStopping(hold);
    ArmMotor.setMaxTorque(60, percent);
    ArmMotor.setTimeout(2, seconds);
    ArmMotor.spinToPosition(-45,degrees); //lowers arm
    wait(1,seconds);
    Drivetrain.turnFor(right,210,degrees); //spins around
    wait(1,seconds);
  }
  Drivetrain.driveFor(reverse,500,mm); //drives forwards
  wait(1,seconds);
}

void clawoperator() {
  ClawMotor.setStopping(hold); 
  ClawMotor.setMaxTorque(60, percent);
  ClawMotor.setTimeout(2, seconds);
  ClawMotor.spinToPosition(180, degrees); //opens the claw
  wait(2,seconds);
  ClawMotor.spinToPosition(0, degrees); //closes the claw
  wait(1,seconds);
}

int whenStarted() {
  ArmMotor.setStopping(hold);
  ArmMotor.setMaxTorque(60, percent);
  ArmMotor.setTimeout(2, seconds);
  ArmMotor.spinToPosition(-45, degrees); //set arm just above floor
  for(int i = 0; i < 4; i++) {
    clawoperator();
    drivepath();
  }
  return 0;
}

int main() {
  whenStarted();
  /*ArmMotor.setStopping(hold);
  ArmMotor.setMaxTorque(60, percent);
  ArmMotor.setTimeout(2, seconds);
  ArmMotor.spinToPosition(-45, degrees); //set arm just above floor
  wait(1,seconds);
  if(-48.0>=ArmMotor.position(degrees)>=-40.0) {
    Brain.Screen.print("success");
  } else {
    Brain.Screen.print("fail");
  }
  Brain.Screen.print("%f", ArmMotor.position(degrees));
  wait(5,seconds);
  ArmMotor.setStopping(hold);
  ArmMotor.setMaxTorque(60, percent);
  ArmMotor.setTimeout(2, seconds);
  ArmMotor.spinToPosition(-240, degrees); //raises arm
  wait(1,seconds);
  if(-245.0>=ArmMotor.position(degrees)>=-235.0) {
    Brain.Screen.print("success");
  } else {
    Brain.Screen.print("fail");
  }
  Brain.Screen.print("%f", ArmMotor.position(degrees));
  wait(5,seconds);*/
}

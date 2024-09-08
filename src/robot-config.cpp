#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT14, ratio6_1, true);
motor LM = motor(PORT16, ratio6_1, true);
motor LB = motor(PORT17, ratio6_1, true);
motor RF = motor(PORT13, ratio6_1, false);
motor RM = motor(PORT18, ratio6_1, false);
motor RB = motor(PORT19, ratio6_1, false);
motor Roller = motor(PORT20, ratio6_1, true);
motor Lift = motor(PORT10 , ratio6_1, true);
digital_out Climb = digital_out(Brain.ThreeWirePort.F);
digital_out Clamp = digital_out(Brain.ThreeWirePort.H);
digital_out RingClamp = digital_out(Brain.ThreeWirePort.G);
rotation LiftSensor(PORT9);
inertial Gyro = inertial(PORT10);
//Naming convention: 
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
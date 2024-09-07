#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RF = motor(PORT12, ratio6_1, false);
motor RM = motor(PORT15, ratio6_1, false);
motor RB = motor(PORT11, ratio6_1, false);
motor LF = motor(PORT18, ratio6_1, true);
motor LM = motor(PORT13, ratio6_1, true);
motor LB = motor(PORT14, ratio6_1, true);
motor In1 = motor(PORT16, ratio6_1, true);
motor In2 = motor(PORT17, ratio6_1, false);
motor Lift = motor(PORT19 , ratio6_1, false);
motor_group Roller = motor_group(In1,In2);
digital_out Climb = digital_out(Brain.ThreeWirePort.F);
digital_out Clamp = digital_out(Brain.ThreeWirePort.A);
digital_out RingClamp = digital_out(Brain.ThreeWirePort.G);
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
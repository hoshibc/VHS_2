#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor LF = motor(PORT3, ratio6_1, false);
motor LM = motor(PORT2, ratio6_1, true);
motor LB = motor(PORT1, ratio6_1, true);

motor RF = motor(PORT8, ratio6_1, true);
motor RM = motor(PORT9, ratio6_1, false);
motor RB = motor(PORT10, ratio6_1, false);


motor Roller = motor(PORT7, ratio6_1, true);
motor Lift = motor(PORT12, ratio6_1, false);

digital_out Clamp = digital_out(Brain.ThreeWirePort.H);
digital_out arm = digital_out(Brain.ThreeWirePort.F);
digital_out leftArm = digital_out(Brain.ThreeWirePort.G);
digital_out intakeLift = digital_out(Brain.ThreeWirePort.A);

rotation LiftSensor(PORT21);
inertial Gyro = inertial(PORT5);
optical OpSens = optical(PORT12);

//Naming convention: 
// Important variables
const double wheelDiam = 3.25;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // nothing to initialize
}
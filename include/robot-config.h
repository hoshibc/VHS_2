using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LF;
extern motor LM;
extern motor RF;
extern motor RM;
extern motor LB;
extern motor RB;
extern motor Lift;
extern motor Roller;
extern digital_out Clamp;
extern digital_out arm;
extern digital_out leftArm;
extern digital_out intakeLift; 
extern digital_out Climb;
extern digital_out RingClamp;
extern motor PU;
extern inertial Gyro;
extern optical OpSens;
extern digital_out LeftBackWing;
extern rotation LiftSensor;

extern const double wheelDiam;
extern const double wheelToMotorRatio;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
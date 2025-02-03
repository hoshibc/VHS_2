#include "vex.h"

#include "math.h"
#include "screen_gui.hpp"
#include "helper_functions.hpp"
#include "movement.hpp"

#include <iostream>

using namespace vex;

int turninverse=-1;//change this to -1 if turning is inversed

int JB;
int PB;
int PX;
int JX;

//Globals for arm movement, measured in degrees 
int loadPosition = 28;
int alliancePosition = 205;
int resetPosition = 0;
int holdPosition = 45;
int ladderPosition = 115;
int wallPosition = 160;

//General Sect;
//This section includes all general codes for drive and auto


/** Resets the robot's drive train and inertial sensor
 * 
 * @param dist 
 * @param HDG
 */
void Zeroing(bool dist, bool HDG) {
  if(dist) {
    LF.resetPosition();
    LM.resetPosition();
    LB.resetPosition();
    RF.resetPosition();
    RM.resetPosition();
    RB.resetPosition();
  }
  if(HDG) {
    Gyro.setHeading(0,degrees);
  }
}


ChassisDataSet ChassisUpdate() {
  ChassisDataSet CDS;
  CDS.Left=get_dist_travelled((LF.position(degrees)+LM.position(degrees)+LB.position(degrees))/3.0);
  CDS.Right=get_dist_travelled((RF.position(degrees)+RM.position(degrees)+RB.position(degrees))/3.0);
  CDS.Avg=(CDS.Left+CDS.Right)/2;
  CDS.Diff=CDS.Left-CDS.Right;
  CDS.HDG=Gyro.heading(degrees);

  return CDS;
}

/** Moves the drivetrain by applying power to the left and right side 
 * @param left left side of the drivetrain
 * @param right right side of the drivetrain 
 */
void Move(int left, int right) {
  LF.setMaxTorque(100,percent);
  LM.setMaxTorque(100,percent);
  LB.setMaxTorque(100,percent);
  RF.setMaxTorque(100,percent);
  RM.setMaxTorque(100,percent);
  RB.setMaxTorque(100,percent);

  LF.spin(forward,(double)left/100.0*11,volt);
  LM.spin(forward,(double)left/100.0*11,volt);
  LB.spin(forward,(double)left/100.0*11,volt);
  RF.spin(forward,(double)right/100.0*11,volt);
  RM.spin(forward,(double)right/100.0*11,volt);
  RB.spin(forward,(double)right/100.0*11,volt);
}


/** Stops all drive motors and set on brake
 * 
 */
void BStop() {
  LF.setStopping(brake);
  LM.setStopping(brake);
  LB.setStopping(brake);
  RF.setStopping(brake);
  RM.setStopping(brake);
  RB.setStopping(brake);

  LF.stop();
  LM.stop();
  LB.stop();
  RF.stop();
  RM.stop();
  RB.stop();
}

/** Stops all drive motors and set on coast
 * 
 */
void CStop() {
  LF.setStopping(coast);
  LM.setStopping(coast);
  LB.setStopping(coast);
  RF.setStopping(coast);
  RM.setStopping(coast);
  RB.setStopping(coast);

  LF.stop();
  LM.stop();
  LB.stop();
  RF.stop();
  RM.stop();
  RB.stop();
}

void allianceStakeAlign() {
  PIDDataSet TestPara={1.5, 0.20, 0.1}; 
  MoveEncoderPID(TestPara, -50, 8, 0.3, -3, true); // back up
  armMoveToAngle(alliancePosition, 100); //score alliace
}

/** Moves the wall stakes arm to a set angle 
 * @param deg the degrees currently measured by the rotation sensor 
 * @param speed the speed of the movement from 0-100 
 */
void armMoveToAngle(int deg, int speed) {

  if (abs(LiftSensor.position(degrees)) < deg) {
    while (abs(LiftSensor.position(degrees)) < deg) {
      RunLift(-speed);
    }
    Lift.setStopping(hold);
    Lift.stop();
    
  }
  else if (abs(LiftSensor.position(degrees)) > deg) {
    while (abs(LiftSensor.position(degrees)) > deg+6) {
      RunLift(speed);
    }
    Lift.setStopping(hold);
    Lift.stop();
  }
  else if (abs(LiftSensor.position(degrees)) < 13) {
    Lift.setStopping(coast);
    Lift.stop();
  }
}

void armMoveToAngle2(int deg, int speed) {
  // Proportional control constants
  const float kP = 0.8;  // Proportional gain (adjust as needed)
  const int minSpeed = 34;  // Minimum speed to prevent stalling

  int error = deg - LiftSensor.position(degrees);
  int currentSpeed = 0;

  while (abs(error) > 2) {  // Allow a small threshold to avoid oscillations
    // Calculate proportional speed
    currentSpeed = error * kP;

    // Ensure the speed is within the desired range
    if (abs(currentSpeed) < minSpeed) {
      currentSpeed = (currentSpeed < 0) ? -minSpeed : minSpeed;
    }
    if (abs(currentSpeed) > speed) {
      currentSpeed = (currentSpeed < 0) ? -speed : speed;
    }

    // Move the lift
    RunLift(-currentSpeed);

    // Update the error
    error = deg - LiftSensor.position(degrees);
  }

  // Stop the lift and hold position
  Lift.setStopping(hold);
  Lift.stop();
}

/** Runs the intake and all connected subsystems 
 * @param val the speed, from -100 to 100 | postive intakes and negative outtakes 
 */

void RunRoller(int val) {
  Roller.setMaxTorque(100,percent);
  Roller.spin(forward,(double)val/100.0*11,volt);
}


/** Runs the arm for the wall stake mech. 
 * @param val the speed, from -100 to 100 | positive moves down and negative moves up 
 */
void RunLift(int val) {
  Lift.setMaxTorque(100,percent);
  Lift.spin(forward,(double)val/100.0*12,volt);
}



int PrevE;//Error at t-1

/** Moves the robot forward or backward. Negative speed moves
 * 
 * @param KVals the PID constants
 * @param Speed the speed, from -100 to 100
 * @param dist distance travelled, in inches
 * @param AccT time to max speed (s)
 * @param ABSHDG absolute heading of the robot
 * @param brake Brake at end, or coast
 */
void MoveEncoderPID(PIDDataSet KVals, int Speed, double dist,double AccT, double ABSHDG, bool brake) {
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0;
  double LGV=0;//define local gyro variable.
  PrevE=0;
  double Correction=0;
  Brain.Screen.clearScreen();

  while(fabs(SensorVals.Avg) <= fabs(dist)) {
    //std::cout << SensorVals.Avg << " " << dist << std::endl;
    if(fabs(CSpeed)<fabs((double)Speed)) {
      CSpeed+=Speed/AccT*0.02;
    }

    SensorVals=ChassisUpdate();
    LGV=SensorVals.HDG-ABSHDG;
    if(LGV>180) LGV=LGV-360;
    PVal=KVals.kp*LGV;
    IVal=IVal+KVals.ki*LGV*0.02;
    DVal=KVals.kd*(LGV-PrevE);

    Correction=PVal+IVal+DVal/0.02;

    Move(CSpeed-Correction,CSpeed+Correction);
    PrevE=LGV;
    wait(20, msec);
  }
  if(brake) {
    BStop();
    wait(130,msec);
  }
  else CStop();
}

/** Moves the robot forward or backward. Negative speed moves
 * 
 * @param KVals the PID constants
 * @param DeltaAngle the absolute heading to turn to
 * @param TE time to calculate turn (not time to turn)
 * @param brake Brake at end, or coast
 */
void TurnMaxTimePID(PIDDataSet KVals,double DeltaAngle,double TE, bool brake) {
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0; 
  double LGV=0;
  PrevE=0;
  double Correction=0;
  Brain.Timer.reset();

  while(Brain.Timer.value() <= TE) {
    SensorVals=ChassisUpdate();
    LGV=SensorVals.HDG-DeltaAngle;
    if(LGV>180) LGV=LGV-360;
    PVal=KVals.kp*LGV;
    IVal=IVal+KVals.ki*LGV*0.02;
    DVal=KVals.kd*(LGV-PrevE);

    Correction=PVal+IVal+DVal/0.02;

    Move(CSpeed-Correction,CSpeed+Correction);
    PrevE=LGV;
    wait(20, msec);
  }
  if(brake) {
    BStop();
    wait(100,msec);}
  else CStop();
}



void MaxTimePIDTurnOneSide(PIDDataSet KVals,double DeltaAngle,double TE, bool brake){
  double CSpeed=0;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0;
  double LGV=0;
  PrevE=0;
  double Correction=0;
  double LV,RV;
  Brain.Timer.reset();

  while(Brain.Timer.value() <= TE) {
    SensorVals=ChassisUpdate();
    LGV=SensorVals.HDG-DeltaAngle;
    if(LGV>180) LGV=LGV-360;
    PVal=KVals.kp*LGV;
    IVal=IVal+KVals.ki*LGV*0.02;
    DVal=KVals.kd*(LGV-PrevE);

    Correction=PVal+IVal+DVal/0.02;
    LV=-CSpeed+Correction;
    RV=-CSpeed-Correction;
    if(LV>=0)LV=0;
    if(RV>=0)RV=0;
    Move(LV,RV);
    PrevE=LGV;
    wait(20, msec);
  }

  if(brake) {
    BStop();
    wait(200,msec);
  }
  else CStop();
}


void MoveTimePID(PIDDataSet KVals, int Speed, double TE,double AccT,double ABSHDG, bool brake) {
  double CSpeed=0;
  Speed *= -1;
  Zeroing(true,false);
  ChassisDataSet SensorVals;
  SensorVals=ChassisUpdate();
  double PVal=0;
  double IVal=0;
  double DVal=0;
  double LGV=0;
  PrevE=0;
  double Correction=0;
  Brain.Timer.reset();

  while(Brain.Timer.value() <= TE) {
    if(fabs(CSpeed)<fabs((double)Speed)) {
      CSpeed+=Speed/AccT*0.02;
    }

    SensorVals=ChassisUpdate();
    LGV=SensorVals.HDG-ABSHDG;
    if(LGV>180) LGV=LGV-360;
    PVal=KVals.kp*LGV;
    IVal=IVal+KVals.ki*LGV*0.02;
    DVal=KVals.kd*(LGV-PrevE);

    Correction=PVal+IVal+DVal/0.02;

    Move(-CSpeed-Correction,-CSpeed+Correction);
    PrevE=LGV;
    wait(20, msec);
  }

  if(brake) {
    BStop();
    wait(100,msec);
  }
  else CStop();
}

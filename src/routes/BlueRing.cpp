#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void BlueRing() {
    PIDDataSet TestPara={1.5, 0.2, 0.1}; 
    intakeDrop.set(true);
    Clamp.set(false);
    arm.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 78, 0.3, 21, true);// rush
    wait(100,msec);
    RunRoller(20);
    MoveEncoderPID(TestPara, -50, 55, 0.8, 46, true);// move back 
    
    Clamp.set(true);
    wait(100,msec);
    arm.set(false);
    RunRoller(100);// move foward
    TurnMaxTimePID(TestPara, 80, 0.3, true);// turn face 3 rings
    
    
    
    MoveEncoderPID(TestPara, 55, 46, 0.6, 80, true);// move intake 3 rings 
    MoveEncoderPID(TestPara, 90, 47, 0.3, 180, false); //turn move toward corner

    RunRoller(100);
    MoveTimePID(TestPara, 55, 1.5, 0.6, 136, true); //move in
    MoveEncoderPID(TestPara, -55, 18, 0.3, 135, true); //move out 

    TurnMaxTimePID(TestPara, -93, 0.5, true);
    
    RunRoller(100);
    MoveEncoderPID(TestPara, 75, 54, 0.3, -89, true); //move to preload
    wait(400, msec);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 40, 23, 0.2, -89, true); //move to alliance ring 
    armMoveToAngle2(loadPosition, 100);
    leftArm.set(true);
    TurnMaxTimePID(TestPara, -180, 0.5, true); //turn face stake and push away rings
    intakeDrop.set(true);
    leftArm.set(false);
    
    MoveTimePID(TestPara, 40, 1.2, 0.3, -180, true); //move in alliance stake 
    
    RunRoller(0);
    double currAngle = Gyro.heading();
    RunLift(-90);
    MoveEncoderPID(TestPara, -65, 6, 0.2, currAngle, true); //score n move back 

    RunLift(0);
    
    MoveEncoderPID(TestPara, -100, 14, 0.3, 170, true); //move back 
    intakeDrop.set(true);
    RunLift(60);
    TurnMaxTimePID(TestPara, -5, 0.5, true);
    RunLift(-60);
    MoveEncoderPID(TestPara, 50, 10, 0.6, -5, true);
    RunLift(0);
}

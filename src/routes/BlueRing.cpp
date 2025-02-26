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
    MoveEncoderPID(TestPara, 100, 78, 0.3, 20, true);// rush
    wait(200,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, -50, 52, 0.8, 44, true);// move back 
    
    Clamp.set(true);
    wait(100,msec);
    arm.set(false);
    TurnMaxTimePID(TestPara, 80, 0.3, true);// turn face 3 rings
    
    
    RunRoller(100);// move foward
    MoveEncoderPID(TestPara, 55, 53, 0.6, 80, true);// move intake 3 rings 
    MoveEncoderPID(TestPara, 90, 42, 0.3, 180, false); //turn move toward corner

    RunRoller(100);
    MoveTimePID(TestPara, 43, 1.5  , 0.6, 135, true); //move in
    MoveEncoderPID(TestPara, -55, 13, 0.3, 135, true); //move out 

    TurnMaxTimePID(TestPara, -93, 0.5, true);
    
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 51, 0.3, -94, true); //move to preload
    wait(400, msec);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 45, 22, 0.2, -94, true); //move to alliance ring 
    armMoveToAngle2(loadPosition, 100);
    leftArm.set(true);
    TurnMaxTimePID(TestPara, -180, 0.5, true); //turn face stake and push away rings
    intakeDrop.set(true);
    leftArm.set(false);
    
    MoveTimePID(TestPara, 40, 1, 0.3, -180, true); //move in alliance stake 
    
    RunRoller(0);
    double currAngle = Gyro.heading();
    RunLift(-90);
    MoveEncoderPID(TestPara, -65, 6, 0.2, currAngle, true); //score n move back 
    wait(75,msec);
    RunLift(0);
    
    MoveEncoderPID(TestPara, -100, 12, 0.3, 178, true); //move back 
    intakeDrop.set(true);
    RunLift(60);
    TurnMaxTimePID(TestPara, -3, 0.5, true);
    RunLift(-70);
    MoveEncoderPID(TestPara, 50, 6, 0.6, -5, true);
    RunLift(0);
}

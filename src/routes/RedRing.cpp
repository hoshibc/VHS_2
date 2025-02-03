#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// global int loadPosition = 20;
// global int alliancePosition = 190;
// global int resetPosition = 0;
// global int holdPosition = 45;
// global int ladderPosition = 120;

void RedRing() {
    PIDDataSet TestPara={1.5, 0.2, 0.1}; 
    Clamp.set(false);
    leftArm.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 87, 0.3, -20, true);// rush
    wait(200,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, -48, 56, 0.8, -44, true);// move back 
    
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, -85, 0.3, true);// turn face 3 rings
    leftArm.set(false);
    
    RunRoller(100);// move foward
    MoveEncoderPID(TestPara, 50, 50, 0.6, -85, true);// move intake 3 rings 
    MoveEncoderPID(TestPara, 70, 46, 0.3, -175, true); //turn move toward corner
    //TurnMaxTimePID(TestPara, -135, 0.3, true);  //turn direct face corner

    RunRoller(100);
    MoveTimePID(TestPara, 40, 1.2, 0.6, -135, true); //move in
    MoveEncoderPID(TestPara, -40, 8, 0.4, -135, true); //move back 
    intakeLift.set(true);
    wait(100,msec);
    MoveTimePID(TestPara, 38, 0.8, 0.5, -135, true); //move in again
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -80, 18, 0.4, -135, true); //move out 


    TurnMaxTimePID(TestPara, 90, 0.3, true);
    RunRoller(-100);
    armMoveToAngle2(loadPosition, 100);
    arm.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 62, 0.5, 93, true); //move to alliance 
    Clamp.set(false);
    TurnMaxTimePID(TestPara, 200, 0.4, true); //turn face stake and push away rings
    wait(100,msec);
    arm.set(false);
    MoveTimePID(TestPara, 50, 1.0, 0.5, 180, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -40, 8, 0.2, 180, true);
    armMoveToAngle2(alliancePosition, 100);
    RunRoller(-100);
    MoveEncoderPID(TestPara,-70, 16, 0.2, 180, false);
    RunRoller(0);
    armMoveToAngle2(resetPosition, 100);
    
    /*
    
    
    MoveEncoderPID(TestPara, 80, 64, 0.3, 20, true); //move to touch bar
    RunRoller(-90);
    armMoveToAngle(ladderPosition+20, 100);
    RunRoller(0);
    */
}
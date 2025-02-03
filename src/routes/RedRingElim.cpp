 #include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// armMoveToAngle(angle position (declared in globals, speed (-100 to 100));

// int loadPosition = 20;
// int alliancePosition = 190;
// int resetPosition = 0;
// int holdPosition = 45;
// int ladderPosition = 140;

void RedRingElim() {
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
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 45, 0.4, 90, true);
    wait(1,sec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 100, 85, 0.4, 95, true);
    TurnMaxTimePID(TestPara, -10, 0.8, true);

    
}
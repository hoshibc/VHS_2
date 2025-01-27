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
    PIDDataSet TestPara={1.5, 0.20, 0.1}; 
    Clamp.set(false);
    leftArm.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 85, 0.3, -20, true);// rush
    wait(500,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, -40, 53, 0.5, -44, true);// move back 
    RunRoller(0);
    Clamp.set(true);
    leftArm.set(false);
    wait(100,msec);
    
    TurnMaxTimePID(TestPara, -80, 0.3, true);// turn face 3 rings

    wait(100,msec);
    RunRoller(90);
    MoveEncoderPID(TestPara, 45, 7, 0.3, -73, false);// move foward
    MoveEncoderPID(TestPara, 45, 39, 0.3, -92, true);// move same
    wait(200,msec);
    MoveEncoderPID(TestPara, 90, 43, 0.3, -170, true); //turn toward corner
    RunRoller(100);
    TurnMaxTimePID(TestPara, -135, 0.3, true);  //turn direct face corner
    RunRoller(100);
    MoveTimePID(TestPara, 50, 1.0, 0.5, -135, true); //move in
    MoveEncoderPID(TestPara, -15, 10, 0.6, -135, true); //move back 
    intakeLift.set(true);
    MoveTimePID(TestPara, 50, 0.7, 0.5, -135, true); //move in again
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -55, 15, 0.4, -150, true); //move out 
    TurnMaxTimePID(TestPara, 90, 0.3, true);
    MoveEncoderPID(TestPara, 80, 25, 0.3, 90, false); //move 
    MoveEncoderPID(TestPara, 80, 64, 0.3, 20, true); //move to touch bar
    RunRoller(-90);
    armMoveToAngle(ladderPosition+20, 100);
    RunRoller(0);

}
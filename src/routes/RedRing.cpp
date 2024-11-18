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
    MoveEncoderPID(TestPara, -100, 20, 0.2, 0, false); //move to close mogo
    MoveEncoderPID(TestPara, -30, 12, 0.2, 0, true); 
    Clamp.set(true); // clamp 
    wait(100,msec);
    TurnMaxTimePID(TestPara, 140, 0.3, true); //to face ring stack
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 35, 0.2, 139, true); //get ring 1
    MoveEncoderPID(TestPara, -50, 5, 0.2, 139, true); //back away
    TurnMaxTimePID(TestPara, 120, 0.2, true);
    MoveEncoderPID(TestPara, 80, 11, 0.2, 122, true); //get ring 2
    wait(200,msec);
    MoveEncoderPID(TestPara, -75, 23, 0.2, 122, true); //back away 
    TurnMaxTimePID(TestPara, 86, 0.2, true); //turn face side ring stack 
    MoveEncoderPID(TestPara, 80, 22, 0.2, 86, true); //move to get 
    wait(175,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -65, 0.4, true); //turn face ring stack in front of alliance stake
    RunRoller(100);
    wait(150,msec);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 50, 0.2, -65, false); //move towards ring 
    armMoveToAngle(loadPosition, 100); //lift arm to loading position 
    MoveEncoderPID(TestPara, 20, 10, 0.3, -65, true); //move forward
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -50, 10, 0.3, -65, true); //move back 
    TurnMaxTimePID(TestPara, -22, 0.3, true); //turn face alliance stake 
    wait(500,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 60, 18, 0.3, -22, true); //move fowards
    wait(200,msec);
    armMoveToAngle(alliancePosition, 100); //score alliance stake 
    MoveEncoderPID(TestPara, -65, 50, 0.3, -26, true); //move back 
    armMoveToAngle(resetPosition, 100); //move arm 
    TurnMaxTimePID(TestPara, -135, 0.3, true); //turn face ladder
    MoveEncoderPID(TestPara, 25, 6, 0.3, -135, true); //move to ladder
    armMoveToAngle(ladderPosition, 100); //move arm 
    
}
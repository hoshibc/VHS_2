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
    MoveEncoderPID(TestPara, 80, 12.5, 0.2, 122, true); //get ring 2
    wait(230,msec);
    MoveEncoderPID(TestPara, -75, 24.5, 0.2, 122, true); //back away 
    TurnMaxTimePID(TestPara, 86, 0.2, true); //turn face side ring stack 
    MoveEncoderPID(TestPara, 80, 24, 0.2, 86, true); //move to get 
    wait(250,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -63, 0.4, true); //turn face ring stack in front of alliance stake
    RunRoller(100);
    wait(150,msec);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 53, 0.2, -63, false); //move towards ring 
    MoveEncoderPID(TestPara, 20, 20, 0.3, -63, true); //move forward
    intakeLift.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara, -45, 10, 0.3, -65, true); //move back 
    wait(500,msec);
}

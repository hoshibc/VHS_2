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
// glocal int ladderPosition = 140;

void RedRing() {
    //PIDDataSet TestPara={3.0, 0.25, 0.15}; //initialize 3.0, 0.25, 0.15
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
    MoveEncoderPID(TestPara, 80, 12, 0.2, 122, true); //get ring 2
    wait(200,msec);
    MoveEncoderPID(TestPara, -75, 23, 0.2, 122, true); //back away 
    TurnMaxTimePID(TestPara, 86, 0.2, true); //turn face side ring stack 
    MoveEncoderPID(TestPara, 80, 22, 0.2, 86, true); //move to get 
    wait(175,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -55, 0.4, true); //turn face ring stack in front of alliance stake
    RunRoller(100);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 60, 0.2, -58, false); //move towards ring 
    armMoveToAngle(loadPosition, 100); //lift arm to loading position 
    MoveEncoderPID(TestPara, 20, 10, 0.3, -58, true);
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -50, 10, 0.3, -58, true);
    TurnMaxTimePID(TestPara, -26, 0.3, true);
    wait(340,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 24, 0.3, -26, true);
    wait(200,msec);
    armMoveToAngle(alliancePosition, 100);
    MoveEncoderPID(TestPara, -50, 35, 0.3, -26, true);
    armMoveToAngle(ladderPosition, 100);
    TurnMaxTimePID(TestPara, -135, 0.3, true);
    MoveEncoderPID(TestPara, 30, 16, 0.3, -135, true);



}
#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void BlueMogo(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5, 0.20, 0.1};   //initialize 1.5, 0.20, 0.1
    armMoveToAngle(loadPosition, 80); //set arm to loading position
    Clamp.set(false);
    wait(150,msec);
    RunRoller(100); //load ring in 
    TurnMaxTimePID(TestPara, -53, 0.3, true); //turn face alliance stake
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 19, 0.2, -53, true); //move foward
    armMoveToAngle(alliancePosition, 100); //score
    MoveEncoderPID(TestPara, -90, 16, 0.2, -53, true); //move back 
    armMoveToAngle(resetPosition, 100); //reset arm 
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn clamp mogo 
    MoveEncoderPID(TestPara, -100, 22, 0.2, 0, false); //move to clamp mogo
    MoveEncoderPID(TestPara, -30, 10, 0.2, 0, true); 
    Clamp.set(true);
    intakeLift.set(true);
    TurnMaxTimePID(TestPara, -50, 0.3, true); //turn face ring stack 
    RunRoller(100);
    MoveEncoderPID(TestPara, 75, 27, 0.2, -50, true); //move foward
    intakeLift.set(false);
    wait(150, msec);
    MoveEncoderPID(TestPara, -30, 32, 0.2, -90, true); //move back 
    TurnMaxTimePID(TestPara, 135, 0.4, true); //turn face ring 2
    MoveEncoderPID(TestPara, 70, 34, 0.2, 135, true); //move foward
    TurnMaxTimePID(TestPara, -112, 0.5, true); //turn face ladder
    MoveEncoderPID(TestPara, 80, 32, 0.2, -112, true); //move foward
    armMoveToAngle(ladderPosition, 100); //raise arm touch bar
    RunRoller(0);
}
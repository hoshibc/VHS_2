#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedMogo(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5, 0.20, 0.1};   //initialize 1.5, 0.20, 0.1
    armMoveToAngle(loadPosition, 80); //move arm to position
    Clamp.set(false);
    wait(150,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 50, 0.3, true);//turn face alliance stake 
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 19, 0.2, 50, true);//move fowards
    armMoveToAngle(alliancePosition, 100); //score alliance
    MoveEncoderPID(TestPara, -90, 16, 0.2, 53, true); // move back 
    armMoveToAngle(resetPosition, 100); //reset arm
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn face mogo 
    MoveEncoderPID(TestPara, -100, 20, 0.2, 0, false); //move to mogo
    MoveEncoderPID(TestPara, -30, 12, 0.2, 0, true); //slow move 
    Clamp.set(true);
    intakeLift.set(true);
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn face ring in front of alliance stake
    RunRoller(100);
    MoveEncoderPID(TestPara, 75, 34, 0.2, 50, true); //move foward
    intakeLift.set(false);
    wait(300, msec);
    MoveEncoderPID(TestPara, -50, 10, 0.2, 50, false); //move back
    MoveEncoderPID(TestPara, -80, 20, 0.7, 50, true);
    TurnMaxTimePID(TestPara, -105, 0.4, true); //turn face side ring
    MoveEncoderPID(TestPara, 75, 30, 0.2, -105, true); //move
    wait(200,msec);
    MoveEncoderPID(TestPara, -75, 30, 0.2, -105, true); //move back 
    TurnMaxTimePID(TestPara, 143, 0.4, true);// turn face bar
    MoveEncoderPID(TestPara, 30, 13, 0.2, 143, true); //move
    armMoveToAngle(ladderPosition, 100);//lift arm to touch bar 
    RunRoller(0);
}
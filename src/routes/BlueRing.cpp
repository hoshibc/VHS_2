#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void BlueRing() {
    PIDDataSet TestPara={1.5, 0.20, 0.1}; 
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 20, 0.2, 0, false); //move to close mogo
    MoveEncoderPID(TestPara, -30, 12, 0.2, 0, true); 
    Clamp.set(true); // clamp 
    wait(100,msec);
    TurnMaxTimePID(TestPara, -140, 0.3, true); //to face ring stack
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 34, 0.2, -139, true); //get ring 1
    MoveEncoderPID(TestPara, -50, 5, 0.2, -139, true); //back away
    TurnMaxTimePID(TestPara, -120, 0.2, true);
    MoveEncoderPID(TestPara, 80, 11, 0.2, -122, true); //get ring 2
    wait(275,msec);
    MoveEncoderPID(TestPara, -75, 24.5, 0.2, -122, true); //back away 
    TurnMaxTimePID(TestPara, -86, 0.2, true); //turn face side ring stack 
    MoveEncoderPID(TestPara, 80, 22, 0.2, -86, true); //move to get 
    wait(125,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, 65, 0.4, true); //turn face ring stack in front of alliance stake
    RunRoller(100);
    wait(150,msec);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 50, 0.2, 65, false); //move towards ring 
    armMoveToAngle(loadPosition, 100); //lift arm to loading position 
    MoveEncoderPID(TestPara, 20, 16, 0.7, 65, true); //move forward
    intakeLift.set(false);
    wait(300,msec);


    //following option for not scoring alliance stake 


    //following option for scoring alliance stake 
    MoveEncoderPID(TestPara, -40, 17, 0.3, 65, true); //move back 
    TurnMaxTimePID(TestPara, 27, 0.3, true); //turn face alliance stake 
    wait(500,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 60, 23, 0.3, 27, true); //move fowards
    wait(200,msec);  
    armMoveToAngle(alliancePosition, 100); //score alliance stake 
    MoveEncoderPID(TestPara, -65, 53, 0.3, 26, true); //move back 
    armMoveToAngle(resetPosition, 100); //move arm 
    RunRoller(-100);
    TurnMaxTimePID(TestPara, 135, 0.3, true); //turn face ladder
    MoveEncoderPID(TestPara, 25, 8, 0.3, 135, true); //move to ladder
    RunRoller(0);
    armMoveToAngle(ladderPosition, 100); //move arm 
}

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
    armMoveToAngle(loadPosition, 80); 
    Clamp.set(false);
    wait(150,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 53, 0.3, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 19, 0.2, 53, true);
    armMoveToAngle(alliancePosition, 100);
    MoveEncoderPID(TestPara, -90, 16, 0.2, 53, true);
    armMoveToAngle(resetPosition, 100);
    TurnMaxTimePID(TestPara, 0, 0.3, true);
    MoveEncoderPID(TestPara, -100, 20, 0.2, 0, false); //move to close mogo
    MoveEncoderPID(TestPara, -30, 10, 0.2, 0, true); 
    Clamp.set(true);
    intakeLift.set(true);
    TurnMaxTimePID(TestPara, 50, 0.3, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 75, 32, 0.2, 50, true);
    intakeLift.set(false);
    wait(150, msec);
    MoveEncoderPID(TestPara, -60, 32, 0.2, 90, true);
    TurnMaxTimePID(TestPara, -135, 0.4, true);
    MoveEncoderPID(TestPara, 70, 34, 0.2, -135, true);
    TurnMaxTimePID(TestPara, 112, 0.5, true);
    MoveEncoderPID(TestPara, 80, 26, 0.2, 112, true);
    armMoveToAngle(ladderPosition, 100);
    RunRoller(0);
}
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
    PIDDataSet TestPara={1.5, 0.2, 0.1};   //initialize 1.5, 0.20, 0.1
    armMoveToAngle2(loadPosition, 100);
    RunRoller(80);
    Clamp.set(false);
    TurnMaxTimePID(TestPara, 48, 0.3, true); //turn face score alliance stake 
    wait(100,msec);
    RunRoller(0);
    RunLift(-100);
    wait(350,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 9, 0.2, 48, true); //move back 
    RunLift(70);
    
    MoveEncoderPID(TestPara, -80, 22, 0.3, 0, false); //move back to goal 
    RunRoller(-100);
    MoveEncoderPID(TestPara, -30, 28, 0.5, 0, true); //slow move 
    RunLift(0);
    Clamp.set(true);
    intakeDrop.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 48, 0.3, true); //turn face alliance stake ring
    RunRoller(100);
    MoveEncoderPID(TestPara, 50, 36, 0.2, 48, true); //move to get
    intakeDrop.set(false);
    wait(300,msec);

    MoveEncoderPID(TestPara, -90, 10, 1.0, 50, true); //move back 
    MoveEncoderPID(TestPara, 80, 22, 0.3, -10, true); //move to wall
    MoveEncoderPID(TestPara, 100, 70, 0.3, -94, true); //move to corner
    TurnMaxTimePID(TestPara, -45, 0.2, true);

    RunRoller(100);

    //corner grab sequence
    MoveTimePID(TestPara, 35, 1.2, 0.6, -45, true); //move in
    MoveEncoderPID(TestPara, -30, 5, 0.4, -45, true); //move back 
    intakeDrop.set(true);
    wait(100,msec);
    MoveTimePID(TestPara, 35, 0.8, 0.6, -45, true); //move in again
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, -80, 50, 0.3, -90, true); //move out 
    
    RunRoller(-20);

    TurnMaxTimePID(TestPara, -151, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 50, 0.3, -151, true);
    TurnMaxTimePID(TestPara, 110, 0.5, true);
    MoveEncoderPID(TestPara, 80, 25, 0.3, 110, true);

    armMoveToAngle2(ladderPosition+35, 100);
    RunRoller(0);



}
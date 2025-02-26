#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedMogo(){
    PIDDataSet TestPara={1.5, 0.2, 0.1};   //initialize 1.5, 0.20, 0.1
    Clamp.set(false);
    RunLift(-90);
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn face score alliance stake 
    wait(150,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 9, 0.2, 50, false); //move back 
    intakeDrop.set(true);
    RunLift(70);
    
    MoveEncoderPID(TestPara, -80, 23, 0.3, 0, false); //move back to goal 
    RunRoller(-100);
    MoveEncoderPID(TestPara, -30, 30, 0.5, 0, true); //slow move 
    RunLift(0);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn face alliance stake ring
    RunRoller(100);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 60, 36, 0.2, 50, true); //move to get
    intakeDrop.set(true);

    MoveEncoderPID(TestPara, -90, 10, 1.0, 50, true); //move back 
    MoveEncoderPID(TestPara, 80, 26, 0.3, -10, true); //move to wall
    MoveEncoderPID(TestPara, 100, 72, 0.3, -92, true); //move to corner
    TurnMaxTimePID(TestPara, -45, 0.2, true);

    RunRoller(100);

    //corner grab sequence
    MoveTimePID(TestPara, 35, 1.2, 0.6, -45, true); //move in
    MoveEncoderPID(TestPara, -30, 5, 0.4, -45, true); //move back 
    intakeDrop.set(false);
    wait(100,msec);
    MoveTimePID(TestPara, 35, 0.8, 0.6, -45, true); //move in again
    intakeDrop.set(true);
    MoveEncoderPID(TestPara, -80, 50, 0.3, -90, true); //move out 
    
    RunRoller(-20);

    TurnMaxTimePID(TestPara, -148, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 50, 0.3, -148, true);
    TurnMaxTimePID(TestPara, 115, 0.5, true);
    MoveEncoderPID(TestPara, 80, 23, 0.3, 115, true);
    RunLift(-60);
    wait(250,msec);
    RunLift(0);
    RunRoller(0);
}
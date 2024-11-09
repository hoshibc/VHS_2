#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedLeft() {
    PIDDataSet TestPara={3.0, 0.25, 0.15}; //initialize 3.0, 0.25, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 14, 0.2, 0, true); 
    MoveEncoderPID(TestPara, -80, 6, 0.2, 0, true);
    Clamp.set(true); //clamp the first goal 
    wait(100, msec);
    TurnMaxTimePID(TestPara, 145, 0.3, true); //turn face stack 
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 29, 0.2, 150, true); //get first ring
    MoveEncoderPID(TestPara, -50, 3, 0.2, 150, true); //move back 
    TurnMaxTimePID(TestPara, 132, 0.3, true); //turn face second ring 
    MoveEncoderPID(TestPara, 70, 10, 0.2, 132, true); //get second ring
    wait(200,msec);
    MoveEncoderPID(TestPara, -80, 26, 0.2, 132, true); //move back
    TurnMaxTimePID(TestPara, 87, 0.2, true); //turn face third ring
    MoveEncoderPID(TestPara, 100, 25, 0.2, 87, true); //get third ring 
    TurnMaxTimePID(TestPara, 15, 0.3, true); //turn face corner ring 
    MoveEncoderPID(TestPara, 100, 30, 0.2, 15, true); //get corner ring 
    MoveEncoderPID(TestPara, 60, 16, 0.2, 15, true); //slow move foward
    MoveEncoderPID(TestPara, -100, 20, 0.2, 15, true); //move back 
    RunRoller(0);
    TurnMaxTimePID(TestPara, -85, 0.3, true); //turn face 5th ring
    RunRoller(100);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 55, 0.2, -85, true); //move to get 5th ring 
    intakeLift.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara, -100, 15, 0.2, -84, true); //move back 
    RunLift(-100);
    TurnMaxTimePID(TestPara, -145, 0.5, true); //turn to face ladder
    RunLift(0);
    MoveEncoderPID(TestPara, 100, 28, 0.2, -145, true); //move straight
    wait(200,msec);
    RunRoller(0);
    RunLift(-100);
    wait(0.2, msec);
    RunLift(0);
}
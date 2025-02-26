#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedMogoElim(){
    PIDDataSet TestPara={1.5, 0.20, 0.1};
    intakeDrop.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 20, 0.3, 0, false); //move back 
    MoveEncoderPID(TestPara, -30, 25, 0.3, 0, true); //move clamp goal 
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn to alliance ring
    intakeDrop.set(false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 50, 48, 0.6, 50, true); //move 
    intakeDrop.set(true);
    wait(50,msec);
    MoveEncoderPID(TestPara, -80, 50, 0.3, 50, true);
    TurnMaxTimePID(TestPara, 127, 0.4, true); //turn face ladder 
    RunRoller(-10);
    arm.set(true);
    MoveEncoderPID(TestPara, 45, 46, 0.3, 128, true); //get ring under ladder 
    MoveEncoderPID(TestPara, -70, 60, 0.3, 150, true); //move back 
    wait(200,msec);
    TurnMaxTimePID(TestPara, -150, 0.4, true); //turn 
    arm.set(false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 40, 0.3, -125, true); //move intake 2 rings 
    MoveEncoderPID(TestPara, 100, 58, 0.6, -20, true); //move to corner 

    MoveTimePID(TestPara, 40, 1.2, 0.6, -40, true); //move in
    MoveEncoderPID(TestPara, -40, 30, 0.4, 15, true); //move back 
    leftArm.set(true);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn 
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 21, 0.3, -6, true); //move back foward to sweep 
    TurnMaxTimePID(TestPara, 150, 0.6, true);
    leftArm.set(false);
    
    MoveTimePID(TestPara, -50, 0.6, 0.6, 135, true); 
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 10, 0.3, 120, false);
    MoveEncoderPID(TestPara, -70, 35, 0.3, 0, true);

} 
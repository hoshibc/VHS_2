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

void BlueMogoElim() {
    PIDDataSet TestPara={1.5, 0.20, 0.1};
    intakeDrop.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 27, 0.3, 0, false); //move back 
    MoveEncoderPID(TestPara, -30, 20, 0.3, 0, true); //move clamp goal 
    Clamp.set(true);
    TurnMaxTimePID(TestPara, -35, 0.2, true); //turn to alliance ring
    //intakeDrop.set(false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 20, 0.6, -35, true); //move 
    leftArm.set(true);
    wait(50,msec);
    MoveEncoderPID(TestPara, -70, 20, 0.6, -50, true); //move back 
    wait(100,msec);
    TurnMaxTimePID(TestPara, -110, 0.35, true); //turn face ladder 
    leftArm.set(false);
    TurnMaxTimePID(TestPara, -138, 0.35, true);
    RunRoller(60);
    leftArm.set(true);
    MoveEncoderPID(TestPara, 45, 44, 0.3, -138, true); //get ring under ladder 
    RunRoller(-10);
    MoveEncoderPID(TestPara, -70, 32, 0.3, -150, true); //move back 
    RunRoller(100);
    wait(200,msec);
    TurnMaxTimePID(TestPara, 140, 0.4, true); //turn 
    leftArm.set(false);
    
    MoveEncoderPID(TestPara, 100, 43, 0.2, 100, true); //move intake 2 rings 
    MoveEncoderPID(TestPara, 100, 54, 0.6, 20, true); //move to corner 

    MoveTimePID(TestPara, 45, 1.2, 0.6, 40, true); //move in
    MoveEncoderPID(TestPara, -40, 30, 0.4, -15, true); //move back 
    arm.set(true);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn 
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 21, 0.3, 6, true); //move back foward to sweep 
    TurnMaxTimePID(TestPara, -150, 0.6, true);
    arm.set(false);
    
    MoveTimePID(TestPara, -50, 0.6, 0.6, -135, true); 
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 8, 0.3, -120, false);
    
    MoveEncoderPID(TestPara, -70, 35, 0.3, 0, true);

}

#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Blue2GoalAwp() {
    PIDDataSet TestPara={3.0, 0.25, 0.15}; //initialize 3.0, 0.25, 0.15
    armMoveToAngle(loadPosition, 100);
    Clamp.set(false);
    wait(100,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 34, 0.3, true); //turn face alliacne stake 
    MoveEncoderPID(TestPara, 80, 4, 0.2, 34, true);//move to 
    wait(200,msec);
    RunRoller(0);
    armMoveToAngle(alliancePosition, 100);
    MoveEncoderPID(TestPara, -100, 30, 0.2, 35, true); //move back 
    MoveEncoderPID(TestPara, -50, 24, 0.2, 0, true);//move face mogo
    Clamp.set(true);
    armMoveToAngle(resetPosition, 100);
    TurnMaxTimePID(TestPara, -128, 0.3, true); //turn face ring stack
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 25, 0.2, -128, true); //get one ring from ring stack 
    wait(250,msec);
    MoveEncoderPID(TestPara, -70, 24, 0.2, -128, true); //move back 
    MoveEncoderPID(TestPara, 100, 25, 0.2, -90, true); //move get side ring stack 
    MoveEncoderPID(TestPara, -80, 27, 0.2, -150, true); //move far back 
    TurnMaxTimePID(TestPara, 90, 0.4, true); //turn face ring stack in front of alliance stake 
    wait(100,msec);
    
    MoveEncoderPID(TestPara, 100, 30, 0.2, 90, false);
    Clamp.set(false); //drop mogo
    MoveEncoderPID(TestPara, 60, 30, 0.2, 90, false); //move slowly
    MoveEncoderPID(TestPara, 50, 23, 0.2, 90, true); //slower
    RunRoller(0); //stop itnake when blue ing is flung out and red ring is being held 
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn back face mogo
    MoveEncoderPID(TestPara, -70, 30, 0.2, 0, false); //move 
    MoveEncoderPID(TestPara, -30, 15, 0.2, 0, true); //slow move
    Clamp.set(true); // clamp
    wait(100,msec);
    TurnMaxTimePID(TestPara, 90, 0.3, true); //turn face side ring stack 
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 28, 0.2, 90, true); //move foward
    MoveEncoderPID(TestPara, -90, 28, 0.2, 110, true); //move back touch bar prep
    TurnMaxTimePID(TestPara, -140, 0.3, true); //turn face bar 
    MoveEncoderPID(TestPara, 70, 15, 0.2, -140, true); //move foward to bar
    armMoveToAngle(ladderPosition, 100); //raise arm 
    RunRoller(0);
}
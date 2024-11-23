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
    PIDDataSet TestPara={1.5, 0.20, 0.1};  //initialize 1.5, 0.20, 0.1
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 24, 0.3, 0, false); //rush mogo
    //TurnMaxTimePID(TestPara, -29, 0.3, true);
    MoveEncoderPID(TestPara, -100, 29, 0.1, -45, false); //continue rush
    MoveEncoderPID(TestPara, -20, 14, 0.1, -28, true); //continue rush
    Clamp.set(true); //clamp mid goal
    wait(100,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 85, 20, 0.3, 40, false);
    MoveEncoderPID(TestPara, 85, 15, 0.3, 15, false);
    RunRoller(0);
    MoveEncoderPID(TestPara, 85, 9, 0.3, 15, true); //move get second ring
    TurnMaxTimePID(TestPara, 170, 0.5, true); //turn to drop goal
    Clamp.set(false); //drop 
    wait(150,msec);
    TurnMaxTimePID(TestPara, 52, 0.3, true); //turn face second goal 
    MoveEncoderPID(TestPara, -100, 34, 0.3, 75, false); //fast move
    MoveEncoderPID(TestPara, -30, 20, 0.3, 75, true); //slow move
    Clamp.set(true); //clamp
    wait(150,msec);
    TurnMaxTimePID(TestPara, -50, 0.6, true); //turn face alliance stake ring 
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 20, 0.3, -50, false);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 30, 28, 0.3, -50, true);
    intakeLift.set(false);
    wait(150,msec);
    MoveEncoderPID(TestPara, -35, 50, 0.3, -50, true);
    TurnMaxTimePID(TestPara, 90, 0.5, true);
    wait(2,sec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 80, 30, 0.3, 90, true);
} 

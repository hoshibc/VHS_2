#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedMogoElim(){
    PIDDataSet TestPara={1.5, 0.20, 0.1};  //initialize 1.5, 0.20, 0.1
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 20, 0.3, 0, false);
    MoveEncoderPID(TestPara, -30, 25, 0.3, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 50, 0.3, true);
    intakeLift.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 45, 50, 0.6, 50, true);
    intakeLift.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -60, 50, 0.5, 50, true);
    TurnMaxTimePID(TestPara, 129, 0.4, true);
    RunRoller(0);
    arm.set(true);
    MoveEncoderPID(TestPara, 45, 47, 0.3, 130, true);
    MoveEncoderPID(TestPara, -70, 60, 0.3, 150, true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, -150, 0.4, true);
    arm.set(false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 42, 0.3, -125, true);
    MoveEncoderPID(TestPara, 100, 58, 0.6, -20, true);

    MoveTimePID(TestPara, 40, 1.2, 0.6, -40, true); //move in
    MoveEncoderPID(TestPara, -30, 9, 0.4, -42, true); //move back 
    intakeLift.set(true);
    wait(100,msec);
    MoveTimePID(TestPara, 35, 0.9, 0.6, -45, true); //move in again
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -80, 20, 0.3, 0 , true); //move back  
    TurnMaxTimePID(TestPara, -170, 0.54, true);
    RunRoller(0);
    Clamp.set(false);
    TurnMaxTimePID(TestPara, -20, 0.3, true);
    MoveEncoderPID(TestPara, -100, 25, 0.3, -20, true);


} 
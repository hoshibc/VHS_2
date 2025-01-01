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
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 48, 0.2, -20, true);
    arm.set(true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -80, 20, 0.2, 0, true);
    wait(150,msec);
    arm.set(false);
    TurnMaxTimePID(TestPara, -179, 0.4, true);
    MoveEncoderPID(TestPara, -40, 25, 0.2, -179, true);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 40, 0.3, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 60, 0.2, 40, true);
    RunRoller(0);
    Clamp.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, 100, 15, 0.7, 60, true);
    TurnMaxTimePID(TestPara, 132, 0.2, true);
    MoveEncoderPID(TestPara, -40, 23, 0.5, 132, true);
    Clamp.set(true);
    wait(100,msec);

    MoveEncoderPID(TestPara, 80, 33, 0.5, 170, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 60, 25, 0.2, 85, false);
    MoveEncoderPID(TestPara, 60, 15, 0.2, 95, false);

    TurnMaxTimePID(TestPara, 135, 0.3, true);
    wait(300, msec);
    RunRoller(-70);
    MoveTimePID(TestPara, 60, 0.5, 0.2, 135, true); //push into corner
    RunRoller(100);
    MoveTimePID(TestPara, 80, 0.3, 0.2, 135, true);
    MoveEncoderPID(TestPara, -10, 3, 0.4, 135, true); //get first ring and move back 
    wait(1,sec);
    intakeLift.set(true);
    RunRoller(-80);
    MoveTimePID(TestPara, 50, 0.5, 0.2, 135, true);  //get second ring
    intakeLift.set(false);
    RunRoller(100);
    wait(300,msec);

    TurnMaxTimePID(TestPara, 90, 0.2, true);
    MoveEncoderPID(TestPara, -70, 28, 0.4, 80, true);
    arm.set(true);
    
    MoveEncoderPID(TestPara, 80, 14, 0.8, 93, true);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    RunRoller(0);
    arm.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara, 80, 14, 0.2, -40, true);
    
    RunRoller(0);
} 
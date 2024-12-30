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
    TurnMaxTimePID(TestPara, 140, 0.2, true);
    MoveEncoderPID(TestPara, -40, 23, 0.5, 140, true);
    Clamp.set(true);
    wait(100,msec);

    MoveEncoderPID(TestPara, 80, 33, 0.5, 170, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 60, 23, 0.2, 100, false);
    arm.set(true);
    MoveEncoderPID(TestPara, 60, 15, 0.2, 95, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, 20, 0.2, true);
    arm.set(false);
    MoveEncoderPID(TestPara, 60, 30, 0.2, 20, true);
    RunRoller(0);

    MoveEncoderPID(TestPara, -80, 30, 0.2, 30, true);


    RunRoller(100);
    MoveEncoderPID(TestPara, 60, 20, 0.2, 135, true);
    wait(300,msec);
    MoveEncoderPID(TestPara, -60, 10, 0.2, 90, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, 100, 30, 1.4, 55, true);
    

} 
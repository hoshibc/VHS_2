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
    arm.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 46, 0.2, -20, false);
    MoveEncoderPID(TestPara, 40, 8, 0.2, -17, true);
    //arm.set(false);
    RunRoller(0);
    
    MoveEncoderPID(TestPara, -70, 25, 0.2, 0, true);
    //arm.set(true);
    TurnMaxTimePID(TestPara, -170, 0.4, true);
    arm.set(false);
    MoveEncoderPID(TestPara, -35, 35, 0.2, -170, true);
    Clamp.set(true);
    RunRoller(-100);
    wait(100,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 55, 0.2, -135, true);
    TurnMaxTimePID(TestPara, 30, 0.3, true);
    wait(100,msec);
    Clamp.set(false);
    wait(150,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 75, 30, 0.2, 70, true);
    TurnMaxTimePID(TestPara, 120, 0.3, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -30, 15, 0.2, 130, true);
    Clamp.set(true);
    RunRoller(0);

} 
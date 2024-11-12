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
    MoveEncoderPID(TestPara, -100, 75, 0.2, 22, true);
    wait(75,msec); 
    Clamp.set(true);
    wait(100,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -14, 0.2, true);
    wait(200,msec);
    MoveEncoderPID(TestPara, 80, 40, 0.2, -14, true); 
    RunRoller(0);
    MoveEncoderPID(TestPara, 80, 25, 0.2, -12, true); 
    TurnMaxTimePID(TestPara, 110, 0.4, true);
    wait(100,msec);
    Clamp.set(false);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -35, 0.4, true);
    MoveEncoderPID(TestPara, -75, 70, 0.2, -40, true);
    wait(100,msec);
    Clamp.set(true);
    MoveEncoderPID(TestPara, 80, 20, 0.2, -40, true);
    RunRoller(100);
}
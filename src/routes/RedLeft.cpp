#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedLeft() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 14, 0.2, 0, true);
    MoveEncoderPID(TestPara, -80, 6, 0.2, 0, true);
    Clamp.set(true);
    wait(150, msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 145, 0.3, true);
    MoveEncoderPID(TestPara, 100, 30, 0.2, 145, true);
    MoveEncoderPID(TestPara, -50, 8, 0.2, 145, true);
    TurnMaxTimePID(TestPara, 128, 0.2, true);
    MoveEncoderPID(TestPara, 100, 16, 0.2, 128, true);
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, 34, 0.2, 128, true);
    TurnMaxTimePID(TestPara, 87, 0.2, true);
    MoveEncoderPID(TestPara, 100, 30, 0.2, 87, true);
    TurnMaxTimePID(TestPara, 18, 0.4, true);
    MoveEncoderPID(TestPara, 100, 30, 0.2, 18, true);
    MoveEncoderPID(TestPara, 60, 15, 0.2, 18, true); 
    MoveEncoderPID(TestPara, -100, 20, 0.2, 18, true);
    TurnMaxTimePID(TestPara, -90, 0.5, true);
    MoveEncoderPID(TestPara, 100, 60, 0.2, -90, true);


}
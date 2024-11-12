#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedMogo(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5, 0.20, 0.1};  //initialize 1.5, 0.20, 0.1
    Clamp.set(false);
    MoveEncoderPID(TestPara, -85, 70, 0.2, 23, false);
    MoveEncoderPID(TestPara, -20, 8, 0.2, 23, true);
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
    wait(100,msec);
    MoveEncoderPID(TestPara, 90, 20, 0.2, 110, true); 
    TurnMaxTimePID(TestPara, -33, 0.4, true);
    MoveEncoderPID(TestPara, -90, 30, 0.2, -33, false);
    MoveEncoderPID(TestPara, -20, 10, 0.2, -33, true);
    Clamp.set(true);
    wait(100,msec);
    MoveEncoderPID(TestPara, 80, 20, 0.2, -33, true);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 75, 0.3, true);
}
#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void SimpleRedRight(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 14, 0.2, 0, true);
    MoveEncoderPID(TestPara, -50, 4, 0.2, 0, true);
    Clamp.set(true); 
    wait(100, msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 63, 0.3, true);
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 24, 0.2, 63, true);
    intakeLift.set(false); 
    RunRoller(100);
    wait(600, msec);
    MoveEncoderPID(TestPara, -100, 6, 0.2, 65, true);
    TurnMaxTimePID(TestPara, -110, 0.5, true);
    MoveEncoderPID(TestPara, 100, 38, 0.3, -110, true);
    MoveEncoderPID(TestPara, 70, 12, 0.3, -110, false);
    MoveEncoderPID(TestPara, -70, 2, 0.2, -110, true);
    TurnMaxTimePID(TestPara, -26, 0.5, true);
    MoveEncoderPID(TestPara, 100, 30, 0.2, -26, true);
    MoveEncoderPID(TestPara, 60, 20, 0.2, -26, true);  
    MoveEncoderPID(TestPara, -80, 25, 0.2, -26, true);
    TurnMaxTimePID(TestPara, 120, 1, true);
    MoveEncoderPID(TestPara, 100, 44, 0.2, 140, true);
    RunRoller(0);
}
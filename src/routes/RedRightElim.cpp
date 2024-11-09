#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedRightElim(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={3.0, 0.25, 0.15}; //initialize 3.0, 0.25, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 76, 0.2, 22, true); 
    Clamp.set(true);
    wait(100,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -14, 0.2, true);
    MoveEncoderPID(TestPara, 80, 40, 0.2, -14, true); 
    RunRoller(0);


}
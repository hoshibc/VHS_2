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
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -85, 24, 0.2, 0, true); //get mogo in on the right side
    MoveEncoderPID(TestPara, -40, 8, 0.2, 0, true);
    Clamp.set(true);
    wait(100,msec);   
    TurnMaxTimePID(TestPara, -90, 0.5, true); // turn to face far right ring
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 40, 0.3, -90, true); //move to get it
    MoveEncoderPID(TestPara, -100,6, 0.3, -90, true); //move back
    TurnMaxTimePID(TestPara, -38, 0.5, true); //turn to face corner
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 26, 0.2, -38, true); //move to corner
    MoveEncoderPID(TestPara, 50, 20, 0.2, -23, true); //move slowly
    wait(300,msec);
    TurnMaxTimePID(TestPara, -90, 0.5, true);
    MoveEncoderPID(TestPara, -80, 14, 0.2, -94, true);
    arm.set(true);
    wait(200,msec);
    MoveEncoderPID(TestPara, 50, 6, 0.2, -85, true);
    TurnMaxTimePID(TestPara, -170, 0.4, true);
    wait(200,msec);
    arm.set(false);

}
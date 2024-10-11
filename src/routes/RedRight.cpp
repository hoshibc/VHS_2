#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedRight(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 15, 0.2, 0, true); //get mogo in on the right side
    MoveEncoderPID(TestPara, -40, 5, 0.2, 0, true);
    Clamp.set(true);
    wait(100,msec);   
    RunRoller(100);//score preload 
    TurnMaxTimePID(TestPara, 62, 0.3, true); //turn to ge middle red ring
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 24, 0.2, 62, true);//get middle field ring 
    intakeLift.set(false); 
    wait(200, msec);
    MoveEncoderPID(TestPara, -100, 6, 0.2, 65, true);  //back away
    wait(700,msec);
    TurnMaxTimePID(TestPara, -113, 0.5, true); // turn to face far right ring
    MoveEncoderPID(TestPara, 100, 38, 0.3, -113, true); //move to get it
    MoveEncoderPID(TestPara, 70, 12, 0.3, -113, true);
    MoveEncoderPID(TestPara, -70, 2, 0.2, -113, true); //back away
    TurnMaxTimePID(TestPara, -25, 0.5, true); //turn to face corner
    MoveEncoderPID(TestPara, 100, 33, 0.2, -25, true); //move to corner
    MoveTimePID(TestPara, 30, 1, 0.3, -25, true); //move time pid function has speed revesed(negative speed for foward)
    //MoveEncoderPID(TestPara, 50, 19, 0.2, -26, true);  
    MoveEncoderPID(TestPara, -80, 25, 0.2, -25, true); // back away from corner
    wait(150, msec);
    TurnMaxTimePID(TestPara, 120, 1, true); //turn to face mid
    MoveEncoderPID(TestPara, 80, 34, 0.2, 140, true); //touch mid
    MoveEncoderPID(TestPara, 30, 10, 0.2, 140, false);
    RunRoller(0);
}
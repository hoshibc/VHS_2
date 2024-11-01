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
    TurnMaxTimePID(TestPara, 54, 0.3, true); //turn to ge middle red ring
    RunRoller(100);//score preload 
    intakeLift.set(true);
    MoveEncoderPID(TestPara, 100, 26, 0.2, 54, true);//get middle field ring 
    intakeLift.set(false); 
    wait(275, msec);
    MoveEncoderPID(TestPara, -100, 8, 0.2, 65, true);  //back away
    //RunRoller(0);
    TurnMaxTimePID(TestPara, -113, 0.5, true); // turn to face far right ring
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 38, 0.3, -113, true); //move to get it
    MoveEncoderPID(TestPara, 70, 12, 0.3, -113, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -70, 2, 0.2, -113, true); //back away
    TurnMaxTimePID(TestPara, -25, 0.5, true); //turn to face corner
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 30, 0.2, -25, true); //move to corner
    MoveEncoderPID(TestPara, 50, 18, 0.2, -25, true); //move slowly
    wait(150,msec);
    MoveEncoderPID(TestPara, -80, 25, 0.2, -25, true); // back away from corner
    wait(150, msec);
    TurnMaxTimePID(TestPara, 120, 1, true); //turn to face mid
    RunRoller(0);
    RunLift(-100);
    wait(350,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, 80, 39, 0.2, 120, true); //touch mid
    RunRoller(0);
}
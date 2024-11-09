#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red2GoalAwp() {
    PIDDataSet TestPara={3.0, 0.25, 0.15}; //initialize 3.0, 0.25, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 14, 0.2, 0, true); 
    MoveEncoderPID(TestPara, -80, 6, 0.2, 0, true);
    Clamp.set(true); //clamp the first goal 
    wait(100, msec);
    TurnMaxTimePID(TestPara, 145, 0.3, true); //turn face stack 
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 32, 0.2, 150, true); //get first ring
    MoveEncoderPID(TestPara, -80, 20, 0.2, 150, true); //move back 
    TurnMaxTimePID(TestPara, 90, 0.3, true); //turn face side ring
    MoveEncoderPID(TestPara, 100, 25, 0.2, 90, true); //get side ring 
    MoveEncoderPID(TestPara, -100, 5, 0.2, 90, true); //back away side ring 
    RunRoller(0);
    TurnMaxTimePID(TestPara, -65, 0.5, true); //turn face ring stack
    intakeLift.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 46, 0.3, -65, true); //move to get ring stack 
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -100, 4, 0.2, -65, true);
    wait(100,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -90, 0.2, true);
    MoveEncoderPID(TestPara, 100, 45, 0.2, -90, true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 7, 0.2, -90, true);
    TurnMaxTimePID(TestPara, -24, 0.2, true);
    MoveEncoderPID(TestPara, -60, 14, 0.2, -24, true);
    Clamp.set(true);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -110, 0.3, true);
    MoveEncoderPID(TestPara, 80, 22, 0.2, -110, true);
    wait(450, msec);
    RunLift(-100);
    wait(100,msec);
    MoveEncoderPID(TestPara, -80, 39, 0.2, -60, true);
    wait(100,msec);
    RunLift(0);
    RunRoller(0);
    
}
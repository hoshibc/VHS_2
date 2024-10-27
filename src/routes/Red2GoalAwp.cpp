#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red2GoalAwp() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 14, 0.2, 0, true); 
    MoveEncoderPID(TestPara, -80, 6, 0.2, 0, true);
    Clamp.set(true); //clamp the first goal 
    wait(100, msec);
    TurnMaxTimePID(TestPara, 145, 0.3, true); //turn face stack 
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 32, 0.2, 150, true); //get first ring
    MoveEncoderPID(TestPara, -50, 8, 0.2, 150, true); //move back 
    TurnMaxTimePID(TestPara, 130, 0.1, true); //turn face second ring 
    MoveEncoderPID(TestPara, 90, 14, 0.2, 130, true); //get second ring
    wait(150,msec);
    MoveEncoderPID(TestPara, -80, 28, 0.2, 132, true); //move back
    TurnMaxTimePID(TestPara, 90, 0.175, true); //turn face third ring
    MoveEncoderPID(TestPara, 100, 25, 0.2, 90, true); //get third ring 
    MoveEncoderPID(TestPara, -100, 5, 0.2, 90, true); //get third ring 
    RunRoller(0);
    TurnMaxTimePID(TestPara, -57, 0.5, true); //turn face 4th ring
    intakeLift.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 46, 0.2, -57, true); //move to get ring stack 
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -100, 4, 0.2, -60, true);
    TurnMaxTimePID(TestPara, -90, 0.2, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, 100, 45, 0.2, -90, true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 7, 0.2, -90, true);
    TurnMaxTimePID(TestPara, 0, 0.2, true);
    MoveEncoderPID(TestPara, -80, 10, 0.2, 0, true);
    Clamp.set(true);
    // Clamp.set(false);
    // RunRoller(0);
    // MoveEncoderPID(TestPara, 100, 12, 0.2, -88, true);
    // TurnMaxTimePID(TestPara, -48, 0.2, true);
    // MoveEncoderPID(TestPara, -65, 25, 0.2, -48, true);
    // Clamp.set(true);
    // RunRoller(100);
    // wait(150,msec);
    // //TurnMaxTimePID(TestPara, -100, 0.2, true);
    // MoveEncoderPID(TestPara, 100, 15, 0.2, -100, true);
    // //TurnMaxTimePID(TestPara, -70, 0.5, true);
    // MoveEncoderPID(TestPara, -100, 30, 0.2, -75, true);
    
}
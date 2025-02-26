#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red2GoalAwp() {
    PIDDataSet TestPara={1.5, 0.2, 0.1};   //initialize 1.5, 0.20, 0.1
    Clamp.set(false);
    RunLift(-90);
    TurnMaxTimePID(TestPara, -50, 0.3, true); //turn face score alliance stake 
    wait(150,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 7, 0.2, -50, false); //move back 
    intakeDrop.set(true);
    RunLift(77);
    
    MoveEncoderPID(TestPara, -80, 32, 0.3, 0, false); //move back to goal 
    
    MoveEncoderPID(TestPara, -40, 21, 0.5, 0, true); //slow move 
    RunLift(0);
    armMoveToAngle2(resetPosition, 100);
    Clamp.set(true);
    wait(100,msec);

    TurnMaxTimePID(TestPara, 90, 0.4, false); //turn to ring stack 
    RunRoller(100); //start intake 
    MoveEncoderPID(TestPara, 100, 30, 0.5, 90, true);
    
    MoveEncoderPID(TestPara, 100, 42, 0.3, 0, false); //turn move toward corner

    RunRoller(100);
    MoveTimePID(TestPara, 45, 1.5, 0.6, 45, true); //move in
    

    MoveEncoderPID(TestPara, -80, 10, 0.3, 45, true); //move out 




    TurnMaxTimePID(TestPara, -90, 0.5, true); //turn to alliance stack 
    RunRoller(70);
    MoveEncoderPID(TestPara, 90, 65, 0.3, -90, true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 40, 65, 0.3, -90, true);
    RunRoller(0);
    TurnMaxTimePID(TestPara, 0, 0.4, false);
    MoveEncoderPID(TestPara, -40, 45, 0.3, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, -80, 0.5, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 38, 0.3, -80, true);
    TurnMaxTimePID(TestPara, 90, 0.6, false);
    MoveEncoderPID(TestPara, 80, 56, 0.3, 90, true);
    RunLift(-100);
    wait(360,msec);
    RunLift(0);
    RunRoller(0);

}
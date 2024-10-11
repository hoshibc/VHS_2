#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red2GoalAwp() {
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    MoveEncoderPID(TestPara, -100, 40, 0.2, 0, true); //move ahead
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn to face side ring
    RunRoller(100);
    MoveEncoderPID(TestPara, 50, 17, 0.4, 50, true); //move to intake
    TurnMaxTimePID(TestPara, 0, 0.3, true); //face the goal 
    //wait(50, msec);
    RunRoller(0); //stop roller
    MoveEncoderPID(TestPara, -50, 19, 0.2, 0, true); //move ahead
    Clamp.set(true);
    RunRoller(100); 
    TurnMaxTimePID(TestPara, -45, 0.2, true);
    MoveEncoderPID(TestPara, 100, 18, 0.2, -20, true);
    TurnMaxTimePID(TestPara, 0, 0.2, true);
    MoveEncoderPID(TestPara, 100, 38, 0.2, 0, true);
    wait(200,msec);
    MoveEncoderPID(TestPara, -50, 10, 0.2, 0, true);
    wait(650,msec);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 5, 0.2, 0, true);
    TurnMaxTimePID(TestPara, -35, 0.3, true);
    MoveEncoderPID(TestPara, 50, 5, 0.2, -35, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, 50, 5, 0.2, -35, true);
    TurnMaxTimePID(TestPara, -90, 0.5, true);
    RunRoller(0);
}
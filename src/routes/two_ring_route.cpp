#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void two_ring_route(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(true);
    MoveEncoderPID(TestPara, -100, 5, 0.4, 0, true); //backup
    TurnMaxTimePID(TestPara, 30, 0.4,true); //turn to face flat edge of goal
    MoveEncoderPID(TestPara, -100, 10, 0.4, 30, true); //backup toward goal
    MoveEncoderPID(TestPara, -100, 10, 0.4, 30, true); //backup toward goal
    Clamp.set(false); // clamp mogo
    wait(600,msec);
    //Tilt.set(false); // tilt mogo up
    wait(600,msec);
    TurnMaxTimePID(TestPara, -100, 1,true); // turn to rings
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 25.5, 0.4, -100, true); // take in rings
    wait(400,msec);
    TurnMaxTimePID(TestPara, -180, 1,true); // turn to rings
    MoveEncoderPID(TestPara, 100, 16, 0.4, -180, true); // take in rings
    wait(2000,msec);
    MoveEncoderPID(TestPara,-100, 10, 0.4, -180, true); // take in rings
    TurnMaxTimePID(TestPara, -90, 0.5,true); // turn 
    RunRoller(0);
    MoveTimePID(TestPara, 100, 0.5, 0.2, -90, true); // hit ladder

   
}
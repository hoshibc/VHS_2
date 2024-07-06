#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void ringquad(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={0,0,0}; //initialize
    MoveEncoderPID(TestPara, 100, 14, 0.4, 0, true); //backup toward goal
    TurnMaxTimePID(TestPara, 30, 0.4,true); //turn to face flat edge of goal
    MoveEncoderPID(TestPara, 100, 13, 0.4, 30, true); //move back to align with goal
    MoveEncoderPID(TestPara, 30, 13, 0.4, 30, true); //move slower to prevent goal from being knocked
    Clamp.set(true); //close clamp
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 0.2, 0.4,30, true); //move back to let goal sit in
    Tilt.set(false); // tilt mogo
    RunRoller(-100); //run intake
    TurnMaxTimePID(TestPara, -135, 0.8, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100, 23, 0.4, -135, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -98, 0.4, true); //turn to face ring 2
    MoveEncoderPID(TestPara, -100, 14, 0.4, -98, true); //pickup ring 2
    wait(100,msec);
    //MoveEncoderPID(TestPara, 100, 7, 0.4, -105, true); 
    TurnMaxTimePID(TestPara, 10, 0.4, true); 
    MoveEncoderPID(TestPara, -100, 28, 0.4, 10, true); //backup closer to ring 3
    //TurnMaxTimePID(TestPara, -90, 0.4, true);  //turn to face ring 3
   // MoveEncoderPID(TestPara, -100, 18, 0.4, -90, true); //drive into ring 3
    TurnMaxTimePID(TestPara, 78, 0.8, true);
    //Pistake.set(true);
    MoveEncoderPID(TestPara, -100, 50, 0.2, 78, true); //drive into ring 4
    MoveEncoderPID(TestPara, -30, 6, 0.2, 78, true); //drive into ring 4
    //Pistake.set(false);
    wait(400,msec);
    MoveEncoderPID(TestPara, 70, 15, 0.4, 78,true);
    TurnMaxTimePID(TestPara, 140, 0.8, true);
    MoveEncoderPID(TestPara, -70, 10, 0.2, 140, false); //drive into ladder

    //wait(200,msec); //wait for mogo to be dropped
}
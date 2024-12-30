 #include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// armMoveToAngle(angle position (declared in globals, speed (-100 to 100));

// int loadPosition = 20;
// int alliancePosition = 190;
// int resetPosition = 0;
// int holdPosition = 45;
// int ladderPosition = 140;

void RedRingElim() {
    PIDDataSet TestPara={1.5, 0.20, 0.1}; 
    armMoveToAngle(loadPosition, 100);
    Clamp.set(false);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -33, 0.3, true); //turn face alliacne stake 
    MoveEncoderPID(TestPara, 100, 4, 0.2, -33, true);
    RunRoller(0);
    armMoveToAngle(alliancePosition, 100);
    MoveEncoderPID(TestPara, -100, 31, 0.2, -33, true); //move back 
    RunLift(100);
    MoveEncoderPID(TestPara, -50, 24, 0.2, 0, true);//move face mogo
    RunLift(0);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 122, 0.3, true); //turn face ring stack
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 12, 0.2, 122, true); //get one ring from ring stack
    MoveEncoderPID(TestPara, 75, 30, 0.2, 90, true); //get seconds ring 
    wait(200,msec);
    MoveEncoderPID(TestPara, -100, 6, 0.2, 94, false); //back up at an angle 
    MoveEncoderPID(TestPara, -100, 6, 0.2, 100, false); //back up more 
    MoveEncoderPID(TestPara, -100, 26, 0.2, 150, true); //more 
    TurnMaxTimePID(TestPara, 85, 0.4, true); //turn face ring stack 
    MoveEncoderPID(TestPara, 100, 18, 0.2, 85, true); //move fowards
    MoveEncoderPID(TestPara, 100, 47, 0.2, 10, true); //move fowards towards corner

    TurnMaxTimePID(TestPara, 45, 0.4, true); //turn face corner 
    
    //following is the corner grab sequence 
    RunRoller(-70);
    MoveTimePID(TestPara, 70, 0.4, 0.2, 45, true); //push into corner
    RunRoller(100);
    MoveTimePID(TestPara, 80, 0.3, 0.2, 45, true);
    MoveEncoderPID(TestPara, -10, 2, 0.4, 45, true); //get first ring and move back 
    wait(0.5,sec);
    intakeLift.set(true);
    RunRoller(-80);
    MoveTimePID(TestPara, 50, 0.5, 0.2, 45, true);  //get second ring
    intakeLift.set(false);
    RunRoller(100);
    wait(100,msec);

    MoveEncoderPID(TestPara, -80, 15, 1, 45, true); //move back 
    MoveEncoderPID(TestPara, 100, 60, 0.4, -90, true);  
    wait(2,sec);
    RunRoller(0);

    

}
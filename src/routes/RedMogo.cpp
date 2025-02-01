#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void RedMogo(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5, 0.20, 0.1};   //initialize 1.5, 0.20, 0.1
    RunRoller(100);
    armMoveToAngle2(loadPosition, 100);
    Clamp.set(false);

    wait(300,msec);
    RunRoller(0);
    RunLift(-90);
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn face score alliance stake 
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 5, 0.2, 50, false); //move back 
    RunLift(70);
    MoveEncoderPID(TestPara, -80, 39, 0.4, 10, true); //move back to goal 
    RunLift(0);



    /*
    MoveEncoderPID(TestPara, 100, 4, 0.2, 33, true);
    RunRoller(0);
    armMoveToAngle(alliancePosition, 100);
    MoveEncoderPID(TestPara, -100, 31, 0.2, 33, true); //move back 
    RunLift(100);
    MoveEncoderPID(TestPara, -50, 20, 0.2, 0, false);//move face mogo
    RunLift(0);
    MoveEncoderPID(TestPara, -50, 4, 0.2, 0, true);
    
    Clamp.set(true);
    intakeLift.set(true);
    TurnMaxTimePID(TestPara, 40, 0.2, true); //turn face ring in front of alliance stake
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 32, 0.2, 40, true); //move foward
    intakeLift.set(false);
    MoveEncoderPID(TestPara, -90, 15, 1.0, 50, true); //move back 
    MoveEncoderPID(TestPara, 100, 29, 0.3, 0, true); //move to wall
    MoveEncoderPID(TestPara, 100, 55, 0.3, -88, true); //move to corner
    TurnMaxTimePID(TestPara, -43, 0.2, true);

    RunRoller(-70);
    MoveTimePID(TestPara, 60, 0.5, 0.2, -43, true); //push into corner
    RunRoller(100);
    MoveTimePID(TestPara, 80, 0.3, 0.2, -45, true);
    MoveEncoderPID(TestPara, -10, 3, 0.4, -45, true); //get first ring and move back 
    wait(1,sec);
    intakeLift.set(true);
    RunRoller(-80);
    MoveTimePID(TestPara, 50, 0.5, 0.2, -45, true);  //get second ring
    intakeLift.set(false);
    RunRoller(100);
    wait(300,msec);
    
    MoveEncoderPID(TestPara, -80, 10, 0.7, -70, true);
    MoveEncoderPID(TestPara, 90, 35, 0.4, 175, false); //move to get side ring 
    wait(100,msec);
    MoveEncoderPID(TestPara, 90, 55, 0.4, -45, true);
    TurnMaxTimePID(TestPara, 176, 0.8, true);
    Clamp.set(false);
    TurnMaxTimePID(TestPara, 0, 0.8, true);
    RunRoller(0);

    */


    // MoveEncoderPID(TestPara, -90, 15, 0.4, 90, false);
    // MoveEncoderPID(TestPara, 90, 36, 0.6, 105, true);
    // armMoveToAngle(ladderPosition, 100);
    // RunRoller(0);

}
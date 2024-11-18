#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Blue2GoalAwp() {
    PIDDataSet TestPara={1.5, 0.20, 0.1};   //initialize 1.5, 0.20, 0.1
    armMoveToAngle(loadPosition, 80); //set arm to loading position
    Clamp.set(false);
    wait(150,msec);
    RunRoller(100); //load ring in 
    TurnMaxTimePID(TestPara, -53, 0.3, true); //turn face alliance stake
    RunRoller(0);
    MoveEncoderPID(TestPara, 75, 19, 0.4, -53, true); //move foward
    armMoveToAngle(alliancePosition, 100); //score alliance
    MoveEncoderPID(TestPara, -90, 16, 0.2, -53, true); //move back 
    armMoveToAngle(resetPosition, 100); //reset arm 
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn face mogo 
    MoveEncoderPID(TestPara, -100, 20, 0.2, 0, false); //move to clamp mogo
    MoveEncoderPID(TestPara, -40, 19, 0.2, 0, true); 
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 90, 0.3, true); 
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 22, 0.3, 90, true); 
    wait(200,msec);
    TurnMaxTimePID(TestPara, -63, 0.3, true); 
    MoveEncoderPID(TestPara, 100, 50, 0.3, -63, false); 
    intakeLift.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 40, 23, 0.5, -63, true); 
    wait(150,msec);
    intakeLift.set(false);
    TurnMaxTimePID(TestPara, 47, 0.3, true);
    wait(150,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, 24, 0.3, 47, false);
    MoveEncoderPID(TestPara, -30, 10, 0.3, 47, true);

}
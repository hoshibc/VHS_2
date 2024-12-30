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

void BlueMogoElim() {
    PIDDataSet TestPara={1.5, 0.20, 0.1};  //initialize 1.5, 0.20, 0.1
    Clamp.set(false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 35, 0.3, -20, false); //rush mogo
    MoveEncoderPID(TestPara, 100, 24, 0.3, 0, true);
    RunRoller(0);
    arm.set(true);
    TurnMaxTimePID(TestPara, -90, 1.0, true);
    wait(150,msec);
    arm.set(false);
    TurnMaxTimePID(TestPara, -58, 0.3, true);
    MoveEncoderPID(TestPara, -50, 20, 0.3, -58, false);
    MoveEncoderPID(TestPara, -30, 10, 0.3, -58, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, -179, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 48, 0.3, -179, true);
    wait(150,msec);
    TurnMaxTimePID(TestPara, 90, 0.3, true);
    wait(1.5,sec);
    Clamp.set(false);
    TurnMaxTimePID(TestPara, -179, 0.3, true);
    MoveEncoderPID(TestPara, -100, 40, 0.3, 179, true);
    MoveEncoderPID(TestPara, -100, 43, 0.3, 90, true);
    TurnMaxTimePID(TestPara, -170, 0.3, true);
    MoveEncoderPID(TestPara, -60, 10, 0.3, -170, true);

} 

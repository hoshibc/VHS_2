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
    MoveEncoderPID(TestPara, 100, 48, 0.2, -20, true);
    arm.set(true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -80, 20, 0.2, 0, true);
    wait(150,msec);
    arm.set(false);
    TurnMaxTimePID(TestPara, -175, 0.4, true);
    MoveEncoderPID(TestPara, -40, 25, 0.2, -175, true);
    Clamp.set(true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, -20, 0.3, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 60, 0.2, -20, true);
    RunRoller(0);
    Clamp.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, 100, 15, 0.7, -60, true);
    TurnMaxTimePID(TestPara, -130, 0.2, true);
    MoveEncoderPID(TestPara, -40, 32, 0.5, -130, true);
    Clamp.set(true);
    wait(100,msec);

    MoveEncoderPID(TestPara, 80, 34, 0.5, -162, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 60, 20, 0.2, -85, false);
    MoveEncoderPID(TestPara, 60, 12, 0.2, -50, true);

    TurnMaxTimePID(TestPara, -135, 0.2, true);
    wait(300,msec);
    RunRoller(-70);
    MoveTimePID(TestPara, 70, 0.5, 0.2, -135, true); 
    RunRoller(100);
    MoveTimePID(TestPara, 80, 0.3, 0.2, -135, true);
    MoveEncoderPID(TestPara, -10, 3, 0.4, -135, true); //get first ring and move back 
    wait(1,sec);
    intakeLift.set(true);
    RunRoller(-80);
    MoveTimePID(TestPara, 50, 0.5, 0.2, -135, true);  //get second ring
    intakeLift.set(false);
    RunRoller(100);
    wait(100,msec);

    TurnMaxTimePID(TestPara, 175, 0.2, true);
    MoveEncoderPID(TestPara, -70, 28, 0.4, 175, true);
    arm.set(true);
    
    MoveEncoderPID(TestPara, 60, 19, 0.8, -178, true);
    TurnMaxTimePID(TestPara, 80, 0.5, true);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 45, 0.5, true);
    arm.set(false);
    RunRoller(0);
}

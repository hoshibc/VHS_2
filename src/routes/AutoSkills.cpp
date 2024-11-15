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

void AutoSkills() {
    PIDDataSet TestPara={1.5, 0.20, 0.1}; 
    Clamp.set(false);   
    RunRoller(100); //score alliance stake 
    wait(300,msec);
    MoveEncoderPID(TestPara, 75, 11, 0.4, 0, true); //move to get goal a
    RunRoller(0);
    TurnMaxTimePID(TestPara, -90, 0.4, true);
    MoveEncoderPID(TestPara, -50, 36, 0.4, -90, true); 
    Clamp.set(true);
    wait(150,msec);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a1
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 34, 0.4, 0, false); //move
    //TurnMaxTimePID(TestPara, 46, 0.3, true); 
    MoveEncoderPID(TestPara, 80, 48, 0.4, 45, false); //move turn
    //TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a2
    MoveEncoderPID(TestPara, 80, 20, 0.4, 0, true); //move
    wait(200,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -170, 0.4, true); //turn face wall stakes prep
    RunRoller(100);
    MoveEncoderPID(TestPara, 70, 25, 0.4, -170, true); //move
    TurnMaxTimePID(TestPara, 90, 0.4, true); //turn face wall stake 
    armMoveToAngle(loadPosition, 100); //raise arm
    MoveEncoderPID(TestPara, 40, 30, 0.4, 90, true); //move
    wait(400,msec); //wait for loading
    RunRoller(0);
    armMoveToAngle(ladderPosition, 80); //score wall stake
    wait(200,msec);
    MoveEncoderPID(TestPara, -70, 17, 0.4, 90, true); //move back
    armMoveToAngle(resetPosition, 100);
    TurnMaxTimePID(TestPara, -180, 0.3, true); //turn face ring a3, a4, a5, 
    RunRoller(100);
    MoveEncoderPID(TestPara, 85, 85, 1.0, -180, true); //drive
    TurnMaxTimePID(TestPara, 25, 0.3, true); //turn face ring a6



    // MoveEncoderPID(TestPara, 50, 35, 0.2, 0, false);
    // MoveEncoderPID(TestPara, 50, 35, 0.3, 90, false);
    // MoveEncoderPID(TestPara, 50, 35, 0.2, 180, false);
    // MoveEncoderPID(TestPara, 50, 35, 0.3, 270, true);
    // TurnMaxTimePID(TestPara, 0, 5, true);
    // TurnMaxTimePID(TestPara, -90, 5, true);
    // TurnMaxTimePID(TestPara, 179, 5, true);
    // TurnMaxTimePID(TestPara, 90, 5, true);
    // Clamp.set(true);
    // wait(5,sec);
    // TurnMaxTimePID(TestPara, 179, 5, true);
    // TurnMaxTimePID(TestPara, 270, 5, true);
    // Clamp.set(false);
    // wait(5,sec);
    // TurnMaxTimePID(TestPara, 0, 5, true);




    // RunRoller(100); 
    // Clamp.set(false);
    // wait(1,sec);
    // MoveEncoderPID(TestPara, 100, 9, 0.2, 0, true);
    // TurnMaxTimePID(TestPara, -90, 0.3, true);
    // MoveEncoderPID(TestPara, -100, 20, 0.2, -90, true);
    // MoveEncoderPID(TestPara, -50, 6, 0.2, -90, true);
    // Clamp.set(true);
    // TurnMaxTimePID(TestPara, 90, 1, true);
    // MoveEncoderPID(TestPara, 70, 30, 0.2, 90, true);
    // wait(200,msec);
    // TurnMaxTimePID(TestPara, -20, 0.4, true);
    // MoveEncoderPID(TestPara, -70, 20, 0.2, -20, true);
    // Clamp.set(false);
    // MoveEncoderPID(TestPara, 70, 23, 0.2, -20, true);






    
}
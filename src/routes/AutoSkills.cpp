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
// int wallPosition = 160;

void AutoSkills() {
    PIDDataSet TestPara={1.5, 0.20, 0.1}; 
    Clamp.set(false);   
    RunRoller(100); //score alliance stake 
    wait(200,msec);
    MoveEncoderPID(TestPara, 95, 11, 0.8, 0, true); //move to get mogo 1
    RunRoller(0);
    TurnMaxTimePID(TestPara, -90, 0.3, true);
    MoveEncoderPID(TestPara, -50, 36, 0.4, -90, true); 
    Clamp.set(true);
    wait(150,msec);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a1
    RunRoller(100);
    MoveEncoderPID(TestPara, 85, 33, 0.4, 0, false); //move
    MoveEncoderPID(TestPara, 95, 47, 0.4, 48, false); //move turn
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a2
    MoveEncoderPID(TestPara, 80, 26, 0.4, 0, true); //move
    wait(150,msec);
    MoveEncoderPID(TestPara, -80, 23, 0.7, 15, true); //move back
    //RunRoller(-10);
    TurnMaxTimePID(TestPara, 90, 0.4, true); //turn face right wall stake right
    armMoveToAngle(loadPosition, 100); //raise arm
    MoveEncoderPID(TestPara, 50, 31, 0.80, 90, true); //move to right wall stake 
    wait(500,msec); //wait for loading
    RunRoller(0);
    armMoveToAngle(wallPosition, 80); //score wall stake
    wait(150,msec);
    MoveEncoderPID(TestPara, -85, 12, 0.4, 90, true); //move back
    armMoveToAngle(resetPosition, 100);
    TurnMaxTimePID(TestPara, -180, 0.4, true); //turn face ring a3, a4, a5, 
    RunRoller(100);
    MoveEncoderPID(TestPara, 85, 74, 1.0, -180, false); //drive
    MoveEncoderPID(TestPara, 40, 20, 0.3, -180, true);
    wait(150,msec);
    MoveEncoderPID(TestPara, -85, 12, 1.0, 160, true); //drive back
    TurnMaxTimePID(TestPara, 90, 0.3, true); //turn face ring a6
    MoveEncoderPID(TestPara, 80, 18, 0.3, 90, true); //drive foward
    wait(100,msec);
    TurnMaxTimePID(TestPara, -10, 0.3, true); //turn mogo face corner 
    wait(100,msec);
    MoveEncoderPID(TestPara, -85, 21, 1.0, -10, true);
    RunRoller(-100);
    Clamp.set(false); // drop goal in corner
    MoveEncoderPID(TestPara, 90, 12, 1.0, -10, true);
    RunRoller(0);
    TurnMaxTimePID(TestPara, 90, 0.5, true); //turn face mogo 2
    MoveEncoderPID(TestPara, -100, 100, 0.3, 86, false); //fast move
    MoveEncoderPID(TestPara, -50, 30, 0.4, 86, true); //slower move
    Clamp.set(true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn face ring b1
    RunRoller(100);
    MoveEncoderPID(TestPara, 95, 25, 0.2, 0, true); //get ring b1
    TurnMaxTimePID(TestPara, 46, 0.2, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, 90, 25, 0.9, 46, false); //get ring b2 (inside ladder)
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 26, 0.3, 46, true);
    wait(150,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, -90, 38, 0.6, 46, false); //back away
    RunRoller(100);
    MoveEncoderPID(TestPara, -90, 12, 0.3, 46, true); // keep backing away 
    TurnMaxTimePID(TestPara, -90, 0.4, true);
    MoveEncoderPID(TestPara, 75, 28, 0.9, -90, true); //get ring b3
    MoveEncoderPID(TestPara, 75, 65, 0.9, -180, true); //get ring b4, b5
    wait(200, msec);
    TurnMaxTimePID(TestPara, 60, 0.4, true); //turn mogo b face corner
    MoveEncoderPID(TestPara, -80, 15, 0.9, 60, true); //move back 
    Clamp.set(false); //drop mogo 
    armMoveToAngle(loadPosition, 100); //raise arm to loading position
    MoveEncoderPID(TestPara, 90, 18, 0.9, 60, false); //move out 
    MoveEncoderPID(TestPara, 90, 95, 0.9, -27, true); //move turn face left wall stake ring 
    TurnMaxTimePID(TestPara, -90, 0.3, true); //turn face wall stake
    MoveEncoderPID(TestPara, 50, 10, 0.9, -90, true); //move foward 
    RunRoller(0);
    RunRoller(0);
    armMoveToAngle(ladderPosition, 100); //score CHANGE TO WALL POSITION !!!!!!!!!!!!!!!!!!!
    MoveEncoderPID(TestPara, -90, 10, 0.5, -90, true); //back up



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
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
// int ladderPosition = 120;
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
    MoveEncoderPID(TestPara, 85, 30, 0.4, 0, false); //move
    MoveEncoderPID(TestPara, 95, 47, 0.4, 48, false); //move turn
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a2
    MoveEncoderPID(TestPara, 80, 30, 0.4, 0, true); //move
    wait(175,msec);
    MoveEncoderPID(TestPara, -80, 26, 0.7, 18, true); //move back
    TurnMaxTimePID(TestPara, 90, 0.4, true); //turn face right wall stake right
    armMoveToAngle(loadPosition, 100); //raise arm
    MoveTimePID(TestPara, 50, 1.0, 0.6, 91, true); //move to right wall stake 
    wait(500,msec); //wait for loading
    RunRoller(0);
    armMoveToAngle(wallPosition, 100); //score wall stake
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
    MoveEncoderPID(TestPara, -100, 105, 0.3, 86, false); //fast move
    MoveEncoderPID(TestPara, -50, 30, 0.4, 86, true); //slower move
    Clamp.set(true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, 2, 0.3, true); //turn face ring b1
    RunRoller(100);
    MoveEncoderPID(TestPara, 95, 28, 0.2, 4, true); //get ring b1
    wait(120,msec);
    MoveEncoderPID(TestPara, 75, 31, 0.9, -91, true); //get ring b2
    MoveEncoderPID(TestPara, 75, 58, 0.9, -180, true); //get ring b3, b4
    wait(200, msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -49, 0.4, true); //turn face ring b5
    MoveEncoderPID(TestPara, 80, 20, 0.4, -49, true); //move
    wait(450,msec);
    //TurnMaxTimePID(TestPara, 15, 0.2, true);
    MoveEncoderPID(TestPara, -80, 18, 0.4, 15, true); //move back 
    Clamp.set(false); //drop mogo 
    RunRoller(-100);
    
    MoveEncoderPID(TestPara, 90, 18, 0.9, 60, false); //move out of corner
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 64, 0.9, -25, true); //move turn face left wall stake ring 
    armMoveToAngle(loadPosition, 100); //raise arm to loading position
    
    MoveEncoderPID(TestPara, 30, 23, 0.2, -25, true);
    wait(130,msec);






    TurnMaxTimePID(TestPara, -90, 0.3, true); //turn face wall stake
    MoveTimePID(TestPara, 50, 0.9, 0.6, -90, true);//move foward 
    RunRoller(0);
    armMoveToAngle(145, 100); //score CHANGE TO WALL POSITION !!!!!!!!!!!!!!!!!!!
    RunRoller(-100);
    MoveEncoderPID(TestPara, -90, 15, 0.5, -90, true); //back up
    armMoveToAngle(resetPosition, 100);
    TurnMaxTimePID(TestPara, 46, 0.3, true); //turn face ring c1
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 67, 0.5, 46, true); //move
    RunRoller(0);
    TurnMaxTimePID(TestPara, -145, 0.4, true); //turn face mogo 3
    MoveEncoderPID(TestPara, -40, 27, 0.7, -140, true); //move
    wait(100,msec);
    Clamp.set(true); //get mogo 3
    RunRoller(-100);
    wait(100,msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 60, 0.4, -89, true); //turn move ring c2 (corner)
    wait(100,msec);
    MoveEncoderPID(TestPara, -65, 10, 0.4, -87, true); //move back 
    MoveEncoderPID(TestPara, 70, 21, 0.4, -53, true); //turn move ring c3 (corner right)
    MoveEncoderPID(TestPara, -75, 51, 0.4, -50, true);  //move back 
    TurnMaxTimePID(TestPara, -110, 0.4, true); //turn ring alliance prep ring
    armMoveToAngle(loadPosition, 100);
    MoveEncoderPID(TestPara, 80, 35, 0.3, -110, true); //move foward
    MoveEncoderPID(TestPara, -80, 81.5, 0.3, -130, true); //move back a lot 
    wait(100,msec);
    TurnMaxTimePID(TestPara, 0, 0.4, true); // turn face
    RunRoller(0);
    MoveTimePID(TestPara, 50, 1, 0.5, 0, true);  //move align alliance stake 
    MoveEncoderPID(TestPara, -50, 8, 0.3, -3, true); // back up
    armMoveToAngle(alliancePosition, 100); //score alliace
    MoveEncoderPID(TestPara, -50, 5, 0.3, 0, true);
    armMoveToAngle(resetPosition, 100);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 125, 0.3, true); //turn face ring c4
    MoveEncoderPID(TestPara, 80, 49, 0.3, 125, true); //move
    TurnMaxTimePID(TestPara, 43, 0.3, true); //turn face ring c5 and corner
    arm.set(true);
    MoveEncoderPID(TestPara, 80, 40, 0.3, 43, false); //move foward

    MoveEncoderPID(TestPara, 45, 15, 0.3, 60, false);
    MoveEncoderPID(TestPara, 30, 13, 0.3, 30, true);
    wait(325,msec);
    TurnMaxTimePID(TestPara, 0, 0.2, true);
    TurnMaxTimePID(TestPara, -135, 0.3, true); //turn mogo face corner
    arm.set(false);
    MoveTimePID(TestPara, -40, 1.0, 0.2, -135, true); //move back to place goal
    RunRoller(0);
    Clamp.set(false); //drop 
    MoveEncoderPID(TestPara, 100, 23, 0.2, -135, false); //drift move to push 
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 82, 0.2, -58, false); //same change angle
    MoveEncoderPID(TestPara, 100, 10, 0.2, -85, true); //same chang angle
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, 20, 0.2, -85, false); //drift back 
    MoveEncoderPID(TestPara, -100, 50, 0.2, 20, true);
    TurnMaxTimePID(TestPara, -50, 0.2, true); //turn back face ladder
    armMoveToAngle(alliancePosition, 100); //climb deploy
    MoveTimePID(TestPara, -35, 1.7, 0.2, -50, true);//climb
    MoveEncoderPID(TestPara, 35, 10, 0.2, -50, true); //help climb reset
    armMoveToAngle(ladderPosition, 100); //move arm 

    //finish auto


    // TurnMaxTimePID(TestPara, -160, 0.4, true); //turn face mogo 3



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
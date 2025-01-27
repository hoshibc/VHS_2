#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// Test test (Chester)
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
// int wallPosition = 160;5
void AutoSkills() {
    PIDDataSet TestPara={1.5, 0.1, 0.2};  //old init 1.50, 0.20, 0.10
    // TurnMaxTimePID(TestPara, 90, 3, true);
    // TurnMaxTimePID(TestPara, 180, 3, true);
    // TurnMaxTimePID(TestPara, -90, 3, true);
    // TurnMaxTimePID(TestPara, 0, 3, true);
    

    armMoveToAngle2(ladderPosition, 100);
    wait(500,msec);
    armMoveToAngle2(alliancePosition, 100);
    wait(500,msec);
    armMoveToAngle2(resetPosition, 100);
    wait(500,msec);
    armMoveToAngle2(loadPosition, 100);
    wait(500,msec);
    armMoveToAngle2(ladderPosition, 100);
    wait(500,msec);
    armMoveToAngle2(alliancePosition, 100);
    wait(500,msec);
    armMoveToAngle2(resetPosition, 100);
    wait(500,msec);
    armMoveToAngle2(loadPosition, 100);
    wait(500,msec);





    // Clamp.set(false);   
    // RunRoller(100); //score alliance stake 
    // wait(200,msec);
    // MoveEncoderPID(TestPara, 95, 11, 0.8, 0, true); //move to get mogo 1
    // RunRoller(0);
    // TurnMaxTimePID(TestPara, -90, 0.3, true);
    // MoveEncoderPID(TestPara, -50, 36, 0.4, -90, true); 
    // Clamp.set(true);
    // wait(150,msec);
    // TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a1
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 85, 26, 0.4, 0, false); //move
    // MoveEncoderPID(TestPara, 95, 42, 0.4, 48, false); //move turn
    // TurnMaxTimePID(TestPara, 0, 0.3, true); //turn to ring a2
    // MoveEncoderPID(TestPara, 80, 32, 0.4, 0, true); //move
    // MoveEncoderPID(TestPara, -80, 25, 0.7, 18, true); //move back
    // TurnMaxTimePID(TestPara, 90, 0.4, true); //turn face right wall stake right
    // armMoveToAngle(loadPosition, 100); //raise arm
    // MoveTimePID(TestPara, 50, 1.1, 0.6, 91, true); //move to right wall stake 
    // wait(600,msec); //wait for loading
    // RunRoller(0);
    // armMoveToAngle(wallPosition, 100); //score wall stake
    // wait(100,msec);
    // MoveEncoderPID(TestPara, -85, 12, 0.4, 90, true); //move back from stake
    // armMoveToAngle(resetPosition, 100);
    // TurnMaxTimePID(TestPara, -180, 0.4, true); //turn face ring a3, a4, a5, 
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 65, 60 , 1.0, -180, false); //drive
    // MoveEncoderPID(TestPara, 40, 30 , 1.0, -180, true);
    // TurnMaxTimePID(TestPara, 45, 0.3, true);
    // MoveEncoderPID(TestPara, 70, 20, 0.3, 45, true); //drive foward
    // wait(600,msec);
    // TurnMaxTimePID(TestPara, -30, 0.3, true); //turn mogo face corner 
    // wait(100,msec);
    // MoveTimePID(TestPara, -90, 1, 0.2, -30, true);
    // RunRoller(-100);
    // Clamp.set(false); // drop goal in corner


    // MoveEncoderPID(TestPara, 90, 11, 1.0, -30, true);
    // RunRoller(0);
    // TurnMaxTimePID(TestPara, 90, 0.5, true); //turn face mogo 2
    // MoveEncoderPID(TestPara, -100, 93, 0.3, 90, false); //fast move
    // MoveEncoderPID(TestPara, -50, 30, 0.4, 90, true); //slower move
    // Clamp.set(true);
    // wait(100, msec);
    // TurnMaxTimePID(TestPara, 2, 0.3, true); //turn face ring b1
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 95, 28, 0.2, 4, true); //get ring b1
    // wait(100,msec);
    // MoveEncoderPID(TestPara, 80, 25, 0.9, -91, true); //get ring b2
    // MoveEncoderPID(TestPara, 50, 60, 0.9, 179, true); //get ring b3, b4
    // RunRoller(100);
    // TurnMaxTimePID(TestPara, -49, 0.4, true); //turn face ring b5
    // MoveEncoderPID(TestPara, 80, 19, 0.4, -49, true); //move
    // wait(600,msec);
    // //TurnMaxTimePID(TestPara, 15, 0.2, true);
    // MoveTimePID(TestPara, -90, 1, 0.2, 30, true); //push mogo in corner 
    // Clamp.set(false); //drop mogo 
    // RunRoller(-50);
    
    // MoveEncoderPID(TestPara, 90, 64, 0.9, 12, false); //move out of corner
    // RunRoller(100);
    // armMoveToAngle(loadPosition, 100); //raise arm to loading position
    // TurnMaxTimePID(TestPara, -90, 0.3, true);
    
    // MoveTimePID(TestPara, 50, 1.2, 0.3, -90, true);//move foward 
    // wait(600,msec);
    // RunRoller(0);
    // armMoveToAngle(145, 100); //score CHANGE TO WALL POSITION !!!!!!!!!!!!!!!!!!!
    // RunRoller(-100);
    // MoveEncoderPID(TestPara, -90, 15, 0.5, -90, true); //back up
    // armMoveToAngle(resetPosition, 100);
    // TurnMaxTimePID(TestPara, 46, 0.3, true); //turn face ring c1
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 80, 67, 0.5, 46, true); //move
    // RunRoller(0);
    // TurnMaxTimePID(TestPara, -138, 0.5, true); //turn face mogo 3
    // MoveEncoderPID(TestPara, -40, 27, 0.7, -138, true); //move
    // Clamp.set(true); //get mogo 3
    // RunRoller(-100);
    // wait(200,msec);
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 80, 72, 0.4, -93, true); //turn move ring c2 (corner)
    // RunRoller(-70);
    // wait(100,msec);
    // RunRoller(100);
    // MoveEncoderPID(TestPara, -65, 10, 0.4, -93, true); //move back 
    // MoveEncoderPID(TestPara, 70, 15, 0.4, -53, true); //turn move ring c3 (corner right)
    // MoveEncoderPID(TestPara, -75, 34, 0.8, -50, true);  //move back 
    // TurnMaxTimePID(TestPara, -110, 0.4, true); //turn ring alliance prep ring
    // armMoveToAngle(loadPosition, 100);
    // MoveEncoderPID(TestPara, 80, 35, 0.3, -110, true); //move foward
    // MoveEncoderPID(TestPara, -80, 87, 0.3, -120, true); //move back a lot 
    // wait(100,msec);
    // TurnMaxTimePID(TestPara, 0, 0.4, true); // turn face
    // RunRoller(0);

    // MoveTimePID(TestPara, 50, 1.2, 0.7, 0, true);  //move align alliance stake
    // MoveEncoderPID(TestPara, -50, 6, 0.3, 0, true); // back up
    // armMoveToAngle(alliancePosition, 100); //score alliace  
    // MoveEncoderPID(TestPara, -50, 5, 0.3, 0, true);
    // armMoveToAngle(wallPosition, 100);
    // RunRoller(100);
    // TurnMaxTimePID(TestPara, 130, 0.3, true); //turn face ring c4
    // MoveEncoderPID(TestPara, 80, 45, 0.3, 130, true); //move
    // TurnMaxTimePID(TestPara, 20, 0.3, true); //turn face ring c5 and corner
    // MoveEncoderPID(TestPara, 90, 30, 0.3, 20, false); //move foward
    // MoveEncoderPID(TestPara, 90, 20, 0.3, 50, true);
    // MoveEncoderPID(TestPara, -95, 18, 0.3, 30, true);
    // MoveEncoderPID(TestPara, 90, 24, 0.3, 90, true);
    // TurnMaxTimePID(TestPara, -135, 0.3, true); //turn mogo face corner
    // wait(200,msec);

    // MoveTimePID(TestPara, -80, 1, 0.6, -135, true); //move back to place goal    
    // Clamp.set(false); //drop 
    // RunRoller(0);
    // MoveEncoderPID(TestPara, 100, 15, 0.2, -135, false); //drift move to push 
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 100, 205, 0.2, -70, true); //same change angle
    // RunRoller(-50);
    // MoveEncoderPID(TestPara, -100, 78, 0.3, -43, false);
    // RunRoller(0);
    // MoveTimePID(TestPara, -40, 1.3, 0.8, -43, true); //move to hang
    // MoveTimePID(TestPara, 30, 0.6, 0.3, -43, true);
}    
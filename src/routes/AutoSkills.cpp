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
    PIDDataSet TestPara={1.5, 0.2, 0.15};  //old init 1.50, 0.20, 0.10
    Clamp.set(false);
    RunLift(-100); //score alliance
    wait(280,msec);
    RunLift(0);
    double curAngle1 = Gyro.heading();
    MoveEncoderPID(TestPara, -35, 25, 0.3, curAngle1, true); //move back to clamp goal 
    Clamp.set(true);
    wait(100,msec);
    intakeDrop.set(true);
    RunLift(95);
    TurnMaxTimePID(TestPara, 0, 0.4, true); //turn face ring a1
    RunLift(0);
    RunRoller(100);
    MoveEncoderPID(TestPara, 90, 23, 0.3, 0, true);
    MoveEncoderPID(TestPara, 80, 110, 0.5, 24, true); // move face ring a2
    armMoveToAngle2(loadPosition, 100); // load arm
    MoveEncoderPID(TestPara, -60, 32, 0.3, 17, true); //move back a bit for wall stakes 
    TurnMaxTimePID(TestPara, 90, 0.4, true); //face wall stakes 
    RunRoller(-20);
    armMoveToAngle2(holdPosition, 100); //raise arm 
    wait(50,msec);
    RunRoller(100);
    MoveTimePID(TestPara, 40, 1.0, 0.3, 90, true); //move in to wall stake 
    RunLift(-100);
    wait(230,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -50, 13, 0.3, 90, true); // move back 
    RunLift(100);
    TurnMaxTimePID(TestPara, 180, 0.4, false); //turn face rings a3, a4, a5
    RunLift(0);
    MoveEncoderPID(TestPara, 50, 120, 0.5, 178, true); //move
    MoveEncoderPID(TestPara, 60, 35, 0.5, 45, true); // move face intake ring a6
    wait(250,msec);
    MoveTimePID(TestPara, -40, 1.5, 0.3, -35, true); // put goal in corner 
    RunRoller(-100);
    Clamp.set(false);


    TurnMaxTimePID(TestPara, -8, 0.3, true); // turn face blue alliace stake ring 
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 145, 0.3, -8, false); //move 
    armMoveToAngle2(loadPosition, 100); //raise arm 
    MoveEncoderPID(TestPara, 50, 25, 0.8, -8, true); //slow move 
    wait(100,msec);
    TurnMaxTimePID(TestPara, 123, 0.5, false); //turn face goal 
    MoveEncoderPID(TestPara, -44, 50, 0.8, 123, true); //move back to clamp 
    Clamp.set(true); //clmap goal 
    leftArm.set(true); //extend arm for sweep 
    wait(50,msec);
    MoveEncoderPID(TestPara, 50, 60, 0.5, 85, true); //move foward
    TurnMaxTimePID(TestPara, -135, 0.6, true); //sweep corner 
    RunRoller(0);
    leftArm.set(false);
    MoveTimePID(TestPara, -40, 0.9, 0.3, -135, true); //place goal in negative
    Clamp.set(false);




    MoveEncoderPID(TestPara, 80, 25, 0.5, -135, true); //move out 
    TurnMaxTimePID(TestPara, 90, 0.5, false); //turn face middle goal 
    MoveEncoderPID(TestPara, -40, 70, 0.3, 90, true); //move
    Clamp.set(true);
    wait(50,msec);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn face alliance stake 
    MoveTimePID(TestPara, 50, 0.9, 0.3, 0, true); //move in 
    double curAngle2 = Gyro.heading();
    MoveEncoderPID(TestPara, -30, 7, 0.3, curAngle2, true); //move back 
    RunLift(-100); //score 
    wait(450, msec);
    RunLift(0);
    


    // Clamp.set(true);
    // MoveTimePID(TestPara, 50, 0.9, 0.3, 0, true);



    MoveEncoderPID(TestPara, -80, 6, 0.3, 0, true); //move back after scoring 
    RunRoller(100);
    RunLift(95);
    TurnMaxTimePID(TestPara, 130, 0.4, false); //turn face ring b1
    RunLift(0);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 53, 0.3, 130, true); //move 
    TurnMaxTimePID(TestPara, -135, 0.5, true); //turn face ladder mid
    wait(340,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 80, 110, 0.3, -135, false); //move
    RunRoller(100);
    MoveEncoderPID(TestPara, 40, 50, 0.3, -138, false); //move get rings b2, b3, 
    MoveEncoderPID(TestPara, 35, 20, 0.3, -138, false);// ring b4
    MoveEncoderPID(TestPara, 35, 25, 0.3, -164, true); //get ring b5
    wait(200,msec);
    TurnMaxTimePID(TestPara, -63, 0.4, false);
    MoveEncoderPID(TestPara, 35, 25, 0.3, -63, true); //get ring b6
    wait(150,msec);
    MoveTimePID(TestPara, -70, 0.8, 0.3, 18, true); //push in corner
    RunRoller(0);
    Clamp.set(false);




    RunRoller(-60);
    MoveEncoderPID(TestPara, 55, 10, 0.3, 12, false); //move out 
    RunRoller(100);
    armMoveToAngle2(loadPosition, 100);
    MoveEncoderPID(TestPara, 55, 50, 0.3, 12, true); //move to get ring after runnign intake 
    TurnMaxTimePID(TestPara, -38, 0.4, true); //turn face goal 
    MoveEncoderPID(TestPara, -40, 63, 0.3, -38, true); //move back to clamp goal 
    Clamp.set(true); //clamp third goal 
    RunRoller(-20);
    armMoveToAngle2(holdPosition, 100); //raise arm to hold ring
    MoveEncoderPID(TestPara, 80, 81, 0.3, -26, true); //move to wall stake
    TurnMaxTimePID(TestPara, -90, 0.4, false);
    RunRoller(100);
    MoveTimePID(TestPara, 50, 0.9, 0.3, -90, true); //move into wall stakes and get ring c1
    RunLift(-100);



    wait(175,msec); //MAKE THIS INTO 230 MSECS



    RunLift(0);
    MoveEncoderPID(TestPara, -50, 16, 0.3, -90, true); // move back 
    RunLift(100);
    TurnMaxTimePID(TestPara, 0, 0.4, false); //turn face ring c2
    RunLift(0);
    MoveEncoderPID(TestPara, 45, 42, 0.3, 0, true); //move get ring c2
    TurnMaxTimePID(TestPara, 90, 0.4, false);  //face ring c3
    MoveEncoderPID(TestPara, 45, 37, 0.3, 90, true); //get ring c3
    TurnMaxTimePID(TestPara, -48, 0.4, false); //face ring c4
    MoveEncoderPID(TestPara, 45, 67, 0.3, -48, true); //get ring c4 (first one in the corner)

    MoveEncoderPID(TestPara, 45, 25, 0.3, -5, true); //get ring c5
    MoveEncoderPID(TestPara, -50, 18, 0.3, -12, true); //move back from c5
    TurnMaxTimePID(TestPara, -84, 0.4, false); //turn face ring c6
    MoveEncoderPID(TestPara, 45, 20, 0.3, -84, true); //move get ring c6
    TurnMaxTimePID(TestPara, 15, 0.4, false); //turn face corner
    MoveEncoderPID(TestPara, -60, 20, 0.3, 15, true); //back up
    leftArm.set(true); 
    RunRoller(0);

    
    MoveTimePID(TestPara, 40, 1.2, 0.3, -5, true);
    TurnMaxTimePID(TestPara, 135, 0.8, true);
    MoveTimePID(TestPara, -80, 1.2, 0.2, 150, true);
    Clamp.set(false);
    RunRoller(-50);
    leftArm.set(false);
    MoveEncoderPID(TestPara, 80, 40, 0.5, 120, true);
    RunLift(-90);
    RunRoller(0);
    TurnMaxTimePID(TestPara, -45, 0.3, true);
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 60, 0.5, -45, true);
    
}    
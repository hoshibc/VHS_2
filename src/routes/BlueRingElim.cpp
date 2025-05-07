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


// color sort TRUE if SORTING RED, set to FALSE is SORTING BLUE 

// extern void ColourSort(int intakeSpeed, bool SortRed);
// extern void StartColourSort(int speed, bool IssRed);
// extern void stopColourSort(int speed);
// extern void toggleColourSort(int Speed, bool IssRed);
// extern int colourSortThreadFn(void* arg);

void BlueRingElim() {
    PIDDataSet TestPara={1.5, 0.2, 0.1}; 
    intakeDrop.set(true);
    Clamp.set(false);
    arm.set(true);
    StartColourSort(100, true);
    MoveEncoderPID(TestPara, 100, 78, 0.3, 20, true);// rush
    wait(200,msec);
    stopColourSort(30);
    MoveEncoderPID(TestPara, -50, 50, 0.8, 48, true);// move back 
    
    Clamp.set(true);
    wait(100,msec);
    StartColourSort(100, true);// move foward
    arm.set(false);
    TurnMaxTimePID(TestPara, 80, 0.3, true);// turn face 3 rings
    
    
    
    MoveEncoderPID(TestPara, 55, 48, 0.6, 80, true);// move intake 3 rings 
    MoveEncoderPID(TestPara, 90, 48, 0.3, 180, false); //turn move toward corner


    MoveTimePID(TestPara, 43, 1.5, 0.6, 135, true); //move in
    MoveEncoderPID(TestPara, -55, 13, 0.3, 135, true); //move out 

    TurnMaxTimePID(TestPara, -93, 0.5, true);
    
  
    MoveEncoderPID(TestPara, 90, 51, 0.3, -94, true); //move to preload
    wait(400, msec);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 45, 22, 0.2, -94, true); //move to alliance ring 
    armMoveToAngle2(loadPosition, 100);
    leftArm.set(true);
    TurnMaxTimePID(TestPara, -180, 0.5, true); //turn face stake and push away rings
    intakeDrop.set(true);
    leftArm.set(false);
    
    MoveTimePID(TestPara, 40, 1, 0.3, -180, true); //move in alliance stake 
    
    stopColourSort(0);
    double currAngle = Gyro.heading();
    RunLift(-90);
    MoveEncoderPID(TestPara, -65, 6, 0.2, currAngle, true); //score n move back 
    wait(75,msec);
    RunLift(0);
    
    MoveEncoderPID(TestPara, -100, 15, 0.3, 178, true); //move back 
    intakeDrop.set(true);
    RunLift(100);
    StartColourSort(100, true);
    TurnMaxTimePID(TestPara, -105, 0.3, false);
    RunLift(0);
    MoveEncoderPID(TestPara, 80, 45, 0.3, -105, false);
    


    //AUTON FOR PILONS

    // intakeDrop.set(true);
    // Clamp.set(false);
    // leftArm.set(true);
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 100, 73, 0.3, 20, true);// rush
    // wait(200,msec);
    // RunRoller(0);
    // MoveEncoderPID(TestPara, -50, 50, 0.8, 44, true);// move back 
    
    // Clamp.set(true);
    // wait(100,msec);
    // leftArm.set(false);
    // TurnMaxTimePID(TestPara, 80, 0.3, true);// turn face 3 rings
    
    
    // RunRoller(100);// move foward
    // MoveEncoderPID(TestPara, 55, 50, 0.6, 80, true);// move intake 3 rings 
    // MoveEncoderPID(TestPara, 90, 40, 0.3, 180, false); //turn move toward corner

    // RunRoller(100);
    // MoveTimePID(TestPara, 43, 1.5, 0.6, 135, true); //move in
    
    // MoveEncoderPID(TestPara, -30, 5, 0.4, 135, true); //move back 
    // intakeDrop.set(false);
    // wait(100,msec);
    // MoveTimePID(TestPara, 35, 0.8, 0.6, 135, true); //move in again
    // intakeDrop.set(true);
    // MoveEncoderPID(TestPara, -55, 13, 0.3, 135, true); //move out 




    // TurnMaxTimePID(TestPara, -93, 0.5, true);
    
    // RunRoller(100);
    // MoveEncoderPID(TestPara, 90, 51, 0.3, -94, true); //move to preload
    // wait(600, msec);
    
    // RunRoller(0);


    // RunLift(0);
    // MoveEncoderPID(TestPara, 80, 50, 0.3, -98, false);

}
    
#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);


// color sort TRUE if SORTING RED, set to FALSE is SORTING BLUE 

// extern void ColourSort(int intakeSpeed, bool SortRed);
// extern void StartColourSort(int speed, bool IssRed);
// extern void stopColourSort(int speed);
// extern void toggleColourSort(int Speed, bool IssRed);
// extern int colourSortThreadFn(void* arg);


void BlueRing() {
    PIDDataSet TestPara={1.5, 0.2, 0.1}; 
    intakeDrop.set(true);
    Clamp.set(false);
    arm.set(true);
    StartColourSort(100, true);
    MoveEncoderPID(TestPara, 100, 88, 0.3, 20, true);// rush
    wait(100,msec);
    stopColourSort(20);
    MoveEncoderPID(TestPara, -50, 60, 0.8, 48, true);// move back 
    
    Clamp.set(true);
    wait(100,msec);
    arm.set(false);
    StartColourSort(100, true);// move foward
    TurnMaxTimePID(TestPara, 80, 0.3, true);// turn face 3 rings
    
    
    
    MoveEncoderPID(TestPara, 55, 47, 0.6, 80, true);// move intake 3 rings 
    MoveEncoderPID(TestPara, 90, 45, 0.3, 180, false); //turn move toward corner


    MoveTimePID(TestPara, 55, 1.5, 0.6, 136, true); //move in
    MoveEncoderPID(TestPara, -55, 18, 0.3, 135, true); //move out 

    TurnMaxTimePID(TestPara, -93, 0.5, true);

    MoveEncoderPID(TestPara, 75, 56, 0.3, -89, true); //move to preload
    wait(400, msec);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 40, 30, 0.2, -89, true); //move to alliance ring 
    armMoveToAngle2(loadPosition, 100);
    leftArm.set(true);
    TurnMaxTimePID(TestPara, -180, 0.5, true); //turn face stake and push away rings
    intakeDrop.set(true);
    leftArm.set(false);
    
    MoveTimePID(TestPara, 40, 1.2, 0.3, -180, true); //move in alliance stake 
    
    stopColourSort(0);
    double currAngle = Gyro.heading();
    RunLift(-90);
    MoveEncoderPID(TestPara, -65, 6, 0.2, currAngle, true); //score n move back 

    RunLift(0);
    
    MoveEncoderPID(TestPara, -100, 14, 0.3, 170, true); //move back 
    intakeDrop.set(true);
    RunLift(60);
    TurnMaxTimePID(TestPara, -5, 0.5, true);
    RunLift(-60);
    MoveEncoderPID(TestPara, 50, 10, 0.6, -5, true);
    RunLift(0);
}

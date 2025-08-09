#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

// global int loadPosition = 20;
// global int alliancePosition = 190;
// global int resetPosition = 0;
// global int holdPosition = 45;
// global int ladderPosition = 120;


// color sort TRUE if SORTING RED, set to FALSE is SORTING BLUE 

// extern void ColourSort(int intakeSpeed, bool SortRed);
// extern void StartColourSort(int speed, bool IssRed);
// extern void stopColourSort(int speed);
// extern void toggleColourSort(int Speed, bool IssRed);
// extern int colourSortThreadFn(void* arg);

void RedRing() {
    PIDDataSet TestPara={1.5, 0.2, 0.1}; 
    intakeDrop.set(true);
    Clamp.set(false);
    leftArm.set(true);
    StartColourSort(100, false);
    MoveEncoderPID(TestPara, 100, 88, 0.3, -21, true);// rush
    wait(100,msec);
    stopColourSort(20);
    MoveEncoderPID(TestPara, -45, 60, 0.8, -48, true);// move back 
    
    Clamp.set(true);
    wait(100,msec); 
    leftArm.set(false);
    StartColourSort(100, false);// move foward
    TurnMaxTimePID(TestPara, -80, 0.3, true);// turn face 3 rings
    
    
    
    MoveEncoderPID(TestPara, 55, 48, 0.6, -80, true);// move intake 3 rings 
    MoveEncoderPID(TestPara, 90, 47, 0.3, -180, false); //turn move toward corner

    
    MoveTimePID(TestPara, 70, 1.8, 0.4, -135, true); //move in
    MoveEncoderPID(TestPara, -55, 18, 0.3, -135, true); //move out 

    TurnMaxTimePID(TestPara, 93, 0.5, true);
    
    
    MoveEncoderPID(TestPara, 90, 56, 0.3, 91, true); //move to preload
    wait(400, msec);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 40, 30, 0.2, 91, true); //move to alliance ring 
    armMoveToAngle2(loadPosition, 100);
    intakeDrop.set(true);
    arm.set(true);
    TurnMaxTimePID(TestPara, 180, 0.5, true); //turn face stake and push away rings
    
    arm.set(false);
    
    MoveTimePID(TestPara, 40, 1, 0.3, 180, true); //move in alliance stake 
    

    double currAngle = Gyro.heading();
    stopColourSort(0);
    RunLift(-90);
    MoveEncoderPID(TestPara, -65, 6, 0.2, currAngle, true); //score n move back 
    wait(75,msec);
    RunLift(0);
    
    MoveEncoderPID(TestPara, -100, 12, 0.3, -178, true); //move back 
    intakeDrop.set(true);
    RunLift(60);
    TurnMaxTimePID(TestPara, 5, 0.5, true);
    RunLift(-65);
    MoveEncoderPID(TestPara, 70, 10, 0.6, 6, true);
    RunLift(0);
}
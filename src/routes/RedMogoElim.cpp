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

void RedMogoElim(){
    PIDDataSet TestPara={1.5, 0.20, 0.1};
    intakeDrop.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 30, 0.3, 0, false); //move back 
    MoveEncoderPID(TestPara, -20, 20, 0.3, 0, true); //move clamp goal 
    Clamp.set(true);
    // TurnMaxTimePID(TestPara, 35, 0.2, true); //turn to alliance ring
    // //intakeDrop.set(false);

    // MoveEncoderPID(TestPara, 80, 20, 0.6, 35, true); //move 
    // arm.set(true);
    // wait(50,msec);
    // MoveEncoderPID(TestPara, -70, 30, 0.6, 50, true); //move back 
    // wait(100,msec);
    // TurnMaxTimePID(TestPara, 110, 0.35, true); //turn face ladder 
    // arm.set(false);
    TurnMaxTimePID(TestPara, 131, 0.35, true);
    arm.set(true);
    MoveEncoderPID(TestPara, 45, 55, 0.3, 137.5, true); //get ring under ladder 
    MoveEncoderPID(TestPara, -70, 32, 0.3, 150, true); //move back 
    StartColourSort(100, false);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -125, 0.4, true); //turn 
    arm.set(false);
    
    MoveEncoderPID(TestPara, 100, 55, 0.3, -102, true); //move intake 2 rings 
    MoveEncoderPID(TestPara, 100, 55, 0.6, -20, true); //move to corner 

    MoveTimePID(TestPara, 55, 1.2, 0.4, -40, true); //move in
    MoveEncoderPID(TestPara, -30, 7, 0.4, -45, true); //move back 
    intakeDrop.set(false);
    wait(30,msec);
    MoveTimePID(TestPara, 50, 0.5, 0.4, -45, true); //move in again
    intakeDrop.set(true);
    MoveEncoderPID(TestPara, -40, 30, 0.4, 15, true); //move back 
    leftArm.set(true);
    TurnMaxTimePID(TestPara, 0, 0.3, true); //turn 
    stopColourSort(0);
    MoveEncoderPID(TestPara, 50, 21, 0.3, -6, true); //move back foward to sweep 
    TurnMaxTimePID(TestPara, 150, 0.6, true);
    leftArm.set(false);
   
    MoveTimePID(TestPara, -50, 0.6, 0.6, 135, true); 
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 8, 0.3, 120, false);
    
    MoveEncoderPID(TestPara, -70, 35, 0.3, 0, true);
    
} 
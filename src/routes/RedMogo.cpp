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

void RedMogo(){
    PIDDataSet TestPara={1.5, 0.2, 0.1};   //initialize 1.5, 0.20, 0.1
    intakeDrop.set(true);
    Clamp.set(false);

    double curAngle1 = Gyro.heading();
    RunLift(-90);

    MoveEncoderPID(TestPara, 40, 3, 0.2, curAngle1, true);
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 38, 0.2 , curAngle1, true);
    RunLift(100);
    MoveEncoderPID(TestPara, -20, 15, 0.2 , curAngle1, true);
    RunLift(0);
    Clamp.set(true);
    

    
    TurnMaxTimePID(TestPara, 50, 0.3, true); //turn face alliance stake ring
    StartColourSort(100, false);
    intakeDrop.set(false);
    MoveEncoderPID(TestPara, 45, 39, 0.2, 50, true); //move to get
    intakeDrop.set(true);

    MoveEncoderPID(TestPara, -70, 14, 1.0, 50, true); //move back 
    MoveEncoderPID(TestPara, 80, 26, 0.3, -10, true); //move to wall
    MoveEncoderPID(TestPara, 100, 72, 0.3, -90, true); //move to corner
    TurnMaxTimePID(TestPara, -45, 0.2, true);


    //corner grab sequence
    MoveTimePID(TestPara, 45, 1.4, 0.6, -45, true); //move in
    MoveEncoderPID(TestPara, -30, 7, 0.4, -45, true); //move back 
    intakeDrop.set(false);
    wait(100,msec);
    MoveTimePID(TestPara, 35, 0.5, 0.4, -45, true); //move in again
    intakeDrop.set(true);
    MoveEncoderPID(TestPara, -80, 55, 0.3, -90, true); //move out 
    wait(0.5,sec);
    stopColourSort(-20);

    TurnMaxTimePID(TestPara, -148, 0.4, true);
    StartColourSort(100, true);
    MoveEncoderPID(TestPara, 100, 50, 0.3, -148, true);
    TurnMaxTimePID(TestPara, 110, 0.5, true);
    MoveEncoderPID(TestPara, 80, 45, 0.3, 110, true);
    stopColourSort(-80);
    wait(250,msec);
    RunLift(0);
    wait(750,msec);
    stopColourSort(0);
}
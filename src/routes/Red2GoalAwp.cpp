#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red2GoalAwp() {
    PIDDataSet TestPara={1.5, 0.2, 0.1};   //initialize 1.5, 0.20, 0.1

    Clamp.set(false);
    intakeDrop.set(true);
    double curAngle1 = Gyro.heading();
    RunLift(-90);

    MoveEncoderPID(TestPara, 40, 2, 0.2, curAngle1, true);
    RunLift(0);
    MoveEncoderPID(TestPara, -80, 35, 0.2 , curAngle1, true);
    RunLift(100);
    MoveEncoderPID(TestPara, -20, 13, 0.2 , curAngle1, true);
    RunLift(0);
    Clamp.set(true);


    
    TurnMaxTimePID(TestPara, 90, 0.4, false); //turn to ring stack 
    RunRoller(100); //start intake 
    MoveEncoderPID(TestPara, 100, 35, 0.5, 90, true);
    
    MoveEncoderPID(TestPara, 100, 43, 0.3, 0, false); //turn move toward corner

    RunRoller(100);
    MoveTimePID(TestPara, 45, 1.5, 0.6, 45, true); //move in
    

    MoveEncoderPID(TestPara, -80, 10, 0.3, 45, true); //move out 




    TurnMaxTimePID(TestPara, -90, 0.5, true); //turn to alliance stack 
    RunRoller(90);
    MoveEncoderPID(TestPara, 90, 65, 0.3, -90, true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 50, 52, 0.3, -90, true);
    RunRoller(0);
    TurnMaxTimePID(TestPara, 0, 0.4, false);
    MoveEncoderPID(TestPara, -40, 48, 0.3, 0, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, -80, 0.5, false);
    RunRoller(100);
    MoveEncoderPID(TestPara, 80, 35, 0.3, -80, true);
    TurnMaxTimePID(TestPara, 90, 0.6, false);
    MoveEncoderPID(TestPara, 80, 56, 0.3, 90, true);
    RunLift(-100);
    wait(360,msec);
    RunLift(0);
    RunRoller(0);

}
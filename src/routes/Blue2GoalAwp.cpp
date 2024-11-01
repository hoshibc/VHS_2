#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Blue2GoalAwp() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    Clamp.set(false);
    MoveEncoderPID(TestPara, -70, 25, 0.2, 0, true); 
    Clamp.set(true); //clamp the first goal 
    wait(100, msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 30, 0.2, 0, true); 
    TurnMaxTimePID(TestPara, -100, 0.4, true);
    MoveEncoderPID(TestPara, 45, 22, 0.2, -100, true); //move to push other bot 
    MoveEncoderPID(TestPara, -100, 5, 0.2, -90, true);
    wait(350,msec);
    TurnMaxTimePID(TestPara, 110, 0.7, true);
    intakeLift.set(true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 100, 22, 0.2, 100, true);
    intakeLift.set(false);
    wait(50,msec);
    TurnMaxTimePID(TestPara, -53, 0.4, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -90, 54, 0.3, -53, true);
    Clamp.set(true);
    wait(5,msec);
    TurnMaxTimePID(TestPara, 89, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 32, 0.2, 89, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -110, 0.5, true);
    MoveEncoderPID(TestPara, 60, 45, 0.2, -110, true);
    RunLift(-100);
    wait(350,msec);
    RunLift(0);
    RunRoller(0);


 
    
    
}
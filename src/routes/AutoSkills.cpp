#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AutoSkills() {
    PIDDataSet TestPara={3.0, 0.25, 0.15}; //initialize 3.0, 0.25, 0.15
    MoveEncoderPID(TestPara, 50, 35, 0.2, 0, false);
    MoveEncoderPID(TestPara, 50, 35, 0.3, 90, false);
    MoveEncoderPID(TestPara, 50, 35, 0.2, 180, false);
    MoveEncoderPID(TestPara, 50, 35, 0.3, 270, true);
    TurnMaxTimePID(TestPara, 0, 5, true);
    Clamp.set(true);
    wait(5,sec);
    TurnMaxTimePID(TestPara, 179, 5, true);
    TurnMaxTimePID(TestPara, 270, 5, true);
    Clamp.set(false);
    wait(5,sec);
    TurnMaxTimePID(TestPara, 0, 5, true);




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
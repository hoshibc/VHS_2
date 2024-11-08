#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
// PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AutoSkills() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    RunRoller(100); 
    Clamp.set(false);
    wait(1,sec);
    MoveEncoderPID(TestPara, 100, 9, 0.2, 0, true);
    TurnMaxTimePID(TestPara, -90, 0.3, true);
    MoveEncoderPID(TestPara, -100, 20, 0.2, -90, true);
    MoveEncoderPID(TestPara, -50, 6, 0.2, -90, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 90, 1, true);
    MoveEncoderPID(TestPara, 70, 30, 0.2, 90, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -20, 0.4, true);
    MoveEncoderPID(TestPara, -70, 20, 0.2, -20, true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 70, 23, 0.2, -20, true);






    
}
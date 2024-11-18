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

void BlueMogoElim() {
    PIDDataSet TestPara={1.5, 0.20, 0.1}; 
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 20, 0.3, 0, false);
    //TurnMaxTimePID(TestPara, -29, 0.3, true);
    MoveEncoderPID(TestPara, -100, 37, 0.1, -27, false);
    MoveEncoderPID(TestPara, -20, 12, 0.1, -27, true);
    wait(100,msec);
    Clamp.set(true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 95, 6, 0.1, -80, false);
    Clamp.set(false);
    MoveEncoderPID(TestPara, 95, 5, 0.1, -80, true);
    wait(100,msec);
    TurnMaxTimePID(TestPara, 133, 0.5, true);
    MoveEncoderPID(TestPara, -75, 13, 0.3, 133, true);
    Clamp.set(true);
    TurnMaxTimePID(TestPara, 100, 0.3, true);



    //MoveEncoderPID(TestPara, -20, 12, 0.1, -27, true);

}
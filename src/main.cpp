/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                 */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

//#include "STDLib.cpp"
#include "vex.h"

#include "screen_gui.hpp"
#include "movement.hpp"
#include "routes/routes.hpp"

#include "iostream"

#include "cmath"
using namespace vex;

// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void OnReleasePageFlip() {
  if(AutoSelectorVal<=6) AutoSelectorVal+=6;
  else AutoSelectorVal+=-6;
  
          //AutoSelectorVal=5;
}

 


bool SP;
bool EXIT;
void pre_auton(void) {
  LiftSensor.resetPosition();
  LiftSensor.setPosition(0,degrees);
  EXIT = false;
  Clamp.set(false);
  PX = 0;
  JX = 0;
  AutoSelectorVal = 0;
  SP = false;
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Gyro.calibrate();

  //Ensure Robot Launch Position is set before auto proceeds, once plugged into field control,
  //start program and do not temper bot under all circumstances

  //1. IF ANY ADJUSTMENT IS NEEDED, QUIT PROGRAM, THEN ADJUST, RESTART PROGRAM AFTER ADJUSTMENTS COMPLETED
  //2. DO NOT START PROGRAM BEFORE PLUGGING IN FIELD CONTROL, THIS MAY DISABLE AUTO
  //3. ONLY SIGNAL JUDGES TO BEGIN MATCH AFTER THE ZEROING PROMPT ON SCREEN HAS CLEARED

  //Print precautionary message
  Brain.Screen.drawRectangle(0,0,500,500);

  Brain.Screen.setFont(monoXL); 
  Brain.Screen.setPenColor("#39FF14");  
  Brain.Screen.setCursor(2,10); 
  Brain.Screen.print("FLIR TIMEOUT"); 


  waitUntil(!Gyro.isCalibrating());
  Zeroing(true,true);
  DisplayAutoSelector();
  DisplayWords();

  //task AutoSelTask=task(ScreenSelMain);
  while(!EXIT) {
    if(Brain.Screen.xPosition()<100) {
      if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=1;
      else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=3;
      else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=5;
    }
    else if(Brain.Screen.xPosition()>375) {
      if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=2;
      else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=4;
      else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=6;
    }

    if(Brain.Screen.xPosition()>187&&Brain.Screen.xPosition()<287) {
      if(Brain.Screen.yPosition()<55&&Brain.Screen.yPosition()>5) EXIT=true;
      else if(Brain.Screen.yPosition()>125&&Brain.Screen.yPosition()<225)
      {
    if(Brain.Screen.pressing()&&!SP) OnReleasePageFlip();
      }
    }

    if(Brain.Screen.pressing()&&!SP) UpdateDynamic();
    SP=Brain.Screen.pressing();
    Brain.Screen.setPenColor(white);
    Brain.Screen.setCursor(5,16);
Brain.Screen.print("%d",AutoSelectorVal);
  }


  Brain.Screen.clearScreen();

  if(AutoSelectorVal==1) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedRingQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedQ");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==2) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueMogoQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueQ");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==3) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedMogoQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedQ");
    Brain.Screen.setFont(monoM);  
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==4) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueRingQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueQ");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==5) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Red2Goal");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedQAwp");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==6) {
  
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("Blue2Goal");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueQAwp");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==7) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("PageFlip");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("PageFlip");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }



  if(AutoSelectorVal==8) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueMogoE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueE");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==9) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedMogoE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedE");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==10) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueRingE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueE");
    Brain.Screen.setFont(monoM);  
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==11) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedRingE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedE");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==12) {

    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("AUTO-SKILLS");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("AUTO-SKILLS");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }




  Brain.Screen.setFillColor(black);
  Brain.Screen.setFont(monoXL);
  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.setCursor(5,10);
  Brain.Screen.print("AUTO CONFIRMED");

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
  //PID Straight and turn arguments:
  // MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
  // TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
  // MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

  //Do not change the below

  Zeroing(true,false);

  //can start editing if nessary
  //Put Auto route function into if statements to use autoselector
  if(AutoSelectorVal==1) { //Red Ring Side
    RedRing();
  }

  if(AutoSelectorVal==2) { //Blue Mogo Side
    BlueMogo();
  }

  if(AutoSelectorVal==3) { //Red Mogo Side
    RedMogo();
  } 

  if(AutoSelectorVal==4) { //Blue Mogo Side
    BlueRing();
  }

  if(AutoSelectorVal==5) { //Red AWP
    Red2GoalAwp();
  }

  if(AutoSelectorVal==6) { //Blue AWP
    Blue2GoalAwp();
  }

  if(AutoSelectorVal==8) { //Blue Ring Side Elims
    BlueMogoElim();
  }

  if(AutoSelectorVal==9) { //Red Mogo Side Elims
    RedMogoElim();
  }

  if(AutoSelectorVal==10) { //Blue Mogo Side Elims
    BlueRingElim();
  }

  if(AutoSelectorVal==11) { //Red Ring Side Elims
    RedRingElim();
  }

  if(AutoSelectorVal==12) { //Auto_skills
    AutoSkills();
  }



  //MoveTimePID(TestPara, -100, 0.5,0.1,-40,true);//score 2nd triball
  //(PID Parameters, motor speed -100 - 100, time for travel 0 - inf, time to accelerate to full speed, Absolute Heading, Braking?)

  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

  CStop();
}

int RV;
int LV;
int DriveTask(void) {
  while(true) {
    EXIT=true;
    RV=Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent);
    LV=Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent);
    Move(LV,RV);
  }
  return 0;
}

int V;
int ButtonPressingU,UTaskActiv;

int ATask(void) {
  double pow;
  while(true) {

    //----------------------
    //Hold for intake rollers
    pow=((Controller1.ButtonL2.pressing()-Controller1.ButtonL1.pressing())*100);//Calculate intake power, if button pressed, button.pressing returns 1
    RunRoller(pow);

    //----------------------
    //Toggles climb activation


  }  
  return 0;


}


int ButtonPressingX,XTaskActiv;
int ButtonPressingY,YTaskActiv;
int ButtonPressingB,BTaskActiv;
int ButtonPressingA,ATaskActiv;
int ButtonPressingD,DTaskActiv;


int PTask(void) {
  while(true) {
    //----------------------
    //Toggles Clamp
    if(BTaskActiv==0&&Controller1.ButtonB.pressing()&&ButtonPressingB==0) {
      ButtonPressingB=1;
      BTaskActiv=1;
      Clamp.set(false);
    }

    else if(!Controller1.ButtonB.pressing())ButtonPressingB=0;

    else if(BTaskActiv==1&&Controller1.ButtonB.pressing()&&ButtonPressingB==0) {
      ButtonPressingB=1;
      BTaskActiv=0;
      Clamp.set(true);
    }

    //----------------------
    //Toggles intake Raise
    if(XTaskActiv==0&&Controller1.ButtonX.pressing()&&ButtonPressingX==0) {
      ButtonPressingX=1;
      XTaskActiv=1;
      intakeDrop.set(true);
    }

    else if(!Controller1.ButtonX.pressing())ButtonPressingX=0;

    else if(XTaskActiv==1&&Controller1.ButtonX.pressing()&&ButtonPressingX==0) {
      ButtonPressingX=1;
      XTaskActiv=0;
      intakeDrop.set(false);
    }

    //----------------------
    //Toggles doinker arm 
    if(DTaskActiv==0&&Controller1.ButtonDown.pressing()&&ButtonPressingD==0) {
      ButtonPressingD=1;
      DTaskActiv=1;
      arm.set(true);
    }

    else if(!Controller1.ButtonDown.pressing())ButtonPressingD=0;

    else if(DTaskActiv==1&&Controller1.ButtonDown.pressing()&&ButtonPressingD==0) {
      ButtonPressingD=1;
      DTaskActiv=0;
      arm.set(false);
    }


    
  }
  return 0;
}



int BTask(void) {
  int pow1 = 0;
  int targetPosition = 18; // Target position for the lift
  double error = 0;
  double kP = 0.85; // Proportional constant (tune this value)
  double motorPower = 0.0;
  double minPower = 30;

  while (true) {
    if (YTaskActiv == 1) {
      error = targetPosition - LiftSensor.position(degrees); // Calculate error
      error = -error;
      motorPower = kP * error;                               // Calculate motor power based on proportional control

      // Apply minimum power threshold
      if (motorPower > 0 && motorPower < minPower) {
          motorPower = minPower; // Set to minimum forward power
      } else if (motorPower < 0 && motorPower > -minPower) {
          motorPower = -minPower; // Set to minimum reverse power
      }

      // Clamp motor power to allowable range (-100 to 100)
      if (motorPower > 100) motorPower = 100;
      if (motorPower < -100) motorPower = -100;

      // Run the motor with calculated power
      RunLift(motorPower);

      // Stop autonomous task if the error is small enough (target reached)
      if (abs(error) < 3.0) {
        YTaskActiv = 0;
        RunLift(0); // Stop the motor
      }
    } 
    else {
      // Manual Control
      pow1 = ((Controller1.ButtonR2.pressing() - Controller1.ButtonR1.pressing()) * 100); // Calculate manual power
      if (pow1 == 0) {
        if (LiftSensor.position(degrees) < 9 || LiftSensor.position(degrees) > 265){
          Lift.setStopping(coast);
        }
        else {
          Lift.setStopping(hold);
        }
        Lift.stop();
      } 
      else {
        RunLift(pow1); // Direct power control in manual mode
      }
    }

    // Button Y Logic to Toggle Autonomous Control
    if (Controller1.ButtonY.pressing() && ButtonPressingY == 0) {
      ButtonPressingY = 1;
      YTaskActiv = 1;
      

    } else if (!Controller1.ButtonY.pressing()) {
        ButtonPressingY = 0;
    }
  }

    return 0;
}
// int BTask(void) {   
//   int mvel = 0;  
//   int pow1 = 0;
   
  

//   while(true) {
//     if(YTaskActiv==1) {
//       if(abs(LiftSensor.position(degrees)) < 24) {
//         RunLift(-45);
//         if(abs(LiftSensor.position(degrees)) > 22) {
//           YTaskActiv = 0;
//         }
//       } 
//       else if(abs(LiftSensor.position(degrees)) > 24) {
//         RunLift(45);
//         if(abs(LiftSensor.position(degrees)) < 30) {
//           YTaskActiv = 0;
//         }
//       } 
//     }
//     else {
//       pow1=((Controller1.ButtonR2.pressing()-Controller1.ButtonR1.pressing())*100);//Calculate intake power, if button pressed, button.pressing returns 1
//       if(pow1==0) {
//         if (LiftSensor.position(degrees) < 10) Lift.setStopping(coast);
//         else Lift.setStopping(hold);
//         Lift.stop();
//       }
//       else {
//         RunLift(pow1);
//       }
//     }  

//     if(Controller1.ButtonY.pressing() && ButtonPressingY == 0) {
//       ButtonPressingY=1;
//       YTaskActiv=1;
//     }

//     else if(!Controller1.ButtonY.pressing())ButtonPressingY=0;

//     else if(YTaskActiv==1&&Controller1.ButtonY.pressing()&&ButtonPressingY==0) {
//       ButtonPressingY=1;
//       YTaskActiv=0;
//       Lift.setStopping(coast);
//       Lift.stop();
//     }
//   }
//   return 0;
// }




/*

int BTask(void) {   
  int mvel = 0;  
  int pow1 = 0;

  while(true) {
    if(YTaskActiv==1) {
      if(abs(LiftSensor.position(degrees)) < 20) {
        RunLift(-40);
        if(abs(LiftSensor.position(degrees)) > 18) {
          YTaskActiv = 0;
        }
      } 
      else if(abs(LiftSensor.position(degrees)) > 20) {
        RunLift(40);
        if(abs(LiftSensor.position(degrees)) < 38) {
          YTaskActiv = 0;
        }
      } 
    }
    else {
      pow1=((Controller1.ButtonR2.pressing()-Controller1.ButtonR1.pressing())*100);//Calculate intake power, if button pressed, button.pressing returns 1
      if(pow1==0) {
        if (LiftSensor.position(degrees) < 10) Lift.setStopping(coast);
        else Lift.setStopping(hold);
        Lift.stop();
      }
      else {
        RunLift(pow1);
      }
    }  

    if(Controller1.ButtonY.pressing() && ButtonPressingY == 0) {
      ButtonPressingY=1;
      YTaskActiv=1;
    }

    else if(!Controller1.ButtonY.pressing())ButtonPressingY=0;

    else if(YTaskActiv==1&&Controller1.ButtonY.pressing()&&ButtonPressingY==0) {
      ButtonPressingY=1;
      YTaskActiv=0;
      Lift.setStopping(coast);
      Lift.stop();
    }
  }
  return 0;
}


*/

    

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  EXIT=true;//Force Exit Autosel once drivercontrol began.
  intakeDrop.set(true);
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    
    task Dtask=task(DriveTask);
    task Atask=task(ATask);
    task Ptask=task(PTask);
    task Btask=task(BTask);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//


int main() {
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  // Run the pre-autonomous function.
  pre_auton();
  

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
  
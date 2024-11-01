#include "screen_gui.hpp"
#include "vex.h"

void DisplayAutoSelector(void) {

  Brain.Screen.clearScreen();

  //auton selector
  Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor(black);
  Brain.Screen.setCursor(1,1);
  Brain.Screen.setPenWidth(3);
  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(1,25,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(375,25,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(1,100,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(375,100,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(1,175,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(375,175,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(187,5,100,50);

  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.drawRectangle(187,175,100,50);
}

void DisplayWords(void) {
  Brain.Screen.setPenColor("#39FF14");
  Brain.Screen.setFont(monoM);
  
  Brain.Screen.setCursor(3,3);
  Brain.Screen.print("RedLeft");

  Brain.Screen.setCursor(7,3);
  Brain.Screen.print("RedRight");

  Brain.Screen.setCursor(11,3);
  Brain.Screen.print("Red2Goal");

  Brain.Screen.setCursor(3,40);
  Brain.Screen.print("BlueLeft");

  Brain.Screen.setCursor(7,40);
  Brain.Screen.print("BlueRight");

  Brain.Screen.setCursor(11,40);
  Brain.Screen.print("Blue2Goal");

  Brain.Screen.setCursor(11,22);
  Brain.Screen.print("FLIP");
}

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
int AutoSelectorVal;

void UpdateDynamic(void) {
  DisplayAutoSelector();
  DisplayWords();
 // wait(1000,msec);
  Brain.Screen.setFillColor("#39FF14");
  Brain.Screen.setPenColor(black);


/*---------------------------------------------------------------------------*/
/*                            !!!IMPORTANT NOTE!!!                           */
/*                                                                           */
/*  When changing the name of a program to be displayed on the brain screen, */
/*  four different strings must be changed; 3 in this cpp file and one in    */
/*  main.cpp where each of the asv values are.                               */
/*                                                                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//EVEN ASV NUMBERS BLUE, ODD ASV NUMBERS RED

  if(AutoSelectorVal==1) {
    Brain.Screen.drawRectangle(1,25,100,50);
    Brain.Screen.setCursor(3,3);
    Brain.Screen.print("RedLeftQ");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedLeftQ");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==2) {
    Brain.Screen.drawRectangle(375,25,100,50);
    Brain.Screen.setCursor(3,40);
    Brain.Screen.print("BlueLeftQ");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueLeftQ");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==3) {
    Brain.Screen.drawRectangle(1,100,100,50);
    Brain.Screen.setCursor(7,3);
    Brain.Screen.print("RedRightQ");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedRightQ");
    Brain.Screen.setFont(monoM);  
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==4) {
    Brain.Screen.drawRectangle(375,100,100,50);
    Brain.Screen.setCursor(7,40);
    Brain.Screen.print("BlueRightQ");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueRightQ");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==5){
    Brain.Screen.drawRectangle(1,175,100,50);
    Brain.Screen.setCursor(11,3);
    Brain.Screen.print("Red2GoalAWP");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("Red2GoalAWP");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==6) {
    Brain.Screen.drawRectangle(375,175,175,50);
    Brain.Screen.setCursor(11,40);
    Brain.Screen.print("Blue2GoalAWP");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueQ");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("Blue2GoalAWP");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

//Page 2 Starts Here
if(AutoSelectorVal==7) {
    Brain.Screen.drawRectangle(1,25,100,50);
    Brain.Screen.setCursor(3,3);
    Brain.Screen.print("FLIP");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("FLIP");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("FLIP");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==8) {
    Brain.Screen.drawRectangle(375,25,100,50);
    Brain.Screen.setCursor(3,40);
    Brain.Screen.print("BlueRightE");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueRightE");
    Brain.Screen.setFont(monoM);
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==9) {
    Brain.Screen.drawRectangle(1,100,100,50);
    Brain.Screen.setCursor(7,3);
    Brain.Screen.print("RedRightE");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedRightE");
    Brain.Screen.setFont(monoM);  
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==10) {
    Brain.Screen.drawRectangle(375,100,100,50);
    Brain.Screen.setCursor(7,40);
    Brain.Screen.print("BlueLeftE");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("BlueE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("BlueLeftE");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==11){
    Brain.Screen.drawRectangle(1,175,100,50);
    Brain.Screen.setCursor(11,3);
    Brain.Screen.print("RedLeftE");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("RedE");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("RedLeftE");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }

  if(AutoSelectorVal==12) {
    Brain.Screen.drawRectangle(375,175,175,50);
    Brain.Screen.setCursor(11,40);
    Brain.Screen.print("AUTO-SKILLS");
    Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
    Brain.Screen.setPenColor("#39FF14");
    Brain.Screen.setCursor(3,10);
    Brain.Screen.print("SKILLS");
    Brain.Screen.setCursor(4,10);
    Brain.Screen.print("AUTO-SKILLS");
    Brain.Screen.setFont(monoM); 
    Brain.Screen.setFillColor("#39FF14");
  }


}

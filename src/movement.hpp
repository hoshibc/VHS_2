#ifndef MOVEMENT_H
#define MOVEMENT_H

extern int turninverse;
extern int JB;
extern int PB;
extern int PX;
extern int JX;

extern int loadPosition;
extern int alliancePosition;
extern int resetPosition;
extern int holdPosition;
extern int ladderPosition;
extern int wallPosition;



struct ChassisDataSet{
  int Left;
  int Right;
  double Avg;   // Average between left and right of the drive train
  int Diff;     // Left - Right
  double HDG;   // Robot heading
};

struct PIDDataSet{
  double kp;
  double ki;
  double kd;
};




extern void ColourSort(int intakeSpeed, bool SortRed);
extern void StartColourSort(int speed, bool IssRed);
extern void stopColourSort(int speed);
extern void toggleColourSort(int Speed, bool IssRed);
extern int colourSortThreadFn(void* arg);

extern void Zeroing(bool dist, bool HDG);
extern ChassisDataSet ChassisUpdate();
extern void Move(int left, int right);
extern void BStop();
extern void CStop();
extern void allianceStakeAlign();
extern void armMoveToAngle(int deg, int speed);
extern void armMoveToAngle2(int deg, int speed);
extern void RunRoller(int val);
extern void RunLift(int val);
extern int PrevE;
extern void MoveEncoderPID(PIDDataSet KVals, int Speed, double dist,double AccT, double ABSHDG,bool brake);
extern void MoveDecelPID(PIDDataSet KVals, int Speed, double dist, double AccT, bool decel, double ABSHDG, bool brake);
extern void TurnMaxTimePID(PIDDataSet KVals,double DeltaAngle,double TE, bool brake);
void MaxTimePIDTurnOneSide(PIDDataSet KVals,double DeltaAngle,double TE, bool brake);
void MoveTimePID(PIDDataSet KVals, int Speed, double TE,double AccT,double ABSHDG, bool brake);


#endif
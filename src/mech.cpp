#include "main.h"
Motor FW(FWport);
Motor ITKL(ITKLport);
Motor ITKR(ITKRport);
Motor IDX(IDXport);
#define GATE_DURATION 800
#define GATE_POW -120
#define FW_KP 0.8 //cumulative kp
#define FW_POW_LEEWAY 2
#define GATE_PASSIVE_POW -120
#define GATE_PASSIVE_DURATION 1000
#define ITK_KP 0.8
#define ITK_POW_LEEWAY 2
double FWpow = 0, targFWpow = 0;
double ITKpow = 0, targITKpow = 0;
void FWmove(double targ){
  targFWpow = targ;
}
void wait(double cutoff){
  double start = millis();
  while((millis() - start) <= cutoff) Task::delay(10);
}
void FWmove(double targ, double cutoff){
  FWmove(targ);
  wait(cutoff);
}
void FWlift(){
    FWmove(GATE_POW);
    wait(GATE_DURATION);
}
void FWhold(){
  FWmove(GATE_PASSIVE_POW);
}
void FWgate(){
  FWlift();
  FWhold();
  wait(GATE_PASSIVE_DURATION);
  FWmove(0);
}
void FWControl(void * ignore){
  while(true){
    double error = targFWpow - FWpow;
    if(fabs(error) >= FW_POW_LEEWAY){
      FWpow += error * FW_KP;
    }
    FW.move(FWpow);
    Task::delay(10);
  }
}

void ITKmove(double targ){
  targITKpow = targ;
}
void ITKControl(void * ignore){
  while(true){
    double error = targITKpow - ITKpow;
    if(fabs(error) >= ITK_POW_LEEWAY){
      ITKpow += error * ITK_KP;
    }
    ITKL.move(ITKpow);
    ITKR.move(ITKpow);
    IDX.move(ITKpow);
    Task::delay(10);
  }
}

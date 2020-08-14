#include "main.h"
Motor FW(FWport);
#define GATE_DURATION 400
#define GATE_POW -120
#define FW_KP 0.8 //cumulative kp
#define FW_POW_LEEWAY 2
#define GATE_PASSIVE_POW -90
#define GATE_PASSIVE_DURATION 1000
double FWpow = 0, targFWpow = 0;
void FWmove(double targ){ 
  targFWpow = targ;
}
void waitFW(double cutoff){
  double start = millis();
  while((millis() - start) <= cutoff) delay(10);
}
void FWgate(){
  FWmove(GATE_POW);
  waitFW(GATE_DURATION);
  FWmove(GATE_PASSIVE_POW);
  waitFW(GATE_PASSIVE_DURATION);
  FWmove(0);
}
void FWControl(void * ignore){
  while(true){
    double error = targFWpow - FWpow;
    if(fabs(error) >= FW_POW_LEEWAY){
      FWpow += error * FW_KP;
    }
    FW.move(FWpow);
    delay(10);
  }
}

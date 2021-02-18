#include "main.h"
int DEBUG_MODE = 0;
void printPosMaster(){
  Controller master(E_CONTROLLER_MASTER);
  master.print(2, 0, "%.2f %.2f %.2f", X, Y, bearing);
}
void printPosTerminal(){
  printf("x: %.2f y: %.2f bearing: %.2f\n", X, Y, bearing);
}
void printEncdTerminal(){
  printf("encdL: %.2f encdR: %.2f\n", encdL, encdR);
}
void printErrorEncdTerminal(){
  printf("errorEncdL: %.2f errorEncdR: %.2f\n", errorEncdL, errorEncdR);
}
void printPowerTerminal(){
  printf("powerL: %.2f powerR: %.2f\n", powerL, powerR);
}
void Debug(void * ignore){
  while(true){
    printPosMaster();
    switch(DEBUG_MODE){
      case 1: printPosTerminal(); break;
      case 2: printEncdTerminal(); break;
      case 3: printErrorEncdTerminal(); break;
      case 4: printPowerTerminal(); break;
    }
    delay(50);
  }
}

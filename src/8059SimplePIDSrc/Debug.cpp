#include "main.h"
int DEBUG_MODE = 0;
void printPosMaster(){
  Controller master(E_CONTROLLER_MASTER);
  Imu imu (imuPort);
  // if(imu.is_calibrating()) master.print(2, 0, "calibrating");
  // else{
  //   master.print(2, 0, "%.1f %.1f %.1f     ", X, Y, bearing);
  // }
  std::string autoIndexUsed = autoIndex? "AUTO": "MAN";
  std::string allianceName = redAlliance? "RED ": "BLUE";
  master.print(2, 0, "    %.0f %s %s   ", battery::get_capacity(), autoIndexUsed.c_str(),  allianceName.c_str());
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
void printErrorBearingTerminal() {
  printf("errorBearing: %.2f\n", errorBearing);
}
void printTargPowerTerminal(){
  printf("targPowerL: %.2f, targPowerR: %.2f\n", targPowerL, targPowerR);
}
void printPowerTerminal(){
  printf("powerL: %.2f powerR: %.2f\n", powerL, powerR);
}
void Debug(void * ignore){
  int count = 0;
  Imu imu (imuPort);
  Controller master(E_CONTROLLER_MASTER);
  master.print(0, 0, "      8059BLANK");
  delay(50);
  master.print(1, 0, "  LETS GO HANSON!");
  delay(50);
  while(true){
    printPosMaster();
    if(imu.is_calibrating()) {
      // printf("imu is calibrating...\n");
    }else {
      switch(DEBUG_MODE){
        case 1: printPosTerminal(); break;
        case 2: printEncdTerminal(); break;
        case 3: printErrorEncdTerminal(); break;
        case 4: printErrorBearingTerminal(); break;
        case 5: printTargPowerTerminal(); break;
        case 6: printPowerTerminal(); break;
        case 7: {
            printf("errorEncdL: %.2f errorEncdR: %.2f\t", errorEncdL, errorEncdR);
            printf("targPowerL: %.2f, targPowerR: %.2f\t", targPowerL, targPowerR);
            printf("powerL: %.2f powerR: %.2f\n", powerL, powerR);
            break;
          }
      }
    }
    delay(50);
  }
}

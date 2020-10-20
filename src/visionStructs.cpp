#include "main.h"
const std::vector<std::string> sigIdToString = {"No object", "Red ball", "Blue ball", "Green flag"};
VisionCoordinates::VisionCoordinates(){
  this -> setVisionCoords(0, 0, 0, 0, 0);
}
VisionCoordinates::VisionCoordinates(int sig, int x, int y, int w, int h){
  this -> setVisionCoords(sig, x, y, w, h);
}
void VisionCoordinates::setVisionCoords(int sig, int x, int y, int w, int h){
  this -> sig = sig;
  this -> x = x;
  this -> y = y;
  this -> w = w;
  this -> h = h;
}
void VisionCoordinates::getFromObject(pros::vision_object_s_t visObj){
  if(visObj.signature <= 7){
    this->setVisionCoords(visObj.signature, visObj.x_middle_coord, visObj.y_middle_coord, visObj.width, visObj.height);
  }else{
    this->setVisionCoords(0, 0, 0, 0, 0);
  }
}
void VisionCoordinates::print(){
    printf("sig: %s x: %d, y: %d, w: %d, h: %d\n",sigIdToString[this->sig].c_str(), this->x, this->y, this->w, this->h);
}

void VisionCoordinates::printMaster(){
    Controller master(E_CONTROLLER_MASTER);
    master.print(2,0,"%d %d %d %d", this->x, this->y, this->w, this->h);
}

VisionObject::VisionObject(){
  this -> curr.setVisionCoords(0, 0, 0, 0, 0);
  this -> targ.setVisionCoords(0, 0, 0, 0, 0);
}
VisionObject::VisionObject(VisionCoordinates c, VisionCoordinates t){
  this -> curr = c;
  this -> targ = t;
}

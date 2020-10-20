#ifndef _8059_VISION_LIB_VISION_STRUCTS_HPP_
#define _8059_VISION_LIB_VISION_STRUCTS_HPP_

class VisionCoordinates{
public:
  int sig, x, y, w, h;
  VisionCoordinates();
  VisionCoordinates(int sig, int x, int y, int w, int h);

  void setVisionCoords(int sig, int x, int y, int w, int h);
  void getFromObject(pros::vision_object_s_t visObj);

  void print();
  void printMaster();
};

class VisionObject{
public:
  VisionCoordinates curr, targ;
  VisionObject();
  VisionObject(VisionCoordinates c, VisionCoordinates t);
};
#endif

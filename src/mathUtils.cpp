/**
 * Mathematical functions
 */
#include "main.h"
/**
 * bound an angle in radians within 0<=angle<twoPI
 * @param  rad angle in radians
 * @return     angle in radians bounded within 0<=angle<twoPI
 */
double boundRad(double rad){
  double res = fmod(rad, twoPI);
  if(res < 0) res += twoPI;
  return res;
}
/**
 * bound an angle in radians within 0<=angle<360
 * @param  deg angle in degrees
 * @return     angle in degrees bounded within 0<=angle<360
 */
double boundDeg(double deg){
  double res = fmod(deg, 360);
  if(res < 0) res += 360;
  return res;
}

/**
 * cap the input |x| <= abscap
 * i.e. within the range -abscap <= x <= abscap
 * @param  x      input
 * @param  abscap absolute (positive) value of the cap
 * @return        capped value of the input
 * for use when capping the absolute power of motors
 */
double abscap(double x, double abscap){
  if(x > abscap) return abscap;
  else if(x < -abscap) return -abscap;
  else return x;
}

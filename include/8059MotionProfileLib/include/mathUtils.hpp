/**
 * Header file for mathUtils.cpp
 * Defines mathematical constants and functions
 */
#ifndef _8059_MOTION_PROFILE_LIB_MATH_UTILS_HPP_
#define _8059_MOTION_PROFILE_LIB_MATH_UTILS_HPP_
/**
 * Mathematical constants
 */
#define PI      3.14159265358979323846264338328
#define halfPI  1.57079632679489661923132169164
#define twoPI	  6.28318530717958647692528676656
/**
 * Angle conversion from radians to degrees and vice versa
 * angleDeg = angle * toDeg
 * angle = angleDeg * toRad
 */
#define toDeg   57.2957795130823208767981548141
#define toRad 0.0174532925199432957692369076849
/**
 * refer to mathUtils.cpp for function documentation
 */
double boundRad(double rad); //bound 0<=angle<twoPI
double boundDeg(double deg); //bound 0<=angle<360
double abscap(double x, double abscap);

#endif

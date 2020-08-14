#ifndef _CHANGE_UP_2020_MECH_HPP_
#define _CHANGE_UP_2020_MECH_HPP_
#define FW_MAX_POW 120
void FWgate();
void FWmove(double targ);
void FWmove(double targ, double cutoff);
void FWlift();
void FWhold();
void FWControl(void * ignore);

void ITKmove(double targ);
void ITKControl(void * ignore);
#endif

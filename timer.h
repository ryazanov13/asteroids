/* File timer.h */
#ifndef TIMER_H
#define TIMER_H

#include "global.h"

unsigned int get_time();
int wait(int t);

class Timer{
  private:
    unsigned int t;
  public:
    Timer();
    void Start();
    unsigned int GetElapsedTime();
};

#endif
/* TIMER_H */

/* File timer.cpp */
#include "timer.h"

#include <sys/time.h>
#include <unistd.h>

unsigned int get_time(){
  struct timeval  now;
  gettimeofday(&now, NULL);
  return (unsigned int)now.tv_sec*(unsigned int)SEC + (unsigned int)now.tv_usec;
}

int wait(int t){
  if(t>0){
    return usleep(t);
  }
  else
    return -2;
}

Timer::Timer(){
  t = 0;
}
void Timer::Start(){
  t = get_time();
}
unsigned int Timer::GetElapsedTime(){
  return get_time()-t;
}

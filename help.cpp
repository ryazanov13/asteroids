/* File help.cpp */
#include "help.h"

float get_segment_length(Point p1, Point p2){
  return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

void print_point(std::string str, Point p){
  std::cout<<str;
  std::cout<<" Point: x = "<<p.x<<" , y = "<<p.y<<"\n";
}

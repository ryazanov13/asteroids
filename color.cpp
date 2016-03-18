/* File color.cpp */
#include "color.h"

Color::Color(){
  r = 0;
  g = 0;
  b = 0;
  a = 0;
}
Color::Color(float r, float g, float b, float a){
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
void Color::Set(float r, float g, float b, float a){
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

Color operator+(Color left, Color right){
  return Color(left.r*right.r,left.g*right.g,left.b*right.b,left.a*right.a);
}
bool operator==(Color left, Color right){
  if(left.r==right.r && left.g==right.g && left.b==right.b && left.a==right.a){
    return true;
  }
  else{
    return false;
  }
}

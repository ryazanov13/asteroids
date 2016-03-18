/* File point.cpp */
#include "point.h"

Point::Point(){
  x = 0;
  y = 0;
}
Point::Point(float x, float y){
  this->x = x;
  this->y = y;
}
void Point::Set(float x, float y){
  this->x = x;
  this->y = y;
}

bool operator==(Point left, Point right){
  if(left.x==right.x && left.y==right.y){
    return true;
  }
  else{
    return false;
  }
}
bool operator!=(Point left, Point right){
  if(left.x!=right.x || left.y!=right.y){
    return true;
  }
  else{
    return false;
  }
}
Point operator+(Point left, Point right){
  return Point(left.x+right.x,left.y+right.y);
}
Point operator-(Point left, Point right){
  return Point(left.x-right.x,left.y-right.y);
}
Point operator+(Point left, float right){
  return Point(left.x+right,left.y+right);
}
Point operator-(Point left, float right){
  return Point(left.x-right,left.y-right);
}
Point operator*(Point left, float right){
  return Point(left.x*right,left.y*right);
}
Point operator/(Point left, float right){
  return Point(left.x/right,left.y/right);
}
Point operator+(float left, Point right){
  return Point(left+right.x,left+right.y);
}
Point operator-(float left, Point right){
  return Point(left-right.x,left-right.y);
}

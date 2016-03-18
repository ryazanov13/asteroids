/* File point.h */
#ifndef POINT_H
#define POINT_H

class Point{
  public:
    float x,y;
    Point();
    Point(float x, float y);
    void Set(float x, float y);
};

bool operator==(Point left, Point right);
bool operator!=(Point left, Point right);
Point operator+(Point left, Point right);
Point operator-(Point left, Point right);
Point operator+(Point left, float right);
Point operator-(Point left, float right);
Point operator*(Point left, float right);
Point operator/(Point left, float right);
Point operator+(float left, Point right);
Point operator-(float left, Point right);

#endif
/* POINT_H */

/* File collision.h */
#ifndef COLLISION_H
#define COLLISION_H

#include <cmath>

#include "global.h"
#include "game_const.h"
#include "scene.h"
#include "object.h"

class Collision{
  //Точки в полигонах должны располагаться против часовой стрелки
  private:
    static int ClassifyPoint(Point p1, Point p2, Point p);
    static bool IsIntersection(Point a1, Point a2, Point b1, Point b2);
    static std::vector<Point> CreateTrail(Object object);
    static bool CheckInside(int i);
    static bool CheckLines(std::vector<Point> p1, std::vector<Point> p2);
    static bool CheckPoints(std::vector<Point> p1, std::vector<Point> p2);
    static std::vector<Point> CreateCollisionArea(Object object);
    static bool PreCheck(Object obj1, Object obj2);
    static bool FullCheck(Object obj1, Object obj2);
  public:
    static bool CheckObjects(Object obj1, Object obj2);
};

#endif
/* COLLISION_H */

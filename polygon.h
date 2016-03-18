/* File polygon.h */
#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "point.h"

class Polygon{
  private:
    Point pos;
    std::vector<Point> points;
    std::vector<Point> base_points;
    void InitPoints();
  public:
    void SetPoints(std::vector<Point> points);
    void SetPosition(Point pos);
    std::vector<Point> GetPoints();
    Point GetPosition();
    void SetTranform(float alpha, float scale_w, float scale_h);
    Polygon();
    Polygon(std::vector<Point> points);
};

#endif
/* POLYGON_H */

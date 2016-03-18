/* File polygon.cpp */
#include "polygon.h"

#include <cmath>
#include "help.h"

void Polygon::InitPoints(){
  Point prev_point = points[0];
  float perimeter = 0;
  float line_length = 0;
  Point amount;
  int i = 1;
  while(true){
    line_length = get_segment_length(points[i], prev_point);
    perimeter += line_length;
    amount.x += (points[i].x + prev_point.x)/2 * line_length;
    amount.y += (points[i].y + prev_point.y)/2 * line_length;
    prev_point = points[i];
    ++i;
    if(i==points.size()){
      line_length = get_segment_length(points[0], prev_point);
      perimeter += line_length;
      amount.x += (points[0].x + prev_point.x)/2 * line_length;
      amount.y += (points[0].y + prev_point.y)/2 * line_length;
      break;
    }
  }
  pos.Set(amount.x/perimeter,amount.y/perimeter);
}
void Polygon::SetPoints(std::vector<Point> points){
  this->points = points;
  base_points = points;
  InitPoints();
}
void Polygon::SetPosition(Point pos){
  for(int i = 0;i<points.size();++i){
    points[i].x += (pos.x-this->pos.x);
    points[i].y += (pos.y-this->pos.y);
    base_points[i].x += (pos.x-this->pos.x);
    base_points[i].y += (pos.y-this->pos.y);
  }
  this->pos = pos;
}
std::vector<Point> Polygon::GetPoints(){
  return points;
}
Point Polygon::GetPosition(){
  return pos;
}
void Polygon::SetTranform(float alpha, float scale_w, float scale_h){
  points = base_points;
  // --- SCALE ---
  for (int i=0;i<points.size();++i){
    points[i].x = pos.x+(points[i].x-pos.x)*scale_w;
    points[i].y = pos.y+(points[i].y-pos.y)*scale_h;
  }
  // --- ROTATE ---
  Point temp;
  float a = alpha * M_PI / 180.0;
  for(int i=0;i<points.size();++i){
    temp.x = pos.x+(points[i].x-pos.x)*cos(a)+(points[i].y-pos.y)*sin(a);
    temp.y = pos.y+(points[i].y-pos.y)*cos(a)-(points[i].x-pos.x)*sin(a);
    points[i].x = temp.x;
    points[i].y = temp.y;
  }
}
Polygon::Polygon(){}
Polygon::Polygon(std::vector<Point> points){
  SetPoints(points);
}

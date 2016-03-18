/* File bullet.cpp */
#include "bullet.h"

Bullet::Bullet():Object(){
  status = ALIVE;
  std::vector<Point> points;
  points.push_back(Point(0, 0));
  points.push_back(Point(BULLET_WIDTH, 0));
  points.push_back(Point(BULLET_WIDTH, BULLET_HEIGHT));
  points.push_back(Point(0, BULLET_HEIGHT));
  Polygon polygon;
  polygon.SetPoints(points);
  SetPolygon(polygon);
  SetColor(Color(1,0,0,1));
}
int Bullet::GetStatus(){
  return status;
}
void Bullet::CheckHidden(){
  if(GetCurrentPosition().y > HEIGHT + GetH()/2){
    status = OFFSCREEN;
  }
}
void Bullet::Update(){
  Object::Update();
  CheckHidden();
}

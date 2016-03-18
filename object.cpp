/* File object.cpp */
#include "object.h"

void Object::Move(){
  prev_pos = current_pos;
  Point diff = current_pos-polygon.GetPosition();
  current_pos = current_pos + speed*GAME_SPEED*SPEED_FACTOR;
  polygon.SetPosition(current_pos-diff);
}
void Object::SetParameters(){
  std::vector<Point> points = polygon.GetPoints();
  float left = points[0].x;
  float right = points[0].x;
  float bottom = points[0].y;
  float top = points[0].y;
  for (int i=0;i<points.size();++i){
    if (points[i].x < left){
      left = points[i].x;
    }
    else if(points[i].x > right){
      right = points[i].x;
    }
    if (points[i].y < bottom){
      bottom = points[i].y;
    }
    else if(points[i].y > top){
      top = points[i].y;
    }
  }
  w = right-left;
  h = top-bottom;
  Point new_pos = Point((right+left)/2,(top+bottom)/2);
  prev_pos = prev_pos+(new_pos-current_pos);
  current_pos = new_pos;
}
Object::Object(){
  visible=true;
  color.Set(1,1,1,1);
  alpha = 0;
  scale_w = 1;
  scale_h = 1;
}
void Object::SetPolygon(Polygon polygon){
  this->polygon = polygon;
  SetParameters();
}
void Object::SetColor(Color color){
  this->color = color;
}
void Object::SetPosition(Point pos){
  Point diff = current_pos-polygon.GetPosition();
  current_pos = pos;
  prev_pos = current_pos;
  polygon.SetPosition(current_pos-diff);
}
void Object::SetSpeed(Point speed){
  this->speed = speed;
}
void Object::SetAlpha(float alpha){
  this->alpha = alpha;
  polygon.SetTranform(this->alpha, this->scale_w, this->scale_h);
  SetParameters();
}
void Object::SetScale(float scale_w, float scale_h){
  scale_w>0 ? this->scale_w=scale_w : this->scale_w=1;
  scale_h>0 ? this->scale_h=scale_h : this->scale_h=1;
  polygon.SetTranform(this->alpha, this->scale_w, this->scale_h);
  SetParameters();
}
void Object::SetVisible(bool value){
  visible=value;
}
Polygon Object::GetPolygon(){
  return polygon;
}
Color Object::GetColor(){
  return color;
}
Point Object::GetCurrentPosition(){
  return current_pos;
}
Point Object::GetPrevPosition(){
  return prev_pos;
}
Point Object::GetSpeed(){
  return speed;
}
float Object::GetAlpha(){
  return alpha;
}
float Object::GetW(){
  return w;
}
float Object::GetH(){
  return h;
}
float Object::GetScaleW(){
  return scale_w;
}
float Object::GetScaleH(){
  return scale_h;
}
void Object::Update(){
  Move();
}
void Object::Draw(){
  if(visible){
    Scene::DrawPolygon(GetPolygon().GetPoints(), GetPolygon().GetPoints().size(), true, color);
  }
}

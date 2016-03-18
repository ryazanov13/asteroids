/* File score.cpp */
#include "score.h"

void Score::UpdateBack(){
  back.SetScale(1,max_value);
  back.SetPosition(Point(pos.x,pos.y+back.GetH()/2));
}
void Score::UpdateBody(){
  body.SetScale(1,current_value);
  if(current_value==0){
    body.SetVisible(false);
  }
  else{
    body.SetVisible(true);
  }
  body.SetPosition(Point(pos.x,pos.y+body.GetH()/2));
}
void Score::Init(){
  std::vector<Point> points;
  points.push_back(Point(0,0));
  points.push_back(Point(width,0));
  points.push_back(Point(width,degree));
  points.push_back(Point(0,degree));
  Polygon polygon;
  polygon.SetPoints(points);
  back.SetPolygon(polygon);
  back.SetColor(Color(0.2,0.2,0.2,0.5));
  body.SetPolygon(polygon);
  body.SetColor(Color(1,0,1,0.5));
  UpdateBack();
  UpdateBody();
}
Score::Score(){
  max_value=100;
  current_value=0;
  width=SCORE_WIDTH;
  degree=SCORE_DEGREE;
  Init();
  SetPosition(Point(0,0));
}
void Score::SetMaxValue(float value){
  max_value=value;
  UpdateBack();
}
void Score::SetCurrentValue(float value){
  if(value>max_value){
    current_value=max_value;  
  }
  else{
    current_value=value;
  }
  UpdateBody();
}
void Score::SetPosition(Point pos){
  this->pos=pos;
  UpdateBack();
  UpdateBody();
}
void Score::SetWidth(float w){
  width=w;
  Init();
}
void Score::SetBodyColor(Color c){
  body.SetColor(c);
}
void Score::SetBackColor(Color c){
  back.SetColor(c);
}
float Score::GetMaxValue(){
  return max_value;
}
float Score::GetCurrentValue(){
  return current_value;
}
Point Score::GetPosition(){
  return pos;
}
float Score::GetWidth(){
  return width;
}
void Score::Draw(){
  back.Draw();
  body.Draw();
}

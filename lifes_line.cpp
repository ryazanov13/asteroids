/* File lifes_line.cpp */
#include "lifes_line.h"

Life::Life(){
  size=LIFE_SIZE;
  std::vector<Point> points;
  points.push_back(Point(0,0));
  points.push_back(Point(size,0));
  points.push_back(Point(size,size));
  points.push_back(Point(0,size));
  Polygon polygon;
  polygon.SetPoints(points);
  SetPolygon(polygon);
  SetColor(Color(1,0,0,1));
}

void LifesLine::Increase(int value){
  for(int i=0;i<value;++i){
    Life l;
    l.SetPosition(Point(pos.x+l.GetW()/2+gap+(size+i)*(l.GetW()+gap*2),pos.y-l.GetH()/2-gap));
    lifes.push_back(l);
  }
  size=size+value;
}
void LifesLine::Dencrease(int value){
  if(value>=size){
    lifes.clear();
    this->size=0;
    return;
  }
  for(int i=0;i<value;++i){
    lifes.pop_back();
  }
  size=size-value;
}
LifesLine::LifesLine(){
  gap=LIFE_GAP;
  size=0;
}
void LifesLine::SetSize(int size){
  if(this->size>size){
    Dencrease(this->size-size);
  }
  else if(this->size<size){
    Increase(size-this->size);
  }
}
void LifesLine::SetPosition(Point pos){
  this->pos=pos;
  int j=0;
  for(std::list<Life>::iterator i=lifes.begin();i!=lifes.end();++i){
    i->SetPosition(Point(pos.x+i->GetW()/2+gap+j*(i->GetW()+gap*2),pos.y-i->GetH()/2-gap));
    ++j;
  }
}
int LifesLine::GetSize(){
  return size;
}
Point LifesLine::GetPosition(){
  return pos;
}
void LifesLine::Draw(){
  for(std::list<Life>::iterator i=lifes.begin();i!=lifes.end();++i){
    i->Draw();
  }
}

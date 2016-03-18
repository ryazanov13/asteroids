/* File menu.cpp */
#include "menu.h"

void Menu::Init(){
  std::vector<Point> points;
  points.push_back(Point(0,0));
  points.push_back(Point(0,HEIGHT));
  points.push_back(Point(WIDTH,HEIGHT));
  points.push_back(Point(WIDTH,0));
  Polygon p;
  p.SetPoints(points);
  quad.SetPolygon(p);
  if(STATUS==-1){
    quad.SetColor(Color(1,0,0,1));
  }
  else if(STATUS==2){
    quad.SetColor(Color(0,1,0,1));
  }
  score.SetMaxValue(MAX_SCORE);
  score.SetCurrentValue(SCORE);
  score.SetPosition(Point(WIDTH-score.GetWidth(),0));
  STATUS = 1;
}
void Menu::Input(int type, int id, float x, float y){
  if(type==1)
    STATUS=0;
}
void Menu::Loop(){
  
}
void Menu::Render(){
  quad.Draw();
  score.Draw();
}
void Menu::Cleanup(){

}

/* File asteroid.cpp */
#include "asteroid.h"

Asteroid::Asteroid(int type):Object(){
  status = ALIVE;
  penetration = false;
  this->type = type;
  SetColor(Color(0.6,0.2,0,1));
}
int Asteroid::GetType(){
  return type;
}
int Asteroid::GetStatus(){
  return status;
}
void Asteroid::CheckHidden(){
  if(GetCurrentPosition().y<-GetH()/2
  || GetCurrentPosition().x<-GetW()/2
  || GetCurrentPosition().x>WIDTH+GetW()/2){
    status = OFFSCREEN;
  }
}
void Asteroid::Update(){
  Object::Update();
  SetAlpha(ASTEROID_ROTATION_SPEED*GAME_SPEED*SPEED_FACTOR+GetAlpha());
  CheckHidden();
}

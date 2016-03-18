/* File player.cpp */
#include "player.h"

void Player::MoveRight(){
  if(GetCurrentPosition().x<WIDTH-GetW()/2){
    SetPosition(Point(GetCurrentPosition().x+PLAYER_SPEED*GAME_SPEED*SPEED_FACTOR,GetCurrentPosition().y));
    SetAlpha(GetAlpha()+PLAYER_TURN_SPEED*GAME_SPEED*SPEED_FACTOR);
    if(GetAlpha()>16)
      SetAlpha(16);
  }
  else{
    moving = false;
  }
}
void Player::MoveLeft(){
  if(GetCurrentPosition().x>GetW()/2){
    SetPosition(Point(GetCurrentPosition().x-PLAYER_SPEED*GAME_SPEED*SPEED_FACTOR,GetCurrentPosition().y));
    SetAlpha(GetAlpha()-PLAYER_TURN_SPEED*GAME_SPEED*SPEED_FACTOR);
    if(GetAlpha()<-16)
      SetAlpha(-16);
  }
  else{
    moving = false;
  }
}
Player::Player() : Object(){
  max_health=10;
  Res();
  burning_color.Set(1,0,0,1);
  normal_color=GetColor();
  std::vector<Point> points;
  points.push_back(Point(0,0));
  points.push_back(Point(50.0*SCALE,0));
  points.push_back(Point(50.0*SCALE,50.0*SCALE));
  points.push_back(Point(25.0*SCALE,75.0*SCALE));
  points.push_back(Point(0,50.0*SCALE));
  Polygon polygon;
  polygon.SetPoints(points);
  SetPolygon(polygon);
}
void Player::MoveTo(Point tp){
  if(target_position!=tp){
    target_position = tp;
    moving = true;
  }
}
void Player::Die(){
  status = DEAD;
  attack_status = 0;
  visible = false;
}
void Player::Res(){
  status = ALIVE;
  visible = true;
  health=max_health;
  burning_time=-1;
  moving = false;
}
void Player::Damaged(int d){
  burning_time=BURNING_TIME;
  health-=d;
  if(health<=0){
    health=0;
    Die();
  }
}
void Player::OpenFire(){
  if(status==ALIVE){
    attack_status = 1;
  }
}
void Player::StopFire(){
  attack_status = 0;
}
int Player::GetAttackStatus(){
  return attack_status;
}
int Player::GetStatus(){
  return status;
}
int Player::GetHealth(){
  return health;
}
Point Player::GetGunPosition(){
  return GetPolygon().GetPoints()[3];
}
void Player::SetColor(Color color){
  Object::SetColor(color);
  normal_color=color;
}
void Player::SetMaxHealth(int value){
  max_health=value;
}
void Player::SetBurningColor(Color color){
  burning_color=color;
}
void Player::Update(){
  Object::Update();
  if(moving){
    if(target_position.x < GetCurrentPosition().x){
      MoveLeft();
      if(GetCurrentPosition().x <= target_position.x){
        SetPosition(Point(target_position.x, GetCurrentPosition().y));
        moving = false;
      }
    }
    else if(target_position.x > GetCurrentPosition().x){
      MoveRight();
      if(GetCurrentPosition().x >= target_position.x){
        SetPosition(Point(target_position.x, GetCurrentPosition().y));
        moving = false;
      }
    }
  }
  else{
    if(GetAlpha()>0){
      SetAlpha(GetAlpha()-PLAYER_TURN_SPEED*GAME_SPEED*SPEED_FACTOR);
      if(GetAlpha()<0)
        SetAlpha(0);
    }
    else if(GetAlpha()<0){
      SetAlpha(GetAlpha()+PLAYER_TURN_SPEED*GAME_SPEED*SPEED_FACTOR);
      if(GetAlpha()>0)
        SetAlpha(0);
    }
  }
  if(burning_time>=0){
    if(GetColor()==burning_color)
      Object::SetColor(normal_color);
    else
      Object::SetColor(burning_color);
    burning_time-=1.0*GAME_SPEED*SPEED_FACTOR;
  }
  else if(burning_time<0){
    Object::SetColor(normal_color);
    burning_time=-1;
  }
}

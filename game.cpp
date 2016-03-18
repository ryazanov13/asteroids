/* File game.cpp */
#include "game.h"

Polygon Game::GetRandomPolygon(float size){
  Polygon polygon;
  std::vector<Point> points;
  int d = 0;
  while(d <= 360){
    points.push_back(Point(size*cos(d*M_PI/180),size*sin(d*M_PI/180)));
    d += (rand()%80 + 10);
  }
  polygon.SetPoints(points);
  return polygon;
}
bool Game::SplitAsteroid(Asteroid parent, Asteroid* child1, Asteroid* child2){
  if(parent.GetPolygon().GetPoints().size()<4){
    return false;
  }
  std::vector<Point> ch1_points,ch2_points,
  parent_points = parent.GetPolygon().GetPoints();
  int r=parent_points.size()/2;
  for(int i=0;i<parent_points.size();++i){
    if(i<=r){
      ch1_points.push_back(parent_points[i]);
    }
    if(i>=r){
      ch2_points.push_back(parent_points[i]);
    }
  }
  child1->SetPolygon(Polygon(ch1_points));
  child2->SetPolygon(Polygon(ch2_points));
  return true;
}
void Game::Init(){
  srand(time(0));
  touch_id = -1;
  STATUS = 1;
  amount_bullets = 0;
  bullets_timer = 0;
  amount_asteroids = 0;
  asteroids_timer = 0;
  player.SetMaxHealth(3);
  player.Res();
  player.SetPosition(Point(WIDTH/2,player.GetH()));
  lifes_line.SetSize(player.GetHealth());
  lifes_line.SetPosition(Point(0,HEIGHT));
  score.SetMaxValue(MAX_SCORE);
  score.SetCurrentValue(0);
  score.SetPosition(Point(WIDTH-score.GetWidth(),0));
}
void Game::Input(int type, int id, float x, float y){
  if(touch_id<0)
  { 
    touch_id = id;
  }
  if(id==touch_id){
    switch(type){
      case 1: // DOWN;
        player.MoveTo(Point(x,player.GetCurrentPosition().y));
        player.OpenFire();
        break;
      case 2: // MOVE
        player.MoveTo(Point(x,player.GetCurrentPosition().y));
        break;
      case 3: // UP
        touch_id = -1;
        player.StopFire();
        break;
    }
  }
  else{
    touch_id = -1;
  }
}
void Game::Loop(){
  /*---UPDATE---*/
  player.Update();
  for(std::list<Asteroid>::iterator i=asteroids.begin();i!=asteroids.end();++i){
    i->Update();
  }
  for(std::list<Bullet>::iterator i=bullets.begin();i!=bullets.end();++i){
    i->Update();
  }

  score.SetCurrentValue(score.GetCurrentValue()+1*GAME_SPEED*SPEED_FACTOR);
  if(score.GetCurrentValue()==score.GetMaxValue()){
    STATUS=2;
  }

  /*---GENERATE---*/
  if(player.GetAttackStatus()==1 && bullets_timer>=1/(float)ATTACK_SPEED){
    Bullet b;
    b.SetPosition(player.GetGunPosition());
    b.SetSpeed(Point(BULLET_SPEED*cos(-player.GetAlpha()*M_PI/180.0+M_PI/2.0),
                     BULLET_SPEED*sin(-player.GetAlpha()*M_PI/180.0+M_PI/2.0)));
    b.SetAlpha(player.GetAlpha());
    bullets.push_back(b);
    ++amount_bullets;
    bullets_timer=0;
  }
  bullets_timer+=1*GAME_SPEED*SPEED_FACTOR;
  if(asteroids_timer>=1/(float)ASTEROIDS_FREQ){
    Asteroid a(BIG);
    float k;
    k = (float)((rand()%10)/10.0+1);
    a.SetPolygon(GetRandomPolygon(k*ASTEROID_SIZE));
    a.SetPosition(Point((rand()%(int)(WIDTH-a.GetW())+a.GetW()/2),HEIGHT+a.GetH()/2));
    a.SetSpeed(Point(0,-k*ASTEROID_SPEED));
    asteroids.push_back(a);
    ++amount_asteroids;
    asteroids_timer=0;
  }
  asteroids_timer+=1*GAME_SPEED*SPEED_FACTOR;

  /*---COLLISION---*/
  for(std::list<Asteroid>::iterator i=asteroids.begin();i!=asteroids.end();++i){
    if (i->GetStatus()==OFFSCREEN){
      i=asteroids.erase(i);
      --amount_asteroids;
      continue;
    }
    if(player.GetStatus()==ALIVE && Collision::CheckObjects(*i,player)){
      player.Damaged(1);
      if(player.GetStatus()==DEAD){
        STATUS=-1;
        break;
      }
      i=asteroids.erase(i);
      --amount_asteroids;
      continue;
    }
    bool penetration = false;
    for(std::list<Asteroid>::iterator j=asteroids.begin();j!=asteroids.end();++j){
      if(i!=j && Collision::CheckObjects(*i,*j)){
        penetration = true;
        if(!i->penetration && !j->penetration){
          Point temp = i->GetSpeed();
          i->SetSpeed(j->GetSpeed());
          j->SetSpeed(temp);
          i->penetration=true;
          j->penetration=true;
          break;
        }
      }
    }
    if(!penetration){
      i->penetration=false;
    }
  }
  for(std::list<Bullet>::iterator i=bullets.begin();i!=bullets.end();++i){
    if(i->GetStatus()==OFFSCREEN){
      i=bullets.erase(i);
      --amount_bullets;
      continue;
    }
    for(std::list<Asteroid>::iterator j=asteroids.begin();j!=asteroids.end();++j){
      if(Collision::CheckObjects(*j,*i)){
        if(j->GetType()==BIG){
          Asteroid a1(SMALL),a2(SMALL);
          SplitAsteroid(*j,&a1,&a2);
          if(a1.GetCurrentPosition().x>a2.GetCurrentPosition().x){
            a1.SetSpeed(Point(ASTEROID_EXPANSION*SCALE,j->GetSpeed().y));
            a2.SetSpeed(Point(-ASTEROID_EXPANSION*SCALE,j->GetSpeed().y));
          }
          else{
            a1.SetSpeed(Point(-ASTEROID_EXPANSION*SCALE,j->GetSpeed().y));
            a2.SetSpeed(Point(ASTEROID_EXPANSION*SCALE,j->GetSpeed().y));
          }
          a1.penetration = true;
          a2.penetration = true;
          a1.SetColor(Color(0.2,0.1,0,1));
          a2.SetColor(Color(0.2,0.1,0,1));
          asteroids.push_back(a1);
          asteroids.push_back(a2);
          amount_asteroids+=2;
        }
        i=bullets.erase(i);
        j=asteroids.erase(j);
        --amount_bullets;
        --amount_asteroids;
        break;
      }
    }
  }

  /*---COUNT LIFES---*/
  lifes_line.SetSize(player.GetHealth());
}
void Game::Render(){
  player.Draw();
  for (std::list<Bullet>::iterator i = bullets.begin() ; i!=bullets.end(); ++i){
    i->Draw();
  }
  for (std::list<Asteroid>::iterator i = asteroids.begin() ; i!=asteroids.end(); ++i){
    i->Draw();
  }
  lifes_line.Draw();
  score.Draw();
}
void Game::Cleanup(){
  SCORE=score.GetCurrentValue();
}

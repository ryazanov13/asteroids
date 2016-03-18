/* File player.h */
#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

class Player : public Object{
  private:
    int health,max_health;
    int status;
    int attack_status;
    Point target_position;
    bool moving;
    float burning_time;
    Color burning_color, normal_color;
    void MoveRight();
    void MoveLeft();
  public:
    Player();
    void MoveTo(Point tp);
    void Die();
    void Res();
    void Damaged(int d);
    void OpenFire();
    void StopFire();
    int GetAttackStatus();
    int GetStatus();
    int GetHealth();
    Point GetGunPosition();
    void SetColor(Color color);
    void SetMaxHealth(int value);
    void SetBurningColor(Color color);
    void Update();
};

#endif
/* PLAYER_H */

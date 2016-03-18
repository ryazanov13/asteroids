/* File bullet.h */
#ifndef BULLET_H
#define BULLET_H

#include "object.h"

class Bullet : public Object{
  private:
    int status;
  public:
    Bullet();
    int GetStatus();
    void CheckHidden();
    void Update();
};

#endif
/* BULLET_H */

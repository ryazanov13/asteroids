/* File asteroid.h */
#ifndef ASTEROID_H
#define ASTEROID_H

#include "object.h"

#define BIG     1
#define SMALL   2

class Asteroid : public Object{
  private:
    int status;
    int type;
  public:
    bool penetration;
    Asteroid(int type);
    int GetType();
    int GetStatus();
    void CheckHidden();
    void Update();
};

#endif
/* ASTEROID_H */

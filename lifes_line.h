/* File lifes_line.h */
#ifndef LIFES_LINE_H
#define LIFES_LINE_H

#include <list>

#include "object.h"

class Life : public Object{
  private:
    float size;
  public:
    Life();
};

class LifesLine{
  private:
    std::list<Life> lifes;
    int size;
    float gap;
    Point pos;
    void Increase(int value);
    void Dencrease(int value);
  public:
    LifesLine();
    void SetSize(int size);
    void SetPosition(Point pos);
    int GetSize();
    Point GetPosition();
    void Draw();
};

#endif
/* LIFES_LINE_H */

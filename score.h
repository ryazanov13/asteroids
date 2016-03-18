/* File score.h */
#ifndef SCORE_H
#define SCORE_H

#include "object.h"

class Score{
  private:
    float max_value,current_value;
    float width,degree;
    Object back,body;
    Point pos;
    void UpdateBack();
    void UpdateBody();
    void Init();
  public:
    Score();
    void SetMaxValue(float value);
    void SetCurrentValue(float value);
    void SetPosition(Point pos);
    void SetWidth(float w);
    void SetBodyColor(Color c);
    void SetBackColor(Color c);
    float GetMaxValue();
    float GetCurrentValue();
    Point GetPosition();
    float GetWidth();
    void Draw();
};

#endif
/* SCORE_H */

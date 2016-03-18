/* File object.h */
#ifndef OBJECT_H
#define OBJECT_H

#include "global.h"
#include "game_const.h"
#include "scene.h"

#define ALIVE     1
#define DEAD      2
#define OFFSCREEN 3

class Object{
  private:
    Polygon polygon;
    Color color;
    Point prev_pos, current_pos, speed;
    float alpha,scale_w,scale_h;
    float w,h;
  protected:
    bool visible;
    void Move();
    void SetParameters();
  public:
    Object();
    void SetPolygon(Polygon polygon);
    void SetColor(Color color);
    void SetPosition(Point pos);
    void SetSpeed(Point speed);
    void SetAlpha(float alpha);
    void SetScale(float scale_w, float scale_h);
    void SetVisible(bool value);
    Polygon GetPolygon();
    Color GetColor();
    Point GetCurrentPosition();
    Point GetPrevPosition();
    Point GetSpeed();
    float GetAlpha();
    float GetW();
    float GetH();
    float GetScaleW();
    float GetScaleH();
    void Update();
    void Draw();
};

#endif
/* OBJECT_H */

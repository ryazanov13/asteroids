/* File scene.h */
#ifndef SCENE_H
#define SCENE_H

#include "graphics.h"
#include "help.h"
#include "point.h"
#include "color.h"
#include "polygon.h"

class Scene{
  private:
    unsigned int frame_count;
  public:
    Scene();
    static void DrawPolygon(std::vector<Point> points, int count, bool fill, Color color);
    static void DrawPoint(Point point, int size, Color color);
    void Update();
    unsigned int GetFrameCount();
    virtual void Init()=0;
    virtual void Input(int type, int id, float x, float y)=0;
    virtual void Loop()=0;
    virtual void Render()=0;
    virtual void Cleanup()=0;
};

#endif
/* SCENE_H */

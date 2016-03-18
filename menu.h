/* File menu.h */
#ifndef MENU_H
#define MENU_H

#include "global.h"
#include "scene.h"
#include "object.h"
#include "score.h"

class Menu : public Scene{
  private:
    Object quad;
    Score score;
  public:
    void Init();
    void Input(int type, int id, float x, float y);
    void Loop();
    void Render();
    void Cleanup();
};

#endif
/* MENU_H */

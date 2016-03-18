/* File app.h */
#ifndef APP_H
#define APP_H

#include "global.h"
#include "scene.h"
#include "timer.h"
#include "game.h"
#include "menu.h"

class App{
  private:
    Scene* scene;
    Timer timer;
    int scene_number;
    static App instance;
    App();
  public:
    static App* GetInstance();
    void Deinit();
    void SetScene(int i);
    void Init();
    void Resize(int w, int h, int dpi);
    void Update();
    void Input(int type, int id, float x, float y);
};

// App App::instance;

#endif
/* APP_H */

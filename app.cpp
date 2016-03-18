/* File app.cpp */
#include "app.h"

App App::instance;

App::App(){
  scene_number=-1;
}
App* App::GetInstance(){
  return &instance;
}
void App::Deinit(){
  scene->Cleanup();
  delete scene;
  scene_number = -1;
  STATUS=0;
}
void App::SetScene(int i){
  if(scene_number>=0){
    scene->Cleanup();
    delete scene;
  }
  scene_number=i;
  if(i==0) scene = new Game();
  if(i==1) scene = new Menu();
  scene->Init();
}
void App::Init(){
  timer.Start();
}
void App::Resize(int w, int h, int dpi){
  WIDTH=w;
  HEIGHT=h;
  SCALE = w*dpi/(1000.0*90);
  g_setup(w,h);

  if(scene_number<0){
    SetScene(0);
  }
}
void App::Update(){
  // FPS=SEC/timer.GetElapsedTime();
  SPEED_FACTOR=(float)timer.GetElapsedTime()/SEC;
  timer.Start();
  scene->Update();
  if(STATUS!=1){
    switch(scene_number){
      case 0:
        SetScene(1);
        break;
      case 1:
        SetScene(0);
        break;
    }
  }
  wait(TARGET_FRAME_TIME-timer.GetElapsedTime());
}
void App::Input(int type, int id, float x, float y){
  scene->Input(type, id, x, y);
}

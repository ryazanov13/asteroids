/* File scene.cpp */
#include "scene.h"

Scene::Scene(){
  frame_count = 0;
}
void Scene::DrawPolygon(std::vector<Point> points, int count, bool fill, Color color){
  float vertices[count*3];
  for(int i = 0 ; i < points.size(); ++i){
    vertices[i*3] = points[i].x;
    vertices[i*3+1] = points[i].y;
    vertices[i*3+2] = 0;
  }
  g_draw_polygon(vertices,count,fill,color.r,color.g,color.b,color.a);
}
void Scene::DrawPoint(Point point, int size, Color color){
  float vertices[3];
  vertices[0] = point.x;
  vertices[1] = point.y;
  vertices[2] = 0;
  g_draw_point(vertices,size,color.r,color.g,color.b,color.a);
}
void Scene::Update(){
  g_clear();
  this->Loop();
  this->Render();
  ++frame_count;
}
unsigned int Scene::GetFrameCount(){
  return frame_count;
}

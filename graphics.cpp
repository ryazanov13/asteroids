/* File graphics.cpp */
#include "graphics.h"

void g_setup(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0,w, 0.0,h, -1,1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(0,0,0,0);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
}

void g_draw_polygon(float vertices[], int count, bool fill, float r, float g, float b, float a){
  glColor4f(r,g,b,a);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  if(fill){
    glDrawArrays(GL_TRIANGLE_FAN, 0, count);
  }
  else{
    glDrawArrays(GL_LINE_LOOP, 0, count);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void g_draw_point(float vertices[], int size, float r, float g, float b, float a){
  glColor4f(r,g,b,a);
  glPointSize(size);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glDrawArrays(GL_POINTS, 0, 1);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void g_clear(){
  glClear(GL_COLOR_BUFFER_BIT);
}
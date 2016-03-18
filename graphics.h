/* File graphics.h */
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <GL/gl.h>

void g_setup(int w, int h);

void g_draw_polygon(float vertices[], int count, bool fill, float r, float g, float b, float a);

void g_draw_point(float vertices[], int size, float r, float g, float b, float a);

void g_clear();

#endif
/* GRAPHICS_H */

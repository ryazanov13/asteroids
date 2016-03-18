/* File main.h */
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <GL/glut.h>

#include "app.h"

void init();

void display(void);

void reshape(int width, int height);

void motion(int x,int y);

void mouse(int button, int state, int x, int y);

void deinit();

int main(int argc, char **argv);

#endif
/* MAIN_H */

/* File main.cpp */
#include "main.h"

void init(){
  App::GetInstance()->Init();
}

void display(void)
{
  App::GetInstance()->Update();
  glutSwapBuffers();
  glutPostRedisplay();
}

void reshape(int width, int height)
{
  App::GetInstance()->Resize(width, height, 90);
}

void motion(int x,int y)
{
  App::GetInstance()->Input(2,0,x,y);
}

void mouse(int button, int state, int x, int y)
{
  if(button==GLUT_LEFT_BUTTON){
    switch (state){
      case GLUT_DOWN:
        App::GetInstance()->Input(1,0,x,y);
        break;
      case GLUT_UP:
        App::GetInstance()->Input(3,0,x,y);
        break;
    }
  }
}

void deinit(){
  App::GetInstance()->Deinit();
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Asteroids");
  init();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutMainLoop();
  deinit();

  return 0;
}

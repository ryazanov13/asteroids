/* File color.h */
#ifndef COLOR_H
#define COLOR_H

class Color{
  public:
    float r,g,b,a;
    Color();
    Color(float r, float g, float b, float a);
    void Set(float r, float g, float b, float a);
};

Color operator+(Color left, Color right);
bool operator==(Color left, Color right);

#endif
/* COLOR_H */

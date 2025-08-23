#pragma once
#include <ncurses.h>

class Estudiante
{
public:

  void setup();
  void draw();

  void update();

  void setX(int x);
  void setY(int y);
  int getX();
  int getY();

  void setVidas(int vidas);
  int getVidas();

private:
  int m_x, m_y;
  int m_vidas;
};

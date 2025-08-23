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

  void setTiempo (float tiempo);
  float getTiempo();

  void setVidas(int vidas);
  int getVidas();

private:
  int m_x, m_y;
  float m_tiempo;
  int m_vidas;
  bool m_crisis;
};

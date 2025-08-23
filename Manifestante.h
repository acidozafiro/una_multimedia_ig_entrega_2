#pragma once
#include <ncurses.h>
#include <cstdlib> // Contiene la función rand()

class Manifestante
{
public:
  Manifestante(int x, int y);
  void update();
  void draw();

private:
  float m_x, m_y;
};

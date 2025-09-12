#pragma once
#include <ncurses.h>
#include <cstdlib> // Contiene la función rand()
#include "Estudiante.h"

class Manifestante
{
public:
  Manifestante(int x, int y);
  void update();
  void draw();
  void colision(Estudiante &rEstudiante);

  int getX();
  int getY();

private:
  float m_x, m_y;
};

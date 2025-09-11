#pragma once
#include <ncurses.h>
#include <cstdlib> // Contiene la función rand()
#include Estudiante.h

class Estudiante;

class Manifestante
{
public:
  Manifestante(int x, int y);
  void update();
  void draw();

// Crearemos el método colision() que servirá para implementar la
  // colisión con el estudiante. Necesitaremos como parámetro una referencia
  // al objeto del tipo estudiante. Por un lado usaremos una referencia para no
  // crear un duplicado del estudiante en la memoria, pero por otra parte,
  // la referencia nos permitirá hacer cambios en el objeto, como por
  // ejemplo disminuir la energía del estudiante. Disminuir la energía en una
  // copia del objeto nave no nos serviría, porque no bajaría la energía
  // del estudiante que estamos usando (que es la original).
  void colision(Estudiante &rEstudiante);

private:
  float m_x, m_y;


};

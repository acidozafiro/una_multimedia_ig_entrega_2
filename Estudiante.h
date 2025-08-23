#pragma once
#include <ncurses.h>

class Estudiante
{
public:
  // En este caso no escribiremos el método constructor por lo que
  // estaremos utilizando el método constructor por defecto.
  // Al no explicitar el método constructor se utiliza el método
  // constructor por defecto que sería como tener escrito algo así:
  // Estudiante ();

  // Método para inicializar los valores que necesita el estudiante.
  void setup();

  // Método para dibujar el estudiante.
  void draw();

  // Getters y Setters.
  void setX(int x);
  void setY(int y);
  int getX();
  int getY();

private:
  int m_x, m_y;
};

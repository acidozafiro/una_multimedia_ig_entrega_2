#include "Estudiante.h"

void Estudiante::setup()
{
  // Al inicial el juego colocamos al estudiante en el centro abajo de la pantalla.
  m_x = 60;
  m_y = 38;

  m_vidas = 3;
}

void Estudiante::draw()
{
  /******************\ 
   Dibujo del estudiante
           O
          -|-
          / \
  \******************/

  mvaddch(m_y, m_x + 2, 'O');
  mvaddch(m_y + 1, m_x + 1, '-');
  mvaddch(m_y + 1, m_x + 2, '|');
  mvaddch(m_y + 1, m_x + 3, '-');
  mvaddch(m_y + 2, m_x + 1, '/');
  mvaddch(m_y + 2, m_x + 2, ' ');
  mvaddch(m_y + 2, m_x + 3, '\');
}

///////////////////////////////////////////////////////////////////////////
void Estudiante::setX(int x) { m_x = x; }
void Estudiante::setY(int y) { m_y = y; }

///////////////////////////////////////////////////////////////////////////
int Nave::getX() { return m_x; }
int Nave::getY() { return m_y; }

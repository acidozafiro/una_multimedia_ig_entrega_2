#include "Manifestante.h"
#include "Estudiante.h"

Manifestante::Manifestante(int x, int y)
{
  m_x = x;
  m_y = y;
}

void Manifestante::update()
{
  // se mueve de izq a der
  m_x = m_x + 0.4;
  
  if (m_x >= 119)
  {
    // Cuando el manifestante llegue al límite lo llevamos a una posicion random de 'y' con x=1
    m_y = rand() % 38 + 1; 
    m_x = 1;
  }
}

void Manifestante::draw()
{
  /******************\ 
  Dibujo del manifestante
        0  {¡#!}
       - -   |  
       / \      
  \******************/ 
  mvaddch(m_y, m_x, ' 0  {¡#!}');
  mvaddch(m_y + 1, m_x, '- -   |  ');
  mvaddch(m_y + 2, m_x, '/ \      ');
}

void Manifestante::colision(Estudiante &rEstudiante)
{
  // Verificamos la colisión. box de manifestante es de 9x ; 3y. box de estudiante es de 3x ; 3y
  if(m_x >= rEstudiante.getX() && m_x <= rEstudiante.getX() + 9 && m_y >= rEstudiante.getY() && m_y <= rEstudiante.getY() + 3)
  {
    // disminuimos las vidas del estudiante.
    rEstudiante.setVidas(rEstudiante.getVidas() - 1);

    // volvemos a colocar al manifestante al costado izq
    m_y = rand() % 38 + 1; 
    m_x = 1;
  }
}

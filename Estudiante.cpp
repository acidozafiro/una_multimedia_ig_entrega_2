#include "Estudiante.h"

void Estudiante::setup()
{
  // Al inicial el juego colocamos al estudiante en el centro abajo de la pantalla.
  m_x = 60;
  m_y = 10;
  //m_tiempo = 100;
  m_vidas = 3;
  //m_crisis = false;
}

void Estudiante::update()
{
  //if (m_tiempo <= 0)
	//{
    //m_crisis = true;
    //m_vidas--;
    //m_tiempo = 100;
  }
}

void Estudiante::draw()
{
 //0 if (!m_crisis)
  //{
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
  mvprintw(m_y + 2, m_x + 3, R"( \ )");
  //}
  //else
  //{
    // Fotograma 1 de la explosión.
    /******************\ 
             *
            *.*
            * *
    \******************/
    //mvprintw(m_y, m_x - 2, "    *    ");
    //mvprintw(m_y + 1, m_x - 2, "   *.*   ");
    //mvprintw(m_y + 2, m_x - 2, "   * *   ");    
    
    //refresh();
    //delay_output(200);

    // Fotograma 2 de la explosión.
    /******************\ 
        \    *    /
         *  . .  *
        *  .   .  *
         /   *   \
    \******************/
    //mvprintw(m_y - 1, m_x - 3, R"(\    *    /)");
    //mvprintw(m_y, m_x - 2, "*  * *  *");
    //mvprintw(m_y + 1, m_x - 3, "*  *   *  *");
    //mvprintw(m_y + 2, m_x - 2, "*  * *  *");
    //mvprintw(m_y + 3, m_x - 3, R"( /   *   \ )");

    // Pausa para ver el fotograma 2.
    //refresh();
    //delay_output(200);
    
    //m_crisis = false;
  //}
}

//Setters y Getters de posicion
void Estudiante::setX(int x) { m_x = x; }
void Estudiante::setY(int y) { m_y = y; }

int Estudiante::getX() { return m_x; }
int Estudiante::getY() { return m_y; }

//Setters y Getters de variables
void Estudiante::setTiempo (float tiempo) { m_tiempo = tiempo; }
float Estudiante::getTiempo() { return m_tiempo; }

void Estudiante::setVidas(int vidas) { m_vidas = vidas; }
int Estudiante::getVidas() { return m_vidas; }

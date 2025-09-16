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
  mvprintw(m_y, m_x, " 0  {¡#!}");
  mvprintw(m_y + 1, m_x, "- -   |  ");
  mvprintw(m_y + 2, m_x, "/ \     ");
}

void Manifestante::colision(Estudiante &rEstudiante)
{
  // Verificamos la colisión. box de manifestante es de 9x ; 3y. box de estudiante es de 3x ; 3y
  if (rEstudiante.getX() < m_x + 9 && 
    rEstudiante.getX() + 3 > m_x &&
    rEstudiante.getY() < m_y + 3 && 
    rEstudiante.getY() + 3 > m_y)
	  {
    //MENSAJES QUE APARECEN DE FORMA RANDOM. ACÁ PODRIAMOS USAR LOS ENUMERADOS Y EL ARRAY?
    
    	for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

    	mvaddch(9, 39, ACS_ULCORNER);
	    mvaddch(9, 80, ACS_URCORNER);
	    mvaddch(16, 39, ACS_LLCORNER);
    	mvaddch(16, 80, ACS_LRCORNER);
    	mvhline(9, 40, ACS_HLINE, 40);
	    mvhline(16, 40, ACS_HLINE, 40);
	    mvvline(10, 39, ACS_VLINE, 6);
    	mvvline(10, 80, ACS_VLINE, 6);

	    mvprintw(12, 55, "NO AL VETO DE LA LEY DE FINANCIAMIENTO UNIVERSITARIO");

      for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

    	mvaddch(9, 39, ACS_ULCORNER);
	    mvaddch(9, 80, ACS_URCORNER);
	    mvaddch(16, 39, ACS_LLCORNER);
    	mvaddch(16, 80, ACS_LRCORNER);
    	mvhline(9, 40, ACS_HLINE, 40);
	    mvhline(16, 40, ACS_HLINE, 40);
	    mvvline(10, 39, ACS_VLINE, 6);
    	mvvline(10, 80, ACS_VLINE, 6);

	    mvprintw(12, 55, "RECOMPOSICIÓN SALARIAL DOCENTE YA");

      for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

    	mvaddch(9, 39, ACS_ULCORNER);
	    mvaddch(9, 80, ACS_URCORNER);
	    mvaddch(16, 39, ACS_LLCORNER);
    	mvaddch(16, 80, ACS_LRCORNER);
    	mvhline(9, 40, ACS_HLINE, 40);
	    mvhline(16, 40, ACS_HLINE, 40);
	    mvvline(10, 39, ACS_VLINE, 6);
    	mvvline(10, 80, ACS_VLINE, 6);

	    mvprintw(12, 55, "ESTUDIÁ, NO SEAS LIBERTARIO");

      for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

    	mvaddch(9, 39, ACS_ULCORNER);
	    mvaddch(9, 80, ACS_URCORNER);
	    mvaddch(16, 39, ACS_LLCORNER);
    	mvaddch(16, 80, ACS_LRCORNER);
    	mvhline(9, 40, ACS_HLINE, 40);
	    mvhline(16, 40, ACS_HLINE, 40);
	    mvvline(10, 39, ACS_VLINE, 6);
    	mvvline(10, 80, ACS_VLINE, 6);

	    mvprintw(12, 55, "SIN EDUCACIÓN NO HAY DEMOCRACIA");

      for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

    	mvaddch(9, 39, ACS_ULCORNER);
	    mvaddch(9, 80, ACS_URCORNER);
	    mvaddch(16, 39, ACS_LLCORNER);
    	mvaddch(16, 80, ACS_LRCORNER);
    	mvhline(9, 40, ACS_HLINE, 40);
	    mvhline(16, 40, ACS_HLINE, 40);
	    mvvline(10, 39, ACS_VLINE, 6);
    	mvvline(10, 80, ACS_VLINE, 6);

	    mvprintw(12, 55, "MILEI VETAME ESTA");

    
    // disminuimos las vidas del estudiante.
   int vidasActuales = rEstudiante.getVidas();
        rEstudiante.setVidas(vidasActuales - 1);
    // volvemos a colocar al manifestante al costado izq
    m_y = rand() % 38 + 1; 
    m_x = 1;
  }
}

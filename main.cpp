//=========================================================================
// OBJETIVO: LLEGAR A RENDIR UN FINAL
// OBSTACULOS: TIEMPO 
// PERSONAJES: JUGADOR + MANIFESTANTES
//=========================================================================

#include <iostream>
#include <ncurses.h>
#include "Estudiante.h"

using namespace std;

//// DECLARACION CONSTANTES ////

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;

//// DECLARACION VARIABLES GLOBALES ////

bool game_over;
int vidas;
float tiempo;
bool salir;

Estudiante miEstudiante ;

//// DECLARACION FUNCIONES GLOBALES ////

void setup();
void input();
void update();
void draw();
void gameover();

//// MAIN ////

int main() 
{
	initscr();
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

    if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}

    setup();

	salir = false;

    while (!salir)
	{
		while (!game_over)
		{
			input();
			update();
			draw();
		}
		gameover();
	}
    
	endwin();

	cout << endl;
	return 0;
}

//// DEFINICION FUNCIONES GLOBALES ////

void setup()
{
	game_over = false;
    vidas = 3;
    tiempo = 100; 

	miEstudiante.setup();
}

void input()
{
	int tecla = getch();

	switch (tecla)
	{
	case KEY_UP:
		miEstudiante.setY(miEstudiante.getY() - 1);
		break;
	case KEY_DOWN:
		miEstudiante.setY(miEstudiante.getY() + 1);
		break;
	case KEY_LEFT:
		miEstudiante.setX(miEstudiante.getX() - 1);
		break;
	case KEY_RIGHT:
		miEstudiante.setX(miEstudiante.getX() + 1);
		break;
	case 27: // 27: tecla esc
		game_over = true;
		break;
	default:
		break;
	}
}

void update()
{
    // contador de tiempo: 
	tiempo -- ;
    if (tiempo <= 0) 
    {
        vidas -- ;
		tiempo = 100
	}
    if (vidas <= 0)
    {
        game_over = true;
    }
}	

// switch (nivel)
    //{
        //case 1: 
        // LA CASA
        //break;
        
        //case 2: 
        // SUBTE
        //break;

        //case 3: 
        // MANIFESTANTES
        //break;
    //}
}

void draw()
{
	erase();
	box(stdscr, 0, 0);

	miEstudiante.draw();

	refresh();
	delay_output(DELAY);
}

void gameover()
{
	for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

	mvaddch(9, 39, ACS_ULCORNER);
	mvaddch(9, 80, ACS_URCORNER);
	mvaddch(16, 39, ACS_LLCORNER);
	mvaddch(16, 80, ACS_LRCORNER);
	mvhline(9, 40, ACS_HLINE, 40);
	mvhline(16, 40, ACS_HLINE, 40);
	mvvline(10, 39, ACS_VLINE, 6);
	mvvline(10, 80, ACS_VLINE, 6);

	mvprintw(12, 55, "GAME OVER");
	mvprintw(13, 50, "VOLVER A JUGAR? (S/N)");

	int opcion = getch();

	if (opcion == 's' || opcion == 'S')
	{
		setup();
	}
	else if (opcion == 'n' || opcion == 'N')
	{
		salir = true;
	}
}

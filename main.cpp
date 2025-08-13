//=========================================================================
// OBJETIVO: LLEGAR A RENDIR UN FINAL
// OBSTACULOS: TIEMPO + 
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
int puntaje;
bool salir;
int vidas;
float tiempo;


//// DECLARACION FUNCIONES GLOBALES ////

void setup();
void input();
void update();
void draw();
void gameover();

//// DEFINICION FUNCIONES GLOBALES ////

void setup()
{
	game_over = false;
	puntaje = 0;
    vidas = 3;
    tiempo = 440; 
}
void input()
{
	int tecla = getch();

	switch (tecla)
	{
	case KEY_UP:
		break;
	case KEY_DOWN:
		break;
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	case 27: // 27: tecla esc
		game_over = true;
		break;
	default:
		break;
	}
}
//* ///////////////////////////////////////////////////////////////////////
void update()
{
    // contador de tiempo: tiempo--;
    if (tiempo <= 0) 
    {
        vidas --;
            if (vidas =0)
            {
                game_over = true;
                else 
                    tiempo = 440; //reinicia el tiempo
            }
    }

    switch (nivel)
    {
        case 1: 
        // LA CASA
        break;
        
        case 2: 
        // SUBTE
        break;

        case 3: 
        // MANIFESTANTES
        break;
    }
}

//* ///////////////////////////////////////////////////////////////////////
void draw()
{
	erase();
	box(stdscr, 0, 0);

	refresh();
	delay_output(DELAY);
}


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

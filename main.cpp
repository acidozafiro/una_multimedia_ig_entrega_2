//=========================================================================
// OBJETIVO: LLEGAR A RENDIR UN FINAL
// OBSTACULOS: TIEMPO 
// PERSONAJES: JUGADOR + MANIFESTANTES
//=========================================================================

#include <iostream>
#include <ncurses.h>
#include "Estudiante.h"

#include <cstdlib> // Contiene la función rand() y srand()
#include <ctime> // Contiene la función time()
#include "Manifestante.h"

using namespace std;

//// DECLARACION CONSTANTES ////

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;
/// MENU ///
enum Estados {
    ESTADO_MENU,
    ESTADO_JUGANDO,
    ESTADO_INSTRUCCIONES,
    ESTADO_GAMEOVER,
    ESTADO_SALIR
};

// Opciones del menú
enum MenuOpciones {
    MENU_JUGAR = 1,
    MENU_INSTRUCCIONES,
    MENU_SALIR
};
//// DECLARACION VARIABLES GLOBALES ////

bool game_over;
int vidas;
float tiempo;
bool crisis;
bool salir;

Estudiante miEstudiante;
Manifestante manifestante_01 (10,2);

// Creamos dos objeto más del tipo Manifestante.
Manifestante manifestante_02(4, 8), manifestante_03(15, 10);


//// DECLARACION FUNCIONES GLOBALES ////

void setup();
void input();
void update();
void draw();
void gameover();
int menuPrincipal();          
void mostrarInstrucciones();

//// MAIN ////
int main() 
{
    srand(time(0));
    initscr();
    noecho();
    curs_set(false);
    keypad(stdscr, true);
    nodelay(stdscr, true);

    if (LINES < ALTO || COLS < ANCHO) {
        endwin();
        printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
        exit(1);
    }

    Estados estadoJuego = ESTADO_MENU;
    salir = false;

    while (!salir) {
        switch (estadoJuego) {
            case ESTADO_MENU: {
                int opcion = menuPrincipal();
                if (opcion == MENU_JUGAR) estadoJuego = ESTADO_JUGANDO;
                else if (opcion == MENU_INSTRUCCIONES) estadoJuego = ESTADO_INSTRUCCIONES;
                else if (opcion == MENU_SALIR) estadoJuego = ESTADO_SALIR;
                break;
            }

            case ESTADO_INSTRUCCIONES:
                mostrarInstrucciones();
                estadoJuego = ESTADO_MENU;
                break;

            case ESTADO_JUGANDO:
                setup();
                while (!game_over) {
                    input();
                    update();
                    draw();
                }
                estadoJuego = ESTADO_GAMEOVER;
                break;

            case ESTADO_GAMEOVER:
                gameover();
                estadoJuego = ESTADO_MENU;
                break;

            case ESTADO_SALIR:
                salir = true;
                break;
        }
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
		if (miEstudiante.getY() > 1) miEstudiante.setY(miEstudiante.getY() - 1);
		break;
	case KEY_DOWN:
		if (miEstudiante.getY() < ALTO - 4) miEstudiante.setY(miEstudiante.getY() + 1);
		break;
	case KEY_LEFT:
		if (miEstudiante.getX() > 1) miEstudiante.setX(miEstudiante.getX() - 1);
		break;
	case KEY_RIGHT:
		if (miEstudiante.getX() < ANCHO - 4) miEstudiante.setX(miEstudiante.getX() + 1);
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
	miEstudiante.update();

	//perder vidas
	if (miEstudiante.getTiempo() <=0 ) crisis = true;
	if (miEstudiante.getVidas() <= 0) game_over = true;

	manifestante_01.update();

	// Actualizamos los valores de los dos manifestantes nuevos.
	manifestante_02.update();
	manifestante_03.update();

	// Vamos verificando las colisiones de los tres manifestantes con el estudiante.
	manifestante_01.colision(miEstudiante);
	manifestante_02.colision(miEstudiante);
	manifestante_03.colision(miEstudiante);

}	

void draw()
{
	erase();
	box(stdscr, 0, 0);

// Dibujamos la interfaz que muestra el tiempo NO SE SI ESTA BIEN, CHECKEAR QUE FUNCIONE
	mvprintw(0, 80, "[ TIEMPO:     ]");
	mvaddch(0, 91 + 1, '1');
	mvaddch(0, 91 + 2, '0');
	mvaddch(0, 91 + 3, '0');

// Dibujamos la interfaz que muestra las vidas.
// Usamos el caracter ♥ para las vidas
	mvprintw(0, 100, "[ VIDAS:     ]");

	for (int i = 0; i < miEstudiante.getVidas(); i++)
	{
		mvaddch(0, 109 + i, ACS_HEART);
	}

	
	miEstudiante.draw();
	manifestante_01.draw();

	// Dibujamos los dos manifestantes nuevos.
	manifestante_02.draw();
	manifestante_03.draw();
	
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
		game_over = false;
	}
	else if (opcion == 'n' || opcion == 'N')
	{
		salir = true;
	}
}
int menuPrincipal()
	{
    while (true)
    {
        erase();
        box(stdscr, 0, 0);
        mvprintw(2, 4, "=== Titulo del juego ===");
        mvprintw(4, 4, "%d) Jugar",       MENU_JUGAR);
        mvprintw(5, 4, "%d) Instrucciones", MENU_INSTRUCCIONES);
        mvprintw(6, 4, "%d) Salir",        MENU_SALIR);
        mvprintw(8, 4, "Selecciona una opcion y presiona ENTER...");
        refresh();

        int tecla = getch();

        switch (tecla)
        {
        case '1': return MENU_JUGAR;
        case '2': return MENU_INSTRUCCIONES;
        case '3': return MENU_SALIR;
        default: break;
        }
    }
}

void mostrarInstrucciones()
{
    erase();
    box(stdscr, 0, 0);
    mvprintw(2, 4, "===Titulo===");
    mvprintw(4, 4, "Objetivo del juego:");
    mvprintw(5, 6, "Llegar a rendir el final antes de que se acabe el tiempo.");
    mvprintw(7, 4, "Controles:");
    mvprintw(8, 6, "Flechas - Mover al estudiante");
    mvprintw(9, 6, "ESC     - Salir del juego");
    mvprintw(11, 4, "Evita chocar con los manifestantes!");
    mvprintw(13, 4, "Presiona cualquier tecla para volver...");
    refresh();
    getch();
}






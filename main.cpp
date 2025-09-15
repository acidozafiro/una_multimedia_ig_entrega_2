//=========================================================================
// OBJETIVO: LLEGAR A RENDIR UN FINAL
// OBSTACULOS: TIEMPO 
// PERSONAJES: JUGADOR + MANIFESTANTES
//=========================================================================


// PONGO EL MENU PRINCIPAL ACA PORQUE NO SE DONDE IRIA

// MENU PRINCIPAL
//system("clear");
// acá iría el ASCII con el título del juego y debajo:
//cout << "ELEGÍ UNA OPCIÓN\n";
//cout << "1. INSTRUCCIONES\n";
//cout << "2. CRÉDITOS\n";
//cout << "3. EMPEZAR JUEGO\n";

 //switch (decision) 
 //{
//	case 1: {
	//	cout << "                                   INSTRUCCIONES:\n"; 			
	//	cout << "          ESTÁS ESTUDIANDO EN LA UNA Y TENÉS QUE IR A RENDIR UN FINAL,\n"
	//	cout <<	"     PERO ESTÁS LLEGANDO TARDE Y TE CRUZÁS CON LA MARCHA FEDERAL UNIVERSITARIA.\n";
	//	cout << "                    USA LAS FLECHAS PARA MOVERTE POR EL ESPACIO\n";
	//	cout << "¡RÁPIDO! TRATÁ DE EVITAR LA REALIDAD DEL CONFLICTO UNIVERSITARIO PARA AVANZAR EN TU CARRERA\n";
//    }
//	case 2: {
		cout << "                                   REALIZADORES:\n";
		cout << "									LUCA DEIRA\n";
		cout << "									VALENTÍN MOSEINCO\n";
		cout << "									LUCERO SANTIN\n";
		cout << "						PROGRAMADO A CONTRARRELOJ EN ARGENTINA.\n";
		cout << "			INFORMÁTICA GENERAL, CÁTEDRA TIRIGALL, UNA MULTIMEDIALES, 2025.\n";
    }
//    case 3: {
  //  system("clear");
   // }
   // default:
  //  cin.clear();
   // cin.ignore();
   // cout << "Opción no válida, " << nombre << " intentá nuevamente.\n\n";
   // cout << "Presione ENTER para volver al menú principal";
   // cin.ignore().get();
   // break;
   // }
//}


#include <iostream>
#include <ncurses.h>
#include <string>
#include <cstdlib> // Contiene la función rand() y srand()
#include <ctime> // Contiene la función time()
#include <vector>
#include "Estudiante.h"
#include "Manifestante.h"

using namespace std;

//// DECLARACION CONSTANTES ////

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;

//// DECLARACION VARIABLES GLOBALES ////

bool game_over;
int vidas;
float tiempo;
bool crisis;
bool salir;

Estudiante miEstudiante;
vector <Manifestante> Manifestantes; 


//// DECLARACION FUNCIONES GLOBALES ////

void setup();
void input();
void update();
void draw();
void gameover();

//// MAIN ////

int main() 
{
	// esto es para que reconozca el char de corazon que usamos en las vidas. checkear si funciona!
	setlocale(LC_ALL, "");
	
	srand(time(0));
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

	Manifestantes.clear();

	for (int i = 0; i < 20; i++)
	{
		Manifestantes.push_back(Manifestante(rand() % 119 + 1, rand() % 38 + 1));
	}
}

//hacemos mover al estudiante
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
	//perder vidas y perder juego
	if (miEstudiante.getTiempo() <=0 ) crisis = true;
	if (miEstudiante.getVidas() <= 0) game_over = true;

	//update de los manifestantes
	for (int i = 0; i < Manifestantes.size(); i++)
	{
		Manifestantes[i].update();
		Manifestantes[i].colision(miEstudiante);
	}

	//para que el Estudiante pierda tiempo 
	tiempo--;
}	

void draw()
{
	erase();
	box(stdscr, 0, 0);

// Dibujamos la interfaz que muestra el tiempo NO SE SI ESTA BIEN, CHECKEAR QUE FUNCIONE... TIENE QUE IR BAJANDO DE A 1 HASTA 0.
	mvprintw(0, 80, "[ TIEMPO:     ]");
	mvprintw(0, 91, "%3d", (int)miEstudiante.getTiempo());

// Dibujamos la interfaz que muestra las vidas.
// Usamos el caracter ♥ para las vidas (wchar_t w_corazon = L'\u2665';)
	mvprintw(0, 100, "L'\u2665';");

	for (int i = 0; i < miEstudiante.getVidas(); i++)
	{
		mvaddch(0, 109 + i, "L'\u2665'";);
	}

	
	miEstudiante.draw();

	for (int i = 0; i < Manifestantes.size(); i++)
	{
		Manifestantes[i].draw();
	}	
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












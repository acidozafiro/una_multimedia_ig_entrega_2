//=========================================================================
// OBJETIVO: LLEGAR A RENDIR UN FINAL
// OBSTACULOS: TIEMPO 
// PERSONAJES: JUGADOR + MANIFESTANTES
//=========================================================================

#include <iostream>
#include <ncurses.h>
#include "Estudiante.h"
#include <vector>
#include <array>
#include <cstdlib> // Contiene la función rand() y srand()
#include <ctime> // Contiene la función time()
#include "Manifestante.h"

using namespace std;

//// DECLARACION CONSTANTES ////

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 100;
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
//float tiempo;
//bool crisis;
bool salir;
bool gano;

Estudiante miEstudiante;
std::vector<Manifestante> manifestantes;
std::array<chtype, 3> simbolosVidas = { ACS_HEART, ACS_HEART, ACS_HEART };




//// DECLARACION FUNCIONES GLOBALES ////

void setup();
void input();
void update();
void draw();
void gameover();
int menuPrincipal();          
void mostrarInstrucciones();
void drawUniversidad();

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
bool llegoALaUniversidad(Estudiante &e) {
    // coordenadas de la "puerta" de la universidad
    return (e.getY() == 12 && e.getX() >= 110 && e.getX() <= 116);
}

//// DEFINICION FUNCIONES GLOBALES ////

void setup()
{
	game_over = false;
    vidas = 3;
    //tiempo = 100; 
	gano = false;
	timeout(50);

	miEstudiante.setup();
	manifestantes.clear();
	for (int i = 0; i < 20; i++)
	{
		Manifestantes.push_back(Manifestante(rand() % 119 + 1, rand() % 38 + 1));
	}
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
	//tiempo--;
	miEstudiante.update();

	//perder vidas
	//if (miEstudiante.getTiempo() <=0 ) crisis = true;
	if (miEstudiante.getVidas() <= 0) game_over = true;

	//colision
	for (size_t i = 0; i < manifestantes.size(); i++) {
        manifestantes[i].update();
        manifestantes[i].colision(miEstudiante);
	}
	// condición de victoria

		if (llegoALaUniversidad(miEstudiante)) {
    gano = true;
    game_over = true;
			
}
	
}	

void draw()
{
	erase();
	box(stdscr, 0, 0);

// Dibujamos la interfaz que muestra el tiempo NO SE SI ESTA BIEN, CHECKEAR QUE FUNCIONE
	//mvprintw(0, 80, "[ TIEMPO:     ]");
	//mvprintw(0, 91, "%3d", (int)miEstudiante.getTiempo());

// Dibujamos la interfaz que muestra las vidas.
// Usamos el caracter ♥ para las vidas
	mvprintw(0, 100, "[ VIDAS:     ]");
	for (int i = 0; i < min(miEstudiante.getVidas(), (int)simbolosVidas.size()); i++)
   	 mvaddch(0, 109 + i, simbolosVidas[i]);

	
	miEstudiante.draw();
	
	for (size_t i = 0; i < manifestantes.size(); i++) {
        manifestantes[i].draw();
    }
	drawUniversidad(); 
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

    if (gano) {
        mvprintw(12, 52, "¡¡¡GANASTE!!!");
        mvprintw(13, 45, "Llegaste a la universidad. ¡¡Éxitos en el final!!");
        gano = false; 
        mvprintw(15, 48, "Presiona cualquier tecla para volver al menu...");
        getch();
    } else {
        mvprintw(12, 55, "GAME OVER");
        mvprintw(13, 50, "VOLVER A JUGAR? (S/N)");

        int opcion = getch();
        if (opcion == 's' || opcion == 'S') {
            setup();
            game_over = false;
        } else if (opcion == 'n' || opcion == 'N') {
            salir = true;
        }
    }
}
void drawUniversidad() {
    mvprintw(10, 100, "  _____ UNIVERSIDAD _____ ");
    mvprintw(11, 100, " |                       |");
    mvprintw(12, 100, " |        [====]         |"); // <-- puerta
    mvprintw(13, 100, " |_______________________|");
}
int menuPrincipal()
	{
    while (true)
    {
        erase();
        box(stdscr, 0, 0);
        mvprintw(2, 4, "=== La batalla por la educación pública ===");
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

void imprimirLinea(int fila, int col, string texto) {
    for (size_t i = 0; i < texto.size(); i++) {
        mvaddch(fila, col + i, texto[i]);
    }
}

void mostrarInstrucciones()
{
    erase();
    box(stdscr, 0, 0);

    string titulo       = "=== La batalla por la educacion publica ===";
    string objetivo     = "Objetivo del juego:";
    string explicacion  = "Llegar a rendir el final antes de que se acabe el tiempo.";
    string controles    = "Controles:";
    string control_up   = "Flechas - Mover al estudiante";
    string control_esc  = "ESC     - Salir del juego";
    string advertencia  = "Evita chocar con los manifestantes!";
    string volver       = "Presiona cualquier tecla para volver...";

    imprimirLinea(2, 4, titulo);
    imprimirLinea(4, 4, objetivo);
    imprimirLinea(5, 6, explicacion);
    imprimirLinea(7, 4, controles);
    imprimirLinea(8, 6, control_up);
    imprimirLinea(9, 6, control_esc);
    imprimirLinea(11, 4, advertencia);
    imprimirLinea(13, 4, volver);

    refresh();
    getch();
}








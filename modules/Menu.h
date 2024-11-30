#ifndef MENU_H
#define MENU_H
#include "estadisticas.h"
#include "util.h"

//Decidi implementar las funciones dentro del header al ser hasta el momento 2.
void Jugar();
bool verificarFinDeJuego(CJugador* player);
void procesarAccion(CJugador* player, int& x, int& y, string& accion_buscar);
void jugarBuscaminas(int nivel_dificultad, string nombre_jugador);
void mostrarMenuDificultad();
void Menu();


#endif //MENU_H

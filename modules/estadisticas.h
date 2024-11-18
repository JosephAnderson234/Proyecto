#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include "CJugador.h"

//Actualizar estadisticas por cada jugador nuevo
void guardar_estadisticas(CJugador* gamer);

//Ordenar y clasificar a los jugadores
vector <CJugador*> cargar_jugadores();
bool compararJugadores(CJugador* a, CJugador* b);
void ordenarNivel(vector <CJugador*> jugadores_dificultad);
void mostrarEstadisticas();


#endif //ESTADISTICAS_H

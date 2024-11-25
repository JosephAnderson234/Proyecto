#ifndef UTIL_H
#define UTIL_H

#include "CTable.h"
#include "CJugador.h"
bool validarPosicion(int& x, int& y, CTablero& table);

void validarDificultad(std::string& nombre_jugador, int& nivel_input);

void operator++(CJugador& player, int);
#endif //UTIL_H

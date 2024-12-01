#ifndef UTIL_H
#define UTIL_H

#include "CJugador.h"

void extraerPosiciones(string& line, int& x, int& y, int& tableDimension);
void validarPosicion(int& x, int& y, CTablero& table, string& aceppted);
void validarDificultad(string& nombre_jugador, int& nivel_input);
void validarEleccon(int& x);
void nombreValido(string& str);


void operator++(CJugador& player, int);
int charToInt(char& text);
bool caracterValido(char& letra);
#endif //UTIL_H

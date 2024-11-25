#ifndef CJUGADOR_H
#define CJUGADOR_H
#include <iostream>
#include <string>
#include <vector>
#include "CTable.h"
using namespace std;

class CJugador {
    string nombre;
    int turnos = 0;
    int dificultad;
    CTablero* tablero = nullptr;
public:
    CJugador(string name, int dificulty);
    CJugador(string name, int turns, int dificulty);
    bool jugar(int x, int y);
    friend class CTablero;
    friend void guardar_estadisticas(CJugador* gamer);
    friend void mostrarEstadisticas();
    friend void ordenarNivel(vector <CJugador*> jugadores_dificultad);
    friend bool compararJugadores(CJugador* a, CJugador* b);
    friend void operator++(CJugador& player, int);
    ~CJugador() {
        delete tablero;
    };
};



#endif //CJUGADOR_H

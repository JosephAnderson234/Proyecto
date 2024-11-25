#ifndef CJUGADOR_H
#define CJUGADOR_H
#include <string>
#include <vector>
#include "CTable.h"
using namespace std;

class CJugador {
    string nombre;
    int turnos = 0;
    int dificultad;
    CTablero* tablero;
public:
    CJugador(string name, int dificulty): nombre(name),  dificultad(dificulty) {
        switch (dificulty) {
            case 1:
                tablero = new CTablero(6);
                break;
            case 2:
                tablero = new CTablero(8);
                break;
            case 3:
                tablero = new CTablero(10);
                break;
        }
    };
    CJugador(string name, int turns, int dificulty): nombre(name), turnos(turns), dificultad(dificulty){}
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

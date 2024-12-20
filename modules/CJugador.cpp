#include "CJugador.h"

//primer constructor
CJugador::CJugador(string name, int dificulty): nombre(name),  dificultad(dificulty) {
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

//segundo constructor
CJugador::CJugador(string name, int turns, int dificulty):
nombre(name), turnos(turns), dificultad(dificulty){}



bool CJugador::jugar(int x, int y) {

    return tablero->jugada(x,y);
}

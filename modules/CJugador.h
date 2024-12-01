#ifndef CJUGADOR_H
#define CJUGADOR_H
#include "CTable.h"
using namespace std;

class CJugador {
    string nombre;
    int turnos = 0;
    int banderas = 0;
    int dificultad;
    CTablero* tablero = nullptr;
public:
    CJugador(string name, int dificulty);
    CJugador(string name, int turns, int dificulty);
    bool jugar(int x, int y);
    bool juegoTerminado();
    friend class CTablero;
    friend void guardar_estadisticas(CJugador* gamer);
    friend void jugarBuscaminas(int nivel_dificultad, string nombre_jugador);
    friend bool verificarFinDeJuego(CJugador* player);
    friend bool procesarAccion(CJugador* player, int& x, int& y, string& accion_buscar);
    friend void mostrarEstadisticas();
    friend void ordenarNivel(vector <CJugador*> jugadores_dificultad);
    friend bool compararJugadores(CJugador* a, CJugador* b);
    friend void operator++(CJugador& player, int);
    ~CJugador() {
        delete tablero;
    };
};



#endif //CJUGADOR_H

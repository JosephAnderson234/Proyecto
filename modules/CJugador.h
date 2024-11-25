#ifndef CJUGADOR_H
#define CJUGADOR_H
#include <string>
#include <vector>
using namespace std;

class CJugador {
    string nombre;
    int turnos;
    int dificultad;
public:
    CJugador(string name, int turnes, int dificulty): nombre(name), turnos(turnes), dificultad(dificulty) {};
    friend class CTablero;
    friend void guardar_estadisticas(CJugador* gamer);
    friend void mostrarEstadisticas();
    friend void ordenarNivel(vector <CJugador*> jugadores_dificultad);
    friend bool compararJugadores(CJugador* a, CJugador* b);
    ~CJugador();
};



#endif //CJUGADOR_H

#ifndef CTABLE_H
#define CTABLE_H

#include<vector>
#include <string>
#include <cmath>
#include <iostream>
#include <ctime>
#include <iomanip>

class CTablero {
    std::vector<std::vector<char>> mTableSolved;
    std::vector<std::vector<char>> mTable;
    int mDimension;
    int mMinas;
public:
    CTablero(int dimension);
    void crearTabla();
    int getMinas();
    bool tableroAvance();
    friend void imprimir(const CTablero& tablero);
    friend class CJugador;
    void colocarBandera(const int& x, const int& y);
    void buscarMina();
    void marcarFMinas();
    friend void validarPosicion(int& x, int& y, CTablero& table, std::string& aceppted);
    bool jugada(const int& x, const int& y);
    void descubrirCeldas0(const int& x, const int& y);
    ~CTablero(){}
};

#endif //CTABLE_H

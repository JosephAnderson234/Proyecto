#ifndef CTABLE_H
#define CTABLE_H

#include<iostream>
#include<vector>
#include "util.h"

class Ctablero {
    std::vector<std::vector<char>> mTableSolved; // son propuestas
    std::vector<std::vector<char>> mTabletoGame; // al final tu elijes como trabajar con esto karolay
    int mDimension;
    //puede ser un atributo extra el número de minas
public:
    Ctablero(int size);

    void colocarBandera(int x, int y);
    bool buscarMina(int x, int y);
    friend bool validarPosicion(int& x, int& y, Ctablero& table);
    ~Ctablero(){}
};



#endif //CTABLE_H

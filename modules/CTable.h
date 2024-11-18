#ifndef CTABLE_H
#define CTABLE_H

#include<iostream>
#include<vector>

class CTablero {
    std::vector<std::vector<char>> mTableSolved; // son propuestas
    std::vector<std::vector<char>> mTable; // al final tu elijes como trabajar con esto karolay
    int mDimension;
    //puede ser un atributo extra el número de minas
public:
    CTablero(int dimension);
    void crearTabla();
    friend void imprimir();
    void colocarBandera(int x, int y);
    bool buscarMina(int x, int y);
    friend bool validarPosicion(int& x, int& y, CTablero& table);
    ~CTablero(){}
};

#endif //CTABLE_H

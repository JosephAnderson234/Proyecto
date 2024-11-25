#ifndef CTABLE_H
#define CTABLE_H


#include<vector>

class CTablero {
    std::vector<std::vector<char>> mTableSolved; // son propuestas
    std::vector<std::vector<char>> mTable; // al final tu elijes como trabajar con esto karolay
    int mDimension;
    //puede ser un atributo extra el número de minas
public:
    CTablero(int dimension);
    void crearTabla();
    bool tableroCompleto();
    friend void imprimir(const CTablero& tablero);
    void colocarBandera(const int& x, const int& y);
    void buscarMina();
    friend bool validarPosicion(int& x, int& y, CTablero& table);
    bool jugada(const int& x, const int& y);
    void descubrirCeldas0(const int& x, const int& y);
    ~CTablero(){}
};

#endif //CTABLE_H

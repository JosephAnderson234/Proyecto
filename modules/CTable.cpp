#include "CTable.h"

Ctablero::Ctablero(int size): mDimension(size) {
    //el codigo para crear el tablero y a la vez el otro tablero donde se buscará
}

bool Ctablero::buscarMina(int x, int y) {
    //si en caso se usa la metodología de tener 2 tableros, uno de juego y otro resutelto,
    //se compará si el resulteto tiene una mina, si lo tiene, entonces retorna true, si no,
    //retorna false
    return mTableSolved[x][y] == '*';
}


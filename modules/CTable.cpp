#include "CTable.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
CTablero::CTablero(int dimension) :
            mDimension(dimension),
            mTable(dimension, vector<char>(dimension,'-')),
            mTableSolved(dimension, vector<char>(dimension,'-')) {}
//el codigo para crear el tablero y a la vez el otro tablero donde se buscará
void CTablero::crearTabla() {
    //LLENADO DE LA TABLA_SOLVED CON MINAS DE MANERA ALEATORIA SEGUN SU DIMENSION
    srand(static_cast<unsigned>(time(0)));
    int cant_Minas=0;
    if (mDimension==6) {
        cant_Minas=rand()%3 + 3;
    }else if (mDimension==8) {
        cant_Minas=rand()%5 + 8;
    }else if (mDimension==10) {
        cant_Minas=rand()%6 + 10;
    }
    while (cant_Minas>0) {
        int fila=rand()%mDimension;
        int columna=rand()%mDimension;
        if (mTableSolved[fila][columna]!='*') {
            mTableSolved[fila][columna]='*';
            cant_Minas--;
        }
    }

}


bool CTablero::buscarMina(int x, int y) {
    //si en caso se usa la metodología de tener 2 tableros, uno de juego y otro resutelto,
    //se compará si el resulteto tiene una mina, si lo tiene, entonces retorna true, si no,
    //retorna false
    return mTableSolved[x][y] == '*';
}

#include "CTable.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

CTablero::CTablero(int dimension) :
            mDimension(dimension),
            mTable(dimension, vector<char>(dimension,'-')),
            mTableSolved(dimension, vector<char>(dimension,'-')) {
    crearTabla();
}
//el codigo para crear el tablero y a la vez el otro tablero donde se buscará

void CTablero::crearTabla() {
    //LLENADO DE LA TABLA_SOLVED CON MINAS DE MANERA ALEATORIA SEGUN SU DIMENSION
    srand(time(nullptr));
    int cant_Minas=0;
    if (mDimension==6) {
        cant_Minas=rand()%3 + 3; //3 a 5 minas (FÁCIL)
    }else if (mDimension==8) {
        cant_Minas=rand()%5 + 8;  //8 a 12 minas (INTERMEDIO)
    }else if (mDimension==10) {
        cant_Minas=rand()%6 + 15;   //15  a  20 minas (DIFÍCIL)
    }
    mMinas=cant_Minas;
    while (cant_Minas>0) {
        int fila=rand()%mDimension;
        int columna=rand()%mDimension;
        if (mTableSolved[fila][columna]!='X') {
            mTableSolved[fila][columna]='X';
            cant_Minas--;
        }
    }

    //LLENADO DE CELDAS QUE CUENTAN LAS MINAS QUE TIENEN A SU ALREDEDOR
    for (int i=0; i<mDimension;i++) {
        for (int j=0; j<mDimension;j++) {
            if (mTableSolved[i][j]!='X') {
                int cont_mina_alrededor=0; //INICIALIZO CONTADOR
                for (int di=-1; di<=1;di++) {
                    for (int dj=-1; dj<=1;dj++) {
                        if (di+i>=0 && di+i<mDimension && dj+j>=0 && dj+j<mDimension) { //VALIDO QUE LA POSICION DÓNDE BUSCARÉ ESTE DENTRO DE LA MATRIZ
                            if (mTableSolved[di+i][dj+j]=='X') {
                                cont_mina_alrededor+=1;
                            }
                        }
                    }
                }
                mTableSolved[i][j]=cont_mina_alrededor +'0'; //COERSIÓN IMPLICITA SUMA ASCII
            }
        }
    }


}


void CTablero::buscarMina() {
    //cuando el jugador pierde (encuentra una mina) se deben buscar todas las minas
    for (int i=0; i<mDimension;i++) {
        for (int j=0; j<mDimension;j++) {
            if (mTableSolved[i][j]=='X') {
                mTable[i][j]='X';
            }
        }
    }
}

void imprimir(const CTablero& tablero) {

    //ENCABEZADO COLUMNA
    cout<<"    ";
    for (int i=0;i<tablero.mDimension;i++) {
        cout<<" "<<i+1<<"  ";
    }
    //DIVISOR DE FILAS
    cout<<endl;
    cout<<"   ";
    for (int i=0;i<tablero.mDimension;i++) {
        cout<<" ___";
    }
    cout<<endl;
    for (int i=0; i<tablero.mDimension;i++) {
        cout<<left<<setw(3)<<i+1<<"| "; //ENCABEZADO FILA
        for (int j=0; j<tablero.mDimension;j++) {
            cout<<tablero.mTable[i][j]<<" | "; //ELEMENTOS DE LA TABLA
        }
        cout<<endl;
        //DIVISOR DE FILAS
        cout<<"   ";
        for (int i=0;i<tablero.mDimension;i++) {
            cout<<" ---";
        }
        cout<<endl;
    }

    cout<<"\n\n";
}
//suponiendo que ingresan (1,1) se refieren a (0,0)
void CTablero::colocarBandera(const int& x, const int& y) {
    if (x>=1 && x<=mDimension && y>=1 && y<=mDimension) {
        if (mTable[x-1][y-1]=='-') {
            mTable[x-1][y-1]=='F'; //SE COLOCA BANDERA
        }
    }


}


void CTablero::descubrirCeldas0(const int& x, const int& y) {

    for (int dx=-1; dx<=1;dx++) {
        for (int dy=-1; dy<=1;dy++) {
            if (dx == 0 && dy == 0) continue; //ignorar la celda actual
            // Coordenadas de la celda vecina
            int nx = x + dx;
            int ny = y + dy;
            if (nx>=0 && nx<mDimension && ny>=0 && ny<mDimension) { //VALIDO QUE LA POSICION DÓNDE BUSCARÉ ESTE DENTRO DE LA MATRIZ
                if (mTableSolved[nx][ny]=='0' && mTable[nx][ny]=='-') {
                    mTable[nx][ny]=mTableSolved[nx][ny];
                    descubrirCeldas0(nx,ny); //llamada recursiva para seguir descubriendo
                }else if (mTableSolved[nx][ny]>='1' && mTableSolved[nx][ny]<='8'){
                    mTable[nx][ny]=mTableSolved[nx][ny];
                }
            }
        }
    }
}


bool CTablero::jugada(const int& x, const int& y) {
    //casos: ya se revelo la posicion intertar con otra coordenada (PENDIENTE)
            //descubrir una posicion nueva
    if (mTable[x-1][y-1]=='F' || mTable[x-1][y-1]=='-') {
        if (mTableSolved[x-1][y-1]=='0') {
            descubrirCeldas0(x-1,y-1);
            return true;
        }else if(mTableSolved[x-1][y-1]>'0' && mTableSolved[x-1][y-1]<='8') {
            mTable[x-1][y-1]=mTableSolved[x-1][y-1];
            return true;
        }else if (mTableSolved[x-1][y-1]=='X'){ //encontró mina
            buscarMina();
            return false;
        }
    }
}

bool CTablero::tableroCompleto() {
    for (int i = 0; i < mDimension; i++) {
        for (int j = 0; j <mDimension; i++) {
            if (mTable[i][j] != mTableSolved[i][j]) {
                return false;
            }
        }
    }
    return true;
}

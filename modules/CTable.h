#ifndef CTABLE_H
#define CTABLE_H

#include<iostream>
#include<vector>


class Ctablero {
    std::vector<std::vector<char>> mTableSolved;
    std::vector<std::vector<char>> mTabletoGame;
    int mSize;
public:
    Ctablero(int size);

    void buscarbandera(int x, int y);
    bool validarPosicion(int x, int y);
};



#endif //CTABLE_H

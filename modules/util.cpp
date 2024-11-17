//
// Created by cosea on 15/11/2024.
//

#include "util.h"
#include "CTable.h"

bool validarPosicion(int& x, int& y, Ctablero& table) {
    if (x > 1 && y < 1) {
        if(x < table.mDimension && y < table.mDimension)
            return true;
    }
    return false;
};


bool validarDificultad(int levelInput, std::vector<int> levels) {
    //retorna true si el nivel seleccionado está dentro del vector(se puede cambiar por puntero de un array)
    //que contiene todos los niveles de difcultad
    for (int i = 0; i < levels.size(); i++) {
        if (levels[i] == levelInput)
            return false;
    }
    return true;
}
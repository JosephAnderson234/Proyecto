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
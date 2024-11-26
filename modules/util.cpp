//
// Created by cosea on 15/11/2024.
//
#include <iostream>
#include<string>
#include "util.h"

int charToInt(char &text) {
    return text-'0';
}


void validarPosicion(int& x, int& y, CTablero& table) {
    bool status = true;
    do {
        char tempX, tempY;
        cout<<"Ingrese fila columna(f c):";cin>>tempX>>tempY;
        x = charToInt(tempX);
        y = charToInt(tempY);
        if (x >= 1 && y >= 1) {
            if(x <= table.mDimension && y <= table.mDimension) {
                status = !table.mTable[x-1][y-1] == '-';
            }else {
                cout<<"Error: Seleccione una opción admitida."<<endl;
            }
        }
    }while(status);

};


void validarDificultad(std::string& nombre_jugador, int& nivel_input) {
    do {
        std::cout << nombre_jugador<< " seleccione una dificultad: ";
        cin.clear();
        char tempInput;
        std::cin >>tempInput;
        nivel_input = charToInt(tempInput);
        if(nivel_input<0 || nivel_input>3) {
            std::cout << "Error: Seleccione una opción admitida." << std::endl;
        }
    }while(nivel_input < 0 || nivel_input>3);
}

void operator++(CJugador& player, int) {
    player.turnos += 1;
}
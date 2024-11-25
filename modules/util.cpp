//
// Created by cosea on 15/11/2024.
//
#include <iostream>
#include<string>
#include "util.h"
void validarPosicion(int& x, int& y, CTablero& table) {
    bool status = true;
    do {
        cout<<"Ingrese fila columna(f c):";cin>>x>>y;
        if (x >= 1 && y >= 1) {
            if(x <= table.mDimension && y <= table.mDimension)
                status = !table.mTable[x-1][y-1] == '-';
        }
    }while(status);

};


void validarDificultad(std::string& nombre_jugador, int& nivel_input) {
    do {
        std::cout << nombre_jugador<< " seleccione una dificultad: ";
        cin.clear();
        std::cin >>nivel_input;
        if(nivel_input<0 || nivel_input>3) {
            std::cout << "Error: Seleccione una opcion valida." << std::endl;
        }
    }while(nivel_input < 0 || nivel_input>3);
}

void operator++(CJugador& player, int) {
    player.turnos += 1;
}
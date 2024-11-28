#include <iostream>
#include<string>
#include "util.h"

int charToInt(char &text) {
    return text-'0';
}

void nombreValido(string& str) {
    bool nombreValido= false;
    while (!nombreValido) {
        cout<< "Escriba su nombre: ";
        getline(cin, str);
        for (auto& letra: str) {
            if(isalnum(letra)) {
                nombreValido = true;
            } else {
                nombreValido = false;
                cout<<"El nombre no es valido\n";
                break;
            }
        }
    }
}

void validarEleccon(int& x) {
    while (true) {
        string temp;
        cout <<"Seleccione una de las opciones: ";
        getline(cin, temp);
        x = temp.size() == 1 ? charToInt(temp[0]) : -1;
        if (x>=1 && x<=3) {
            break;
        } else {
            cout<<"Elige una opcion válida\n";
        }
    }
}

void extraerPosiciones(string& line, int& x, int& y) {

    switch (line.size()) {
        case 3:
            x = line.size() == 3 && line[1] == ' ' ? charToInt(line[0]) : -1;
            y = line.size() == 3 && line[1] == ' ' ? charToInt(line[2]) : -1;
            break;
        case 4:
            if (line[1] == ' ') {
                x = charToInt(line[0]);
                y = charToInt(line[2])*10+charToInt(line[3]);
            }else if(line[2] == ' ') {
                x = charToInt(line[0])*10+charToInt(line[1]);
                y = charToInt(line[3]);
            } else {
                x = -1;
                y = -1;
            }
        case 5:
            x = line[2] == ' ' ? charToInt(line[0])*10 + charToInt(line[1]) : -1;
            y = line[2] == ' ' ? charToInt(line[3])*10 + charToInt(line[4]) : -1;
            break;
    }


}


void validarPosicion(int& x, int& y, CTablero& table) {
    do {
        string temp;
        cout<<"Ingrese fila columna(f c):";
        getline(cin, temp);
        extraerPosiciones(temp, x, y);
        if (x >= 1 && y >= 1) {
            if((x <= table.mDimension) && (y <= table.mDimension)) {
                if (table.mTable[x-1][y-1] == '-') {
                    break;
                } else {
                    cout<<"Seleccione una celda que este disponible\n";
                }
            }else {
                cout<<"Error: Seleccione una opcion dentro de las dimensiones.\n"<<endl;
            }
        }else {
            cout<<"Error: Seleccione una opcion mayor a 0.\n"<<endl;
        }

    }while(true);

};


void validarDificultad(string& nombre_jugador, int& nivel_input) {
    do {
        cout << nombre_jugador<< " seleccione una dificultad: ";
        string tempInput;
        getline(cin, tempInput);
        nivel_input =tempInput.size() == 1 ? charToInt(tempInput[0]): -1;
        if(nivel_input<0 || nivel_input>3) {
            cout << "Error: Seleccione una opcion admitida." << std::endl;
        }
    }while(nivel_input < 0 || nivel_input>3);
}

void operator++(CJugador& player, int) {
    player.turnos += 1;
}
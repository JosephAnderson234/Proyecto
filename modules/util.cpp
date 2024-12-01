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

void validarEleccion(int& x) {
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
        case 3: {
            // formato "x y"
            if (line[1] == ' ') {
                x = charToInt(line[0]);
                y = charToInt(line[2]);
            } else {
                x = y = -1; // Valor por defecto si no es "x y"
            }
            break;
        }

        case 4: {
            // Pposibles formatos:
            // 1. "x yyy"
            // 2. "xx y"
            if (line[1] == ' ') {
                x = charToInt(line[0]);
                y = charToInt(line[2]) * 10 + charToInt(line[3]);
            } else if (line[2] == ' ') {
                x = charToInt(line[0]) * 10 + charToInt(line[1]);
                y = charToInt(line[3]);
            } else {
                x = y = -1; // Caso no válido
            }
            break;
        }

        case 5: {
            // formato "xx yy"
            if (line[2] == ' ') {
                x = charToInt(line[0]) * 10 + charToInt(line[1]);
                y = charToInt(line[3]) * 10 + charToInt(line[4]);
            } else {
                x = y = -1; // Valor por defecto si no es válido
            }
            break;
        }

        default: {
            // Caso por defecto, tamaño inválido
            x = y = -1;
            break;
        }
    }
}


void validarPosicion(int& x, int& y, CTablero& table, string& aceppted) {
    do {
        string temp;
        cout<<"Ingrese fila columna(f c):";
        getline(cin, temp);
        extraerPosiciones(temp, x, y);
        if (x >= 1 && y >= 1) {
            if((x <= table.mDimension) && (y <= table.mDimension)) {
                if (aceppted.find(table.mTable[x - 1][y - 1]) != string::npos) {
                    break;
                } else {
                    cout<<"Seleccione una celda que este disponible\n";
                }
            }else {
                cout<<"Error: Seleccione una opcion dentro de las dimensiones.\n"<<endl;
            }
        }else {
            cout<<"Error: caso no valido\n"<<endl;
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
            cout << "Error: Seleccione una opcion admitida." << endl;
        }
    }while(nivel_input < 0 || nivel_input>3);
}

void operator++(CJugador& player, int) {
    player.turnos += 1;
}
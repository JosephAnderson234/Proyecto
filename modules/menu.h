#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "estadisticas.cpp"
#include <iomanip>

//Decidi implementar las funciones dentro del header al ser hasta el momento 2.
void Jugar();
void Menu(){
        int option_menu;
        cout << "----------------------------------------" << endl;
        cout << "|            Buscaminas                |" << endl;
        cout << "|  1. Jugar                            |" << endl;
        cout << "|  2. Mejores Jugadores                |" << endl;
        cout << "|  3. Salir                            |" << endl;
        cout << "----------------------------------------" << endl;
        do {
            cout <<"Seleccione una de las opciones: ";
            cin >> option_menu;
            switch(option_menu) {
                case 1:
                    Jugar();
                    break;
                case 2:
                    mostrarEstadisticas();
                break;
                case 3:
                    cout << "Hasta una proxima oportunidad!" <<endl;
                    break;
                default:
                    cout << "Error: Seleccione una opcion valida" << endl;
                    break;
            }
        }while(option_menu<1 || option_menu>3);
    }
void Jugar() {
    int nivel_dificultad;
    string nombre_jugador;

    cout<< "Escriba su nombre: "; cin >>nombre_jugador;
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "|            Buscaminas:Jugar          |" << endl;
    cout << "|  1. Facil                            |" << endl;
    cout << "|  2. Intermedio                       |" << endl;
    cout << "|  3. Dificil                          |" << endl;
    cout << "|  Presione 0 para regresar            |" << endl;
    cout << "----------------------------------------" << endl;
    do {
        cout << nombre_jugador<< " seleccione una dificultad: ";
        cin >>nivel_dificultad;
        if(nivel_dificultad<0 || nivel_dificultad>3) {
            cout << "Error: Seleccione una opcion valida." << endl;
        }
    }while(nivel_dificultad<0 || nivel_dificultad>3);
    // En este caso se tendria que crear una funcion que de comienzo a la partida (con un objeto tipo CTablero), donde el tamaño del tablero dependeria de la dificultad.
    //Por dicha razon se envia a este como su parametro, ademas de registrar el nombre del jugador para las estadisticas cuando la partida culmine.
    //empezarJuego(nombre_jugador, nivel_dificultad);

}

#endif //MENU_H

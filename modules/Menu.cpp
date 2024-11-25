#include "Menu.h"
#include "CTable.h"
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

    validarDificultad(nombre_jugador, nivel_dificultad);

    if (nivel_dificultad != 0) {

        CJugador* player = new CJugador(nombre_jugador, nivel_dificultad);
        do {
            int x, y;
            (*player)++;
            cout<<"Turno: "<<player->turnos<<endl;
            imprimir(*player->tablero);
            if (player->juegoTerminado()) {
                cout<<"Ganaste"<<endl;
                break;
            }
            validarPosicion(x, y, *(player->tablero));

            if(!player->jugar(x, y)) {
                imprimir(*player->tablero);
                cout<<"Perdiste"<<endl;
                break;
            }
        }while (true);
        delete player;
    }

    Menu();
}
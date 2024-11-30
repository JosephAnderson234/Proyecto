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

    validarEleccon(option_menu);
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
    }
}

void Jugar() {
    int nivel_dificultad;
    string nombre_jugador;

    nombreValido(nombre_jugador);


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
            cout<<"Minas: "<<player->tablero->getMinas()<<endl;
            imprimir(*player->tablero);
            string accion;
            string accion_buscar;
            do {
                cout<<"Va a desenterrar o marcar/descarmarcar (D o F):";
                getline(cin, accion);
            } while (accion != "D" && accion != "F");

            if (accion == "D") {
                accion_buscar = "-";
                validarPosicion(x, y, *(player->tablero), accion_buscar);
                if(!player->jugar(x, y)) {
                    imprimir(*player->tablero);
                    cout<<"Perdiste"<<endl;
                    break;
                }
            } else {
                accion_buscar = "F-";
                validarPosicion(x, y, *(player->tablero), accion_buscar);
                player->tablero->colocarBandera(x, y);
            }
            if (player->tablero->tableroAvance()) {
                player->tablero->marcarFMinas();
                imprimir(*player->tablero);
                cout<<"Ganaste"<<endl;
                break;
            }
        }while (true);
        delete player;
    }

    Menu();
}
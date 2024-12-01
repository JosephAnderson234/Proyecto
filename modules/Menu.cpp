#include "Menu.h"


void Menu(){
    int option_menu;
    cout << "----------------------------------------" << endl;
    cout << "|            Buscaminas                |" << endl;
    cout << "|  1. Jugar                            |" << endl;
    cout << "|  2. Mejores Jugadores                |" << endl;
    cout << "|  3. Salir                            |" << endl;
    cout << "----------------------------------------" << endl;

    validarEleccion(option_menu);
    switch(option_menu) {
        case 1:
            Jugar();
        break;
        case 2:
            mostrarEstadisticas();
            Menu();
        break;
        case 3:
            cout << "Hasta una proxima oportunidad!" <<endl;
        break;
    }
}

void mostrarMenuDificultad() {
    cout << "----------------------------------------" << endl;
    cout << "|            Buscaminas:Jugar          |" << endl;
    cout << "|  1. Facil                            |" << endl;
    cout << "|  2. Intermedio                       |" << endl;
    cout << "|  3. Dificil                          |" << endl;
    cout << "|  Presione 0 para regresar            |" << endl;
    cout << "----------------------------------------" << endl;
}

bool procesarAccion(CJugador* player, int& x, int& y, string& accion_buscar) {
    string accion;
    do {
        cout << "Va a desenterrar(D o d) o marcar/desmarcar(F o f): ";
        getline(cin, accion);
    } while (accion != "D"&& accion != "d"&& accion != "f" && accion != "F");

    if (accion == "D" || accion == "d") {
        accion_buscar = "-";
        validarPosicion(x, y, *(player->tablero), accion_buscar);
        if (!player->jugar(x, y)) {
            imprimir(*player->tablero);
            cout << "Perdiste" << endl;
            return false;
        }
    } else {
        accion_buscar = "F-";
        validarPosicion(x, y, *(player->tablero), accion_buscar);
        player->tablero->colocarBandera(x, y);
        player->banderas = player->tablero->banderasColocadas();
    }
    return true;
}

bool verificarFinDeJuego(CJugador* player) {
    if (player->tablero->tableroAvance()) {
        player->tablero->marcarFMinas();
        imprimir(*player->tablero);
        cout << "Ganaste" << endl;
        guardar_estadisticas(player);
        return true;
    }
    return false;
}

void jugarBuscaminas(int nivel_dificultad, string nombre_jugador) {
    CJugador* player = new CJugador(nombre_jugador, nivel_dificultad);
    do {
        int x, y;
        (*player)++;
        cout << "Turno: " << player->turnos << endl;
        cout << "Minas: " << player->tablero->getMinas() << endl;
        cout << "Banderas: "<<player->banderas<<endl;
        imprimir(*player->tablero);

        string accion_buscar;
        if (!procesarAccion(player, x, y, accion_buscar)) {
            break;
        }

        if (verificarFinDeJuego(player)) {
            break;
        }
    } while (true);
    delete player;
}

void Jugar() {
    string nombre_jugador;
    nombreValido(nombre_jugador);

    mostrarMenuDificultad();

    int nivel_dificultad;
    validarDificultad(nombre_jugador, nivel_dificultad);

    if (nivel_dificultad != 0) {
        jugarBuscaminas(nivel_dificultad, nombre_jugador);
    }

    Menu();  // Regresar al menú principal
}

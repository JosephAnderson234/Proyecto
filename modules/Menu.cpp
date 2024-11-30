#include "Menu.h"
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

void procesarAccion(CJugador* player, int& x, int& y, string& accion_buscar) {
    string accion;
    do {
        cout << "Va a desenterrar o marcar/desmarcar (D o F): ";
        getline(cin, accion);
    } while (accion != "D"&& accion != "d"&& accion != "f" && accion != "F");

    if (accion == "D" || accion == "d") {
        accion_buscar = "-";
        validarPosicion(x, y, *(player->tablero), accion_buscar);
        if (!player->jugar(x, y)) {
            imprimir(*player->tablero);
            cout << "Perdiste" << endl;
        }
    } else {
        accion_buscar = "F-";
        validarPosicion(x, y, *(player->tablero), accion_buscar);
        player->tablero->colocarBandera(x, y);
    }
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
        (*player)++;  // Incrementar turno
        cout << "Turno: " << player->turnos << endl;
        cout << "Minas: " << player->tablero->getMinas() << endl;
        imprimir(*player->tablero);

        string accion_buscar;
        procesarAccion(player, x, y, accion_buscar);

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

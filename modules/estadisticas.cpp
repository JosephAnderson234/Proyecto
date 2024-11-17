#include "estadisticas.h"

#include "menu.h"
#include "menu.h"

void guardar_estadisticas(CJugador* gamer){ //guardar o actualizar
    ofstream archivo;
    //Si no existe el archivo se crea uno, ademas si el archivo ya tenia informacion cuando se quiera agregar
    //mas se coloca por debajo del que ya habia:
    archivo.open("mejoresJugadores.txt",ios::app);

    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    //Se guarda la informacion en el archivo de texto simple:
    archivo<<gamer->nombre<< "," <<gamer->turnos << "," <<gamer->dificultad <<endl;
    archivo.close();
}

vector <CJugador*> cargar_jugadores() {
        vector <CJugador*> gamers;

        ifstream archivo("mejoresJugadores.txt"); //Se comienza a leer el archivo
        string info_linea;
        while(getline(archivo,info_linea)) { //El bucle continuara hasta que se llegue al ultimo texto de linea
            int size = info_linea.length(),contador=0,turnos_n;
            int dificultad=info_linea[size-1]-'0';
            string nombre,turnos;
            for(int i=0;i<size-2;i++) {
                if(info_linea[i]!=',' && contador==0) {
                    nombre+=info_linea[i];
                }else if(info_linea[i]!=',' &&contador==1) {
                    turnos+=info_linea[i];
                }
                else {
                    contador++;
                }
            }
            turnos_n=stoi(turnos);
     //Los datos se almacenan en un objeto tipo CJugador para usarlas posteriormente ya que se manejan mejor sus datos:
            gamers.emplace_back(new CJugador(nombre,turnos_n,dificultad));
        }
        return gamers;
    }
bool compararJugadores(CJugador* a, CJugador* b) {
        if (a->turnos != b->turnos) {
            return a->turnos < b->turnos; // Ordenar segun el menor numero de turnos
        }else {
            return false;//Mantener el orden si tienen igual numero de turnos: quienes juegan primero estan antes.
        }
}
void ordenarNivel(vector <CJugador*> jugadores_dificultad) {
        sort(jugadores_dificultad.begin(), jugadores_dificultad.end(), compararJugadores);
        for (int i=0; i<jugadores_dificultad.size(); i++) {
            cout << i+1<<". " << jugadores_dificultad[i]->nombre<< " - " <<jugadores_dificultad[i]->turnos <<" turnos"<<endl;
        }
        cout <<endl;
    }
void mostrarEstadisticas() {
    int option_menu;
    vector <CJugador*> jugadores = cargar_jugadores();
    vector <CJugador*> facil, medio, dificil;
    for(int i=0;i<jugadores.size();i++) {
        switch(jugadores[i]->dificultad) {
            case 1:
                facil.push_back(jugadores[i]);
            break;
            case 2:
                medio.push_back(jugadores[i]);
            break;
            case 3:
                dificil.push_back(jugadores[i]);
            break;
        }
    }
    cout << "----------------------------------------" << endl;
    cout <<"            Mejores jugadores            " <<endl;
    cout << "Facil:" << endl;
    ordenarNivel(facil);
    cout << "Intermedio:" << endl;
    ordenarNivel(medio);
    cout << "Dificil:" << endl;
    ordenarNivel(dificil);
    cout << "----------------------------------------" << endl;
    do {
        cout << "Presione 0 para regresar al Menu: "<< endl;
        cin >>option_menu;
    }while(option_menu!=0);

}

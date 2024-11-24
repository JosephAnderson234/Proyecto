#include <iostream>
#include <vector>

#include "modules/CTable.h"
#include "modules/util.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    CTablero* p1= new CTablero(6);
    p1->crearTabla();
    imprimir(*p1);
    p1->jugada(2,2);
    p1->jugada(3,2);
    p1->jugada(4,2);

    delete p1;
    return 0;
}

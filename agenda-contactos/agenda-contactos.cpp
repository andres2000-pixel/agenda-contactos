#include <iostream>
#include "ArregloDinamico.h"
using namespace std;

int main() {
    ArregloDinamico agenda;
    agenda.agregar({ "Ana", "8888-1111", "ana@mail.com" });
    agenda.agregar({ "Luis", "8777-2222", "luis@mail.com" });
    agenda.agregar({ "Maria", "8666-3333", "maria@mail.com" });

    for (int i = 0; i < agenda.tamano(); i++) {
        cout << agenda.obtener(i).nombre << " - "
            << agenda.obtener(i).telefono << endl;
    }
    return 0;
}
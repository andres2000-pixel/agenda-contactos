#include <iostream>
#include "ArregloDinamico.h"
#include "ListaEnlazada.h"
#include "Pila.h"
using namespace std;

int main() {
    // Prueba del arreglo dinámico
    ArregloDinamico agenda;
    agenda.agregar({ "Ana", "8888-1111", "ana@mail.com" });
    agenda.agregar({ "Luis", "8777-2222", "luis@mail.com" });
    agenda.agregar({ "Maria", "8666-3333", "maria@mail.com" });

    for (int i = 0; i < agenda.tamano(); i++) {
        cout << agenda.obtener(i).nombre << " - "
            << agenda.obtener(i).telefono << endl;
    }

    // Prueba de la lista enlazada
    ListaEnlazada lista;
    lista.agregarAlFinal({ "Ana", "8888-1111", "ana@mail.com" });
    lista.agregarAlFinal({ "Luis", "8777-2222", "luis@mail.com" });

    Contacto borrado;
    if (lista.eliminarPorNombre("Ana", borrado)) {
        cout << "Eliminado: " << borrado.nombre << endl;
    }
    cout << "Quedan: " << lista.tamano() << endl;

    // Prueba de la pila
    Pila historial;
    historial.apilar({ "Agregar",{ "Ana", "8888-1111", "ana@mail.com" } });
    historial.apilar({ "Agregar",{ "Luis", "8777-2222", "luis@mail.com" } });
    historial.apilar({ "Eliminar",{ "Ana", "8888-1111", "ana@mail.com" } });

    cout << "Historial:" << endl;
    historial.mostrarHistorial();

    return 0;
}
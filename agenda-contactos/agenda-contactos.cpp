#include <iostream>
#include "ArregloDinamico.h"
#include "ListaEnlazada.h"
#include "Pila.h"
#include "Cola.h"
#include "Arbol.h"
using namespace std;

int main() {
    // Arreglo dinámico
    ArregloDinamico agenda;
    agenda.agregar({ "Maria", "8666-3333", "maria@mail.com" });
    agenda.agregar({ "Ana", "8888-1111", "ana@mail.com" });
    agenda.agregar({ "Luis", "8777-2222", "luis@mail.com" });

    // Lista enlazada
    ListaEnlazada lista;
    lista.agregarAlFinal({ "Ana", "8888-1111", "ana@mail.com" });
    lista.agregarAlFinal({ "Luis", "8777-2222", "luis@mail.com" });
    Contacto borrado;
    if (lista.eliminarPorNombre("Ana", borrado)) {
        cout << "Eliminado: " << borrado.nombre << endl;
    }

    // Pila
    Pila historial;
    historial.apilar({ "Agregar",{ "Ana", "8888-1111", "ana@mail.com" } });
    historial.apilar({ "Eliminar",{ "Ana", "8888-1111", "ana@mail.com" } });
    cout << "Historial:" << endl;
    historial.mostrarHistorial();

    // Cola: pendientes que pasan al arreglo principal
    Cola pendientes;
    pendientes.encolar({ "Pedro", "8555-4444", "pedro@mail.com" });
    pendientes.encolar({ "Sofia", "8444-5555", "sofia@mail.com" });
    Contacto siguiente;
    while (pendientes.desencolar(siguiente)) {
        agenda.agregar(siguiente);
    }
    cout << "Contactos en la agenda: " << agenda.tamano() << endl;

    // Árbol: todos los contactos ordenados por nombre
    Arbol arbol;
    for (int i = 0; i < agenda.tamano(); i++) {
        arbol.insertar(agenda.obtener(i));
    }
    cout << "Contactos ordenados (inorden):" << endl;
    arbol.mostrarInorden();

    // Ordenamiento y búsquedas
    agenda.ordenarPorNombre();
    cout << "Ordenados con insercion:" << endl;
    for (int i = 0; i < agenda.tamano(); i++) {
        cout << agenda.obtener(i).nombre << endl;
    }

    int pos = agenda.buscarBinaria("Luis");
    cout << "Binaria 'Luis': posicion " << pos << endl;

    pos = agenda.buscarSecuencial("8444-5555");
    cout << "Secuencial '8444-5555': posicion " << pos << endl;

    return 0;
}
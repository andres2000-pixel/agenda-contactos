#include <iostream>
#include <string>
#include "ArregloDinamico.h"
#include "ListaEnlazada.h"
#include "Pila.h"
#include "Cola.h"
#include "Arbol.h"
using namespace std;

// Pide un texto y no acepta que quede vacío
string pedirTexto(const string& mensaje) {
    string texto;
    do {
        cout << mensaje;
        getline(cin, texto);
        if (texto.empty()) cout << "No puede estar vacio." << endl;
    } while (texto.empty());
    return texto;
}
// Verifica que el teléfono tenga solo dígitos y guiones
bool telefonoValido(const string& t) {
    if (t.length() < 8) return false;
    for (char ch : t) {
        if (!isdigit(ch) && ch != '-') return false;
    }
    return true;
}

// Pide los datos de un contacto con validaciones
Contacto pedirContacto() {
    Contacto c;
    c.nombre = pedirTexto("Nombre: ");
    do {
        c.telefono = pedirTexto("Telefono: ");
        if (!telefonoValido(c.telefono)) {
            cout << "Telefono invalido (minimo 8 digitos, solo numeros y guiones)." << endl;
        }
    } while (!telefonoValido(c.telefono));
    do {
        c.correo = pedirTexto("Correo: ");
        if (c.correo.find('@') == string::npos) {
            cout << "El correo debe contener '@'." << endl;
        }
    } while (c.correo.find('@') == string::npos);
    return c;
}

void mostrarContacto(const Contacto& c) {
    cout << c.nombre << " | " << c.telefono << " | " << c.correo << endl;
}

int main() {
    ArregloDinamico agenda;   // almacenamiento principal
    Pila historial;           // últimas operaciones
    Cola pendientes;          // contactos por agregar
    int opcion = -1;

    do {
        cout << "\n=== AGENDA DE CONTACTOS ===" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Listar contactos (ordenados)" << endl;
        cout << "3. Buscar por telefono (secuencial)" << endl;
        cout << "4. Buscar por nombre (binaria)" << endl;
        cout << "5. Eliminar contacto" << endl;
        cout << "6. Ver historial" << endl;
        cout << "7. Encolar contacto pendiente" << endl;
        cout << "8. Transferir pendientes a la agenda" << endl;
        cout << "9. Mostrar arbol (inorden)" << endl;
        cout << "10. Modificar contacto" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }
        else {
            cin.ignore(10000, '\n');
        }

        switch (opcion) {
        case 1: {
            Contacto c = pedirContacto();
            agenda.agregar(c);
            historial.apilar({ "Agregar", c });
            cout << "Contacto agregado." << endl;
            break;
        }
        case 2: {
            if (agenda.tamano() == 0) {
                cout << "La agenda esta vacia." << endl;
                break;
            }
            agenda.ordenarPorNombre();
            for (int i = 0; i < agenda.tamano(); i++) {
                mostrarContacto(agenda.obtener(i));
            }
            break;
        }
        case 3: {
            string tel = pedirTexto("Telefono a buscar: ");
            int pos = agenda.buscarSecuencial(tel);
            if (pos == -1) cout << "No encontrado." << endl;
            else mostrarContacto(agenda.obtener(pos));
            break;
        }
        case 4: {
            string nombre = pedirTexto("Nombre a buscar: ");
            agenda.ordenarPorNombre();   // la binaria requiere orden
            int pos = agenda.buscarBinaria(nombre);
            if (pos == -1) cout << "No encontrado." << endl;
            else mostrarContacto(agenda.obtener(pos));
            break;
        }
        case 5: {
            string nombre = pedirTexto("Nombre a eliminar: ");
            // Se copia a una lista enlazada, se elimina el nodo
            // y se reconstruye el arreglo principal
            ListaEnlazada lista;
            for (int i = 0; i < agenda.tamano(); i++) {
                lista.agregarAlFinal(agenda.obtener(i));
            }
            Contacto borrado;
            if (lista.eliminarPorNombre(nombre, borrado)) {
                agenda.vaciar();
                for (Nodo* n = lista.inicio(); n != nullptr; n = n->siguiente) {
                    agenda.agregar(n->dato);
                }
                historial.apilar({ "Eliminar", borrado });
                cout << "Contacto eliminado." << endl;
            }
            else {
                cout << "No se encontro ese contacto." << endl;
            }
            break;
        }
        case 6: {
            if (historial.estaVacia()) {
                cout << "Aun no hay operaciones." << endl;
            }
            else {
                cout << "Historial (ultima operacion primero):" << endl;
                historial.mostrarHistorial();
            }
            break;
        }
        case 7: {
            pendientes.encolar(pedirContacto());
            cout << "Contacto en cola de pendientes." << endl;
            break;
        }
        case 8: {
            if (pendientes.estaVacia()) {
                cout << "No hay pendientes." << endl;
                break;
            }
            Contacto siguiente;
            while (pendientes.desencolar(siguiente)) {
                agenda.agregar(siguiente);
                historial.apilar({ "Agregar", siguiente });
            }
            cout << "Pendientes transferidos a la agenda." << endl;
            break;
        }
        case 9: {
            if (agenda.tamano() == 0) {
                cout << "La agenda esta vacia." << endl;
                break;
            }
            Arbol arbol;
            for (int i = 0; i < agenda.tamano(); i++) {
                arbol.insertar(agenda.obtener(i));
            }
            cout << "Contactos en el arbol (inorden):" << endl;
            arbol.mostrarInorden();
            break;
        }
        case 10: {
            string nombre = pedirTexto("Nombre del contacto a modificar: ");
            agenda.ordenarPorNombre();
            int pos = agenda.buscarBinaria(nombre);
            if (pos == -1) {
                cout << "No se encontro ese contacto." << endl;
                break;
            }
            cout << "Ingrese los nuevos datos:" << endl;
            Contacto nuevo = pedirContacto();
            agenda.obtener(pos) = nuevo;
            historial.apilar({ "Modificar", nuevo });
            cout << "Contacto modificado." << endl;
            break;
        }
        case 0:
            cout << "Hasta luego." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
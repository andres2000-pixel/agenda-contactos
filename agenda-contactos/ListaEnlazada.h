#pragma once
#pragma once
#include "Contacto.h"

// Cada nodo guarda un contacto y apunta al siguiente
struct Nodo {
    Contacto dato;
    Nodo* siguiente;
};

// Lista enlazada simple hecha desde cero (sin list)
class ListaEnlazada {
private:
    Nodo* cabeza;
    int cantidad;

public:
    ListaEnlazada() {
        cabeza = nullptr;
        cantidad = 0;
    }

    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    ListaEnlazada(const ListaEnlazada&) = delete;

    void agregarAlFinal(const Contacto& c) {
        Nodo* nuevo = new Nodo{ c, nullptr };
        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        cantidad++;
    }

    // Elimina el primer contacto con ese nombre.
    // Devuelve true si lo encontró y lo guarda en 'eliminado'.
    bool eliminarPorNombre(const string& nombre, Contacto& eliminado) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;
        while (actual != nullptr) {
            if (actual->dato.nombre == nombre) {
                if (anterior == nullptr) {
                    cabeza = actual->siguiente;
                }
                else {
                    anterior->siguiente = actual->siguiente;
                }
                eliminado = actual->dato;
                delete actual;
                cantidad--;
                return true;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        return false;
    }

    int tamano() const { return cantidad; }
    Nodo* inicio() const { return cabeza; }
};
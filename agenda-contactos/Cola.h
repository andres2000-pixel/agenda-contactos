#pragma once
#include <iostream>
#include "Contacto.h"

struct NodoCola {
    Contacto dato;
    NodoCola* siguiente;
};

// Cola hecha desde cero (sin queue): el primero en entrar es el primero en salir
class Cola {
private:
    NodoCola* frente;
    NodoCola* final;
    int cantidad;

public:
    Cola() {
        frente = nullptr;
        final = nullptr;
        cantidad = 0;
    }

    ~Cola() {
        while (frente != nullptr) {
            NodoCola* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    Cola(const Cola&) = delete;

    void encolar(const Contacto& c) {
        NodoCola* nuevo = new NodoCola{ c, nullptr };
        if (final == nullptr) {
            frente = nuevo;
            final = nuevo;
        }
        else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        cantidad++;
    }

    bool desencolar(Contacto& c) {
        if (frente == nullptr) return false;
        NodoCola* temp = frente;
        c = temp->dato;
        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;
        delete temp;
        cantidad--;
        return true;
    }

    bool estaVacia() const { return frente == nullptr; }
    int tamano() const { return cantidad; }
};

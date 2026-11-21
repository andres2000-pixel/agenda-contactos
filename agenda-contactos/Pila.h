#pragma once
#include <iostream>
#include "Contacto.h"

// Una operación del historial (Agregar o Eliminar)
struct Operacion {
    string tipo;
    Contacto contacto;
};

struct NodoPila {
    Operacion dato;
    NodoPila* abajo;
};

// Pila hecha desde cero (sin stack): el último en entrar es el primero en salir
class Pila {
private:
    NodoPila* tope;
    int cantidad;

public:
    Pila() {
        tope = nullptr;
        cantidad = 0;
    }

    ~Pila() {
        while (tope != nullptr) {
            NodoPila* temp = tope;
            tope = tope->abajo;
            delete temp;
        }
    }

    Pila(const Pila&) = delete;

    void apilar(const Operacion& op) {
        tope = new NodoPila{ op, tope };
        cantidad++;
    }

    bool desapilar(Operacion& op) {
        if (tope == nullptr) return false;
        NodoPila* temp = tope;
        op = temp->dato;
        tope = tope->abajo;
        delete temp;
        cantidad--;
        return true;
    }

    bool estaVacia() const { return tope == nullptr; }

    // Muestra de la más reciente a la más antigua
    void mostrarHistorial() const {
        NodoPila* actual = tope;
        while (actual != nullptr) {
            cout << actual->dato.tipo << ": "
                << actual->dato.contacto.nombre << endl;
            actual = actual->abajo;
        }
    }
};

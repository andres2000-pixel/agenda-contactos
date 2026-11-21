#pragma once
#include "Contacto.h"

// Arreglo dinámico hecho desde cero (sin vector)
class ArregloDinamico {
private:
    Contacto* datos;   // memoria reservada
    int cantidad;      // contactos guardados
    int capacidad;     // espacios disponibles

    // Duplica la capacidad cuando se llena
    void crecer() {
        capacidad *= 2;
        Contacto* nuevo = new Contacto[capacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevo[i] = datos[i];
        }
        delete[] datos;
        datos = nuevo;
    }

public:
    ArregloDinamico() {
        capacidad = 2;
        cantidad = 0;
        datos = new Contacto[capacidad];
    }

    ~ArregloDinamico() {
        delete[] datos;
    }

    // Evita copias accidentales del arreglo
    ArregloDinamico(const ArregloDinamico&) = delete;

    void agregar(const Contacto& c) {
        if (cantidad == capacidad) {
            crecer();
        }
        datos[cantidad] = c;
        cantidad++;
    }

    int tamano() const { return cantidad; }

    Contacto& obtener(int i) { return datos[i]; }
};

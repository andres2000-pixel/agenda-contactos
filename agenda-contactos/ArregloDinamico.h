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
    // Ordenamiento por inserción (por nombre)
    void ordenarPorNombre() {
        for (int i = 1; i < cantidad; i++) {
            Contacto actual = datos[i];
            int j = i - 1;
            while (j >= 0 && datos[j].nombre > actual.nombre) {
                datos[j + 1] = datos[j];
                j--;
            }
            datos[j + 1] = actual;
        }
    }

    // Búsqueda secuencial por teléfono: revisa uno por uno
    int buscarSecuencial(const string& telefono) const {
        for (int i = 0; i < cantidad; i++) {
            if (datos[i].telefono == telefono) return i;
        }
        return -1;
    }

    // Búsqueda binaria por nombre: requiere el arreglo ya ordenado
    int buscarBinaria(const string& nombre) const {
        int inicio = 0;
        int fin = cantidad - 1;
        while (inicio <= fin) {
            int medio = (inicio + fin) / 2;
            if (datos[medio].nombre == nombre) return medio;
            if (datos[medio].nombre < nombre) inicio = medio + 1;
            else fin = medio - 1;
        }
        return -1;
    }   
};

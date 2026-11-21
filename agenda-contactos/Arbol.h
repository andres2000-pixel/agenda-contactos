#pragma once
#include <iostream>
#include "Contacto.h"

struct NodoArbol {
    Contacto dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};

// Árbol binario de búsqueda hecho desde cero, ordenado por nombre
class Arbol {
private:
    NodoArbol* raiz;

    NodoArbol* insertarEn(NodoArbol* nodo, const Contacto& c) {
        if (nodo == nullptr) {
            return new NodoArbol{ c, nullptr, nullptr };
        }
        if (c.nombre < nodo->dato.nombre) {
            nodo->izquierdo = insertarEn(nodo->izquierdo, c);
        }
        else {
            nodo->derecho = insertarEn(nodo->derecho, c);
        }
        return nodo;
    }

    // Izquierdo, nodo, derecho: sale ordenado alfabéticamente
    void inordenEn(NodoArbol* nodo) const {
        if (nodo == nullptr) return;
        inordenEn(nodo->izquierdo);
        cout << nodo->dato.nombre << " - " << nodo->dato.telefono << endl;
        inordenEn(nodo->derecho);
    }

    void liberar(NodoArbol* nodo) {
        if (nodo == nullptr) return;
        liberar(nodo->izquierdo);
        liberar(nodo->derecho);
        delete nodo;
    }

public:
    Arbol() { raiz = nullptr; }
    ~Arbol() { liberar(raiz); }
    Arbol(const Arbol&) = delete;

    void insertar(const Contacto& c) { raiz = insertarEn(raiz, c); }
    void mostrarInorden() const { inordenEn(raiz); }

};  
#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"
#include "Palabra.h"
using namespace std;


class NodoArbol {
private:
    Palabra palabra;
    NodoArbol* padre;
    Cola<NodoArbol*> hijos;
public:
    NodoArbol(Palabra palabra_agregar, NodoArbol *padre_agregar) {
        palabra = palabra_agregar;
        padre = padre_agregar;
    }
    void addHijo(NodoArbol *palabra_agregar) {
        hijos.encolar(palabra_agregar);
    }
    NodoArbol* getPadre() {
        return padre;
    }
    Palabra getPalabra() {
        return palabra;
    }
    void setPalabra(Palabra palabra_modificar) {
        palabra = palabra_modificar;
    }
    Cola<NodoArbol*> getHijos() {
        return hijos;
    }
    void setPadre(NodoArbol* padre_nuevo) {
        padre = padre_nuevo;
    }
};

class Arbol {
private:
    int hijos_maximos;
    int comparaciones;
    Pila<NodoArbol*> pila;
    Cola<NodoArbol*> arbol_izq;
    Cola<NodoArbol*> final;
    NodoArbol* padre;
    void swap(NodoArbol *&p1);
    void swapSimple(NodoArbol*& p1, NodoArbol*& p2);
    void reOrdenar(NodoArbol* raiz_principal, Palabra aux);
    NodoArbol* obtenerRaizPrincipal(NodoArbol* ultimo_hijo);
    NodoArbol* buscarMayor(Cola<NodoArbol*> hijos);
public:
    Arbol(int n);
    void add(Palabra palabra);
    void ordenar();
    bool esta(string palabra);
    Cola<NodoArbol*> getArbol();
    void prueba();
};

#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include "Lista.h"
#include "Cola.h"
#include "Palabra.h"
using namespace std;


class NodoArbol {
private:
    Palabra palabra;
    NodoArbol* padre;
    Lista<NodoArbol*> hijos;
public:
    NodoArbol(Palabra palabra_agregar, NodoArbol *padre_agregar) {
        palabra = palabra_agregar;
        padre = padre_agregar;
    }
    void addHijo(NodoArbol *palabra_agregar) {
        hijos.add(palabra_agregar);
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
    Lista<NodoArbol*> getHijos() {
        return hijos;
    }
};

class Arbol {
private:
    int hijos_maximos;
    int comparaciones;
    Cola<NodoArbol*> arbol_izq;
    NodoArbol* raiz_principal;
    void swap(NodoArbol*& p1, NodoArbol*& p2);
    bool esta(NodoArbol* aux, string palabra);
    void add(Palabra palabra, NodoArbol* padre, Cola<NodoArbol*> proximas_raices);
public:
    Arbol(int n);
    void addPalabra(Palabra palabra);
    bool esta(string palabra);
    Cola<NodoArbol*> getArbol();
};

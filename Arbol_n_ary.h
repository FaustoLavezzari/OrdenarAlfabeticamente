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
    Cola<NodoArbol*> arbol_izq;
    Cola<NodoArbol*> final;
    NodoArbol* raiz_principal;
    void swap(NodoArbol *&p1);
    bool esta(NodoArbol *aux, string palabra);
    NodoArbol* buscarMayor(Cola<NodoArbol*> hijos);
public:
    Arbol(int n);
    void add(Palabra palabra);
    bool esta(string palabra);
    Cola<NodoArbol*> getArbol();
    void prueba();
};

#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include "Lista.h"
using namespace std;


class NodoArbol {
private:
    string palabra;
    NodoArbol* padre;
    Lista<NodoArbol*> hijos;
    int contador;
public:
    NodoArbol(string palabra_agregar, NodoArbol *padre_agregar, int n) {
        palabra = palabra_agregar;
        padre = padre_agregar;
    }
    void addHijo(NodoArbol *palabra_agregar) {
        hijos.add(palabra_agregar);
    }
    NodoArbol* getPadre() {
        return padre;
    }
    void repetida() {
        contador++;
    }
    int getRepeticiones() {
        return contador;
    }
};

class arbol {
private:
    int hijos_maximos;
    NodoArbol* raiz;

};
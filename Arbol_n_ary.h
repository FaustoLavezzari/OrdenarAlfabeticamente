#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include "Palabra.h"
#include <stack>;
#include <queue>;
#include <list>;
using namespace std;


class NodoArbol {
private:
    Palabra palabra;
    NodoArbol* padre;
    queue<NodoArbol*> hijos;
    bool fijo;
public:
    NodoArbol(Palabra palabra_agregar, NodoArbol *padre_agregar) {
        palabra = palabra_agregar;
        padre = padre_agregar;
        fijo = 0;
    }
    void addHijo(NodoArbol *palabra_agregar) {
        hijos.emplace(palabra_agregar);
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
    queue<NodoArbol*> getHijos() {
        return hijos;
    }
    void setPadre(NodoArbol* padre_nuevo) {
        padre = padre_nuevo;
    }
    bool getFijo() {
        return fijo;
    }
    void setFijo() {
        fijo = 1;
    }
};

class Arbol {
private:
    int hijos_maximos;
    long int comparaciones;
    stack<NodoArbol*> pila;
    queue<NodoArbol*> arbol_izq;
    queue<NodoArbol*> final;
    NodoArbol* padre;
    void swap(NodoArbol *p1);
    void swapSimple(NodoArbol *p1, NodoArbol *p2);
    void reOrdenar(NodoArbol* raiz_principal, Palabra aux);
    NodoArbol* obtenerRaizPrincipal(NodoArbol* ultimo_hijo);
    NodoArbol* buscarMayor(NodoArbol* padre);
public:
    Arbol(int n);
    void add(Palabra palabra);
    void ordenar();
    long int getComparaciones() { return comparaciones; }
    queue<NodoArbol*> getArbol();
};

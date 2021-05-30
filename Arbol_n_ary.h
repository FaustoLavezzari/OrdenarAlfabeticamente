#pragma once
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include "Lista.h"
#include "Cola.h"
using namespace std;


class NodoArbol {
private:
    string palabra;
    NodoArbol* padre;
    Lista<NodoArbol*> hijos;
    int contador;
public:
    NodoArbol(string palabra_agregar, NodoArbol *padre_agregar) {
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
    string getPalabra() {
        return palabra;
    }
    void setPalabra(string palabra_modificar) {
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
    Cola<NodoArbol*> proximas_raices;
    NodoArbol* raiz;
    void swap(NodoArbol*& p1, NodoArbol*& p2);
    bool esta(NodoArbol* aux, string palabra);
public:
    
    Arbol(int n) {
        hijos_maximos = n;
        int comparaciones = 0;
        raiz = NULL;
    }
    
    void add(string palabra) {
        NodoArbol* nuevo = new NodoArbol(palabra, raiz);
        proximas_raices.add(nuevo);
        if (raiz == NULL) {       
            raiz = nuevo;
        }
        else{
            bool repetida = esta(palabra);
            if(!repetida){
                if (raiz->getHijos().size() != hijos_maximos) {
                    if (palabra > raiz->getPalabra()) {
                        swap(nuevo, raiz);
                    }
                    raiz->addHijo(nuevo);
                }
                else {
                    raiz = proximas_raices.tope();
                    proximas_raices.desencolar();
                }
            }
        }
    }
    bool esta(string palabra);

};

#pragma once
#include <sstream> 
#include <stack>;
#include <queue>;
using namespace std;

class NodoArbol {
private:
    string palabra;
    NodoArbol* padre;
    queue<NodoArbol*> hijos;
    bool fijo;
public:
    NodoArbol(string palabra_agregar, NodoArbol *padre_agregar) {
        palabra = palabra_agregar;
        padre = padre_agregar;
        fijo = 0;
    }
    void addHijo(NodoArbol *palabra_agregar) {hijos.emplace(palabra_agregar);}
    NodoArbol* getPadre() { return padre;}
    string getPalabra() {return palabra;}
    void setPalabra(string palabra_modificar) {palabra = palabra_modificar;}
    queue<NodoArbol*> getHijos() {return hijos;}
    void setPadre(NodoArbol* padre_nuevo) {padre = padre_nuevo;}
    bool getFijo() {return fijo;}
    void setFijo() {fijo = 1; }
};

class Arbol{
private:
    int hijos_maximos;
    long int comparaciones;
    long int swaps;
    stack<NodoArbol*> pila_ordenamiento;
    queue<NodoArbol*> cola_armado;
    queue<NodoArbol*> final;
    NodoArbol* padre;
    void swap(NodoArbol *p1);
    void swapSimple(NodoArbol *p1, NodoArbol *p2);
    void reOrdenar(NodoArbol* raiz_principal, string aux);
    NodoArbol* obtenerRaizPrincipal(NodoArbol* ultimo_hijo);
    NodoArbol* buscarMayor(NodoArbol* padre);
public:
    Arbol(int n);
    void add(string palabra);
    void ordenar();
    long int getComparaciones() { return comparaciones; }
    long int getSwaps() { return swaps; }
    queue<NodoArbol*> getArbol() { return final; }
};

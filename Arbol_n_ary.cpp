#include "Arbol_n_ary.h"


Arbol:: Arbol(int n) {
    hijos_maximos = n;
    int comparaciones = 0;
    raiz_principal = NULL;
}

void Arbol::addPalabra(Palabra palabra) {
    Cola<NodoArbol*> proximas_raices;
    proximas_raices = arbol_izq;
    NodoArbol* raiz = proximas_raices.tope();
    proximas_raices.desencolar();
    add(palabra, raiz, proximas_raices);
}

void Arbol:: add(Palabra palabra, NodoArbol* padre, Cola<NodoArbol*> proximas_raices) {
    NodoArbol* nuevo = new NodoArbol(palabra, padre);
    if (padre == NULL) {
        raiz_principal = nuevo;
        arbol_izq.add(nuevo);
    }
    else if (padre->getHijos().size() < hijos_maximos) {
      if (palabra.texto > padre->getPalabra().texto) {
            swap(nuevo, padre);
      }
        padre->addHijo(nuevo);
        arbol_izq.add(nuevo);
    }
    else {
        if (palabra.texto > padre->getPalabra().texto) {
            swap(nuevo, padre);
        }
        NodoArbol* raiz = proximas_raices.tope();
        proximas_raices.desencolar();
        add(palabra, raiz, proximas_raices);
    }
}

void Arbol::swap(NodoArbol*& p1, NodoArbol*& p2){
    Palabra auxiliar = p1->getPalabra();
    p1->setPalabra(p2->getPalabra());
    p2->setPalabra(auxiliar);
}

Cola<NodoArbol*> Arbol::getArbol(){
    return arbol_izq;
}

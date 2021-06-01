#include "Arbol_n_ary.h"


Arbol:: Arbol(int n) {
    hijos_maximos = n;
    int comparaciones = 0;
    raiz_principal = NULL;
}

void Arbol::add(Palabra palabra) {
    NodoArbol* nuevo = new NodoArbol(palabra, raiz_principal);
    arbol_izq.encolar(nuevo);
    final.encolar(nuevo);
    if (raiz_principal == NULL) {
        raiz_principal = nuevo;
    }
    else {
        if (arbol_izq.tope()->getHijos().size() >= hijos_maximos) {
            arbol_izq.desencolar();                
            raiz_principal = arbol_izq.tope();
            nuevo->setPadre(raiz_principal);
            cout << "cambio de padre, ahora es: "<<raiz_principal->getPalabra().texto << endl;
        }
        raiz_principal->addHijo(nuevo);
        cout << "agregue el: " << nuevo->getPalabra().texto << endl;
        swap(nuevo);
    }
}

void Arbol::swap(NodoArbol *&p1){
    if((p1->getPadre() != NULL) && (p1->getPadre()->getPalabra().texto < p1->getPalabra().texto)){
        cout << "Estoy swapeando al hijo " << p1->getPalabra().texto <<" Por el padre "<<p1->getPadre()->getPalabra().texto<< endl;
        Palabra auxiliar = p1->getPadre()->getPalabra();
        p1->getPadre()->setPalabra(p1->getPalabra());
        p1->setPalabra(auxiliar);
        
        NodoArbol* aux2 = p1->getPadre();
        swap(aux2);
    }
}

Cola<NodoArbol*> Arbol::getArbol(){
    return final;
}

NodoArbol* Arbol::buscarMayor(Cola<NodoArbol*> hijos) {
    string mayor = " ";
    NodoArbol* mayor_nodo= NULL;
    for (int i = 0; i <=hijos.size(); i++) {
        if(hijos.tope()->getPalabra().texto > mayor){
            mayor = hijos.tope()->getPalabra().texto;
            mayor_nodo = hijos.tope();
        }
    hijos.desencolar();
    }
    return mayor_nodo;
}

void Arbol:: prueba() {
    for (int i = 0; i < final.size(); i++) {
        for (int i = 0; i < final.tope()->getHijos().size(); i++) {
        }
        NodoArbol* mayor = buscarMayor(final.tope()->getHijos());
        cout << "el hijo mayor de " << final.tope()->getPalabra().texto << " es: " << mayor->getPalabra().texto<< endl;
        final.desencolar();
    }
}

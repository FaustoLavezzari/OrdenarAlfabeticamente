#include "Arbol_n_ary.h"
Arbol:: Arbol(int n) {
    hijos_maximos = n;
    int comparaciones = 0;
    padre = NULL;
}

void Arbol::add(Palabra palabra) {
    NodoArbol* nuevo = new NodoArbol(palabra, padre);
    arbol_izq.encolar(nuevo);
    pila.apilar(nuevo);
    final.encolar(nuevo);
    if (padre == NULL) {
        padre = nuevo;
    }
    else {
        if (arbol_izq.tope()->getHijos().size() >= hijos_maximos) {
            arbol_izq.desencolar();                
            padre = arbol_izq.tope();
            nuevo->setPadre(padre);
        }
        padre->addHijo(nuevo);
        swap(nuevo);
    }
}

void Arbol::swap(NodoArbol *p1){
    if((p1->getPadre() != NULL) && (p1->getPadre()->getPalabra().texto < p1->getPalabra().texto)){
        Palabra auxiliar = p1->getPadre()->getPalabra();
        p1->getPadre()->setPalabra(p1->getPalabra());
        p1->setPalabra(auxiliar);
        
        NodoArbol* aux2 = p1->getPadre();
        swap(aux2);
    }
}

void Arbol::swapSimple(NodoArbol *p1, NodoArbol *p2){                                // El primer valor p1 lo remplazamos por la palabra de p2, y p2 le remplazamos la palabra por " "
    Palabra aux;
    aux.texto = " ";
    p1->setPalabra(p2->getPalabra());
    p2->setPalabra(aux);
}

void Arbol::ordenar() {
    while (!pila.esvacia()) {
        NodoArbol* ultimo_hijo = pila.tope();
        pila.desapilar();
        Palabra aux = ultimo_hijo->getPalabra();
        NodoArbol* raiz_principal = obtenerRaizPrincipal(ultimo_hijo);
        swapSimple(ultimo_hijo, raiz_principal);        
        reOrdenar(raiz_principal, aux);
    }   
}

void Arbol::reOrdenar(NodoArbol *raiz_principal2, Palabra aux) {
    int aux2 = raiz_principal2->getHijos().size();
    NodoArbol* mayor = buscarMayor(raiz_principal2->getHijos(), raiz_principal2);
    if (aux2 != 0 && mayor != NULL) {
        swapSimple(raiz_principal2, mayor);
        reOrdenar(mayor, aux);
    }
    else {
        raiz_principal2->setPalabra(aux);
        swap(raiz_principal2);
    }
}

NodoArbol* Arbol::buscarMayor(Cola<NodoArbol*> hijos, NodoArbol* padre) {
    string mayor =  " ";
    NodoArbol* mayor_nodo= NULL;
    int aux = hijos.size();
    for (int i = 0; i < aux && aux != 0; i++) {
        if(hijos.tope()->getPalabra().texto >= mayor && pila.esta(hijos.tope())){
            mayor = hijos.tope()->getPalabra().texto;
            mayor_nodo = hijos.tope();
        }
        padre->addHijo(hijos.tope());
        hijos.desencolar();
    }
    return mayor_nodo;
}

Cola<NodoArbol*> Arbol::getArbol() {
    return final;
}

NodoArbol* Arbol::obtenerRaizPrincipal(NodoArbol* ultimo_hijo){
    NodoArbol* raiz_principal1;
    if(ultimo_hijo->getPadre() != NULL){
        raiz_principal1 = ultimo_hijo->getPadre();
        obtenerRaizPrincipal(raiz_principal1);
    }
    else{
        return ultimo_hijo;
    }
}
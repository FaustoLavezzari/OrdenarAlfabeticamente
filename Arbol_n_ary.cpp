#include "Arbol_n_ary.h"
Arbol:: Arbol(int n) {
    hijos_maximos = n;
    int comparaciones = 0;
    padre = NULL;
}

void Arbol::add(Palabra palabra) {
    NodoArbol* nuevo = new NodoArbol(palabra, padre);
    arbol_izq.emplace(nuevo);
    pila.push(nuevo);
    final.emplace(nuevo);
    if (padre == NULL) {
        padre = nuevo;
    }
    else {
        comparaciones++;
        if (arbol_izq.front()->getHijos().size() >= hijos_maximos) {
            arbol_izq.pop();                
            padre = arbol_izq.front();
            nuevo->setPadre(padre);
        }
        padre->addHijo(nuevo);
        swap(nuevo);
    }
}

void Arbol::swap(NodoArbol *p1){
    if((p1->getPadre() != NULL) && (p1->getPadre()->getPalabra().texto < p1->getPalabra().texto)){
        comparaciones++;
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
    while (!pila.empty()) {
        NodoArbol* ultimo_hijo = pila.top();
        pila.pop();
        Palabra aux = ultimo_hijo->getPalabra();
        NodoArbol* raiz_principal = obtenerRaizPrincipal(ultimo_hijo);
        swapSimple(ultimo_hijo, raiz_principal); 
        ultimo_hijo->setFijo();
        reOrdenar(raiz_principal, aux);
    }   
}

void Arbol::reOrdenar(NodoArbol *raiz_principal2, Palabra aux) {
    int aux2 = raiz_principal2->getHijos().size();
    NodoArbol* mayor = buscarMayor(raiz_principal2);
    if (aux2 != 0 && mayor != NULL) {
        swapSimple(raiz_principal2, mayor);
        reOrdenar(mayor, aux);
    }
    else {
        raiz_principal2->setPalabra(aux);
        swap(raiz_principal2);
    }
}

NodoArbol* Arbol::buscarMayor(NodoArbol* padre) {
    queue<NodoArbol*> hijos = padre->getHijos();
    string mayor =  " ";
    NodoArbol* mayor_nodo= NULL;
    int aux = hijos.size();
    for (int i = 0; i < aux && aux != 0; i++) {
        comparaciones++;
        if(hijos.front()->getPalabra().texto >= mayor && !hijos.front()->getFijo()){
            mayor = hijos.front()->getPalabra().texto;
            mayor_nodo = hijos.front();
        }
        hijos.pop();
    }
    return mayor_nodo;
}

queue<NodoArbol*> Arbol::getArbol() {
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
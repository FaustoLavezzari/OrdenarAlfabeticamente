#include "Arbol_n_ary.h"

Arbol:: Arbol(int n) {
    hijos_maximos = n;
    long int comparaciones = 0;
    long int swaps = 0;
    padre = NULL;
}

void Arbol::add(string palabra) {
    NodoArbol* nuevo = new NodoArbol(palabra, padre);
    cola_armado.emplace(nuevo);
    pila_ordenamiento.push(nuevo);
    final.emplace(nuevo);
    if (padre == NULL) {
        padre = nuevo;
    }
    else {
        if (cola_armado.front()->getHijos().size() >= hijos_maximos) {
            cola_armado.pop();                
            padre = cola_armado.front();
            nuevo->setPadre(padre);
        }
        padre->addHijo(nuevo);
        swap(nuevo);
    }
}

void Arbol::swap(NodoArbol *p1){
    comparaciones++;
    if((p1->getPadre() != NULL) && (p1->getPadre()->getPalabra() < p1->getPalabra())){
        swaps++;
        string auxiliar = p1->getPadre()->getPalabra();
        p1->getPadre()->setPalabra(p1->getPalabra());
        p1->setPalabra(auxiliar);
        swap(p1->getPadre());
    }
}

void Arbol::swapSimple(NodoArbol *p1, NodoArbol *p2){                                // El primer valor p1 lo remplazamos por la palabra de p2, y p2 le remplazamos la palabra por " "
    string aux = " ";
    p1->setPalabra(p2->getPalabra());
    p2->setPalabra(aux);
    swaps++;
}

void Arbol::ordenar() {
    comparaciones = 0;
    swaps = 0;
    while (!pila_ordenamiento.empty()) {
        NodoArbol* ultimo_hijo = pila_ordenamiento.top();
        pila_ordenamiento.pop();
        string aux = ultimo_hijo->getPalabra();
        NodoArbol* raiz_principal = obtenerRaizPrincipal(ultimo_hijo);
        swapSimple(ultimo_hijo, raiz_principal); 
        ultimo_hijo->setFijo();
        reOrdenar(raiz_principal, aux);
    }   
}

void Arbol::reOrdenar(NodoArbol *raiz, string aux) {
    NodoArbol* mayor = buscarMayor(raiz);           //determina el mayor de los hijos
    if (mayor != NULL) {
        swapSimple(raiz, mayor);
        reOrdenar(mayor, aux);
    }
    else {
        raiz->setPalabra(aux);
        swap(raiz);
    }
}

NodoArbol* Arbol::buscarMayor(NodoArbol* padre) {
    queue<NodoArbol*> hijos = padre->getHijos();
    string mayor =  " ";
    NodoArbol* mayor_nodo= NULL;
    int cantidad_hijos = hijos.size();                                            //si la cantidad de hijos es 0 retorna null
    for (int i = 0; i < cantidad_hijos && cantidad_hijos != 0; i++) {
        comparaciones++;
        if(hijos.front()->getPalabra() >= mayor && !hijos.front()->getFijo()){
            mayor = hijos.front()->getPalabra();
            mayor_nodo = hijos.front();
        }
        hijos.pop();
    }
    return mayor_nodo;
}

NodoArbol* Arbol::obtenerRaizPrincipal(NodoArbol* ultimo_hijo){
    if(ultimo_hijo->getPadre() != NULL){
        obtenerRaizPrincipal(ultimo_hijo->getPadre());
    }
    else{
        return ultimo_hijo;
    }
}
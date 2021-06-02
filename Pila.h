#pragma once
#include "Lista.h"
template <class T> class Pila :public Lista<T> {
public:
    Pila() { Lista<T>(); };
    void apilar(T d) { this->add(d); };
    T tope(void) { return this->cabeza(); };
    void desapilar(void) { this->borrar(); };
    bool pilavacia() { return this->esvacia(); };
};


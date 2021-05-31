
#include <iostream>
#include <fstream>
#include <sstream>
#include "Cola.h"
#include "Lista.h"
#include "Arbol_n_ary.h"

using namespace std;
void leer_archivo(Cola<string>&palabras);


int main()
{
    int n;
    cout << "ingrese el n a utilizar: ";
    cin >> n;
    Arbol arbol(n);
    Cola<string> *palabras = new Cola<string>;
    leer_archivo(*palabras);
    
    while (!palabras->esvacia()) {
        Palabra siguiente;
        siguiente.texto = palabras->tope();
        siguiente.contador = 0;
        arbol.addPalabra(siguiente);
        palabras->desencolar();
    }

    Cola<NodoArbol*> arbol_final = arbol.getArbol();
    while (!arbol_final.esvacia())
    {
        Palabra siguiente = arbol_final.tope()->getPalabra();
        cout << siguiente.texto << endl;
        arbol_final.desencolar();
    }


    return 0;
}




void leer_archivo(Cola<string> &palabras){

    ifstream archivo;
    string linea;

    archivo.open("archivoLeer.txt", ios::in);          //para abrir el archivo que contiene las 1000 palabras o mas
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    
    while(getline(archivo,linea)){                         //ciclo while que lee el archivo
        istringstream isstream(linea);

    while(!isstream.eof()){                                 //ciclo while para separar palabra por palabra la fila del .txt
        string tempLinea;
        isstream >> tempLinea;
        if (!tempLinea.empty()) {                           //evitar que luego de un espacio antes del salto de linea agregue un string vacio a la cola
            palabras.encolar(tempLinea);
            }      
        }
    }
    archivo.close();
}
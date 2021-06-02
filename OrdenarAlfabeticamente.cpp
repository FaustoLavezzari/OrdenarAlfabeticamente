#include <iostream>
#include <fstream>
#include <sstream>
#include "Arbol_n_ary.h"
#include <stack>;

using namespace std;
void leer_archivo(queue<string>&palabras);
void escribir_archivo(Arbol arbol);


int main()
{
    int n;
    cout << "ingrese el n a utilizar: ";
    cin >> n;
    Arbol arbol(n);
    queue<string> *palabras = new queue<string>;
    leer_archivo(*palabras);
    
    while (!palabras->empty()) {
        arbol.add(palabras->front());
        palabras->pop();
    }

    arbol.ordenar();

    escribir_archivo(arbol);                                  //escribo el texto final ordenado en un archivo de texto llamado archivoEscribir.txt
    return 0;
}

void leer_archivo(queue<string> &palabras){

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
            palabras.emplace(tempLinea);
            }      
        }
    }
    archivo.close();
}

void escribir_archivo(Arbol arbol) {
    ofstream archivo;
    queue<NodoArbol*> cola = arbol.getArbol();
    archivo.open("archivoEscribir.txt", ios::out);      //Abriendo el archivo
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!cola.empty())
    {
        string siguiente = cola.front()->getPalabra();
        archivo << siguiente << endl;
        cola.pop();
    }
    archivo <<"Se realizaron: "<< arbol.getComparaciones() << " comparaciones"<< endl;
    archivo << "Se realizaron: " << arbol.getSwaps() << " swaps" << endl;
    archivo.close();
}
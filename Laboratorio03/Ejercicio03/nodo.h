#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo
{
    public:
        int valor;
        Nodo *siguiente;
        Nodo *anterior; // Puntero al nodo anterior
        ~Nodo(){
            cout << "\nNodo eliminado "<<valor;
        }
};
#endif
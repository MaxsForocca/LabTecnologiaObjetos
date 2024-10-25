#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {
public:
    Nodo *inicio; // Apuntador al inicio de la lista
    Nodo *fin;    // Apuntador al final de la lista

    Lista();
    void copiaArreglo(int arreglo[], int size);
    void imprimeListaAdelante();
    void imprimeListaAtras();
    bool buscarDesdeAdelante(int valor);
    bool buscarDesdeAtras(int valor);
    void destruyeLista();
    ~Lista();
};

#endif

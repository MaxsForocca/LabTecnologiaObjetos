#include "lista.h"

// Constructor por defecto
Lista::Lista() {
    cout << "Constructor por defecto\n";
    inicio = nullptr;
    fin = nullptr; // Inicializamos fin en nullptr
}

void Lista::copiaArreglo(int arreglo[], int size) {
    for (int i = 0; i < size; ++i) {
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->valor = arreglo[i];
        nuevoNodo->siguiente = nullptr;
        nuevoNodo->anterior = fin; // Apunta al nodo anterior

        if (inicio == nullptr) {
            // Si la lista está vacía, el nuevo nodo es el inicio
            inicio = nuevoNodo;
        } else {
            // Enlazamos el nuevo nodo al final de la lista
            fin->siguiente = nuevoNodo;
        }

        fin = nuevoNodo; // Actualizamos el puntero fin
    }
}

void Lista::imprimeListaAdelante() {
    Nodo *iNodo = inicio;
    while (iNodo != nullptr) {
        cout << iNodo->valor << " ";
        iNodo = iNodo->siguiente;
    }
    cout << endl;
}

void Lista::imprimeListaAtras() {
    Nodo *iNodo = fin;
    while (iNodo != nullptr) {
        cout << iNodo->valor << " ";
        iNodo = iNodo->anterior;
    }
    cout << endl;
}

bool Lista::buscarDesdeAdelante(int valor) {
    Nodo *iNodo = inicio;
    while (iNodo != nullptr) {
        if (iNodo->valor == valor) {
            return true; 
        }
        iNodo = iNodo->siguiente;
    }
    return false; 
}

bool Lista::buscarDesdeAtras(int valor) {
    Nodo *iNodo = fin;
    while (iNodo != nullptr) {
        if (iNodo->valor == valor) {
            return true; 
        }
        iNodo = iNodo->anterior;
    }
    return false; 
}

void Lista::destruyeLista() {
    Nodo *iNodo = inicio;
    while (iNodo != nullptr) {
        Nodo *auxNodo = iNodo;
        iNodo = iNodo->siguiente;
        delete auxNodo; // Se elimina el nodo
    }
}

Lista::~Lista() {
    destruyeLista(); // Llamamos a destruyeLista en el destructor
}

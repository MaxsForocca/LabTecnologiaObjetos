/*
Laboratorio 02 - Ejercicio 02
Implementar con punteros una lista doblemente enlazada, utilizar clases o struct
*/
#include <iostream>

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;               
    Nodo* siguiente;      
    Nodo* anterior;       

    Nodo(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;  
    Nodo<T>* cola;    

public:
    
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    ~ListaDoble() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertarAlFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);

        if (cabeza == nullptr) {  // La lista está vacía
            cabeza = cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    void insertarAlInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);

        if (cabeza == nullptr) {  // La lista está vacía
            cabeza = cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
    }

    void eliminar(T valor) {
        Nodo<T>* actual = cabeza;

        while (actual != nullptr && actual->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "Valor no encontrado en la lista." << endl;
            return;
        }

        if (actual == cabeza) {
            cabeza = actual->siguiente;
        }
        if (actual == cola) {
            cola = actual->anterior;
        }

        if (actual->anterior != nullptr) {
            actual->anterior->siguiente = actual->siguiente;
        }

        if (actual->siguiente != nullptr) {
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual;
        cout << "Nodo con valor " << valor << " eliminado." << endl;
    }

    void mostrarAdelante() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void mostrarAtras() {
        Nodo<T>* actual = cola;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->anterior;
        }
        cout << endl;
    }
};

int main() {

    ListaDoble<int> listaEnteros;
    listaEnteros.insertarAlFinal(10);
    listaEnteros.insertarAlFinal(20);
    listaEnteros.insertarAlFinal(30);
    listaEnteros.insertarAlInicio(5);
    listaEnteros.insertarAlInicio(1);

    cout << "Lista de enteros hacia adelante: ";
    listaEnteros.mostrarAdelante();

    cout << "Lista de enteros hacia atrás: ";
    listaEnteros.mostrarAtras();

    listaEnteros.eliminar(20);
    cout << "Lista de enteros después de eliminar 20: ";
    listaEnteros.mostrarAdelante();

    ListaDoble<string> listaCadenas;
    listaCadenas.insertarAlFinal("Hola");
    listaCadenas.insertarAlFinal("Mundo");
    listaCadenas.insertarAlFinal("Generica");
    listaCadenas.insertarAlInicio("dice");
    listaCadenas.insertarAlInicio("C++");

    cout << "Lista de cadenas hacia adelante: ";
    listaCadenas.mostrarAdelante();

    listaCadenas.eliminar("Mundo");
    cout << "Lista de cadenas después de eliminar 'Mundo': ";
    listaCadenas.mostrarAdelante();

    return 0;
}

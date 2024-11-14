/*
 * Usar clase template para implementar estructuras de lista enlazada simple,
 * que permita armar secuencia de edades, secuencia de palabras.
*/
/*
#include <iostream>
#include <memory>

template <typename T>
class Nodo{
public:
    T dato;
    std::shared_ptr<Nodo<T>> siguiente;
    Nodo(T dat): dato(dat), siguiente(nullptr){}
    //~Nodo(){}
};

template <typename T>
class Lista{
public:
    std::shared_ptr<Nodo<T>> cabeza;

    Lista(): cabeza(nullptr) {}
    //~Lista(){}

    void agregar(T dat){
        auto nuevo = std::make_shared<Nodo<T>>(dat);

        if(!cabeza){
            cabeza = nuevo;
        } else {
            auto temp = cabeza;
            while(temp->siguiente){
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    void mostrar() {
        auto temp = cabeza;
        while (temp){
            std::cout << temp->dato << " - ";
            temp = temp->siguiente;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main(){
    Lista<int> *listaEdades = new Lista<int>();
    listaEdades->agregar(15); listaEdades->agregar(45); listaEdades->agregar(20);
    listaEdades->agregar(10); listaEdades->agregar(30); listaEdades->agregar(25);
    listaEdades->mostrar();

    Lista<std::string> *listaPalabras = new Lista<std::string>();
    listaPalabras->agregar("Hola"); listaPalabras->agregar("Mundo"); listaPalabras->agregar("Tecnologia");
    listaPalabras->agregar("Objetos"); listaPalabras->agregar("Maxs"); listaPalabras->agregar("!!!!");
    listaPalabras->mostrar();
    return 0;
}
*/

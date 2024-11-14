/*
 * Usar una clase plantilla para estructuras pila, debe permitir
 * manipular inserciones de tipos numéricos o caracteres.
*/
/*
#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Pila{
private:
    std::vector<T> elementos;
public:
    void push(const T& ele){
        elementos.push_back(ele);
    }

    void pop(){
        if (elementos.empty())
            throw std::out_of_range("Pila esta vacia");

        elementos.pop_back();
    }

    T top() const{
        if(elementos.empty())
            throw std::out_of_range("Pila esta vacia");

        return elementos.back();
    }

    T peek() const{
        if(elementos.empty())
            throw std::out_of_range("Pila esta vacia");

        return elementos.front();
    }

    void show(){
        for(T ele: elementos){
            std::cout << ele << " - ";
        }
        std::cout << "|" << std::endl;
    }

    bool isEmpty(){
        return elementos.empty();
    }
};


int main(){
    Pila<int> *miPila = new Pila<int>();
    miPila->push(80); miPila->push(90); miPila->push(70); miPila->push(40); miPila->push(10);
    miPila->show();
    std::cout << "TOP: " << miPila->top() << std::endl;
    std::cout << "PEEK: " << miPila->peek() << std::endl;
    miPila->pop();
    std::cout << "miPila -> pop() " << std::endl;
    std::cout << "TOP: " << miPila->top() << std::endl;
    std::cout << "PEEK: " << miPila->peek() << std::endl;
    miPila->show();
    return 0;
}
*/

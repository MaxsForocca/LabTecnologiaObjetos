// Ejercicio 01
#include <iostream>
#include "ToyFactory.cpp"
#include "RecetaFactory.cpp"
#include <windows.h>

using namespace std;

// client

int main ()
{
    SetConsoleOutputCP(CP_UTF8);
    int type;
    /*
    while (1){
        cout << endl << "Ingresa un tipo (1 a 3) o '0' para salir" << endl;
        cin >> type;
        if (!type) {
            break;
        }
        Toy *v = ToyFactory::createToy(type);
        if (v) {
            v->showProduct();
            delete v;
        }
    }
    */
    while (1){
        cout << endl << "Ingresa un tipo (1 a 3) o '0' para salir" << endl;
        cin >> type;
        if (!type) {
            break;
        }
        Receta *v = RecetaFactory::createReceta(type);
        if (v) {
            v->showReceta();
            delete v;
        }
    }

    cout << "Saliendo ..." << endl;
    return 0;
}

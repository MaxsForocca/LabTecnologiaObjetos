#include "GUIFactory.cpp"
#include <iostream>
#include <memory.h>

// Aplicacion
void Aplication(const GUIFactory& factory, int os) {
    // Crear componentes segun factory 
    auto button = factory.CrearControlWO();
    auto checkbox = factory.CrearControlMO();

    std::cout << "Creando interfaz para ";
    switch (os) {
        case 1:
            std::cout << "Windows:" << std::endl;
            break;
        case 2:
            std::cout << "Mac:" << std::endl;
            break;
        case 3:
            std::cout << "Linux:" << std::endl;
            break;
        default:
            std::cout << "Sistema desconocido" << std::endl;
            return;
    }

    button->Draw();
    checkbox->Draw();
}


int main () {
    // Con punteros inteligentes
    std::cout << "Cliente: Windows" << std::endl;
    WinFactory winFactory;
    Aplication(winFactory, 1);

    std::cout << "\nCliente: Mac" << std::endl;
    MacFactory macFactory;
    Aplication(macFactory, 2);

    std::cout << "\nCliente: Linux" << std::endl;
    LinuxFactory linuxFactory;
    Aplication(linuxFactory, 3);

    return 0;
}
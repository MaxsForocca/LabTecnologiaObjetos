#include "rectangulo.h"

int main()
{
    auto x = make_unique<Rectangulo>(); 
    std::cout << "Dibujar( )" << std::endl;
    x->Dibujar();

    auto y = make_unique<Rectangulo>(30, 5);

    std::cout << "Dibujar(30,5) : \n"; y->Dibujar();
    
    std::cout << "Dibujar (40,2): \n"; x->Dibujar(40, 2);

    auto obj1 = make_unique<Rectangulo>(*x);
    
    auto obj2 = make_unique<Rectangulo>(*y);

    obj1->Dibujar();
    obj2->Dibujar();
    
    return 0;
}

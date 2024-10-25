#include "rectangulo.h"

// CONSTRUCTOR POR DEFECTO
Rectangulo::Rectangulo()
{
    cout << "Constructor por defecto\n";
    miancho = make_unique<USHORT>(10);
    mialto = make_unique<USHORT>(2);
    val1 = make_unique<int>(0);
    val2 = make_unique<int>(0);
    val3 = make_unique<int>(0);
}

// CONSTRUCTOR PARAMETRIZADO
Rectangulo::Rectangulo(USHORT ancho, USHORT alto)
{
    cout << "Constructor normal\n";
    miancho = make_unique<USHORT>(ancho);
    mialto = make_unique<USHORT>(alto);
    val1 = make_unique<int>(0);
    val2 = make_unique<int>(0);
    val3 = make_unique<int>(0);
}

// CONSTRUCTOR COPIA
Rectangulo::Rectangulo(const Rectangulo& F)
{
    cout << "Constructor copia\n";
    miancho = make_unique<USHORT>(*F.miancho);
    mialto = make_unique<USHORT>(*F.mialto);
    val1 = make_unique<int>(*F.val1);
    val2 = make_unique<int>(*F.val2);
    val3 = make_unique<int>(*F.val3);
}

void Rectangulo::Dibujar()
{
    *val1 = 1; *val2 = 4; *val3 = 8;
    Dibujar(*miancho, *mialto);
}

void Rectangulo::Dibujar(USHORT ancho, USHORT alto)
{
    for (USHORT i = 0; i < alto; i++) {
        for (USHORT j = 0; j < ancho; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

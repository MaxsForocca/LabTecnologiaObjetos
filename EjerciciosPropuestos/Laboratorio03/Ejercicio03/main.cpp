#include "lista.h"

int main(int argc, char const *argv[]) {
    int arreglo[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const int longitud = sizeof(arreglo) / sizeof(*arreglo);

    Lista lista1; // llama al constructor por defecto
    lista1.copiaArreglo(arreglo, longitud);
    
    cout << "Imprimiendo lista desde adelante: ";
    lista1.imprimeListaAdelante();
    
    cout << "Imprimiendo lista desde atras: ";
    lista1.imprimeListaAtras();

    // Buscar valores
    int valorABuscar = 5;
    if (lista1.buscarDesdeAdelante(valorABuscar))
        cout << "Valor " << valorABuscar << " encontrado desde adelante\n";
    else
        cout << "Valor " << valorABuscar << " NO encontrado desde adelante\n";

    if (lista1.buscarDesdeAtras(valorABuscar))
        cout << "Valor " << valorABuscar << " encontrado desde atras\n";
    else
        cout << "Valor " << valorABuscar << " NO encontrado desde atras\n";

    lista1.destruyeLista();
    
    return 0;
}

/*
Ejercicio 03
Diseñe un programa que imprima los divisores de un número ingresado por teclado y la cantidad de divisores encontrados.
*/
#include <iostream>

using namespace std;

int divisoresNumero(int numero, int divisores[]){
    int cantidad = 0;
    for (int i = 1 ; i <= numero; i++){
        if(numero % i == 0){
            divisores[cantidad] = i;
            cantidad++;
        }
    }
    return cantidad;
}

void imprimirDivisores(int divisores[], int cantidad){
    cout << "Divisores: ";
    for (int i = 0; i < cantidad; i++){
        cout << divisores[i] << " ";
    }
    cout << endl;
}

int main(){
    int num;
    cout << "Ingrese un numero: "; 
    cin >> num;

    int divisores[num];

    int cantidad = divisoresNumero(num, divisores);

    imprimirDivisores(divisores, cantidad);

    cout << "Cantidad de divisores: " << cantidad << endl;

    return 0;
}
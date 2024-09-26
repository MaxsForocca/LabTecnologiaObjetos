/*
Ejercicio 01
Crear un programa que indique si un número es un cubo perfecto (anstrong) o no, se dice que un número es cubo perfecto si al sumar el cubo de sus dígitos dan el mismo número. 
*/
#include <iostream>
#include <cmath>
using namespace std;

bool isAnstrong(int n){
    int suma = 0;
    int aux = n;
    while (aux != 0){
        suma += pow(aux%10, 3);
        aux /= 10;
    }

    return n == suma;
}

int main(){
    int numero;
    cout << "Ingrese el numero: ";
    cin >> numero;

    cout << "El numero "<< numero <<(isAnstrong(numero)? " SI": " NO") << " es un cubo perfecto (anstrong)" << endl;


    return 0;
}

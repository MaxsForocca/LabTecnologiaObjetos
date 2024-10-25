/*
 * Ejercicio 01:
 *Contar los números impares y menores de 20 de un vector de números
 * enteros generados de forma aleatoria (la solución puede usar el método std :: count_if )
*/
/*
#include <QCoreApplication> // qDebug
#include <QDebug>
#include <algorithm> // count_if
#include <vector> // vector
#include <random> // random

#define MINIMO 0
#define MAXIMO 50

using namespace std;

random_device random; // semilla aleatoria
mt19937 generador(random()); // generador Mersenne Twister 19937
uniform_int_distribution<> distribucion(MINIMO, MAXIMO); // distribución uniforme int

void llenarVector(vector<int> &vec, int n) {
    for (int i = 0; i < n; i++) {
        vec.push_back(distribucion(generador)); // Generar número aleatorio
    }
}

bool esImparMenor20(int x) {
    return (x % 2 == 1 && x < 20);
}

int main() {

    vector<int> miVector;
    int cantidad = 40;
    llenarVector(miVector, cantidad);

    int cantidadNumeros = count_if(miVector.begin(), miVector.end(), esImparMenor20);

    qDebug() << "La cantidad de numeros impares menores a 20 de" << cantidad << "numeros es:" << cantidadNumeros;

    return 0;
}
*/

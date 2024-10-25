/*
Ejercicio 02
Se ha seleccionado N números de personas para realizar una encuesta, en un proceso repetitivo se ingresa el grado de instrucción (1-Primaria/2-Secundaria/3-Superior) y la edad (entre 15 y 80 años) de cada persona. Obtener la edad y el grado de instrucción usando números aleatorios.

Construya un programa que muestre lo siguiente:
El promedio de edades
La mayor edad.
Cantidad de Personas con instrucción Primaria
Cantidad de Personas con instrucción Secundaria.
Cantidad de Personas con instrucción Superior.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int EDAD_MINIMA = 15;
const int EDAD_MAXIMA = 80;

struct persona
{
    int edad;
    int gradoInstruccion;
};

// Para aleatorios entre edad y grado instruccion
int genAleatorio(int min, int max){
    return rand() % (max - min + 1) + min;
}

void generarPersonas(persona personas[], int n){
    for (int i = 0; i < n ; i++){
        personas[i].edad = genAleatorio(EDAD_MINIMA, EDAD_MAXIMA);
        personas[i].gradoInstruccion = genAleatorio(1, 3);
    }
}

double promedioEdad(persona personas[], int n){
    int sumaEdad = 0;
    for (int i = 0; i< n; i++){
        sumaEdad += personas[i].edad;
    }
    return static_cast<double> (sumaEdad) / n;
}

int mayorEdad(persona personas[], int n){
    int mayorEdad = personas[0].edad;
    for (int i = 1; i < n ; i ++){
        if(personas[i].edad > mayorEdad)
            mayorEdad = personas[i].edad;
    }
    return mayorEdad;
}

void cantidadGradoInstruccion(persona personas[], int n, int &primaria, int &secundaria, int &superior){
    primaria = secundaria = superior = 0;
    for (int i = 0; i < n; i++){
        if(personas[i].gradoInstruccion == 1) 
            primaria++;
        else if (personas[i].gradoInstruccion == 2)
            secundaria++;
        else if (personas[i].gradoInstruccion == 3)
            superior++;
    }
}

int main(){
    srand(time(0));
    int n;
    cout << "Ingrese la cantidad de personas: ";
    cin >> n;
    persona personas[n];
    generarPersonas(personas, n);
    int primaria, secundaria, superior;
    cantidadGradoInstruccion(personas, n, primaria, secundaria, superior);

    cout << "Promedio de edades: " << promedioEdad(personas, n) << endl;
    cout << "Mayor edad: " << mayorEdad(personas, n) << endl;
    cout << "Cantidad de personas con instruccion Primaria: " << primaria << endl;
    cout << "Cantidad de personas con instruccion Secundaria: " << secundaria << endl;
    cout << "Cantidad de personas con instruccion Superior: " << superior << endl;
    return 0;
}
/*
Laboratorio 02 - Ejercicio 01
Implementar una calculadora con 3 clases en el lenguaje c++, donde la primera analizará la
operación matemática (suma, resta….), la segunda administrará las operaciones matemáticas (el
núcleo de la calculadora), y la tercera procesara la operación ingresada.
El programa recibirá de entrada una cadena de texto con la operación a realizar
(“10+37”) (“45+14-42”) (“1+2+3+4+5+6”)
Como máximo el programa recibe 6 números a operar. 
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Para usar stringstream
#include <cctype>
#include <windows.h>

using namespace std;

class Analizador {
public:
    void analizarOperacion(const string& operacion, vector<int>& numeros, vector<char>& operadores) {
        stringstream ss(operacion); // Similar a un buffer (flujo de Entrada/Salida)
        int numero;
        char operador;

        ss >> numero;
        numeros.push_back(numero);

        while (ss >> operador >> numero) {
            operadores.push_back(operador);
            numeros.push_back(numero);
            if(numeros.size() >= 6 )
                break;
        }
    }
};

class Operador {
public:

    int operar(int a, int b, char oper) {
        switch (oper) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return b != 0 ? a / b : 0; // Evitar división por cero
            default:
                cout << "Operador inválido." << endl;
                return 0;
        }
    }
};

class Procesador {
private:
    Analizador analizador;
    Operador operador;
    
public:
    int procesarOperacion(const string& operacion) {
        vector<int> numeros;
        vector<char> operadores;

        analizador.analizarOperacion(operacion, numeros, operadores);

        int resultado = numeros[0];
        for (size_t i = 0; i < operadores.size(); ++i) {
            resultado = operador.operar(resultado, numeros[i + 1], operadores[i]); 
        }  

        return resultado;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Procesador procesador;

    string operacion;
    cout << "CALCULADORA SECUENCIAL" << endl;
    cout << "Introduce una operación matemática (máx. 6 números): ";
    cin >> operacion;

    int resultado = procesador.procesarOperacion(operacion);

    cout << "Resultado: " << resultado << endl;

    return 0;
}

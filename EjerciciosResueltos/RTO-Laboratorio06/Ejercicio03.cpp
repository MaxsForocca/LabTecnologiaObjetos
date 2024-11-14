/*
 * Aplicación C++ de comparación de tiempo de procesamiento para encontrar números primos en un
 * rango de 100000 (cien mil) números enteros, algoritmo con procesamiento secuencial y
 * procesamiento paralelo (hilos).
*/
#include <QDebug>
#include <QCoreApplication>
#include <QDebug>
#include <thread>
//#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>

// Funcion de procesamiento secuencial
void FindPrimes1(unsigned int start, unsigned int end,
                 std::vector<unsigned int>& vect){
    // Recorrer los numeros, menos los pares
    for (unsigned int x = start; x <= end; x+=2){
        for (unsigned int y = 2; y < x; y++){
            if ((x % y)==0){
                break;
            } else if ((y+1) == x){
                vect.push_back(x);
            }
        }
    }
}

// Funciones de procesamiento paralelo
std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start, unsigned int end){
    // Recorrer los numeros, menos los pares
    for (unsigned int x = start; x <= end; x+=2){

        for (unsigned int y = 2; y < x; y++){
            if ((x % y)==0){
                break;
            } else if ((y+1) == x){
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end,
                unsigned int numThreads){

    std::vector<std::thread> threadVect;
    // dividir la cantidad de numeros a procesar por hilo
    unsigned int threadSpread = end/ numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    // crear lista para cada hilo
    for (unsigned int x = 0; x < numThreads; x++){
        threadVect.emplace_back(FindPrimes, start, newEnd);

        start += threadSpread;
        newEnd += threadSpread;
    }

    // Lanzar cada hilo
    for (auto& t : threadVect) {
        t.join();
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // SIN HILOS
    std::vector<unsigned int> primeVect;

    // capturar fecha
    int startTime = clock();

    // encontrar primos sin hilos
    FindPrimes1(1, 100000, primeVect);

    // Capturar fecha final
    int endTime = clock();

    // tiempo transcurrido
    qDebug()<< ">> SIN HILOS"<< Qt::endl <<"Tiempo de ejecucion: " <<
        (endTime - startTime)/double(CLOCKS_PER_SEC) << Qt::endl;

    // CON HILOS
    // capturar fecha inicial
    startTime = clock();
    FindPrimesWithThreads(1, 100000, 8);
    endTime = clock();

    qDebug()<< ">> CON HILOS"<< Qt::endl <<"Tiempo de ejecucion: " <<
        (endTime - startTime)/double(CLOCKS_PER_SEC) << Qt::endl;

    return 0;
}

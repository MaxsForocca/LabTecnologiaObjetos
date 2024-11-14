/*
* Aplicación en C++ que simula la implementación de procesos paralelos
* por hilos, utilizando POSIX <pthread.h>
*/
/*
#include <qdebug.h>
//#include <stdlib.h>
#include <pthread.h> // pthread_delay_np, hilos POSIX

void* procesoHilo(void *dato) {
    struct timespec tm = {1, 0}; // segundos, nanosegundos
    while (1) {
        qDebug() << "proceso";
        pthread_delay_np(&tm); // struct timespec
    }
}

int main(){
    // Declarar hilos
    pthread_t proceso1;
    pthread_t proceso2;

    // Crear hilos
    pthread_create(&proceso1, NULL, &procesoHilo, NULL);
    pthread_create(&proceso2, NULL, &procesoHilo, NULL);

    // Lanzar hilos (procesos)
    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);

    return 0;
}
*/

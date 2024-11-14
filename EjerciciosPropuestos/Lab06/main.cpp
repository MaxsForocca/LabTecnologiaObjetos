#include <QCoreApplication>
#include <QDebug>
#include <memory>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>

// Nodo de la lista enlazada
template <typename T>
class Nodo {
public:
    T dato;
    std::shared_ptr<Nodo<T>> next;
    Nodo(T data) : dato(data), next(nullptr) {}
};

// Clase de la lista enlazada
template <typename T>
class ListaEnlazada {
private:
    std::shared_ptr<Nodo<T>> head;
    std::mutex mtx;

public:
    ListaEnlazada() : head(nullptr) {}

    void insertar(T valor) {
        std::lock_guard<std::mutex> lock(mtx);
        auto nuevo_nodo = std::make_shared<Nodo<T>>(valor);
        nuevo_nodo->next = head;
        head = nuevo_nodo;
        qDebug() << "Insertando:" << valor;
    }

    bool eliminar(T valor) {
        std::lock_guard<std::mutex> lock(mtx);
        auto actual = head;
        std::shared_ptr<Nodo<T>> anterior = nullptr;

        while (actual) {
            if (actual->dato == valor) {
                if (anterior) {
                    anterior->next = actual->next;
                } else {
                    head = actual->next;
                }
                qDebug() << "Eliminando:" << valor;
                return true;
            }
            anterior = actual;
            actual = actual->next;
        }
        qDebug() << "No se eliminó:" << valor;
        return false;
    }

    bool buscar(T valor) {
        std::lock_guard<std::mutex> lock(mtx);
        auto actual = head;

        while (actual) {
            if (actual->dato == valor) {
                qDebug() << "Buscado:" << valor;
                return true;
            }
            actual = actual->next;
        }
        qDebug() << "No encontrado:" << valor;
        return false;
    }

    bool modificar(T valor, T nuevo_valor) {
        std::lock_guard<std::mutex> lock(mtx);
        auto actual = head;

        while (actual) {
            if (actual->dato == valor) {
                actual->dato = nuevo_valor;
                qDebug() << "Modificando" << valor << "a" << nuevo_valor;
                return true;
            }
            actual = actual->next;
        }
        qDebug() << "No se encontró:" << valor;
        return false;
    }
};

void tarea_eliminar(ListaEnlazada<int>& lista) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        lista.eliminar(num);
    }
}

void tarea_insertar(ListaEnlazada<int>& lista) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        lista.insertar(num);
    }
}

void tarea_buscar(ListaEnlazada<int>& lista) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        lista.buscar(num);
    }
}

void tarea_modificar(ListaEnlazada<int>& lista) {
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        lista.modificar(num, rand() % 10 + 1);  // Modificar aleatorio entre 1 y 10
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    srand(static_cast<unsigned int>(time(nullptr)));

    ListaEnlazada<int> lista;

    std::thread hilo1(tarea_eliminar, std::ref(lista));
    std::thread hilo2(tarea_insertar, std::ref(lista));
    std::thread hilo3(tarea_buscar, std::ref(lista));
    std::thread hilo4(tarea_modificar, std::ref(lista));

    hilo1.join();
    hilo2.join();
    hilo3.join();
    hilo4.join();

    return 0;
}

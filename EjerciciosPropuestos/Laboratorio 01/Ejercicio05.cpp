/*
Implementar la estructura anterior con una clase.
Proponer en forma grafica una clase con atributos, referido a una billetera electronica (manejar saldo, productos en el carrito, numero de productos comprados).
*/
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Producto {
private:
    string nombre;
    float precio;
    string descripcion;

public:
    Producto(string _nombre, float _precio, string _descripcion)
        : nombre(_nombre), precio(_precio), descripcion(_descripcion) {}

    float obtenerPrecio() const {
        return precio;
    }

    string obtenerNombre() const {
        return nombre;
    }

    friend ostream& operator<< (ostream& os, const Producto& producto){
        os << "Producto: " << producto.nombre 
        << ", Precio: " << producto.precio 
        << ", Descripcion: " << producto.descripcion << endl;
        return os;
    }
};

class BilleteraElectronica {
private:
    float saldo;
    vector<Producto> productosEnCarrito;
    int numeroProductosComprados;

public:
    // Constructor
    BilleteraElectronica(float _saldo = 0.0)
        : saldo(_saldo), numeroProductosComprados(0) {}

    void agregarProducto(const Producto& producto) {
        productosEnCarrito.push_back(producto);
        cout << producto.obtenerNombre() << " ha sido añadido al carrito." << endl;
    }

    void eliminarProducto(const Producto& producto) {
        for (auto it = productosEnCarrito.begin(); it != productosEnCarrito.end(); ++it) {
            if (it->obtenerNombre() == producto.obtenerNombre()) {
                productosEnCarrito.erase(it);
                cout << producto.obtenerNombre() << " ha sido eliminado del carrito." << endl;
                return;
            }
        }
        cout << "Producto no encontrado en el carrito." << endl;
    }

    void comprar() {
        float total = 0;
        for (const auto& producto : productosEnCarrito) {
            total += producto.obtenerPrecio();
        }

        if (total > saldo) {
            cout << "Saldo insuficiente para realizar la compra." << endl;
        } else {
            saldo -= total;
            numeroProductosComprados += productosEnCarrito.size();
            productosEnCarrito.clear();
            cout << "Compra realizada exitosamente. Total gastado: " << total << endl;
        }
    }

    float consultarSaldo() const {
        return saldo;
    }

    void recargarSaldo(float monto) {
        saldo += monto;
        cout << "Saldo recargado exitosamente. Nuevo saldo: " << saldo << endl;
    }

    void mostrarCarrito() const {
        if (productosEnCarrito.empty()) {
            cout << "El carrito esta vacio." << endl;
        } else {
            cout << "Productos en el carrito:" << endl;
            for (const auto& producto : productosEnCarrito) {
                cout << producto;
            }
        }
    }

    int obtenerNumeroProductosComprados() const {
        return numeroProductosComprados;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    BilleteraElectronica billetera(100.0);

    Producto producto1("Smartphone", 50.0, "Un smartphone");
    Producto producto2("Audifonos", 20.0, "Audifonos de alta calidad");
    Producto producto3("Laptop", 120.0, "Una poderosa");

    billetera.agregarProducto(producto1);
    billetera.agregarProducto(producto2);

    billetera.mostrarCarrito();

    cout << "Saldo disponible: " << billetera.consultarSaldo() << endl;

    billetera.comprar();

    cout << "Saldo disponible despues de la compra: " << billetera.consultarSaldo() << endl;

    cout << "Numero de productos comprados: " << billetera.obtenerNumeroProductosComprados() << endl;

    // Sobrepasa el saldo
    billetera.agregarProducto(producto3);
    billetera.mostrarCarrito();
    billetera.comprar();

    billetera.recargarSaldo(100.0);

    return 0;
}

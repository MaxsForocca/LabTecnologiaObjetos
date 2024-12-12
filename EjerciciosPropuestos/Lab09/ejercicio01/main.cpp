#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <ctime>

// Enumeraciones para tipos de cuenta y operaciones
enum class TipoCuenta {
    AHORRO,
    JOVEN,
    PLUSS,
    EMPRESARIAL,
    TARJETA_CREDITO
};

enum class TipoOperacion {
    PRESTAMO_PERSONAL,
    TRANSFERENCIA_NACIONAL,
    COMPRA_TARJETA_CREDITO
};

// Clase abstracta para cuentas
class Cuenta {
protected:
    std::string numeroCuenta;
    double saldo;
    TipoCuenta tipoCuenta;

public:
    Cuenta(const std::string& numero, TipoCuenta tipo) 
        : numeroCuenta(numero), tipoCuenta(tipo), saldo(0.0) {}

    virtual double calcularInteres() const = 0;
    virtual double obtenerTasaOperacion(TipoOperacion operacion) const = 0;

    std::string getNumeroCuenta() const { return numeroCuenta; }
    TipoCuenta getTipoCuenta() const { return tipoCuenta; }
    double getSaldo() const { return saldo; }
    void setSaldo(double nuevoSaldo) { saldo = nuevoSaldo; }
};

// Implementaciones específicas de cuenta
class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro(const std::string& numero) : Cuenta(numero, TipoCuenta::AHORRO) {}

    double calcularInteres() const override { return 0.5; }
    double obtenerTasaOperacion(TipoOperacion operacion) const override {
        switch(operacion) {
            case TipoOperacion::TRANSFERENCIA_NACIONAL: return 0.5;
            default: return 0.0;
        }
    }
};

class CuentaJoven : public Cuenta {
public:
    CuentaJoven(const std::string& numero) : Cuenta(numero, TipoCuenta::JOVEN) {}

    double calcularInteres() const override { return 0.6; }
    double obtenerTasaOperacion(TipoOperacion operacion) const override {
        switch(operacion) {
            case TipoOperacion::TRANSFERENCIA_NACIONAL: return 0.5;
            default: return 0.0;
        }
    }
};

class CuentaPluss : public Cuenta {
public:
    CuentaPluss(const std::string& numero) : Cuenta(numero, TipoCuenta::PLUSS) {}

    double calcularInteres() const override { return 0.5; }
    double obtenerTasaOperacion(TipoOperacion operacion) const override {
        switch(operacion) {
            case TipoOperacion::TRANSFERENCIA_NACIONAL: return 0.5;
            case TipoOperacion::PRESTAMO_PERSONAL: return 10.0;
            default: return 0.0;
        }
    }
};

class CuentaTarjetaCredito : public Cuenta {
public:
    CuentaTarjetaCredito(const std::string& numero) : Cuenta(numero, TipoCuenta::TARJETA_CREDITO) {}

    double calcularInteres() const override { return 15.0; }
    double obtenerTasaOperacion(TipoOperacion operacion) const override {
        switch(operacion) {
            case TipoOperacion::COMPRA_TARJETA_CREDITO: return 25.0;
            case TipoOperacion::PRESTAMO_PERSONAL: return 10.0;
            default: return 0.0;
        }
    }
};

// Clase Cliente
class Cliente {
private:
    std::string nombre;
    std::string identificacion;
    std::vector<std::shared_ptr<Cuenta>> cuentas;

public:
    Cliente() : nombre(""), identificacion("") {}
    Cliente(const std::string& nom, const std::string& id) 
        : nombre(nom), identificacion(id) {}

    void agregarCuenta(std::shared_ptr<Cuenta> cuenta) {
        cuentas.push_back(cuenta);
    }

    std::vector<std::shared_ptr<Cuenta>> getCuentas() const { return cuentas; }
    std::string getNombre() const { return nombre; }
    std::string getIdentificacion() const { return identificacion; }
};

// Repositorio Singleton para gestión de clientes y cuentas
class RepositorioCuentas {
private:
    static RepositorioCuentas* instancia;
    std::unordered_map<std::string, Cliente> clientes;

    // Constructor privado
    RepositorioCuentas() {}

public:
    // Método estático para obtener la instancia
    static RepositorioCuentas* obtenerInstancia() {
        if (instancia == nullptr) {
            instancia = new RepositorioCuentas();
        }
        return instancia;
    }

    void registrarCliente(const Cliente& cliente) {
        clientes[cliente.getIdentificacion()] = cliente;
    }

    Cliente* obtenerCliente(const std::string& identificacion) {
        auto it = clientes.find(identificacion);
        return (it != clientes.end()) ? &(it->second) : nullptr;
    }

    std::string generarEstadoCuenta(const std::string& identificacion, std::time_t fecha = std::time(nullptr)) {
        Cliente* cliente = obtenerCliente(identificacion);
        if (!cliente) return "Cliente no encontrado";

        std::string estado = "Estado de Cuenta - " + cliente->getNombre() + "\n";
        for (const auto& cuenta : cliente->getCuentas()) {
            estado += "Cuenta: " + cuenta->getNumeroCuenta() + 
                      " | Tipo: " + std::to_string(static_cast<int>(cuenta->getTipoCuenta())) + 
                      " | Saldo: $" + std::to_string(cuenta->getSaldo()) + "\n";
        }
        return estado;
    }

    // Prevenir copia
    RepositorioCuentas(const RepositorioCuentas&) = delete;
    RepositorioCuentas& operator=(const RepositorioCuentas&) = delete;
};

// Inicializar puntero estático
RepositorioCuentas* RepositorioCuentas::instancia = nullptr;

int main() {
    // Ejemplo de uso
    auto repositorio = RepositorioCuentas::obtenerInstancia();

    // Crear cliente
    Cliente cliente1("Juan Perez", "12345");
    
    // Crear cuentas
    auto cuentaAhorro = std::make_shared<CuentaAhorro>("001-AHORRO");
    auto cuentaCredito = std::make_shared<CuentaTarjetaCredito>("002-CREDITO");
    
    cuentaAhorro->setSaldo(5000.0);
    cuentaCredito->setSaldo(10000.0);

    cliente1.agregarCuenta(cuentaAhorro);
    cliente1.agregarCuenta(cuentaCredito);

    // Registrar cliente
    repositorio->registrarCliente(cliente1);

    // Obtener estado de cuenta
    std::cout << repositorio->generarEstadoCuenta("12345") << std::endl;

    /// REPOSITORIO 2
    auto repositorio2 = RepositorioCuentas::obtenerInstancia();

    // Crear cliente
    Cliente cliente2("John Doe", "12346");
    
    // Crear cuentas
    auto cuentaJoven = std::make_shared<CuentaJoven>("001-JOVEN");
    auto cuentaPluss = std::make_shared<CuentaPluss>("002-PLUSS");
    
    cuentaJoven->setSaldo(3000.0);
    cuentaPluss->setSaldo(1800.0);

    cliente2.agregarCuenta(cuentaJoven);
    cliente2.agregarCuenta(cuentaPluss);

    // Registrar cliente
    repositorio->registrarCliente(cliente2);

    // Obtener estado de cuenta
    std::cout << repositorio->generarEstadoCuenta("12346") << std::endl;

    return 0;
}
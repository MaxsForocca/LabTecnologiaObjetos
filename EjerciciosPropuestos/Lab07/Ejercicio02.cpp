// Ejercicio 02

#include <QDebug>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// tipos de cuenta
#define AHORROS "CUENTA_DE_AHORROS"
#define JOVEN "CUENTA_JOVEN"
#define PLUSS "CUENTA_PLUSS"
#define EMPRESARIAL "CUENTA_EMPRESARIAL"
#define CREDITO "CUENTA_TARJETA_CREDITO"
// tipos de moneda
#define SOL "SOLES"
#define DOLAR "DOLARES"
// estados de cuenta
#define ACT "ACTIVO"
#define INA "INACTIVO"
#define CER "CERRADO"
#define BLO "BLOQUEADO"
#define SUS "SUSPENDIDO"

// Polimorfismo
class CuentaBancaria {
private:
    int numeroCuenta;
    std::string moneda = SOL;
    float saldo = 0.0;
    std::string estado = ACT;
public:
    CuentaBancaria(int numero): numeroCuenta(numero){}
    CuentaBancaria(int numero, float saldo): numeroCuenta(numero), saldo(saldo){}
    CuentaBancaria(int numero, float saldo, std::string money): numeroCuenta(numero), saldo(saldo), moneda(money) {}
    virtual ~CuentaBancaria() = default;

    int obtenerNumeroCuenta() const {
        return numeroCuenta;
    }

    float obtenerSaldo() const {
        return saldo;
    }
    std::string obtenerMoneda() const {
        return moneda;
    }
    std::string obtenerEstado() const {
        return estado;
    }
    float calcularInteres(float monto, float interes) const {
        return monto * interes;
    }

    virtual float interesPrestamosPersonales(float monto) = 0;
    virtual float interesTransferenciasNacionales(float monto) = 0;
    virtual float interesCompras(float monto) = 0;
    virtual std::string obtenerTipo() const { return ""; }

    void mostrarEstadoCuenta() const {
        qDebug() << "Estado: " << QString::fromStdString(estado);
    }

    void liquidar() {
        if (estado == CER) {
            qDebug() << "La cuenta ya está cerrada.";
            return;
        }

        qDebug() << "Liquidando la cuenta. Se devolverá el saldo restante: " << saldo << " " << QString::fromStdString(moneda);
        saldo = 0;
        estado = CER;
        qDebug() << "La cuenta ha sido liquidada.";
    }

    void adelantar(float monto) {
        if (monto <= 0) {
            throw std::invalid_argument("El monto a adelantar debe ser positivo.");
        }
        if (estado != ACT || monto > saldo) {
            qDebug() << "No se puede adelantar dinero";
            return;
        }
        saldo -= monto;
        qDebug() << "Se ha adelantado: " << monto << ". Nuevo saldo: " << saldo << " " << QString::fromStdString(moneda);
    }
};

class CuentaAhorro : public CuentaBancaria {
public:
    using CuentaBancaria::CuentaBancaria;
    std::string obtenerTipo() const override {
        return AHORROS;
    }

    float interesPrestamosPersonales(float monto) override {
        return calcularInteres(monto, 0.0855);
    }

    float interesTransferenciasNacionales(float monto) override {
        return (this->obtenerMoneda() == SOL) ? calcularInteres(monto, 0.005) : calcularInteres(monto, 0.0021);
    }

    float interesCompras(float monto) override {
        return calcularInteres(monto, 0.15);
    }
};

// Cuenta JOVEN
class CuentaJoven : public CuentaBancaria {
public:
    using CuentaBancaria::CuentaBancaria;

    std::string obtenerTipo() const override {
        return JOVEN;
    }

    float interesPrestamosPersonales(float monto) override {
        return calcularInteres(monto, 0.095);
    }

    float interesTransferenciasNacionales(float monto) override {
        return (this->obtenerMoneda() == SOL) ? calcularInteres(monto, 0.012) : calcularInteres(monto, 0.0025);
    }

    float interesCompras(float monto) override {
        return calcularInteres(monto, 0.17);
    }
};

// Cuenta PLUSS
class CuentaPluss: public CuentaBancaria {
public:
    using CuentaBancaria::CuentaBancaria;
    std::string obtenerTipo() const override {
        return PLUSS;
    }
    float interesPrestamosPersonales(float monto) override {
        // Para pluss = interes 10% o 0.1
        return calcularInteres(monto, 0.1);
    }
    float interesTransferenciasNacionales(float monto) override{
        // Para pluss: Soles - 1.7% o 0.017; Dolares - 0.27% o 0.0027
        return (this->obtenerTipo().compare(SOL) == 0)?
                   calcularInteres(monto, 0.017): calcularInteres(monto, 0.0027);
    }
    float interesCompras(float monto) override {
        //  Para pluss: interes 20% - 0.2
        return calcularInteres(monto, 0.2);
    }
};

// Cuenta EMPRESARIAL
class CuentaEmpresarial: public CuentaBancaria {
public:
    using CuentaBancaria::CuentaBancaria;
    std::string obtenerTipo() const override {
        return EMPRESARIAL;
    }
    float interesPrestamosPersonales(float monto) override {
        // Para empresarial = interes 10.5% o 0.105
        return calcularInteres(monto, 0.105);
    }
    float interesTransferenciasNacionales(float monto) override{
        // Para empresarial: Soles - 2.5% o 0.025; Dolares - 0.32% o 0.0032
        return (this->obtenerTipo().compare(SOL) == 0)?
                   calcularInteres(monto, 0.025): calcularInteres(monto, 0.0032);
    }
    float interesCompras(float monto) override {
        //  Para empresarial: interes 22.5% - 0.225
        return calcularInteres(monto, 0.225);
    }
};

// Cuenta Tarjeta credito
class CuentaTarjetaCredito: public CuentaBancaria {
public:
    using CuentaBancaria::CuentaBancaria;
    std::string obtenerTipo() const override {
        return CREDITO;
    }
    float interesPrestamosPersonales(float monto) override {
        // Para credito = interes 11.25% o 0.1125
        return calcularInteres(monto, 0.1125);
    }
    float interesTransferenciasNacionales(float monto) override{
        // Para empresarial: Soles - 4% o 0.04; Dolares - 0.35% o 0.0035
        return (this->obtenerTipo().compare(SOL) == 0)?
                   calcularInteres(monto, 0.04): calcularInteres(monto, 0.0035);
    }
    float interesCompras(float monto) override {
        //  Para empresarial: interes 25% - 0.25
        return calcularInteres(monto, 0.25);
    }
};


// Función para buscar una cuenta por número
std::shared_ptr<CuentaBancaria> buscarPorNumeroCuenta(const std::vector<std::shared_ptr<CuentaBancaria>>& cuentas, int numero) {
    auto it = std::find_if(cuentas.begin(), cuentas.end(),
                           [numero](const std::shared_ptr<CuentaBancaria>& cuenta) {
                               return cuenta->obtenerNumeroCuenta() == numero;
                           });

    return (it != cuentas.end()) ? *it : nullptr;
}

class Cliente {
private:
    std::string nombre;
    std::vector<std::shared_ptr<CuentaBancaria>> misCuentas;

public:
    Cliente(std::string nombre): nombre(nombre) {}
    void agregarCuenta(std::shared_ptr<CuentaBancaria> cuenta_ptr){
        misCuentas.push_back(cuenta_ptr);
    }

    void solicitarEstadoCuentaTipo(const std::string& tipo) const {
        qDebug() << "|||||| ----- CUENTAS "<< tipo << "--+-- " << nombre << "||||||";
        for (const auto& cuenta : misCuentas) {
            if (cuenta->obtenerTipo() == tipo) {
                qDebug() << "|--- CUENTA ---|";
                qDebug() << "Numero de Cuenta: " << cuenta->obtenerNumeroCuenta();
                qDebug() << "Tipo Cuenta: " << QString::fromStdString(cuenta->obtenerTipo());
                qDebug() << "Saldo: " << cuenta->obtenerSaldo();
            }
        }
    }

    void solicitarEstadoCuentaGlobal() const {
        qDebug() << "|||||| ----- CUENTAS --+-- " << nombre << "||||||";
        for (const auto& cuenta : misCuentas) {
            qDebug() << "|--- CUENTA ---|";
            qDebug() << "Numero de Cuenta: " << cuenta->obtenerNumeroCuenta();
            qDebug() << "Tipo Cuenta: " << QString::fromStdString(cuenta->obtenerTipo());
            qDebug() << "Saldo: " << cuenta->obtenerSaldo();
        }
    }

    void mancomunarCuenta(int numeroCuenta, Cliente& cliente) {
        auto cuenta = buscarPorNumeroCuenta(misCuentas, numeroCuenta);
        if (cuenta) {
            cliente.agregarCuenta(cuenta);
        } else {
            qDebug() << "No se encontró la cuenta";
        }
    }
};
/*
int main() {
    Cliente cliente1("Cliente1");
    Cliente cliente2("Cliente2");
    auto cuenta1 = std::make_shared<CuentaAhorro>(1, 1000, SOL);
    auto cuenta2 = std::make_shared<CuentaJoven>(2, 2000, SOL);
    auto cuenta3 = std::make_shared<CuentaPluss>(3, 3000, SOL);
    auto cuenta4 = std::make_shared<CuentaEmpresarial>(4, 4000, SOL);
    auto cuenta5 = std::make_shared<CuentaTarjetaCredito>(5, 5000, SOL);
    auto cuenta6 = std::make_shared<CuentaAhorro>(7, 6000, SOL);

    cliente1.agregarCuenta(cuenta1);
    cliente1.agregarCuenta(cuenta2);
    cliente1.agregarCuenta(cuenta3);
    cliente1.agregarCuenta(cuenta4);
    cliente1.agregarCuenta(cuenta5);
    cliente1.solicitarEstadoCuentaGlobal();
    // cliente 2
    cliente2.agregarCuenta(cuenta6);
    // mancomunar
    cliente1.mancomunarCuenta(1, cliente2);
    cliente2.solicitarEstadoCuentaTipo(AHORROS);
    return 0;
}
*/

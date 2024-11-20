#include <QDebug>
#include <QTextStream>
#include <vector>
#include <string>

std::vector<std::string> modelos = {"TOYOTA COROLLA", "FORD MUSTANG", "HONDA CIVIC"};
std::vector<std::string> motorizacion = {"MOTOR 1.5L", "MOTOR 2.0 TURBO", "MOTOR ELECTRICO"};
std::vector<std::string> colores = {"NEGRO", "BLANCO", "AZUL", "AZUL METALIZADO", "ROJO", "PLATEADO"};
std::vector<std::string> pais_fabricacion = {"JAPON", "ESTADOS UNIDOS", "ALEMANIA", "CHINA"};
std::vector<std::string> precios = {"MENOS DE $20000", "ENTRE $20000 Y $35000", "MAS DE $35000"};
std::vector<std::string> accesorios_adicionales = {"ASIENTOS DE CUERO", "SISTEMA DE SONIDO PREMIUM", "RINES DE ALEACION"};

void mostrarVector(const std::vector<std::string>& vect) {
    for (size_t i = 0; i < vect.size(); i++) {
        qDebug() << i << ". " << vect[i].c_str();
    }
}

class ComponenteAuto {
private:
    std::string color;
    float precio;
public:
    virtual ~ComponenteAuto() = default;
    ComponenteAuto(float precio, std::string color): precio(precio), color(color) {}
    ComponenteAuto(): precio(2000), color(colores[0]){}
    std::string GetColor() { return color; }
    void SetColor(std::string color) { this->color = color; }
    float GetPrecio() { return precio; }

    virtual std::string GetNombre() const = 0;
    virtual std::string GetDescripcion() = 0;
};

class Puerta : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "PUERTA"; }
    std::string GetDescripcion() override { return "Puerta color " + this->GetColor(); }
};

class Llanta : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "LLANTA"; }
    std::string GetDescripcion() override { return "Llanta estandar de color " + this->GetColor(); }
};

class Timon : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "TIMON"; }
    std::string GetDescripcion() override { return "Timon estandar de color " + this->GetColor(); }
};

class Motor : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "MOTOR"; }
    std::string GetDescripcion() override { return "Motor color " + this->GetColor(); }
};

class Asiento : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "ASIENTO"; }
    std::string GetDescripcion() override { return "Asiento estandar de color " + this->GetColor(); }
};

class Espejo : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "ESPEJO"; }
    std::string GetDescripcion() override { return "Espejo de color " + this->GetColor(); }
};

class Vidrio : public ComponenteAuto {
public:
    using ComponenteAuto::ComponenteAuto;
    std::string GetNombre() const override { return "VIDRIO"; }
    std::string GetDescripcion() override { return "Vidrio de color " + this->GetColor(); }
};

class Auto {
private:
    std::vector<ComponenteAuto*> componentes;
    std::string modelo;
    std::string motor;
    std::string precio;
    std::vector<std::string> accesorios;
public:
    ~Auto() {
        for (auto comp : componentes) delete comp;
    }

    void SetModelo(std::string m) { modelo = m; }
    void SetMotor(std::string m) { motor = m; }
    void SetPrecio(std::string p) { precio = p; }
    void AddAccesorio(std::string accesorio) { accesorios.push_back(accesorio); }

    std::vector<ComponenteAuto*>& getComponentes() { return componentes; }
    void AddComponent(ComponenteAuto* comp) { componentes.push_back(comp); }

    float GetCost() {
        float cost = 0.0;
        for (auto comp : componentes) {
            cost += comp->GetPrecio();
        }
        return cost;
    }

    void GetConfiguration() {
        qDebug() << "Modelo:" << modelo.c_str();
        qDebug() << "Motorización:" << motor.c_str();
        qDebug() << "Precio:" << precio.c_str();
        qDebug() << "Accesorios adicionales:";
        for (const auto& acc : accesorios) {
            qDebug() << " - " << acc.c_str();
        }
        qDebug() << "Componentes:";
        for (auto comp : componentes) {
            qDebug() << comp->GetNombre().c_str() << ": " << comp->GetDescripcion().c_str();
        }
    }
};

class AutoBuilder {
public:
    Auto* opcionPersonalizada() {
        Auto* aut = new Auto();
        QTextStream qtin(stdin);
        int opcion = 0;

        // Seleccionar Modelo
        while (true) {
            qDebug() << "Seleccione un modelo:";
            mostrarVector(modelos);
            qtin >> opcion;
            if (opcion >= 0 && opcion < modelos.size()) {
                aut->SetModelo(modelos[opcion]);
                break;
            }
        }

        // Agregar componentes
        aut->AddComponent(new Puerta(2500, colores[0]));
        aut->AddComponent(new Llanta(1500, colores[0]));
        aut->AddComponent(new Timon(1000, colores[0]));
        aut->AddComponent(new Motor(8000, colores[0]));
        aut->AddComponent(new Asiento(3000, colores[0]));
        aut->AddComponent(new Espejo(1000, colores[0]));
        aut->AddComponent(new Vidrio(1000, colores[0]));
        auto& comp = aut->getComponentes();

        // Seleccionar color para cada componente
        for (auto& c : comp) {
            qDebug() << "Elige color para:" << c->GetNombre().c_str();
            do {
                mostrarVector(colores);
                qDebug().noquote() << "Opción: ";
                qtin >> opcion;
            } while (opcion < 0 || opcion >= colores.size());
            c->SetColor(colores[opcion]);
        }
        return aut;
    }
};

int main() {
    AutoBuilder ab;
    Auto* auto1 = ab.opcionPersonalizada();
    auto1->GetConfiguration();
    qDebug() << "Costos: " << auto1->GetCost();
    delete auto1;
    return 0;
}

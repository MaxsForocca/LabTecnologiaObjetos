#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

// Enumeracion de Sectores
enum class SectorVivero {
    TREPADORAS,
    ARBOLES_NORMALES,
    ORNAMENTALES,
    BONSAIS
};

// Clase base Abstracta para Plantas (Prototype)
class Planta {
protected:
    std::string nombre;
    std::string nombreCientifico;
    double altura;
    SectorVivero sector;
    std::string caracteristicasEspeciales;

public:
    Planta() = default;
    virtual ~Planta() = default;

    // Metodo clonar virtual puro (metodo Prototype)
    virtual std::unique_ptr<Planta> clonar() const = 0;

    // Setters y Getters
    void setNombre(const std::string& n) { nombre = n; }
    std::string getNombre() const { return nombre; }

    void setNombreCientifico(const std::string& nc) { nombreCientifico = nc; }
    std::string getNombreCientifico() const { return nombreCientifico; }

    void setAltura(double alt) { altura = alt; }
    double getAltura() const { return altura; }

    void setSector(SectorVivero s) { sector = s; }
    SectorVivero getSector() const { return sector; }

    void setCaracteristicasEspeciales(const std::string& car) { caracteristicasEspeciales = car; }
    std::string getCaracteristicasEspeciales() const { return caracteristicasEspeciales; }

    // Metodo para imprimir detalles
    virtual void mostrarDetalles() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Nombre Cientifico: " << nombreCientifico << std::endl;
        std::cout << "Altura: " << altura << " m" << std::endl;
        std::cout << "Sector: " << static_cast<int>(sector) << std::endl;
        std::cout << "Caracteristicas: " << caracteristicasEspeciales << std::endl;
    }
};

// Implementaciones Concretas de Plantas
class Trepadora : public Planta {
public:
    Trepadora() { sector = SectorVivero::TREPADORAS; }

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<Trepadora>(*this);
    }
};

class ArbolNormal : public Planta {
public:
    ArbolNormal() { sector = SectorVivero::ARBOLES_NORMALES; }

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<ArbolNormal>(*this);
    }
};

class Ornamental : public Planta {
public:
    Ornamental() { sector = SectorVivero::ORNAMENTALES; }

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<Ornamental>(*this);
    }
};

class Bonsai : public Planta {
public:
    Bonsai() { sector = SectorVivero::BONSAIS; }

    std::unique_ptr<Planta> clonar() const override {
        return std::make_unique<Bonsai>(*this);
    }
};

// Fabrica de Prototipos (Gestor de Plantas)
class ViveroPrototipo {
private:
    std::unordered_map<std::string, std::unique_ptr<Planta>> prototipos;

public:
    // Registrar prototipos
    void registrarPrototipo(const std::string& key, std::unique_ptr<Planta> prototipo) {
        prototipos[key] = std::move(prototipo);
    }

    // Clonar planta desde un prototipo
    std::unique_ptr<Planta> clonarPlanta(const std::string& key) {
        auto it = prototipos.find(key);
        if (it != prototipos.end()) {
            return it->second->clonar();
        }
        return nullptr;
    }
};

int main() {
    // Crear fabrica de prototipos
    ViveroPrototipo vivero;

    // Crear y registrar prototipos
    auto trepadoraBase = std::make_unique<Trepadora>();
    trepadoraBase->setNombre("Hiedra Comun");
    trepadoraBase->setNombreCientifico("Hedera helix");
    trepadoraBase->setAltura(5.0);
    trepadoraBase->setCaracteristicasEspeciales("Rapido crecimiento, se adhiere a superficies");
    vivero.registrarPrototipo("trepadora_base", std::move(trepadoraBase));

    auto arbolBase = std::make_unique<ArbolNormal>();
    arbolBase->setNombre("Roble");
    arbolBase->setNombreCientifico("Quercus");
    arbolBase->setAltura(15.0);
    arbolBase->setCaracteristicasEspeciales("Madera dura, longevidad");
    vivero.registrarPrototipo("arbol_base", std::move(arbolBase));

    auto ornamentalBase = std::make_unique<Ornamental>();
    ornamentalBase->setNombre("Rosa");
    ornamentalBase->setNombreCientifico("Rosa sp.");
    ornamentalBase->setAltura(1.2);
    ornamentalBase->setCaracteristicasEspeciales("Flores coloridas, multiples variedades");
    vivero.registrarPrototipo("ornamental_base", std::move(ornamentalBase));

    auto bonsaiBase = std::make_unique<Bonsai>();
    bonsaiBase->setNombre("Pino Japones");
    bonsaiBase->setNombreCientifico("Pinus thunbergiana");
    bonsaiBase->setAltura(0.5);
    bonsaiBase->setCaracteristicasEspeciales("Miniatura, tecnica de poda especial");
    vivero.registrarPrototipo("bonsai_base", std::move(bonsaiBase));

    // Clonar plantas desde prototipos
    auto nuevaTrepadora = vivero.clonarPlanta("trepadora_base");
    auto nuevoArbol = vivero.clonarPlanta("arbol_base");
    
    if (nuevaTrepadora) {
        std::cout << "Detalles Nueva Trepadora:" << std::endl;
        nuevaTrepadora->mostrarDetalles();
    }

    if (nuevoArbol) {
        std::cout << "\nDetalles Nuevo arbol:" << std::endl;
        nuevoArbol->mostrarDetalles();
    }

    return 0;
}
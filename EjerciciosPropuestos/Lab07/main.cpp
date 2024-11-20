// Ejercicio a/1

#include <QCoreApplication>
#include <QDebug>
class item{
public:
    virtual std::string GetName() {return "";}
    virtual float GetPrice() {return 0.0;}
    virtual void getConfiguration(){};
};

class Processor : public item{
    virtual std::string GetName() {return "";}
    virtual float GetPrice() {return 0.0;}
    virtual void getConfiguration(){};
};

class IntelI5 : public Processor{
    std::string GetName() {
        return "Intel I5";
    }
    float GetPrice() {
        return 3000.0;
    }
    void getConfiguration(){
        qDebug() << "1.50 Ghz, up to 2.0 Ghz with turbo, 2 cores, 4 threads, 8 MB cache, RAM 4GB - 8GB";
    }
};

class IntelI7 : public Processor{
    std::string GetName() {
        return "Intel I7";
    }
    float GetPrice() {
        return 4700.0;
    }
    void getConfiguration(){
        qDebug() << "1.6 Ghz, up to 1.99, 9na Gen, 4 cores, 8 threads, 16 MB cache, RAM 16GB";
    }
};

class Drive : public item{
    virtual std::string GetName() {return "";}
    virtual float GetPrice() {return 0.0;}
    virtual void getConfiguration(){};
};

class HDD : public Drive{
    std::string GetName() {
        return "Hard disk drive: ";
    }
    float GetPrice() {
        return 150.0;
    }
    void getConfiguration(){
        qDebug() << "capacity: 1 TB, data  transfer 1050 mbits/s";
    }
};

class SDD : public Drive{
    std::string GetName() {
        return "Solid state drive: ";
    }
    float GetPrice() {
        return 195.0;
    }
    void getConfiguration(){
        qDebug() << "capacity: 250 TB, data  transfer 1800 mbits/s";
    }
};

class DisplayType : public item{
    virtual std::string GetName() {return "";}
    virtual float GetPrice() {return 0.0;}
    virtual void getConfiguration(){};
};

class Normal : public DisplayType{
    std::string GetName() {
        return "Non-touch screen: ";
    }
    float GetPrice() {
        return 195.0;
    }
    void getConfiguration(){
        qDebug() << "15.6 inch FHD(1920 x 1080), plane, ... etc";
    }
};

// Nuevas caracteristicas con item
class Color: public item{
public:
    std::string GetName() override {return "Color: ";}
    float GetPrice() override {return 5.0;}
    void getConfiguration() override {
        qDebug() << "Negro con enchapado dorado";
    };
};

class Marca: public item{
public:
    std::string GetName() override{return "Marca";}
    float GetPrice() override {return 200.0;}
    void getConfiguration() override {
        qDebug() << "Lenovo IdeaPad 5";
    };
};

class Impresora: public item{
public:
    std::string GetName() override {return "Impresora: ";}
    float GetPrice() override {return 200.0;}
    void getConfiguration() override {
        qDebug() << "MiniImpresora Termica portatil recargable 1000mAh";
    };
};

// Nuevos Componentes
/*
// Processor ya existe
class CPU: public item{
public:
    virtual std::string GetName() {return "";}
    virtual float GetPrice() {return 0.0;}
    virtual void getConfiguration(){};
};
*/
// Caracteristicas Color - Marca
/*
class Color {
private:
    std::string color;
public:
    Color(): color("Negro") {}
    Color(std::string newColor): color(newColor){}
};
class Marca {
private:
    std::string marca;
public:
    Marca(): marca("Lenovo"){}
    Marca(std::string newMarca): marca(newMarca){}
};
*/
// Nuevo Monitor
class MonitorPlasma: public DisplayType {
    std::string GetName() {
        return "Monitor Plasma: ";
    }
    float GetPrice() {
        return 250.0;
    }
    void getConfiguration(){
        qDebug() << "Plasma Monitor 17 inch FHD(1920 x 1080), resolution 4K, ... etc";
    }
};

class laptop{
public:
    void AddParts(item *item) {
        mLaptopParts.push_back(item);
    }
    float GetCost(){
        float cost = 0.0;
        for (auto item : mLaptopParts){
            cost += item->GetPrice();
        }
        return cost;
    }
    void GetConfiguration(){
        for (auto i =0; i < mLaptopParts.size(); i++){
            qDebug() << mLaptopParts[i]->GetName() << ":"; mLaptopParts[i]->getConfiguration();
        }
    }
private:
    std::vector<item *> mLaptopParts;
};

class LaptopBuilder {
public:
    laptop *opcion1(){
        laptop *lap = new laptop();
        lap->AddParts(new IntelI5());
        lap->AddParts(new Normal());
        lap->AddParts(new HDD());
        return lap;
    }
    laptop *opcion2(){
        laptop *lap = new laptop();
        lap->AddParts(new Marca());
        lap->AddParts(new Color());
        lap->AddParts(new IntelI7());
        lap->AddParts(new MonitorPlasma());
        lap->AddParts(new SDD());
        return lap;
    }
};
/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LaptopBuilder cotizar;
    qDebug() << "Laptop";

    laptop *lenovo = cotizar.opcion2();
    lenovo->GetConfiguration();
    qDebug() << "precio: " << lenovo->GetCost();
    return 0;
}
*/

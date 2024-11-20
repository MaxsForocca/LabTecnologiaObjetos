// Ejercicio 02
#include <qDebug>

class IBuilder{
public:
    virtual ~IBuilder(){}
    virtual void ProducirParteA() const = 0;
    virtual void ProducirParteB() const = 0;
    virtual void ProducirParteC() const = 0;
};

class Producto1{
public:
    std::vector<std::string> componentes;
    void ListaComp() const {
        qDebug() << "Componentes: ";
        for(size_t i =0; i<componentes.size(); i++){
            if (componentes[i] == componentes.back()){
                qDebug() << componentes[i];
            } else{
                qDebug().noquote()<< componentes[i] << ", ";
            }
        }
    }
};

class BuilderEspecifico:public IBuilder{
private:
    Producto1* producto;
public:
    BuilderEspecifico(){
        this->Reset();
    }
    ~BuilderEspecifico(){
        delete producto;
    }
    void Reset(){
        this->producto = new Producto1();
    }
    void ProducirParteA() const override {
        this->producto->componentes.push_back("ParteA1");
    }
    void ProducirParteB() const override {
        this->producto->componentes.push_back("ParteB1");
    }
    void ProducirParteC() const override {
        this->producto->componentes.push_back("ParteC1");
    }
    Producto1* GetProducto(){
        Producto1* resultado = this->producto;
        this->Reset();
        return resultado;
    }
};

class Director{
private:
    IBuilder *builder;
public:
    void set_builder(IBuilder *builder){
        this->builder = builder;
    }
    void BuildProductoMin(){
        this->builder->ProducirParteA();
    }
    void BuildProductoCompleto(){
        this->builder->ProducirParteA();
        this->builder->ProducirParteB();
        this->builder->ProducirParteC();
    }
};

void ClienteCode(Director& director){
    BuilderEspecifico *builder = new BuilderEspecifico();
    director.set_builder(builder);
    qDebug() << "Producto Basico: ";
    director.BuildProductoMin();

    Producto1* p = builder->GetProducto();
    p->ListaComp();
    delete p;

    qDebug() << "Producto Completo: ";
    director.BuildProductoCompleto();

    p = builder->GetProducto();
    p->ListaComp();
    delete p;

    qDebug() << "Producto Basico";
    builder->ProducirParteA();
    builder->ProducirParteC();

    p = builder->GetProducto();
    p->ListaComp();
    delete p;
    delete builder;
};

int main(){
    Director *director = new Director();
    ClienteCode(*director);
    delete director;
    return 0;
}

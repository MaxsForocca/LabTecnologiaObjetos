#include <iostream>
using namespace std;

// Herencia en C++
class infante{
private:
    string nombre;
public:
    infante(const string &nom){
        nombre = nom;
    }
    void gatear(){
        cout<<nombre<< " gateando ...\n";
    }
};

class joven{
private:
    string nombre;
public:
    joven(const string &nom){
        nombre = nom;
    }
    void correr(){
        cout<<nombre<< " corriendo ...\n";
    }
};

class adulto: public infante, public joven{
private:
    string nombre;
public:
    adulto(const string &nom): infante(nom), joven(nom), nombre(nom){};
    void caminar(){
        cout << nombre << " caminando ...\n";
    }
};

// Polimorfismo en C++
class Mamifero {
public:
    Mamifero() : edad() { cout << "mamifero constructor...\n";}
    //Mamifero() { cout << "mamifero constructor...\n"; }
    ~Mamifero() { cout << "mamifero destructor...\n"; }
    void Move() const { cout << "mamifero move one step\n"; }
    virtual void Speak() const { cout << "mamifero speak!\n"; }

protected:
    int edad;
};

class Dog : public Mamifero {
public:
    Dog() { cout << "Dog Constructor...\n"; }
    ~Dog() { cout << "Dog destructor...\n"; }
    void WagTail() { cout << "Wagging Tail...\n"; }
    void Speak()const { cout << "Woof!\n"; }
    void Move() const { cout << "Dog moves 5 steps...\n"; }
};

/*
int main(){
    // Para herencia
    infante inf1 = infante("Infante 1");
    joven jov1 = joven("Joven 1");
    adulto adu1 = adulto("Adulto 1");
    // Para polimorfismo
    Mamifero mamifero = Mamifero();
    Dog dog = Dog();
    // Ejemplos
    cout << "Ejemplos usando herencia" << endl;
    inf1.gatear();
    jov1.correr();
    adu1.caminar();
    adu1.gatear();
    adu1.correr();
    cout << "Ejemplos usando polimorfismo" << endl;
    mamifero.Move();
    mamifero.Speak();
    dog.Move();
    dog.Speak();
    dog.WagTail();
    return 0;
}
*/

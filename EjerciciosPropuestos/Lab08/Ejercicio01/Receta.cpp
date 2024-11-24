// Receta.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Receta {
    protected:
    string name;
    string caracteristicas;
    string lugar;
    vector<string> ingredientes;
    vector<string> pasos;
    public:
    virtual void alistarReceta() = 0;
    virtual void prepareIngredientes() = 0;
    virtual void prepareReceta() = 0;
    virtual void showReceta() = 0;
};

class Receta1 : public Receta{
public:
    void alistarReceta() {
        cout << "Alistando Receta 1" << endl;

        name = "Receta 1: Tacos al Pastor";
        caracteristicas = "Tacos con carne de cerdo marinada, típicamente servidos con piña, cebolla y cilantro.";
        lugar = "Mexico";
    }
    void prepareIngredientes() {
        cout << "Preparando igredientes de  Receta 1" << endl;
        
        ingredientes.push_back("500 g de carne de cerdo (pierna o lomo)");
        ingredientes.push_back("100 g de achiote");
        ingredientes.push_back("2 naranjas (su jugo)");
        ingredientes.push_back("1 piña (en rodajas)");
        ingredientes.push_back("4 tortillas de maíz");
        ingredientes.push_back("Cebolla picada al gusto");
        ingredientes.push_back("Cilantro fresco picado al gusto");
        ingredientes.push_back("Sal al gusto");
    }
    void prepareReceta() {
        cout << "Preparando Receta 1" << endl;
        
        pasos.push_back("Marinar la carne: Mezcla el achiote con el jugo de naranja y marina la carne durante al menos 2 horas.");
        pasos.push_back("Cocinar la carne: Asa la carne en un sartén caliente hasta que esté bien cocida y dorada.");
        pasos.push_back("Preparar los tacos: Calienta las tortillas en el comal, coloca la carne, añade piña, cebolla y cilantro.");
        pasos.push_back("Servir: Disfruta los tacos calientes.");
    }
    void showReceta() {
        cout << "- Nombre: " << name << endl
        << "- Caracteristicas: "<< caracteristicas << endl
        << "- Lugar: " << lugar << endl
        << "- Ingredientes: " << endl;

        for (auto i : ingredientes) {
            cout << "*" << i << endl;
        }

        cout << "- Pasos: " << endl;
        for (auto p : pasos) {
            cout << "*" << p << endl;
        }
    }
};

class Receta2 : public Receta {
public:
    void alistarReceta() {
        cout << "Alistando Receta 2" << endl;
        name = "Receta 2: Paella Valenciana";
        caracteristicas = "Plato tradicional español, rico en sabor y con una mezcla de mariscos y carne.";
        lugar = "España";
    }
    
    void prepareIngredientes() {
        cout << "Preparando igredientes de  Receta 2" << endl;
        ingredientes.push_back("400 g de arroz");
        ingredientes.push_back("800 ml de caldo de pollo");
        ingredientes.push_back("200 g de pollo (en trozos)");
        ingredientes.push_back("200 g de conejo (en trozos)");
        ingredientes.push_back("100 g de judías verdes");
        ingredientes.push_back("1 pimiento rojo (en tiras)");
        ingredientes.push_back("2 tomates (picados)");
        ingredientes.push_back("Azafrán al gusto");
        ingredientes.push_back("Aceite de oliva");
        ingredientes.push_back("Sal al gusto");
    }
    
    void prepareReceta() {
        cout << "Preparando Receta 2" << endl;
        pasos.push_back("Sellar la carne: En una paellera, calienta el aceite y sella el pollo y conejo hasta dorar.");
        pasos.push_back("Añadir verduras: Agrega las judías verdes y los tomates, cocina por unos minutos.");
        pasos.push_back("Incorporar el arroz: Añade el arroz y mezcla bien con los ingredientes.");
        pasos.push_back("Agregar caldo: Vierte el caldo caliente junto con el azafrán; cocina a fuego medio hasta que el arroz absorba el líquido.");
        pasos.push_back("Servir: Deja reposar unos minutos antes de servir.");
    }
    
    void showReceta() {
        cout << "- Nombre: " << name << endl
             << "- Caracteristicas: " << caracteristicas << endl
             << "- Lugar: " << lugar << endl
             << "- Ingredientes: " << endl;

        for (auto i : ingredientes) {
            cout << "*" << i << endl;
        }

        cout << "- Pasos: " << endl;
        for (auto p : pasos) {
            cout << "*" << p << endl;
        }
    };
};

class Receta3 : public Receta {
public:
    void alistarReceta() {
        cout << "Alistando Receta 3" << endl;
        name = "Receta 3: Arroz con Leche";
        caracteristicas = "Postre cremoso a base de arroz, leche y azúcar, aromatizado con canela.";
        lugar = "América Latina";
    }
    
    void prepareIngredientes() {
        cout << "Preparando igredientes de  Receta 3" << endl;
        ingredientes.push_back("1 taza de arroz de grano redondo");
        ingredientes.push_back("4 tazas de leche");
        ingredientes.push_back("250 g de azúcar");
        ingredientes.push_back("1 lata grande de leche condensada");
        ingredientes.push_back("Canela en polvo al gusto");
        ingredientes.push_back("Piel de limón (opcional)");
    }
    
    void prepareReceta() {
        cout << "Preparando Receta 3" << endl;
        pasos.push_back("Cocinar el arroz: En una olla, cocina el arroz cubierto con agua a fuego lento hasta que se consuma el agua.");
        pasos.push_back("Agregar leche: Incorpora la leche caliente y la piel del limón; cocina a fuego lento durante 25 minutos, removiendo frecuentemente.");
        pasos.push_back("Añadir azúcar: Mezcla el azúcar y retira del fuego; añade la leche condensada.");
        pasos.push_back("Servir frío: Retira la piel del limón, enfría y espolvorea canela antes de servir.");
    }
    
    void showReceta() {
        cout << "- Nombre: " << name << endl
             << "- Caracteristicas: " << caracteristicas << endl
             << "- Lugar: " << lugar << endl
             << "- Ingredientes: " << endl;

        for (auto i : ingredientes) {
            cout << "*" << i << endl;
        }

        cout << "- Pasos: " << endl;
        for (auto p : pasos) {
            cout << "*" << p << endl;
        }
    };
};
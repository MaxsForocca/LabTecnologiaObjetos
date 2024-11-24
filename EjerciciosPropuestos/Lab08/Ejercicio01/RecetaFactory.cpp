#include <iostream>
#include "Receta.cpp"

using namespace std;

class RecetaFactory {
public:
    static Receta *createReceta(int type) {
        Receta *receta = NULL;

        switch (type)
        {
        case 1:
            receta = new Receta1;
            break;
        case 2:
            receta = new Receta2;
            break;
        case 3:
            receta = new Receta3;
            break;
        default:
            cout << "Invalido RECETA type, ingresa otra opcion" << endl;
            return NULL;
        }
        receta->alistarReceta();
        receta->prepareIngredientes();
        receta->prepareReceta();

        return receta;
    }
};
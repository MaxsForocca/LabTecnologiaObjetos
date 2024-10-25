#include <iostream>
#include "ExpressionTree.h"

int main() {
    std::string expression = "54 + 5 * 34 + 1 * 2"; // Expresion en notacion infija

    ExpressionTree tree(expression);
    std::cout << "El resultado de la expresion es: " << tree.evaluate() << std::endl;

    return 0;
}

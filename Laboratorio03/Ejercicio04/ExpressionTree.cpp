#include "ExpressionTree.h"
#include <sstream>
#include <algorithm>

// Convertir la expresion infija a postfija usando la notacion RPN
std::vector<std::string> ExpressionTree::infixToPostfix(const std::string& expression) {
    std::stack<char> operators;
    std::vector<std::string> output;
    std::istringstream stream(expression);
    std::string token;

    while (stream >> token) {
        // Si el token es un número, lo añadimos a la salida
        if (isdigit(token[0])) {
            output.push_back(token);
        } 
        // Si el token es un operador
        else if (token == "+" || token == "*") {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0])) {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(token[0]);
        }
    }

    // Añadir los operadores restantes a la salida
    while (!operators.empty()) {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }

    return output;
}

// Determinar la precedencia de los operadores
int ExpressionTree::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::unique_ptr<Node> ExpressionTree::buildTree(const std::string& expression) {
    auto postfix = infixToPostfix(expression);
    std::stack<std::unique_ptr<Node>> nodes;

    for (const auto& tok : postfix) {
        if (isdigit(tok[0])) { // Si el token es un número
            nodes.push(std::make_unique<NumberNode>(std::stod(tok)));
        } else { // Si el token es un operador
            auto right = std::move(nodes.top()); nodes.pop();
            auto left = std::move(nodes.top()); nodes.pop();
            nodes.push(std::make_unique<OperatorNode>(tok[0], std::move(left), std::move(right)));
        }
    }

    return std::move(nodes.top()); // Retornar la raiz del arbol
}

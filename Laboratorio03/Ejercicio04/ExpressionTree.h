#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <iostream>
#include <string>
#include <cctype>
#include <memory>
#include <stack>
#include <vector>

class Node {
public:
    virtual ~Node() {}
    virtual double evaluate() const = 0; // Metodo virtual puro para evaluar el nodo
};

class NumberNode : public Node {
private:
    double value;
public:
    NumberNode(double value) : value(value) {}
    double evaluate() const override {
        return value; // Retorna el valor del numero
    }
};

class OperatorNode : public Node {
private:
    char op; // Operador: '+' o '*'
    std::unique_ptr<Node> left; // Nodo izquierdo
    std::unique_ptr<Node> right; // Nodo derecho
public:
    OperatorNode(char op, std::unique_ptr<Node> left, std::unique_ptr<Node> right)
        : op(op), left(std::move(left)), right(std::move(right)) {}

    double evaluate() const override {
        if (op == '+') {
            return left->evaluate() + right->evaluate(); // Suma
        } else if (op == '*') {
            return left->evaluate() * right->evaluate(); // Multiplicacion
        }
        return 0;
    }
};

class ExpressionTree {
private:
    std::unique_ptr<Node> root;

    // Metodo para construir el arbol a partir de una expresion infija
    std::unique_ptr<Node> buildTree(const std::string& expression);

    // Metodo para convertir infija a postfija
    std::vector<std::string> infixToPostfix(const std::string& expression);
    
    // Metodo para determinar la precedencia de los operadores
    int precedence(char op);

public:
    ExpressionTree(const std::string& expression) {
        root = buildTree(expression); // Construir el arbol
    }
    
    double evaluate() const {
        return root->evaluate(); // Evaluar el arbol
    }
};

#endif

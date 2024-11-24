
#include <iostream>

// Productos abstractos
class Button {
public:
    virtual void Draw() const = 0;
    virtual ~Button() = default;
};

class CheckBox {
public:
    virtual void Draw() const = 0;
    virtual ~CheckBox() = default;
};

// Productos concretos para Windows
class WinButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Windows" << std::endl;
    }
};

class WinCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Windows" << std::endl;
    }
};

// Productos concretos para Mac
class MacButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Mac" << std::endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Mac" << std::endl;
    }
};

// Productos concretos para Linux
class LinuxButton : public Button {
public:
    void Draw() const override {
        std::cout << "Dibujando Button Linux" << std::endl;
    }
};

class LinuxCheckBox : public CheckBox {
public:
    void Draw() const override {
        std::cout << "Dibujando CheckBox Linux" << std::endl;
    }
};
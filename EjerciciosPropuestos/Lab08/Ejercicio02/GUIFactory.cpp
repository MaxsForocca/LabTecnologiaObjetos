#include <memory>
#include <iostream>
#include "GUIComponents.cpp"


class GUIFactory {
public:
    virtual std::unique_ptr<Button> CrearControlWO() const = 0;
    virtual std::unique_ptr<CheckBox> CrearControlMO() const = 0;
    virtual ~GUIFactory() = default;
};

// Fábrica concreta para Windows
class WinFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CrearControlWO() const override {
        return std::make_unique<WinButton>();
    }

    std::unique_ptr<CheckBox> CrearControlMO() const override {
        return std::make_unique<WinCheckBox>();
    }
};

// Fábrica concreta para Mac
class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CrearControlWO() const override {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<CheckBox> CrearControlMO() const override {
        return std::make_unique<MacCheckBox>();
    }
};

// Fábrica concreta para Linux
class LinuxFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CrearControlWO() const override {
        return std::make_unique<LinuxButton>();
    }

    std::unique_ptr<CheckBox> CrearControlMO() const override {
        return std::make_unique<LinuxCheckBox>();
    }
};
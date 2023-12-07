#pragma once
#include "Prerequisites.h"

// Clase base para productos A
class ProductA {
public:
    virtual void operationA() = 0; // M�todo virtual puro para la operaci�n A
};

// Clase base para productos B
class ProductB {
public:
    virtual void operationB() = 0; // M�todo virtual puro para la operaci�n B
};

// Clase abstracta para la f�brica abstracta
class AbstractFactory {
public:
    virtual ProductA* crearProductoA() = 0; // M�todo virtual puro para crear ProductA
    virtual ProductB* crearProductoB() = 0; // M�todo virtual puro para crear ProductB
};

// Clase concreta para productos A
class ProductA1 : public ProductA {
public:
    void operationA() override {
        cout << "Operaci�n A en ProductoA1" << endl;
    }
};

// Clase concreta para productos B
class ProductB1 : public ProductB {
public:
    void operationB() override {
        cout << "Operaci�n B en ProductoB1" << endl;
    }
};

// Clase concreta para la implementaci�n de AbstractFactory
class ConcreteAbsFactory : public AbstractFactory {
public:
    ProductA* crearProductoA() override {
        return new ProductA1(); // Crea una instancia de ProductA1
    }

    ProductB* crearProductoB() override {
        return new ProductB1(); // Crea una instancia de ProductB1
    }
};

#pragma once
#include "Prerequisites.h"

//Clase base para productos A
class ProductA {
public:
    virtual
        void
        operationA() = 0;
};

//Clase base para productos B
class ProductB {
public:
    virtual
        void
        operationB() = 0;
};

//Clase abstract factory
class AbstractFactory {
public:
    virtual ProductA* crearProductoA() = 0;
    virtual ProductB* crearProductoB() = 0;
};

//Clase concreta para productos A
class productA1 : public ProductA {
public:
    void
        operationA() override {
        cout << "Operación A en ProductoA1" << endl;
    }
};

//Clase concreta para productos B
class productB1 : public ProductB {
public:
    void
        operationB() override {
        cout << "Operación B en ProductoA1" << endl;
    }
};

//Clase concreta para la implementación de abstract factory
class ConcreteAbsFactory : public AbstractFactory {
public:
    ProductA* crearProductoA() override {
        return new productA1();
    }
    ProductB* crearProductoB() override {
        return new productB1();
    }
};
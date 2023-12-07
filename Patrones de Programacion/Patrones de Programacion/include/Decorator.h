#pragma once
#include "Prerequisites.h"



// Interfaz base - Componente
class Component {
public:
    virtual void operacion() = 0;
};

// Clase concreta
class ConcreteComponent : public Component {
public:
    void operacion() override {
        cout << "Operación del componente concreto" << endl;
    }
};

// Decorador base
class Decorator : public Component {
public:
    Decorator(Component* _component) : m_component(_component) { }

    void operacion() override {
        m_component->operacion();
    }

private:
    Component* m_component;
};

// Decorador concreto A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* _component) : Decorator(_component) {}

    void operacion() override {
        Decorator::operacion();
        cout << "Operación del decorador A" << endl;
    }
};

// Otro decorador concreto B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* _component) : Decorator(_component) {}

    void operacion() override {
        Decorator::operacion();
        cout << "Operación del decorador B" << endl;
    }
};

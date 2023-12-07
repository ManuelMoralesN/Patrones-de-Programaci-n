#pragma once
#include "Prerequisites.h"

// Interfaz base - Componente
class Component {
public:
    virtual void operacion() = 0; // Método virtual puro para la operación del componente
};

// Clase concreta
class ConcreteComponent : public Component {
public:
    void operacion() override {
        cout << "Operación del componente concreto" << endl; // Implementación de la operación en la clase concreta
    }
};

// Decorador base
class Decorator : public Component {
public:
    Decorator(Component* _component) : m_component(_component) { }

    void operacion() override {
        m_component->operacion(); // Llama a la operación del componente base o del decorador anterior
    }

private:
    Component* m_component; // Puntero al componente que está siendo decorado
};

// Decorador concreto A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* _component) : Decorator(_component) {}

    void operacion() override {
        Decorator::operacion(); // Llama a la operación del decorador base
        cout << "Operación del decorador A" << endl; // Agrega funcionalidad específica del decorador A
    }
};

// Otro decorador concreto B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* _component) : Decorator(_component) {}

    void operacion() override {
        Decorator::operacion(); // Llama a la operación del decorador base
        cout << "Operación del decorador B" << endl; // Agrega funcionalidad específica del decorador B
    }
};

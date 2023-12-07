#pragma once
#include "Prerequisites.h"

// Interfaz base - Componente
class Component {
public:
    virtual void operacion() = 0; // M�todo virtual puro para la operaci�n del componente
};

// Clase concreta
class ConcreteComponent : public Component {
public:
    void operacion() override {
        cout << "Operaci�n del componente concreto" << endl; // Implementaci�n de la operaci�n en la clase concreta
    }
};

// Decorador base
class Decorator : public Component {
public:
    Decorator(Component* _component) : m_component(_component) { }

    void operacion() override {
        m_component->operacion(); // Llama a la operaci�n del componente base o del decorador anterior
    }

private:
    Component* m_component; // Puntero al componente que est� siendo decorado
};

// Decorador concreto A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* _component) : Decorator(_component) {}

    void operacion() override {
        Decorator::operacion(); // Llama a la operaci�n del decorador base
        cout << "Operaci�n del decorador A" << endl; // Agrega funcionalidad espec�fica del decorador A
    }
};

// Otro decorador concreto B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* _component) : Decorator(_component) {}

    void operacion() override {
        Decorator::operacion(); // Llama a la operaci�n del decorador base
        cout << "Operaci�n del decorador B" << endl; // Agrega funcionalidad espec�fica del decorador B
    }
};

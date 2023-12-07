#pragma once
#include "Prerequisites.h"



// Clase concreta para la cafetería
class Cafeteria {
public:
    void PrepararCafe() {
        cout << "Café listo" << endl;
    }
};

// Clase base para los condimentos
class Condimento {
public:
    virtual void decorar() = 0;
};

// Decorador base para añadir la leche usando Condimento
class Nutrileche : public Condimento {
public:
    Nutrileche(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe();
        cout << "Nutrileche agregada" << endl;
    }

private:
    Cafeteria* m_component;
};

// Decorador base para añadir el azúcar usando Condimento
class Azucar : public Condimento {
public:
    Azucar(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe();
        cout << "Azúcar agregada" << endl;
    }

private:
    Cafeteria* m_component;
};

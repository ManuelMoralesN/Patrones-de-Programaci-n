#pragma once
#include "Prerequisites.h"



// Clase concreta para la cafeter�a
class Cafeteria {
public:
    void PrepararCafe() {
        cout << "Caf� listo" << endl;
    }
};

// Clase base para los condimentos
class Condimento {
public:
    virtual void decorar() = 0;
};

// Decorador base para a�adir la leche usando Condimento
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

// Decorador base para a�adir el az�car usando Condimento
class Azucar : public Condimento {
public:
    Azucar(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe();
        cout << "Az�car agregada" << endl;
    }

private:
    Cafeteria* m_component;
};

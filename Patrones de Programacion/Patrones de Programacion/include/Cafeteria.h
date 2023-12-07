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
    virtual void decorar() = 0; // Método virtual puro para decorar el café
};

// Decorador base para añadir la leche usando Condimento
class Nutrileche : public Condimento {
public:
    Nutrileche(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe(); // Llama al método de la cafetería base
        cout << "Nutrileche agregada" << endl; // Agrega funcionalidad específica del decorador
    }

private:
    Cafeteria* m_component; // Puntero a la cafetería base
};

// Decorador base para añadir el azúcar usando Condimento
class Azucar : public Condimento {
public:
    Azucar(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe(); // Llama al método de la cafetería base
        cout << "Azúcar agregada" << endl; // Agrega funcionalidad específica del decorador
    }

private:
    Cafeteria* m_component; // Puntero a la cafetería base
};

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
    virtual void decorar() = 0; // M�todo virtual puro para decorar el caf�
};

// Decorador base para a�adir la leche usando Condimento
class Nutrileche : public Condimento {
public:
    Nutrileche(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe(); // Llama al m�todo de la cafeter�a base
        cout << "Nutrileche agregada" << endl; // Agrega funcionalidad espec�fica del decorador
    }

private:
    Cafeteria* m_component; // Puntero a la cafeter�a base
};

// Decorador base para a�adir el az�car usando Condimento
class Azucar : public Condimento {
public:
    Azucar(Cafeteria* _condimento) : m_component(_condimento) { }

    void decorar() override {
        m_component->PrepararCafe(); // Llama al m�todo de la cafeter�a base
        cout << "Az�car agregada" << endl; // Agrega funcionalidad espec�fica del decorador
    }

private:
    Cafeteria* m_component; // Puntero a la cafeter�a base
};

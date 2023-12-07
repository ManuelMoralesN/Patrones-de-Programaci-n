#pragma once
#include "Prerequisites.h"

// Clase con la lógica para el patrón Prototype
class Prototype
{
public:
    // Método virtual para clonar el objeto
    virtual Prototype* clonar() = 0;

    // Método virtual para configurar el prototipo con un valor específico
    virtual void configurar(string _value) = 0;

    // Método virtual para imprimir los valores configurados del prototipo
    virtual void print() = 0;
};

// Clase concreta de prototipo
class PrototipoConcreto : public Prototype {
public:
    // Implementación de clonar para crear una copia del prototipo
    Prototype* clonar() override {
        PrototipoConcreto* copia = new PrototipoConcreto();
        copia->configurar(m_valor);
        return copia;
    }

    // Implementación para configurar el valor del prototipo
    void configurar(string _valor) override {
        m_valor = _valor;
    }

    // Implementación para imprimir el valor configurado
    void print() override {
        cout << "Valor: " << m_valor << endl;
    }

private:
    string m_valor;
};

#pragma once
#include "Prerequisites.h"

// Clase con la l�gica para el patr�n Prototype
class Prototype
{
public:
    // M�todo virtual para clonar el objeto
    virtual Prototype* clonar() = 0;

    // M�todo virtual para configurar el prototipo con un valor espec�fico
    virtual void configurar(string _value) = 0;

    // M�todo virtual para imprimir los valores configurados del prototipo
    virtual void print() = 0;
};

// Clase concreta de prototipo
class PrototipoConcreto : public Prototype {
public:
    // Implementaci�n de clonar para crear una copia del prototipo
    Prototype* clonar() override {
        PrototipoConcreto* copia = new PrototipoConcreto();
        copia->configurar(m_valor);
        return copia;
    }

    // Implementaci�n para configurar el valor del prototipo
    void configurar(string _valor) override {
        m_valor = _valor;
    }

    // Implementaci�n para imprimir el valor configurado
    void print() override {
        cout << "Valor: " << m_valor << endl;
    }

private:
    string m_valor;
};

#pragma once
#include "Prerequisites.h"


// Clase para las pizzas por cocinar
class Pizza
{
public:
    void AgregarParte(const string _part) { // Función para agregar partes a la pizza
        m_parts.push_back(_part);
    }

    void print() { // Función para imprimir las partes de la pizza
        cout << "Partes de la pizza: ";
        for (int i = 0; i < m_parts.size(); i++)
        {
            cout << m_parts[i] << ", ";
        }
        cout << "" << endl;
    }

private:
    vector<string> m_parts;
};

// Interfaz para definir las partes del objeto para cocinar la pizza
class Oven
{
public:
    virtual void BuildMasita() = 0;       // Construir la masa de la pizza
    virtual void BuildQueso() = 0;        // Añadir el queso a la pizza
    virtual void BuildSalsa() = 0;        // Añadir la salsa a la pizza
    virtual void BuildIngredientes() = 0; // Añadir ingredientes específicos a la pizza
    virtual Pizza* getProduct() = 0;      // Obtener la pizza construida
};

// Implementación de los métodos de Oven para hacer una pizza hawaiana
class PizzaHawaiana : public Oven {
public:
    PizzaHawaiana() {
        m_product = new Pizza();
    }

    void BuildMasita() override {
        m_product->AgregarParte("Masita");
    }

    void BuildQueso() override {
        m_product->AgregarParte("Repartido el cheese");
    }

    void BuildSalsa() override {
        m_product->AgregarParte("Sauce No reaction");
    }

    void BuildIngredientes() override {
        m_product->AgregarParte("La piña");
    }

    Pizza* getProduct() override {
        return m_product;
    }

private:
    Pizza* m_product;
};

// Implementación de los métodos de Oven para hacer una pizza veggie
class PizzaVegetariana : public Oven {
public:
    PizzaVegetariana() {
        m_product = new Pizza();
    }

    void BuildMasita() override {
        m_product->AgregarParte("Masita");
    }

    void BuildQueso() override {
        m_product->AgregarParte("Chesse bajo en grasa");
    }

    void BuildSalsa() override {
        m_product->AgregarParte("Sauce No reaction");
    }

    void BuildIngredientes() override {
        m_product->AgregarParte("Champiñones");
    }

    Pizza* getProduct() override {
        return m_product;
    }

private:
    Pizza* m_product;
};

// Método que funciona como director para construir una pizza con un Oven específico
class Chef {
public:
    Chef(Oven* _oven) : m_builder(_oven) {}

    void build() {
        m_builder->BuildMasita();
        m_builder->BuildQueso();
        m_builder->BuildSalsa();
        m_builder->BuildIngredientes();
    }

private:
    Oven* m_builder;
};

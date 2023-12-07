#pragma once
#include "Prerequisites.h"

// Clase para el objeto a construir
class bProduct {
public:
    void agregarParte(const string& _parte) { // Función para agregar nuevas partes al producto
        m_partes.push_back(_parte);
    }

    void print() { // Función para imprimir las partes del producto
        cout << "Partes del producto: ";
        for (int i = 0; i < m_partes.size(); i++) {
            cout << m_partes[i] << " ";
        }
    }

private:
    vector<string> m_partes; // Vector para almacenar las partes del producto
};

// Interfaz para definir las partes del objeto
class Builder {
public:
    virtual void buildParteA() = 0; // Método virtual puro para construir la parte A
    virtual void buildParteB() = 0; // Método virtual puro para construir la parte B
    virtual bProduct* obtenerProducto() = 0; // Método virtual puro para obtener el producto final
};

// Clase para implementar las partes del producto
class BuilderConcreto : public Builder {
public:
    BuilderConcreto() {
        m_product = new bProduct(); // Inicializa el producto en el constructor
    }

    void buildParteA() override {
        m_product->agregarParte("Parte A"); // Construye la parte A del producto
    }

    void buildParteB() override {
        m_product->agregarParte("Parte B"); // Construye la parte B del producto
    }

    bProduct* obtenerProducto() override {
        return m_product; // Devuelve el producto construido
    }

private:
    bProduct* m_product; // Puntero al producto en construcción
};

// Clase que se encarga de la construcción del producto
class Director {
public:
    Director(Builder* _builder) : m_builder(_builder) {}

    void build() {
        m_builder->buildParteA(); // Construye la parte A
        m_builder->buildParteB(); // Construye la parte B
    }

private:
    Builder* m_builder; // Puntero al constructor concreto
};

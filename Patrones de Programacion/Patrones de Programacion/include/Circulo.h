#pragma once
#include "Prerequisites.h"

// En este caso, la interfaz vieja es un c�rculo
class Circulo {
public:
    virtual void DibujarCirculo() {
        cout << "C�rculo Dibujado" << endl;
    }
};

// En este caso, la interfaz vieja es un cuadrado
class Cuadrado {
public:
    virtual void DibujarCuadrado() {
        cout << "Cuadrado dibujado." << endl;
    }
};

// Clase que funciona como una nueva interfaz para cuadrado y c�rculo
class Dibujable {
public:
    virtual void dibujar() {
        cout << "M�todo nuevo." << endl;
    }
};

// Implementa la clase dibujable heredando el c�rculo para poder dibujarlo
class CirculoAdapter : public Dibujable {
public:
    CirculoAdapter(Circulo* circulo) : m_Circulo(circulo) {}

    void dibujar() override {
        cout << "Adaptador para dibujar." << endl;
        m_Circulo->DibujarCirculo(); // Llama al m�todo de la interfaz vieja para adaptarlo al nuevo
    }

private:
    Circulo* m_Circulo; // Puntero a la interfaz vieja (c�rculo)
};

// Implementa la clase dibujable heredando el cuadrado para poder dibujarlo
class CuadradoAdapter : public Dibujable {
public:
    CuadradoAdapter(Cuadrado* cuadrado) : m_cuadrado(cuadrado) {}

    void dibujar() override {
        cout << "Adaptador para dibujar." << endl;
        m_cuadrado->DibujarCuadrado(); // Llama al m�todo de la interfaz vieja para adaptarlo al nuevo
    }

private:
    Cuadrado* m_cuadrado; // Puntero a la interfaz vieja (cuadrado)
};

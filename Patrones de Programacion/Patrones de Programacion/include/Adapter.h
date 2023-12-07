#pragma once
#include "Prerequisites.h"

// Clase deprecada para la interfaz vieja
class InterfazVieja {
public:
    // Método de la interfaz vieja
    virtual void OldMethod() {
        cout << "Método viejo llamado." << endl;
    }
};

// Clase objetivo para una nueva interfaz
class InterfazNueva {
public:
    // Método de la interfaz nueva
    virtual void newMethod() {
        cout << "Método nuevo llamado." << endl;
    }
};

// Implementa la nueva interfaz pero hereda la interfaz vieja para adaptarla
class Adapter : public InterfazNueva {
public:
    // Constructor que recibe un puntero a la interfaz vieja
    Adapter(InterfazVieja* _vieja) : m_interfazVieja(_vieja) {}

    // Implementación del método de la interfaz nueva
    void newMethod() override {
        cout << "Adaptador llamado al método nuevo." << endl;

        // Llama al método de la interfaz vieja para adaptarlo al nuevo
        m_interfazVieja->OldMethod();
    }

private:
    InterfazVieja* m_interfazVieja; // Puntero a la interfaz vieja
};

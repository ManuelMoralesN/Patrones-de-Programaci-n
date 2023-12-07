#pragma once
#include "Prerequisites.h"

// Clase deprecada para la interfaz vieja
class InterfazVieja {
public:
    // M�todo de la interfaz vieja
    virtual void OldMethod() {
        cout << "M�todo viejo llamado." << endl;
    }
};

// Clase objetivo para una nueva interfaz
class InterfazNueva {
public:
    // M�todo de la interfaz nueva
    virtual void newMethod() {
        cout << "M�todo nuevo llamado." << endl;
    }
};

// Implementa la nueva interfaz pero hereda la interfaz vieja para adaptarla
class Adapter : public InterfazNueva {
public:
    // Constructor que recibe un puntero a la interfaz vieja
    Adapter(InterfazVieja* _vieja) : m_interfazVieja(_vieja) {}

    // Implementaci�n del m�todo de la interfaz nueva
    void newMethod() override {
        cout << "Adaptador llamado al m�todo nuevo." << endl;

        // Llama al m�todo de la interfaz vieja para adaptarlo al nuevo
        m_interfazVieja->OldMethod();
    }

private:
    InterfazVieja* m_interfazVieja; // Puntero a la interfaz vieja
};

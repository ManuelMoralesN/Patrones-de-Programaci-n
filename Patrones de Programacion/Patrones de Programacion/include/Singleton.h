#pragma once

// Clase Singleton para representar un objeto único
class Singleton
{
public:
    // Constructor privado para evitar instanciación directa
    Singleton() : m_value(0) {};

    // Método estático para obtener la única instancia de Singleton
    static Singleton* getInstance() {
        if (m_instance != nullptr) {
            return m_instance; // Devuelve una instancia existente
        }
        else {
            m_instance = new Singleton; // Crea una nueva instancia si no existe
        }
        return m_instance; // Devuelve la instancia creada o existente
    }

    // Destructor predeterminado
    ~Singleton() = default;

    // Establecer el valor de la variable m_value
    void setValue(int _v) {
        m_value = _v;
    }

    // Obtener el valor de la variable m_value
    int getValue() {
        return m_value;
    }

private:
    // Instancia única de Singleton
    static Singleton* m_instance;

    // Variable de valor único
    int m_value;
};

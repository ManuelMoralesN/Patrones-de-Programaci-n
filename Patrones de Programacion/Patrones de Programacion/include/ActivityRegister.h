#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RegistroActividad {
public:
    RegistroActividad() : m_numActs(0) {}

    static
        RegistroActividad*
        getInstance() { // Obtiene la instancia del Singleton
        if (m_instance != nullptr) // Verifica si ya hay una instancia creada
        {
            return m_instance; // Devuelve la instancia existente
        }
        else {
            m_instance = new RegistroActividad; // Crea una nueva instancia si no existe
        }
        return m_instance; // Devuelve la instancia creada
    }

    void
        addActivity(const string actividad) { // Funci�n para agregar una actividad al registro
        if (m_numActs < m_maxActs) { // Verifica que el registro no est� lleno
            m_acts.push_back(actividad); // Agrega la actividad al vector m_acts
        }
        else {
            cout << "Registro de actividades est� lleno." << endl; // Muestra un mensaje si el registro est� lleno
        }
    }

    void
        showActivities() { // Funci�n para mostrar todas las actividades registradas
        cout << "Registro de Actividades:" << endl;
        for (const string actividad : m_acts) {
            cout << actividad << endl; // Muestra cada actividad registrada en una nueva l�nea
        }
    }

private:
    static RegistroActividad* m_instance; // Instancia �nica del Singleton
    static const int m_maxActs = 20; // N�mero m�ximo de actividades que se pueden almacenar
    vector<string> m_acts; // Vector que almacena las actividades
    int m_numActs; // N�mero actual de actividades en el registro
};

#pragma once
#include "Prerequisites.h"



// Clase base para definir Archivo
class Archivo {
public:
    virtual void MostrarInfo() {
        cout << "¡Hola! Soy un archivo." << endl;
    }
};

// Clase base para definir Carpeta
class Carpeta {
public:
    virtual void MostrarInfo() {
        cout << "¡Hola! Soy una carpeta." << endl;
    }
};

// Clase que funciona como interfaz
class Sistema {
public:
    virtual void MostrarInfo() = 0;
};

// Clase que representa un archivo y también es un sistema
class SistemaArchivo : public Archivo, public Sistema {
public:
    void MostrarInfo() override {
        cout << "Contiene: " << m_docs.size() << " documentos." << endl;

        // Muestra información de cada documento (archivo)
        for (auto hoja : m_docs) {
            hoja->MostrarInfo();
        }
    }

    void agregarSistema(Sistema* _doc) {
        m_docs.push_back(_doc);
    }

private:
    vector<Sistema*> m_docs; // Almacena documentos (archivos)
};

// Clase que representa una carpeta y también es un sistema
class SistemaCarpeta : public Carpeta, public Sistema {
public:
    void MostrarInfo() override {
        cout << "Contiene: " << m_carp.size() << " carpetas." << endl;

        // Muestra información de cada carpeta
        for (auto hoja : m_carp) {
            hoja->MostrarInfo();
        }
    }

    void AgregarSistema(Sistema* _doc) {
        m_carp.push_back(_doc);
    }

private:
    vector<Sistema*> m_carp; // Almacena carpetas
};

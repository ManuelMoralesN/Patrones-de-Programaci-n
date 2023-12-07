#pragma once
#include "Prerequisites.h"

// Base interface for products
class Product {
public:
    virtual void operacion() = 0; // Virtual function for product operation
};

// Base interface for factories
class Factory {
public:
    virtual Product* crearProducto() = 0; // Virtual function to create products
};

// Concrete implementation of the Product interface
class ConcreteProduct : public Product {
public:
    void operacion() override {
        cout << "Acá se realiza una operación" << endl; // Implementation of the product operation
    }
};

// Concrete implementation of the Factory interface
class ConcreteFactory : public Factory {
public:
    Product* crearProducto() override {
        return new ConcreteProduct(); // Creates instances of ConcreteProduct
    }
};

// Example of the Factory Method pattern for vehicles

// Base interface for vehicles
class Vehiculo {
public:
    virtual void descripcion() {
        cout << "Hola, soy un vehículo" << endl; // Virtual function for describing the vehicle
    }
};

// Concrete implementation for a car
class ConcreteCoche : public Vehiculo {
public:
    void descripcion() override {
        cout << "Hola, soy un coche" << endl; // Implementation of the description for a car
    }
};

// Concrete implementation for a bicycle
class ConcreteBicicleta : public Vehiculo {
public:
    void descripcion() override {
        cout << "Hola, soy una bicicleta" << endl; // Implementation of the description for a bicycle
    }
};

// Base interface for vehicle factories
class FactoryVehiculos {
public:
    virtual Vehiculo* crearVehiculo() = 0; // Virtual function to create instances of Vehiculo
};

// Concrete implementation for a factory that creates cars
class ConcreteFactoryCoche : public FactoryVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new ConcreteCoche(); // Creates instances of ConcreteCoche
    }
};

// Concrete implementation for a factory that creates bicycles
class ConcreteFactoryBicicleta : public FactoryVehiculos {
public:
    Vehiculo* crearVehiculo() override {
        return new ConcreteBicicleta(); // Creates instances of ConcreteBicicleta
    }
};

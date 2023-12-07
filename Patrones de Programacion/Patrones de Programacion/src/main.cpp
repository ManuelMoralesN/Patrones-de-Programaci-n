#include "Prerequisites.h"
#include "Singleton.h"
#include "ActivityRegister.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Pizza.h"
#include "Adapter.h"
#include "Circulo.h"
#include "Prototype.h"
#include "Decorator.h"
#include "Cafeteria.h"
#include "Composite.h"
#include "Archivo.h"

// Inicialización de las variables de Singleton de forma nula
Singleton* Singleton::m_instance = nullptr;
RegistroActividad* RegistroActividad::m_instance = nullptr;

int main() {
    // Singleton
    cout << "//////////////Singleton/////////////////////"<<endl;
    // Obtiene la instancia única del Singleton
    Singleton* SingleMan = Singleton::getInstance();
    SingleMan->setValue(27);

    // Muestra el valor almacenado en Singleton
    Singleton* SingleMan2 = Singleton::getInstance();
    std::cout << "Value: " << SingleMan2->getValue() << std::endl;

    // Singleton Register

    // Obtiene las instancias del Singleton
    RegistroActividad* Registro = RegistroActividad::getInstance();
    RegistroActividad* Registro2 = RegistroActividad::getInstance();

    // Agrega actividades al primer registro
    Registro->addActivity("Primer actividad");
    Registro->addActivity("Segunda actividad");
    Registro->addActivity("Tercea actividad");
    Registro->addActivity("Cuarta actividad");

    // Muestra las actividades del registro anterior, al ser Singleton esto es posible
    Registro2->showActivities();

    // Factory
    cout << "//////////////Factory///////////////////" << endl;
    // Se crea una instancia para la clase concreta de factory y se crea un producto
    Factory* factory = new ConcreteFactory();
    Product* product = factory->crearProducto();
    product->operacion();

    // Liberar memoria
    delete factory;
    delete product;

    // Factory Vehículos

    // Se crea una instancia para la clase concreta de factory y se crea un vehículo
    FactoryVehiculos* factoryV = new ConcreteFactoryCoche();
    Vehiculo* vehiculo = factoryV->crearVehiculo();
    vehiculo->descripcion();

    // Liberar memoria
    delete factoryV;
    delete vehiculo;

    // Abstract Factory
    cout << "////////////////Abstract Factory////////////////////" << endl;
    AbstractFactory* AFactory = new ConcreteAbsFactory();

    // Se crean productos usando la fábrica
    ProductA* productA = AFactory->crearProductoA();
    ProductB* productB = AFactory->crearProductoB();
    // Se mandan a llamar las operaciones de cada producto
    productA->operationA();
    productB->operationB();

    // Liberar memoria
    delete AFactory;
    delete productA;
    delete productB;

    // Builder
    cout << "///////////////////////Builder////////////////////////////" << endl;
    Builder* constructor = new BuilderConcreto();

    // Se crea al director que se encargará de construir el producto
    Director director(constructor);

    // Construcción del producto usando el Director
    director.build();

    // Se obtiene el nuevo producto desde el constructor
    bProduct* producto = constructor->obtenerProducto();
    producto->print();

    // Liberar memoria asignada
    delete constructor;
    delete producto;

    // Pizza Builder
    cout << "/////////////////////////Pizza/////////////////////////" << endl;
    // Creación de los objetos de BuilderConcretos
    Oven* construct = new PizzaHawaiana();
    Oven* construct1 = new PizzaVegetariana();

    // Se crea al chef que funciona como el director para crear las pizzas
    Chef chef1(construct);
    Chef chef2(construct1);

    // Construcción de las pizzas usando al chefsito
    chef1.build();
    chef2.build();

    // Se obtiene las nuevas pizzas desde el constructor
    Pizza* pizza = construct->getProduct();
    pizza->print();
    Pizza* pizza1 = construct1->getProduct();
    pizza1->print();

    // Liberar memoria asignada
    delete construct;
    delete pizza;

    // Adapter
    cout << "/////////////////////////Adapter/////////////////////////" << endl;
    // Se crea la interfaz vieja y la nueva
    InterfazVieja* objViejo = new InterfazVieja();
    InterfazNueva* objNuevo = new Adapter(objViejo);

    // Se llama al newMethod desde el adapter
    objNuevo->newMethod();

    // Liberar memoria asignada
    delete objViejo;
    delete objNuevo;

    // Adapter de círculo
    cout << "////////////////////////Circulo///////////////////////" << endl;
    // Se crean cuadrado y círculo como interfaces viejas y Dibujable como la nueva
    Circulo* circle = new Circulo();
    Cuadrado* square = new Cuadrado();
    Dibujable* AdCircle = new CirculoAdapter(circle);
    Dibujable* AdSquare = new CuadradoAdapter(square);

    // Se llama a la función de dibujar desde los adapter para dibujar ambas figuras
    AdCircle->dibujar();
    AdSquare->dibujar();

    // Liberar memoria asignada
    delete circle;
    delete square;
    delete AdCircle;
    delete AdSquare;

    // Prototype
    cout << "//////////////////////////Prototype///////////////////////////"<< endl;
    // Se usa el puntero para la clase que se está clonando
    Prototype* prototype = new PrototipoConcreto();
    prototype->configurar("Ejemplo"); // Se configura el recurso

    Prototype* copia = prototype->clonar(); // Se clona el recurso

    // Se imprimen los recursos
    prototype->print();
    copia->print();

    // Liberar memoria asignada
    delete prototype;
    delete copia;

    // Decorator
    cout << "//////////////////////////Decorator//////////////////////////////////" << endl;
    ConcreteComponent* objeto = new ConcreteComponent();
    // Se crea un decorator que obtiene al objeto del Concrete component
    ConcreteDecoratorA* decoratorA = new ConcreteDecoratorA(objeto);
    // Se crea un decorator que obtiene al objeto del ConcreteDecoratorA
    ConcreteDecoratorB* decoratorB = new ConcreteDecoratorB(decoratorA);

    // Se llama a la función operación de los objetos
    objeto->operacion();
    decoratorA->operacion();
    decoratorB->operacion();

    // Liberar memoria asignada
    delete objeto;
    delete decoratorA;
    delete decoratorB;

    // Cafetería Decorator
    cout << "///////////////////////////Cafeteria////////////////////////////" << endl;
    // Creación de un objeto Cafetería que actúa como ConcreteComponent
    Cafeteria* cafeteria = new Cafeteria();

    // Se crea decoradores (Leche y Azúcar) que obtienen el objeto de la cafetería
    Nutrileche* cafeLeche = new Nutrileche(cafeteria);
    Azucar* cafeAzucar = new Azucar(cafeteria);

    // Se llama a la función prepararCafe y se añade la función decorar para cada café
    cafeteria->PrepararCafe();
    cafeLeche->decorar();
    cafeAzucar->decorar();

    // Liberar memoria asignada
    delete cafeteria;
    delete cafeAzucar;
    delete cafeLeche;

    // Composite
    cout << "////////////////////////////Composite///////////////////////////////////" << endl;
    // Se crean dos objetos de hojas y un composite
    leaf* hoja1 = new leaf();
    leaf* hoja2 = new leaf();
    Composite* composite = new Composite();

    // El composite añade los objetos creados de las hojas
    composite->addLeaf(hoja1);
    composite->addLeaf(hoja2);

    // Composite manda a llamar la función para las operaciones en las hojas
    composite->operacion();

    // Liberar memoria asignada
    delete hoja1;
    delete hoja2;
    delete composite;

    // Archivo Composite
    cout << "/////////////////////////////Archivo///////////////////////////////////" << endl;
    // Se crean dos objetos de archivos y una carpeta que actúa como composite
    SistemaArchivo* archivo1 = new SistemaArchivo();
    SistemaArchivo* archivo2 = new SistemaArchivo();
    SistemaCarpeta* carpeta = new SistemaCarpeta();

    // La carpeta busca a los archivos dentro de cada carpeta
    carpeta->AgregarSistema(archivo1);
    carpeta->AgregarSistema(archivo2);

    // La carpeta manda a llamar la función para las operaciones en los archivos
    // Dado a la estructura realizada, los archivos están vacíos
    carpeta->MostrarInfo();

    // Liberar memoria asignada
    delete archivo1;
    delete archivo2;
    delete carpeta;

    return 0;
}

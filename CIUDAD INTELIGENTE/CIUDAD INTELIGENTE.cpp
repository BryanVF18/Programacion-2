// CIUDAD INTELIGENTE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "GestorCiudad.h"
//#include "PlantaSolar.h"
#include "EdificioResidencial.h"
//#include "ComplejoIndustrial.h"
//#include "CiudadException.h"
//#include "EstrategiaAhorro.h"
//#include "DeficitRecursoException.h"
#include "SensorConsumoInteligente.h"
#include "BlindajeTermico.h"
#include "ReduccionEmisiones.h"

using namespace std;


// MAIN PARA LA PRUEBA DE LA DECORADORA

int main() {

    cout << "------- PRUEBA CLASE DECORADORA -------";


    auto edificio = make_shared<EdificioResidencial>("Edificio Central", 200, 20);

    cout << "\nConsumo inicial: " << edificio->consumirEnergia() << endl;

    auto edificioSensor = make_shared<SensorConsumoInteligente>("Sensor Inteligente", edificio);

    cout << "Consumo con sensor inteligente: " << edificioSensor->consumirEnergia() << endl;

    auto edificioBlindado = make_shared<BlindajeTermico>("Blindaje Termico", edificioSensor);

    cout << "Consumo con sensor + blindaje: " << edificioBlindado->consumirEnergia() << endl;

    cout << "\nFlujo de decoradores aplicado:" << endl;
    cout << "Edificio -> Sensor -> Blindaje" << endl;

    // Ahora probamos que GestorCiudad sigue procesando el objeto sin saber que ha sido decorado (Polimorfismo)

    auto central911 = make_shared<CentralEmergencias>("911-EcoCity");
    GestorCiudad motor(central911);
    auto distIndustrial = make_shared<Distrito>("Parque Industrial");
    distIndustrial->agregarEdificio(edificioBlindado);
    motor.agregarDistrito(distIndustrial);
    motor.procesarTurno();




    return 0;


}


/*int main()
{
    try
    {
        // 1. Instanciamos la Central (Objeto de alto nivel)
        auto central911 = std::make_shared<CentralEmergencias>("911-EcoCity");

        // 2. Creamos el Motor inyectando la central (DIP - Inversión de Dependencias)
        GestorCiudad motor(central911);

        // 3. Configuramos la infraestructura
        auto distIndustrial = std::make_shared<Distrito>("Parque Industrial");

        // UPCAST: PlantaSolar es un IEntidad. Se guarda en el vector del distrito automáticamente.
        distIndustrial->agregarEdificio(std::make_shared<PlantaSolar>("Solar-Max", 100));

        // Forzamos un déficit para ver la central en acción
        distIndustrial->agregarEdificio(std::make_shared<EdificioResidencial>("Mega Torre", 500, 1000));

        motor.agregarDistrito(distIndustrial);

        // PRINCIPIO YAGNI: No creamos un menú complejo, solo ejecutamos la simulación necesaria
        std::cout << "Iniciando simulacion de emergencia...\n";
        motor.procesarTurno();
    }
    catch (const DeficitRecursoException& error)
    {
        //Manejamos la excepción: Aceptamos el error específico
        std::cerr << "FALLO EN LA CIUDAD: " << error.what() << std::endl;
        std::cerr << "Acción recomendada: Revisar la red eléctrica" << std::endl;
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error Inesperado" << error.what() << std::endl;
    }

    return 0;
}
*/

/*
auto ciudad = make_unique<GestorCiudad >();

//Generar una simulacion a partir de polimorfismo y sustitucion de Liscov

ciudad->agregarEntidad(make_shared<PlantaSolar>("Planta Solar de Golfito", 200.00));
}
    ciudad->agregarEntidad(make_shared<EdificioResidencial>("Condominio Altavista", 40.00, 50));

    ciudad->agregarEntidad(make_shared<ComplejoIndustrial>("Planta RECOPE", 100.00, 150.00));

    cout << "--- SISTEMA DE GESTION CIG --- \n ";
    cout << "Fase 1: SOLID\n";
    cout << "Presione ENTER para ejecutar el proceso de revision\n";
    cout << "Presione x para salir\n";

    while (cin.get() != 'x') {
        ciudad->procesarTurno();
    }
    return 0;
    
    */
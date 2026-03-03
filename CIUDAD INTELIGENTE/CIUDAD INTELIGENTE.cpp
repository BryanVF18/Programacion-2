// CIUDAD INTELIGENTE.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "GestorCiudad.h"
#include "PlantaSolar.h"
#include "EdificioResidencial.h"
#include "ComplejoIndustrial.h"
using namespace std;

int main()
{
    auto central911 = make_shared<CentralEmergencias>("911 CIUDAD INTELIGENTE");
    GestorCiudad gestor(central911);

    //Crear el distrito residencial
    auto distResidencial = make_shared<Distrito>("Zona Norte - Residencial");
    distResidencial->agregarEdificio(make_shared<EdificioResidencial>("Torre A", 20, 100));
    distResidencial->agregarEdificio(make_shared<EdificioResidencial>("Torre B", 20, 80));

    //Crear el distrito industrial
    auto distIndustrial = make_shared<Distrito>("Parque Insdustrial Sur");
    distIndustrial->agregarEdificio(make_shared<PlantaSolar>("Planta Solar", 500));
    distIndustrial->agregarEdificio(make_shared<ComplejoIndustrial>("Fabrica de Pinturas", 100));


    //Retornamos el reporte
    gestor.agregarDistrito(distResidencial);
    gestor.agregarDistrito(distIndustrial);
    gestor.procesarTurno();
    return 0;
}



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
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
    auto ciudad = make_unique<GestorCiudad > ();

    //Generar una simulacion a partir de polimorfismo y sustitucion de Liscov

    ciudad->agregarEntidad(make_shared<PlantaSolar>("Planta Solar de Golfito", 200.00));

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
}


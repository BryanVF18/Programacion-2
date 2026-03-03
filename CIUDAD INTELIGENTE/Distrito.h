#pragma once
#include <memory>
#include <string>
#include "IEntidad.h"
#include <vector>

//FORWARD DECLARATION:
//Resolvemos la dependencia mutua, no se incluyen los .h para evitar la recursividad infinita
//solo avisamos que hay una clase que existe y puede resolver el problema cuando se necesite unicamente
//(YAGNI)


using namespace std;

class CentralEmergencias;

class Distrito
{
private: 
	string nombre;
	vector<shared_ptr<IEntidad>>edificios;
	
	//El distrito tiene una referencia a la central (Agregacion)

	shared_ptr<CentralEmergencias>centralAsignada;


public:
	Distrito(string n);
	void agregarEdificio(shared_ptr<IEntidad>edifcio);

	//Realizamos inyeccion de dependencia a la central

	void setCentral(shared_ptr<CentralEmergencias>c);


	//Ley de Démeter: El gestor no pide la lista de edificios, pide los totales directamente al distrito
	double obtenerProduccionTotal()const;
	double obtenerComsumoTOtal()const;

	string getNombre() const;
	void mostrarReporteDistrito()const;

	//Metodo que dispara la comunicacion a la central

	void generarAlerta(string causa);
};


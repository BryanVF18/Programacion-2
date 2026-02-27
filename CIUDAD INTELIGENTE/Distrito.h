#pragma once
#include <memory>
#include <string>
#include "IEntidad.h"
#include <vector>

using namespace std;

class Distrito
{
private: 
	string nombre;
	vector<shared_ptr<IEntidad>>edificios;
public:
	Distrito(string n);
	void agregarEdificio(shared_ptr<IEntidad>edifcio);

	//Ley de Démeter: El gestor no pide la lista de edificios, pide los totales directamente al distrito
	double obtenerProduccionTotal()const;
	double obtenerComsumoTOtal()const;

	string getNombre() const;
	void mostrarReporteDistrito()const;
};


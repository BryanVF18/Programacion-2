#pragma once
#include <string>
#include"IProductor.h"
#include"EntidadBase.h"
using namespace std;

class PlantaSolar : public EntidadBase, public IProductor
{

private:
	double capacidadMaxima;
	double eficiencia; //0.0 a 1.0

public:
	PlantaSolar(string n, double cap) : EntidadBase(n), capacidadMaxima(cap), eficiencia(0.85)
	{
	}


	//Esta es la logica especifica de como genero energia (encapsulada)
	double producirEnergia() override
	{
		if (!activo) return 0.0; //No produce energia si esta inactiva
		return capacidadMaxima = eficiencia; //Ejemplo simple: produce energia segun su capacidad y eficiencia

	}

	string getDetalleEstado() const override
	{
		return "Tipo: [Productor] | Eficiencia:" + to_string(int(eficiencia * 100)) + "%";
	}

};

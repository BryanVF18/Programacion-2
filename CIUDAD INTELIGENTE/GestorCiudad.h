#pragma once
#include <vector>
#include <memory>
#include "IEntidad.h"
#include "IProductor.h"
#include "IConsumidor.h"
using namespace std;

class GestorCiudad {
	private:
	vector<shared_ptr<IEntidad>> entidades;
	int turnoActual;	
public:
	GestorCiudad();
	void agregarEntidad(shared_ptr<IEntidad> nuevaentidad);
	void procesarTurno();
	void mostrarBalance(double prod, double cons)const;
};
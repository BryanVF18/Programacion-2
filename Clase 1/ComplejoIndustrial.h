#pragma once
#include "EntidadBase.h"
#include "IConsumidor.h"
#include "IProductor.h"
using namespace std;
class ComplejoIndustrial:public EntidadBase, public IProductor, public IConsumidor
{

private:
	double produccionPropia;
	double consumoMaquinaria;
public:
	ComplejoIndustrial(string n, double prod, double cons);
	double producirEnergia()override;
	double consumirEnergia()override;
	string getDetalleEstado()const override;

};


#pragma once
#include "EntidadBase.h";
#include "IConsumidor.h";

class EdificioResidencial: public EntidadBase, public IConsumidor
{
private:
	double consumoBase;
	int habitantes;
	
public:
	EdificioResidencial(string n, double base, int hab);
	double consumirEnergia() override;
	string getDetalleEstado()const override;

};


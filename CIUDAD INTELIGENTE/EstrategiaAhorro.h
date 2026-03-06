#pragma once
#include "IEstrategiaEnergia.h"

class EstrategiaAhorro : public IEstrategiaEnergia
{
public:
	void ejecutarAccion(Distrito* contexto)override;
	string getTipoEstrategia()const override { 
		return "Ejecutanto plan de ahorro de energia"; }

};


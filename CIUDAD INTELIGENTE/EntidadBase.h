#pragma once
#include <string>
#include "IEntidad.h"
using namespace std;

class EntidadBase : public IEntidad
{
protected:
	string nombre;
	bool activo; //Parnas: El estado iterno esta protegido

public:
	EntidadBase(string n) : nombre(n), activo(true) {}
	string getNombre() const override
	{
		return nombre;
	}

	virtual void alternarEstado()
	{
		activo = !activo;
	}

	bool estaActivo() const
	{
		return activo;
	}

};


#pragma once
#include <string>
#include "MedicionTrafico.h"

using namespace std;
//Esta clase es la base de nuestro patrón composite
//Es decir nuestras carreteras van a estar compuestas de componentes viales
class ComponenteVial
{
public:
	virtual ~ComponenteVial() = default;
	virtual MedicionTrafico obtenerMedicion() const = 0;
	virtual string getNombre() const = 0;
	virtual void mostrarReporte(int nivel = 0)const = 0;
};
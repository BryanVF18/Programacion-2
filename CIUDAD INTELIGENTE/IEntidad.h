#pragma once
#include <string>
using namespace std;

class IEntidad
{
public:
	virtual ~IEntidad() = default;
	virtual string getNombre() const = 0;
	virtual string getDetalleEstado() const = 0;

};

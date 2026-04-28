#pragma once
#include "ComponenteVial.h"
#include "AdaptadorSensorTrafico.h"
#include <memory>
#include <string>
using namespace std;

//Esta clase aplica el big 3 rule

class ViaAlterna : public ComponenteVial
{
private:
	string nombre;
	double longitudKM;
	AdaptadorSensorTrafico* sensor;
public:
	ViaAlterna(string nombre, double longitudKM, AdaptadorSensorTrafico* sensor);

	//Big3Rule -> 1. Destructor -> 2. Constructor de copia -> 3. Comparador
	//Regla 1:
	~ViaAlterna();
	//Regla 2:
	ViaAlterna(const ViaAlterna& otraViaAlterna);
	//Regla 3:
	//Sobrecargamos el operador =
	ViaAlterna& operator=(const ViaAlterna& otraViaAlterna);
	string getNombre() const override;
	MedicionTrafico obtenerMedicionTotal()const override;
	void mostrarReporte(int nivel = 0) const override;

};
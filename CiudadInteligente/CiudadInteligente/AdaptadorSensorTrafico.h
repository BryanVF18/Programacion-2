#pragma once
#include "SensorTraficoExterno.h"
#include "MedicionTrafico.h"

using namespace std;

//En esta clase vamos a aplicar el patrón adapter
//Vamos a obtener la información del sensor externo y convertirla en informacion de MedicionTrafico para que pueda ser utilizada dentro de la CI

class AdaptadorSensorTrafico
{
private:
	SensorTraficoExterno sensorExterno;
public:
	AdaptadorSensorTrafico(const SensorTraficoExterno& sensor) : sensorExterno(sensor) {}
	
	MedicionTrafico obtenerMedicion() const {
		return MedicionTrafico(sensorExterno.getConteoVehiculos(), sensorExterno.getVelocidadMedia(),
			sensorExterno.getOcupacionVia());
	}

	string getCodigoSensor() const {
		return sensorExterno.getCodigoSensor();
	}
};
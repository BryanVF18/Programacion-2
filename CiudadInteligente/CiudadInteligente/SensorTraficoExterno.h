#pragma once
#include <string>
using namespace std;

//Esta es una clase externa incompatible con la estructura de ciudadInteligente
//Sin embargo es un insumo importante para el control del trafico
//Por ejemplo el sensor del trafico no puede saber si hay un choque, pero el externo
//podria saberlo por medio del reporte de sus usuarios, ademas de informacion más relevante sobre la vía

//Esta clase solo sirve para leer datos externos, no implemanta nada dentro de la CI

class SensorTraficoExterno
{
private: 
	string codigoSensor;
	int conteoVehiculos;
	double velocidadMedia;
	double ocupacionVia;
public:
	SensorTraficoExterno(string codigoSensor, int conteoVehiculos, double velocidadMedia, double ocupacionVia)
		: codigoSensor(codigoSensor), conteoVehiculos(conteoVehiculos), velocidadMedia(velocidadMedia), ocupacionVia(ocupacionVia) {
	}

	string getCodigoSensor() const { return codigoSensor; }
	int getConteoVehiculos() const { return conteoVehiculos; }
	double getVelocidadMedia() const { return velocidadMedia; }
	double getOcupacionVia() const { return ocupacionVia; }
};
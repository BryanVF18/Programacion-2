#pragma once
#include <iostream>
#include <string>
using namespace std;
//En esta clase vamos a desarrollar sobrecarga de operadores
//FIJO ENTRA EN EL EXAMEN
class MedicionTrafico
{
private:
	int vehiculos;
	double velocidadPromedio;
	double nivelCongestion;
public:
	MedicionTrafico(int vehiculos = 0, double velocidadPromedio = 0.0, double nivelCongestion = 0.0)
		: vehiculos(vehiculos), velocidadPromedio(velocidadPromedio), nivelCongestion(nivelCongestion) {
	}

	int getVehiculos() const { return vehiculos; }
	double getVelocidadPromedio() const { return velocidadPromedio; }
	double getNivelCongestion() const { return nivelCongestion; }

	// Sobrecarga del operadores
	//1. Sobrecargamos el operador de +

	MedicionTrafico operator+(const MedicionTrafico& otraCarretera)const {

		//Primero sumamos las variables de cada carretera

		//MedicionTrafico carretera 1;
		//MedicionTrafico carretera 2;
		//MedicionTrafico cruce = carretera1 + carretera2;  Es lo que hara el programa si usa un + entre dos carreteras

		int totalVehiculos = vehiculos + otraCarretera.vehiculos;
		if (totalVehiculos == 0) {
			return MedicionTrafico(); // Evitar división por cero
		}
		double velocidadPonderada = ((velocidadPromedio * vehiculos + otraCarretera.velocidadPromedio * otraCarretera.vehiculos));
		double congestionPromedio = (nivelCongestion + otraCarretera.nivelCongestion) / 2.0;
		//Devolvemos un nuevo objeto que condensa la suma de las variables en un todo.

		return MedicionTrafico(totalVehiculos, velocidadPonderada, congestionPromedio);
	}

	//2. Sobrecargamos el operador de >
	bool operator>(const MedicionTrafico& otraCarretera) const {
		//MedicionTrafico carretera 1;
		//MedicionTrafico carretera 2;
		//bool esmayor = carretera1 > carretera2;  Es lo que hara el programa si usa un > entre dos carreteras
		return nivelCongestion > otraCarretera.nivelCongestion;
	}

	//3. Sobrecargamos el operador de <<
	//MedicionTrafico carretera;
	//cout << carretera1;  Es lo que hara el programa si usa un << entre una carretera y cout
	friend ostream& operator<<(ostream& os, const MedicionTrafico& m) {
		os<<"Vehiculos: " <<m.vehiculos<< ", Velocidad Promedio: " <<m.velocidadPromedio
			<< " km/h, Nivel de Congestion: " << m.nivelCongestion << "%";
		return os;
	}
};

#pragma once
#include "SensorAmbiental.h"
#include "EstrategiaPrioridadAmbiental.h"

using namespace std;

class EvaluadorPrioridadAmbiental {
private: 
	EstrategiaPrioridadAmbiental* estrategia;

public:
	EvaluadorPrioridadAmbiental(EstrategiaPrioridadAmbiental* estrategia) {
		this->estrategia = estrategia;
	}
	void cambiarEstrategia(EstrategiaPrioridadAmbiental* nuevaEstrategia) {
		this->estrategia = nuevaEstrategia;
	}
	void evaluar(SensorAmbiental* sensor) {
		cout << "[Estrategia de evaluacion] - Sensor: " << sensor->getTipo() << endl;
		cout << "Ubicacion: " << sensor->getUbicacion() << endl;
		cout << "Valor: " << sensor->getValor() << endl;
		cout << "Prioridad calculada: " << estrategia->calcularPrioridad(sensor) << endl;
	}
};
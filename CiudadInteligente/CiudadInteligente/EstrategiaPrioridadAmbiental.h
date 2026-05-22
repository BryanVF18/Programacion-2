#pragma once
#include <iostream>
#include <string>
#include "SensorAmbiental.h"
using namespace std;

class EstrategiaPrioridadAmbiental {

public:
	virtual ~EstrategiaPrioridadAmbiental() {}
	virtual string calcularPrioridad(SensorAmbiental* sensor) = 0;
};

class PrioridadPorAire : public EstrategiaPrioridadAmbiental {
	string calcularPrioridad(SensorAmbiental* sensor)override {
		if (sensor->getTipo() == "Calidad del aire" && sensor->getValor() >= 70) {
			return "ALTA";
		}
		return "NORMAL";
	}
};

class PrioridadPorRuido : public EstrategiaPrioridadAmbiental {
	string calcularPrioridad(SensorAmbiental* sensor)override {
		if (sensor->getTipo() == "Ruido ambiental" && sensor->getValor() >= 70) {
			return "ALTA";
		}
		return "NORMAL";
	}
};

class PrioridadPorAgua : public EstrategiaPrioridadAmbiental {
	string calcularPrioridad(SensorAmbiental* sensor)override {
		if (sensor->getTipo() == "Calidad del agua" && sensor->getValor() >= 70) {
			return "ALTA";
		}
		return "NORMAL";
	}
};
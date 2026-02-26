#include "ComplejoIndustrial.h"


ComplejoIndustrial::ComplejoIndustrial(string n, double prod, double cons) :EntidadBase(n), produccionPropia(prod), consumoMaquinaria(cons) {

}

double ComplejoIndustrial::producirEnergia() {
	return activo ? produccionPropia : 0.0;
}

double ComplejoIndustrial::consumirEnergia() {
	return activo ? consumoMaquinaria : 0.0;
}

string ComplejoIndustrial::getDetalleEstado()const {
	bool autosuficiente = produccionPropia >= consumoMaquinaria;
	return "Tipo: [Hibrido] | Autosuficiente: " + string(autosuficiente ? "Si" : "No");
}

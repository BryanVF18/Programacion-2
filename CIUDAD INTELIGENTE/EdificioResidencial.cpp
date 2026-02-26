#include "EdificioResidencial.h"

EdificioResidencial::EdificioResidencial(string n, double base, int hab) : EntidadBase(n), consumoBase(base), habitantes(hab) {

}

double EdificioResidencial::consumirEnergia() {
	if (!activo)return 0.0;
	return consumoBase + (habitantes * 0.5);
}

string EdificioResidencial::getDetalleEstado()const {
	return "Tipo: [Consumidor] | Habitantes: " + to_string(habitantes);
}

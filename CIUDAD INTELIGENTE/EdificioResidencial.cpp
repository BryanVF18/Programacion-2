#include "EdificioResidencial.h"

EdificioResidencial::EdificioResidencial(std::string n, double base, int hab)
    : EntidadBase(n), consumoBase(base), habitantes(hab) {
}

double EdificioResidencial::consumirEnergia() {
    if (!activo) return 0.0;
    return consumoBase + (habitantes * 0.5);
}

std::string EdificioResidencial::getDetalleEstado() const {
    return "Tipo: [Consumidor] | Habitantes: " + std::to_string(habitantes);
}

#pragma once
#include "EntidadBase.h"
#include "IConsumidor.h"


using namespace std;
// PRINCIPIO DE SUSTITUCIÓN DE LISKOV (LSP):
// PlantaSolar PUEDE sustituir a IEntidad en cualquier parte del código
// sin que el programa falle. Es un subtipo real.

class EdificioResidencial : public EntidadBase, public IConsumidor {
private:
    double consumoBase;
    int habitantes;

public:
    EdificioResidencial(std::string n, double base, int hab);
    double consumirEnergia() override;
    std::string getDetalleEstado() const override;
    void serializarBinario(ofstream& os) const override;
    void serializarTexto(ostream& os) const override;
};
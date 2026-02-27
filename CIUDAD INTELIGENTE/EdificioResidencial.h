#pragma once
#include "EntidadBase.h";
#include "IConsumidor.h";

class EdificioResidencial : public EntidadBase, public IConsumidor {
private:
    double consumoBase;
    int habitantes;

public:
    EdificioResidencial(std::string n, double base, int hab);
    double consumirEnergia() override;
    std::string getDetalleEstado() const override;
};

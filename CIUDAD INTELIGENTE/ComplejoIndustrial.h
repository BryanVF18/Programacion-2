#pragma once
#include "EntidadBase.h"
#include "IConsumidor.h"
#include "IProductor.h"

class ComplejoIndustrial : public EntidadBase, public IProductor, public IConsumidor {
private:
    double produccionPropia;
    double consumoMaquinaria;

public:
    ComplejoIndustrial(std::string n, double prod, double cons);
    double producirEnergia() override;
    double consumirEnergia() override;
    std::string getDetalleEstado() const override;
};

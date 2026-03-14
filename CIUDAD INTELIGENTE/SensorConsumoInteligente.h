#pragma once
#include <string>
#include "IConsumidor.h"

#include "EntidadDecoradora.h"

using namespace std;

class SensorConsumoInteligente : public EntidadDecoradora
{

public:

    SensorConsumoInteligente(string nombre, shared_ptr<IConsumidor> entidadDecorada);

    double consumirEnergia() override;

    string getDetalleEstado() const override;

};


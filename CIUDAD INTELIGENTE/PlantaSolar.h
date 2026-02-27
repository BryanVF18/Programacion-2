#pragma once
#include <string>
#include"IProductor.h"
#include"EntidadBase.h"
using namespace std;

//SOLID(L)
//LA PLANTA SOLAR PUEDE HACER PASAR SUSTIUIR A IENTIDAD EN CUALQUIER PARTE DEL CODIGO SIN QUE EL PROGRAMA FALLE 
class PlantaSolar : public EntidadBase, public IProductor {
private:
    double capacidadMaxima;
    double eficiencia;
public:
    PlantaSolar(string n, double cap);
    double producirEnergia() override;
    string getDetalleEstado() const override;
};


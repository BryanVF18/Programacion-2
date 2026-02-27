#pragma once
#include <string>
using namespace std;

//PRINCIPIO DE SEGREGACIÓN DE INTERFAZ (ISP)
//CREANDO CONTRATOS ESPECIFICOS, CONSUMIDOR O PRODUCTOR
//SOLID(I) LAS CLASES NO DEBEN SER FORZADAS A IMPLEMENTAR METODOS QUE NO USAN

class IEntidad {
public:
    virtual ~IEntidad() = default;
    virtual string getNombre() const = 0;
    virtual string getDetalleEstado() const = 0;
};

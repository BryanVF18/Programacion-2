#pragma once
#include <string>
#include <fstream> //ABSOLUTAMENTA NECESARIO PARA EL OSTREAM Y OFSTREAM
using namespace std;

// PRINCIPIO DE SEGREGACIÓN DE INTERFAZ (ISP):
// Creamos contratos pequeños (IEntidad, IProductor) en lugar de uno gigante.
// SOLID (I): Las clases no deben ser forzadas a implementar métodos que no usan.

class IEntidad {
public:
    virtual ~IEntidad() = default;
    virtual string getNombre() const = 0;
    virtual string getDetalleEstado() const = 0;

    //PERSISTENCIA 
    //1. Flujos de texto (Reportes)

    virtual void serializarTexto(ostream& os)const = 0; //El ostream sirve para la salida de datos





    //2. Flujos binarios (Guardar datos planos)

    virtual void serializarBinario(ofstream& os)const = 0;

};

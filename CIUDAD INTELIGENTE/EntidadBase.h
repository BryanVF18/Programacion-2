#pragma once
#include <string>
#include "IEntidad.h"
using namespace std;

//LOS ATRIBUTOS NOMBRE Y ACTIVO SON PROTECTED
//"EL MUNDO EXTERIOR NO SABE CÓMO SE GUARDAN, SOLO SE ACCEDE VÍA MÉTODOS PÚBLICOS"


class EntidadBase : public IEntidad {
protected:
    string nombre;
    bool activo;

public:
    EntidadBase(string n);
    string getNombre() const override;
    virtual void alternarEstado();
    bool isActivo() const;
};



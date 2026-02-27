#pragma once
#include <vector>
#include <memory>
#include "IEntidad.h"
#include "IProductor.h"
#include "IConsumidor.h"

//PRINCIPIO ABIERTO/CERRADO
//SOLID(O) EL GESTOR ESTA CERRADO A LA MODIFICACION, SOLO "MUEVE DATOS" NO SE TOCA PARA AGREGAR NUEVAS ENTIDADES
class GestorCiudad {
private:
    std::vector<std::shared_ptr<IEntidad>> entidades;
    int turnoActual;
    void mostrarBalance(double prod, double cons) const; // Ley de Deméter (privado)

public:
    GestorCiudad();
    void agregarEntidad(std::shared_ptr<IEntidad> nuevaEntidad);
    void procesarTurno();
};
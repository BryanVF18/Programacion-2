#pragma once
#include <vector>
#include <memory>
#include "Distrito.h"

//PRINCIPIO ABIERTO/CERRADO
//SOLID(O) EL GESTOR ESTA CERRADO A LA MODIFICACION, SOLO "MUEVE DATOS" NO SE TOCA PARA AGREGAR NUEVAS ENTIDADES
class GestorCiudad {
private:
    std::vector<std::shared_ptr<Distrito>> distritos;
    int turnoActual;
    

public:
    GestorCiudad();
    void agregarDistrito(std::shared_ptr<Distrito> nuevoDistrito);
    void procesarTurno();
};
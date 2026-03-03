#pragma once
#include <vector>
#include <memory>
#include "Distrito.h"
#include "CentralEmergencias.h"

using namespace std;

//PRINCIPIO ABIERTO/CERRADO
//SOLID(O) EL GESTOR ESTA CERRADO A LA MODIFICACION, SOLO "MUEVE DATOS" NO SE TOCA PARA AGREGAR NUEVAS ENTIDADES
class GestorCiudad {
private:
    std::vector<std::shared_ptr<Distrito>> distritos;
    int turnoActual;
    shared_ptr<CentralEmergencias>centralUrbana;//La central de emergencias del gestor

public:
    //Principio KISS: Solo inicializar lo más basico

    GestorCiudad(shared_ptr<CentralEmergencias>central);
    void agregarDistrito(std::shared_ptr<Distrito> nuevoDistrito);
    void procesarTurno();

};